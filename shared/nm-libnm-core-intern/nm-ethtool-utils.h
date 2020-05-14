// SPDX-License-Identifier: LGPL-2.1+
/*
 * Copyright (C) 2018 Red Hat, Inc.
 */

#ifndef __NM_ETHTOOL_UTILS_H__
#define __NM_ETHTOOL_UTILS_H__

/*****************************************************************************/

typedef enum {
	NM_ETHTOOL_ID_UNKNOWN = -1,

	_NM_ETHTOOL_ID_FIRST = 0,

	_NM_ETHTOOL_ID_COALESCE_FIRST = _NM_ETHTOOL_ID_FIRST,
	NM_ETHTOOL_ID_COALESCE_ADAPTIVE_RX = _NM_ETHTOOL_ID_COALESCE_FIRST,
	NM_ETHTOOL_ID_COALESCE_ADAPTIVE_TX,
	NM_ETHTOOL_ID_COALESCE_PKT_RATE_HIGH,
	NM_ETHTOOL_ID_COALESCE_PKT_RATE_LOW,
	NM_ETHTOOL_ID_COALESCE_RX_FRAMES,
	NM_ETHTOOL_ID_COALESCE_RX_FRAMES_HIGH,
	NM_ETHTOOL_ID_COALESCE_RX_FRAMES_IRQ,
	NM_ETHTOOL_ID_COALESCE_RX_FRAMES_LOW,
	NM_ETHTOOL_ID_COALESCE_RX_USECS,
	NM_ETHTOOL_ID_COALESCE_RX_USECS_HIGH,
	NM_ETHTOOL_ID_COALESCE_RX_USECS_IRQ,
	NM_ETHTOOL_ID_COALESCE_RX_USECS_LOW,
	NM_ETHTOOL_ID_COALESCE_SAMPLE_INTERVAL,
	NM_ETHTOOL_ID_COALESCE_STATS_BLOCK_USECS,
	NM_ETHTOOL_ID_COALESCE_TX_FRAMES,
	NM_ETHTOOL_ID_COALESCE_TX_FRAMES_HIGH,
	NM_ETHTOOL_ID_COALESCE_TX_FRAMES_IRQ,
	NM_ETHTOOL_ID_COALESCE_TX_FRAMES_LOW,
	NM_ETHTOOL_ID_COALESCE_TX_USECS,
	NM_ETHTOOL_ID_COALESCE_TX_USECS_HIGH,
	NM_ETHTOOL_ID_COALESCE_TX_USECS_IRQ,
	NM_ETHTOOL_ID_COALESCE_TX_USECS_LOW,
	_NM_ETHTOOL_ID_COALESCE_LAST = NM_ETHTOOL_ID_COALESCE_TX_USECS_LOW,

	_NM_ETHTOOL_ID_FEATURE_FIRST = _NM_ETHTOOL_ID_COALESCE_LAST + 1,
	NM_ETHTOOL_ID_FEATURE_ESP_HW_OFFLOAD = _NM_ETHTOOL_ID_FEATURE_FIRST,
	NM_ETHTOOL_ID_FEATURE_ESP_TX_CSUM_HW_OFFLOAD,
	NM_ETHTOOL_ID_FEATURE_FCOE_MTU,
	NM_ETHTOOL_ID_FEATURE_GRO,
	NM_ETHTOOL_ID_FEATURE_GSO,
	NM_ETHTOOL_ID_FEATURE_HIGHDMA,
	NM_ETHTOOL_ID_FEATURE_HW_TC_OFFLOAD,
	NM_ETHTOOL_ID_FEATURE_L2_FWD_OFFLOAD,
	NM_ETHTOOL_ID_FEATURE_LOOPBACK,
	NM_ETHTOOL_ID_FEATURE_LRO,
	NM_ETHTOOL_ID_FEATURE_NTUPLE,
	NM_ETHTOOL_ID_FEATURE_RX,
	NM_ETHTOOL_ID_FEATURE_RXHASH,
	NM_ETHTOOL_ID_FEATURE_RXVLAN,
	NM_ETHTOOL_ID_FEATURE_RX_ALL,
	NM_ETHTOOL_ID_FEATURE_RX_FCS,
	NM_ETHTOOL_ID_FEATURE_RX_GRO_HW,
	NM_ETHTOOL_ID_FEATURE_RX_UDP_TUNNEL_PORT_OFFLOAD,
	NM_ETHTOOL_ID_FEATURE_RX_VLAN_FILTER,
	NM_ETHTOOL_ID_FEATURE_RX_VLAN_STAG_FILTER,
	NM_ETHTOOL_ID_FEATURE_RX_VLAN_STAG_HW_PARSE,
	NM_ETHTOOL_ID_FEATURE_SG,
	NM_ETHTOOL_ID_FEATURE_TLS_HW_RECORD,
	NM_ETHTOOL_ID_FEATURE_TLS_HW_TX_OFFLOAD,
	NM_ETHTOOL_ID_FEATURE_TSO,
	NM_ETHTOOL_ID_FEATURE_TX,
	NM_ETHTOOL_ID_FEATURE_TXVLAN,
	NM_ETHTOOL_ID_FEATURE_TX_CHECKSUM_FCOE_CRC,
	NM_ETHTOOL_ID_FEATURE_TX_CHECKSUM_IPV4,
	NM_ETHTOOL_ID_FEATURE_TX_CHECKSUM_IPV6,
	NM_ETHTOOL_ID_FEATURE_TX_CHECKSUM_IP_GENERIC,
	NM_ETHTOOL_ID_FEATURE_TX_CHECKSUM_SCTP,
	NM_ETHTOOL_ID_FEATURE_TX_ESP_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_FCOE_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_GRE_CSUM_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_GRE_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_GSO_PARTIAL,
	NM_ETHTOOL_ID_FEATURE_TX_GSO_ROBUST,
	NM_ETHTOOL_ID_FEATURE_TX_IPXIP4_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_IPXIP6_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_NOCACHE_COPY,
	NM_ETHTOOL_ID_FEATURE_TX_SCATTER_GATHER,
	NM_ETHTOOL_ID_FEATURE_TX_SCATTER_GATHER_FRAGLIST,
	NM_ETHTOOL_ID_FEATURE_TX_SCTP_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_TCP6_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_TCP_ECN_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_TCP_MANGLEID_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_TCP_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_UDP_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_UDP_TNL_CSUM_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_UDP_TNL_SEGMENTATION,
	NM_ETHTOOL_ID_FEATURE_TX_VLAN_STAG_HW_INSERT,
	_NM_ETHTOOL_ID_FEATURE_LAST = NM_ETHTOOL_ID_FEATURE_TX_VLAN_STAG_HW_INSERT,

	_NM_ETHTOOL_ID_RING_FIRST = _NM_ETHTOOL_ID_FEATURE_LAST + 1,
	NM_ETHTOOL_ID_RING_RX = _NM_ETHTOOL_ID_RING_FIRST,
	NM_ETHTOOL_ID_RING_RX_JUMBO,
	NM_ETHTOOL_ID_RING_RX_MINI,
	NM_ETHTOOL_ID_RING_TX,
	_NM_ETHTOOL_ID_RING_LAST = NM_ETHTOOL_ID_RING_TX,

	_NM_ETHTOOL_ID_LAST = _NM_ETHTOOL_ID_RING_LAST,

	_NM_ETHTOOL_ID_COALESCE_NUM = (_NM_ETHTOOL_ID_COALESCE_LAST - _NM_ETHTOOL_ID_COALESCE_FIRST + 1),
	_NM_ETHTOOL_ID_FEATURE_NUM = (_NM_ETHTOOL_ID_FEATURE_LAST - _NM_ETHTOOL_ID_FEATURE_FIRST + 1),
	_NM_ETHTOOL_ID_RING_NUM = (_NM_ETHTOOL_ID_RING_LAST - _NM_ETHTOOL_ID_RING_FIRST + 1),
	_NM_ETHTOOL_ID_NUM = (_NM_ETHTOOL_ID_LAST - _NM_ETHTOOL_ID_FIRST + 1),
} NMEthtoolID;

typedef enum {
	NM_ETHTOOL_TYPE_UNKNOWN,
	NM_ETHTOOL_TYPE_COALESCE,
	NM_ETHTOOL_TYPE_FEATURE,
	NM_ETHTOOL_TYPE_RING,
} NMEthtoolType;

typedef struct {
	const char *optname;
	NMEthtoolID id;
} NMEthtoolData;

extern const NMEthtoolData *const nm_ethtool_data[_NM_ETHTOOL_ID_NUM + 1];

const NMEthtoolData *nm_ethtool_data_get_by_optname (const char *optname);

NMEthtoolType nm_ethtool_id_to_type (NMEthtoolID id);

/****************************************************************************/

static inline NMEthtoolID
nm_ethtool_id_get_by_name (const char *optname)
{
	const NMEthtoolData *d;

	d = nm_ethtool_data_get_by_optname (optname);
	return d ? d->id : NM_ETHTOOL_ID_UNKNOWN;
}

static inline gboolean
nm_ethtool_id_is_feature (NMEthtoolID id)
{
	return id >= _NM_ETHTOOL_ID_FEATURE_FIRST && id <= _NM_ETHTOOL_ID_FEATURE_LAST;
}

static inline gboolean
nm_ethtool_id_is_coalesce (NMEthtoolID id)
{
	return id >= _NM_ETHTOOL_ID_COALESCE_FIRST && id <= _NM_ETHTOOL_ID_COALESCE_LAST;
}

static inline gboolean
nm_ethtool_id_is_ring (NMEthtoolID id)
{
	return id >= _NM_ETHTOOL_ID_RING_FIRST && id <= _NM_ETHTOOL_ID_RING_LAST;
}

/****************************************************************************/

#endif /* __NM_ETHTOOL_UTILS_H__ */
