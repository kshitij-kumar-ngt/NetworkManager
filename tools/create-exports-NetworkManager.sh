#!/bin/bash

set -e
set -o pipefail

die() {
    echo "$@"
    exit 1
}

# generates the linker version script src/NetworkManager.ver
# by looking at the symbols needed by the device and settings
# plugins. Note that this depends on how NetworkManager and
# the plugins are build. For example, compiling without
# --with-more-asserts will yield less symbols.
#
# _build re-builds NetworkManager with relevant compile time
# options to yield the most symbols.
_build() {
    git clean -fdx
    ./autogen.sh --enable-ld-gc --enable-ifcfg-rh --enable-ifupdown \
        --enable-config-plugin-ibft --enable-teamdctl --enable-wifi \
        --with-modem-manager-1 --with-ofono --with-more-asserts \
        --with-more-logging
    make -j20
}

_sort() {
    LANG=C sort -u
}

call_nm() {
    "${NM:-nm}" "$1" |
        sed -n 's/.* \([^ ]\) \([^ ]*\)$/\1 \2/p'
}

get_symbols_nm () {
    if [ -z "$from_meson" ]; then
        base=./src/.libs/libNetworkManager.a
    else
        base=./src/nm-full-symbols
    fi
    call_nm "$base" |
        sed -n 's/^[tTDGRBS] //p' |
        _sort
}

get_symbols_explict() {
    cat <<EOF | _sort
_IO_stdin_used
EOF
}

get_symbols_missing() {
    (for f in $(find ./src/settings/plugins/*/${libs} \
                     ./src/devices/*/${libs} \
                     ./src/ppp/${libs} -name '*.so' 2>/dev/null); do
        call_nm "$f" |
            sed -n 's/^\([U]\) \(\(nm_\|nmp_\|_nm\|NM\|_NM\|nmtst_\|c_siphash_\|c_list_\).*\)$/\2/p'
    done) |
        _sort |
        grep -Fx -f <(get_symbols_explict) -v |
        grep -Fx -f <(get_symbols_nm)
}

pretty() {
    sed 's/.*/\t\0;/'
}

do_build() {
    do_update
    make
}

do_rebuild() {
    _build
    do_build
}

do_update() {
    do_generate > ./src/NetworkManager.ver
}

do_generate() {
    cat <<EOF
# this file is generated by $0
{
global:
$(get_symbols_missing | pretty)

$(get_symbols_explict | pretty)
local:
	*;
};
EOF
}

if [ -f "build.ninja" ]; then
    from_meson=1
    libs=
else
    libs=.libs/
fi

test -f ./src/${libs}libNetworkManager.a || die "must be called from NetworkManager top build dir after building the tree"

case "$1" in
    rebuild)
        [ -n "$from_meson" ] && die "can't do a build when called from meson"
        do_rebuild
        ;;
    build)
        [ -n "$from_meson" ] && die "can't do a build when called from meson"
        do_build
        ;;
    --called-from-build)
        if test -z "${NM_BUILD_NO_CREATE_EXPORTS+x}"; then
            do_update
        else
            if test -f "./src/NetworkManager.ver"; then
                touch ./src/NetworkManager.ver
            fi
        fi
        ;;
    update)
        do_update
        ;;
    *)
        do_generate
        ;;
esac

