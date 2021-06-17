#ifdef mini_network
//+doc network definitions
//+def network


#define IFHWADDRLEN  6
#define IF_NAMESIZE  16
#define IFNAMSIZ  IF_NAMESIZE



#define ifr_name  ifr_ifrn.ifrn_name
#define ifr_hwaddr   ifr_ifru.ifru_hwaddr
#define ifr_addr  ifr_ifru.ifru_addr
#define ifr_dstaddr  ifr_ifru.ifru_dstaddr
#define ifr_broadaddr   ifr_ifru.ifru_broadaddr
#define ifr_netmask  ifr_ifru.ifru_netmask
#define ifr_flags ifr_ifru.ifru_flags
#define ifr_metric   ifr_ifru.ifru_ivalue
#define ifr_mtu      ifr_ifru.ifru_mtu
#define ifr_map      ifr_ifru.ifru_map
#define ifr_slave ifr_ifru.ifru_slave
#define ifr_data  ifr_ifru.ifru_data
#define ifr_ifindex  ifr_ifru.ifru_ivalue
#define ifr_bandwidth   ifr_ifru.ifru_ivalue
#define ifr_qlen  ifr_ifru.ifru_ivalue
#define ifr_newname  ifr_ifru.ifru_newname

struct udphdr {
	uint16_t uh_sport;
	uint16_t uh_dport;
	uint16_t uh_ulen;
	uint16_t uh_sum;
};

#define UDP_CORK  1
#define UDP_ENCAP 100
#define UDP_NO_CHECK6_TX 101
#define UDP_NO_CHECK6_RX 102
#define UDP_SEGMENT  103

#define UDP_ENCAP_ESPINUDP_NON_IKE 1
#define UDP_ENCAP_ESPINUDP 2
#define UDP_ENCAP_L2TPINUDP   3
#define UDP_ENCAP_GTP0     4
#define UDP_ENCAP_GTP1U    5

#define SOL_UDP            17




#define IPPORT_RESERVED 1024

#define IPPROTO_IP       0
#define IPPROTO_HOPOPTS  0
#define IPPROTO_ICMP     1
#define IPPROTO_IGMP     2
#define IPPROTO_IPIP     4
#define IPPROTO_TCP      6
#define IPPROTO_EGP      8
#define IPPROTO_PUP      12
#define IPPROTO_UDP      17
#define IPPROTO_IDP      22
#define IPPROTO_TP       29
#define IPPROTO_DCCP     33
#define IPPROTO_IPV6     41
#define IPPROTO_ROUTING  43
#define IPPROTO_FRAGMENT 44
#define IPPROTO_RSVP     46
#define IPPROTO_GRE      47
#define IPPROTO_ESP      50
#define IPPROTO_AH       51
#define IPPROTO_ICMPV6   58
#define IPPROTO_NONE     59
#define IPPROTO_DSTOPTS  60
#define IPPROTO_MTP      92
#define IPPROTO_BEETPH   94
#define IPPROTO_ENCAP    98
#define IPPROTO_PIM      103
#define IPPROTO_COMP     108
#define IPPROTO_SCTP     132
#define IPPROTO_MH       135
#define IPPROTO_UDPLITE  136
#define IPPROTO_MPLS     137
#define IPPROTO_RAW      255
#define IPPROTO_MAX      256



#define	IPVERSION	4
#define	IP_MAXPACKET	65535

#define	IPTOS_ECN_MASK		0x03
#define	IPTOS_ECN(x)		((x) & IPTOS_ECN_MASK)
#define	IPTOS_ECN_NOT_ECT	0x00
#define	IPTOS_ECN_ECT1		0x01
#define	IPTOS_ECN_ECT0		0x02
#define	IPTOS_ECN_CE		0x03

#define	IPTOS_DSCP_MASK		0xfc
#define	IPTOS_DSCP(x)		((x) & IPTOS_DSCP_MASK)
#define	IPTOS_DSCP_AF11		0x28
#define	IPTOS_DSCP_AF12		0x30
#define	IPTOS_DSCP_AF13		0x38
#define	IPTOS_DSCP_AF21		0x48
#define	IPTOS_DSCP_AF22		0x50
#define	IPTOS_DSCP_AF23		0x58
#define	IPTOS_DSCP_AF31		0x68
#define	IPTOS_DSCP_AF32		0x70
#define	IPTOS_DSCP_AF33		0x78
#define	IPTOS_DSCP_AF41		0x88
#define	IPTOS_DSCP_AF42		0x90
#define	IPTOS_DSCP_AF43		0x98
#define	IPTOS_DSCP_EF		0xb8

#define	IPTOS_CLASS_MASK	0xe0
#define	IPTOS_CLASS(x)		((x) & IPTOS_CLASS_MASK)
#define	IPTOS_CLASS_CS0		0x00
#define	IPTOS_CLASS_CS1		0x20
#define	IPTOS_CLASS_CS2		0x40
#define	IPTOS_CLASS_CS3		0x60
#define	IPTOS_CLASS_CS4		0x80
#define	IPTOS_CLASS_CS5		0xa0
#define	IPTOS_CLASS_CS6		0xc0
#define	IPTOS_CLASS_CS7		0xe0
#define	IPTOS_CLASS_DEFAULT	IPTOS_CLASS_CS0

#define	IPTOS_TOS_MASK		0x1E
#define	IPTOS_TOS(tos)		((tos) & IPTOS_TOS_MASK)
#define	IPTOS_LOWDELAY		0x10
#define	IPTOS_THROUGHPUT	0x08
#define	IPTOS_RELIABILITY	0x04
#define	IPTOS_LOWCOST		0x02
#define	IPTOS_MINCOST		IPTOS_LOWCOST

#define	IPTOS_PREC_MASK			0xe0
#define	IPTOS_PREC(tos)                ((tos) & IPTOS_PREC_MASK)
#define	IPTOS_PREC_NETCONTROL		0xe0
#define	IPTOS_PREC_INTERNETCONTROL	0xc0
#define	IPTOS_PREC_CRITIC_ECP		0xa0
#define	IPTOS_PREC_FLASHOVERRIDE	0x80
#define	IPTOS_PREC_FLASH		0x60
#define	IPTOS_PREC_IMMEDIATE		0x40
#define	IPTOS_PREC_PRIORITY		0x20
#define	IPTOS_PREC_ROUTINE		0x00

#define	IPOPT_COPY		0x80
#define	IPOPT_CLASS_MASK	0x60
#define	IPOPT_NUMBER_MASK	0x1f

#define	IPOPT_COPIED(o)		((o) & IPOPT_COPY)
#define	IPOPT_CLASS(o)		((o) & IPOPT_CLASS_MASK)
#define	IPOPT_NUMBER(o)		((o) & IPOPT_NUMBER_MASK)

#define	IPOPT_CONTROL		0x00
#define	IPOPT_RESERVED1		0x20
#define	IPOPT_DEBMEAS		0x40
#define	IPOPT_MEASUREMENT       IPOPT_DEBMEAS
#define	IPOPT_RESERVED2		0x60

#define	IPOPT_EOL		0
#define	IPOPT_END		IPOPT_EOL
#define	IPOPT_NOP		1
#define	IPOPT_NOOP		IPOPT_NOP

#define	IPOPT_RR		7
#define	IPOPT_TS		68
#define	IPOPT_TIMESTAMP		IPOPT_TS
#define	IPOPT_SECURITY		130
#define	IPOPT_SEC		IPOPT_SECURITY
#define	IPOPT_LSRR		131
#define	IPOPT_SATID		136
#define	IPOPT_SID		IPOPT_SATID
#define	IPOPT_SSRR		137
#define	IPOPT_RA		148

#define	IPOPT_OPTVAL		0
#define	IPOPT_OLEN		1
#define	IPOPT_OFFSET		2
#define	IPOPT_MINOFF		4

#define	MAX_IPOPTLEN		40

#define	IPOPT_TS_TSONLY		0
#define	IPOPT_TS_TSANDADDR	1
#define	IPOPT_TS_PRESPEC	3

#define	IPOPT_SECUR_UNCLASS	0x0000
#define	IPOPT_SECUR_CONFID	0xf135
#define	IPOPT_SECUR_EFTO	0x789a
#define	IPOPT_SECUR_MMMM	0xbc4d
#define	IPOPT_SECUR_RESTR	0xaf13
#define	IPOPT_SECUR_SECRET	0xd788
#define	IPOPT_SECUR_TOPSECRET	0x6bc5

#define	MAXTTL		255
#define	IPDEFTTL	64
#define	IPFRAGTTL	60
#define	IPTTLDEC	1

#define	IP_MSS		576




#define ETHER_ADDR_LEN 6



#define IFF_UP 0x1
#define IFF_BROADCAST 0x2
#define IFF_DEBUG 0x4
#define IFF_LOOPBACK 0x8
#define IFF_POINTOPOINT 0x10
#define IFF_NOTRAILERS 0x20
#define IFF_RUNNING 0x40
#define IFF_NOARP 0x80
#define IFF_PROMISC 0x100
#define IFF_ALLMULTI 0x200
#define IFF_MASTER 0x400
#define IFF_SLAVE 0x800
#define IFF_MULTICAST 0x1000
#define IFF_PORTSEL 0x2000
#define IFF_AUTOMEDIA 0x4000
#define IFF_DYNAMIC 0x8000
#define IFF_LOWER_UP 0x10000
#define IFF_DORMANT 0x20000
#define IFF_ECHO 0x40000
#define IFF_VOLATILE (IFF_LOOPBACK|IFF_POINTOPOINT|IFF_BROADCAST| \
		        IFF_ECHO|IFF_MASTER|IFF_SLAVE|IFF_RUNNING|IFF_LOWER_UP|IFF_DORMANT)


#define ETH_P_802_3  0x0001
#define ETH_P_AX25   0x0002
#define ETH_P_ALL 0x0003
#define ETH_P_802_2  0x0004
#define ETH_P_SNAP   0x0005
#define ETH_P_DDCMP     0x0006
#define ETH_P_WAN_PPP   0x0007
#define ETH_P_PPP_MP    0x0008
#define ETH_P_LOCALTALK 0x0009
#define ETH_P_CAN 0x000C
#define ETH_P_CANFD  0x000D
#define ETH_P_PPPTALK   0x0010
#define ETH_P_TR_802_2  0x0011
#define ETH_P_MOBITEX   0x0015
#define ETH_P_CONTROL   0x0016
#define ETH_P_IRDA   0x0017
#define ETH_P_ECONET 0x0018
#define ETH_P_HDLC   0x0019
#define ETH_P_ARCNET 0x001A
#define ETH_P_DSA 0x001B
#define ETH_P_TRAILER   0x001C
#define ETH_P_PHONET 0x00F5
#define ETH_P_IEEE802154 0x00F6
#define ETH_P_CAIF   0x00F7
#define ETH_P_XDSA   0x00F8
#define ETH_P_MAP 0x00F9


#define ETH_ALEN  6
#define ETH_TLEN  2
#define ETH_HLEN  14
#define ETH_ZLEN  60
#define ETH_DATA_LEN 1500
#define ETH_FRAME_LEN   1514
#define ETH_FCS_LEN  4
#define ETH_MIN_MTU  68
#define ETH_MAX_MTU  0xFFFFU

#define ETH_P_LOOP   0x0060
#define ETH_P_PUP 0x0200
#define ETH_P_PUPAT  0x0201
#define ETH_P_TSN 0x22F0
#define ETH_P_ERSPAN2   0x22EB
#define ETH_P_IP  0x0800
#define ETH_P_X25 0x0805
#define ETH_P_ARP 0x0806
#define  ETH_P_BPQ   0x08FF
#define ETH_P_IEEEPUP   0x0a00
#define ETH_P_IEEEPUPAT 0x0a01
#define ETH_P_BATMAN 0x4305
#define ETH_P_DEC       0x6000
#define ETH_P_DNA_DL    0x6001
#define ETH_P_DNA_RC    0x6002
#define ETH_P_DNA_RT    0x6003
#define ETH_P_LAT       0x6004
#define ETH_P_DIAG      0x6005
#define ETH_P_CUST      0x6006
#define ETH_P_SCA       0x6007
#define ETH_P_TEB 0x6558
#define ETH_P_RARP      0x8035
#define ETH_P_ATALK  0x809B
#define ETH_P_AARP   0x80F3
#define ETH_P_8021Q  0x8100
#define ETH_P_IPX 0x8137
#define ETH_P_IPV6   0x86DD
#define ETH_P_PAUSE  0x8808
#define ETH_P_SLOW   0x8809
#define ETH_P_WCCP   0x883E
#define ETH_P_MPLS_UC   0x8847
#define ETH_P_MPLS_MC   0x8848
#define ETH_P_ATMMPOA   0x884c
#define ETH_P_PPP_DISC  0x8863
#define ETH_P_PPP_SES   0x8864
#define ETH_P_LINK_CTL  0x886c
#define ETH_P_ATMFATE   0x8884
#define ETH_P_PAE 0x888E
#define ETH_P_AOE 0x88A2
#define ETH_P_8021AD 0x88A8
#define ETH_P_802_EX1   0x88B5
#define ETH_P_ERSPAN 0x88BE
#define ETH_P_PREAUTH   0x88C7
#define ETH_P_TIPC   0x88CA
#define ETH_P_MACSEC 0x88E5
#define ETH_P_8021AH 0x88E7
#define ETH_P_MVRP   0x88F5
#define ETH_P_1588   0x88F7
#define ETH_P_NCSI   0x88F8
#define ETH_P_PRP 0x88FB
#define ETH_P_FCOE   0x8906
#define ETH_P_TDLS   0x890D
#define ETH_P_FIP 0x8914
#define ETH_P_IBOE   0x8915
#define ETH_P_80221  0x8917
#define ETH_P_HSR 0x892F
#define ETH_P_NSH 0x894F
#define ETH_P_LOOPBACK  0x9000
#define ETH_P_QINQ1  0x9100
#define ETH_P_QINQ2  0x9200
#define ETH_P_QINQ3  0x9300
#define ETH_P_EDSA   0xDADA
#define ETH_P_IFE 0xED3E
#define ETH_P_AF_IUCV   0xFBFB

#define ETH_P_802_3_MIN 0x0600




#define INADDR_ANY        ((in_addr_t) 0x00000000)
#define INADDR_BROADCAST  ((in_addr_t) 0xffffffff)
#define INADDR_NONE       ((in_addr_t) 0xffffffff)
#define INADDR_LOOPBACK   ((in_addr_t) 0x7f000001)

#define INADDR_UNSPEC_GROUP     ((in_addr_t) 0xe0000000)
#define INADDR_ALLHOSTS_GROUP   ((in_addr_t) 0xe0000001)
#define INADDR_ALLRTRS_GROUP    ((in_addr_t) 0xe0000002)
#define INADDR_MAX_LOCAL_GROUP  ((in_addr_t) 0xe00000ff)

#define IN6ADDR_ANY_INIT      { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
#define IN6ADDR_LOOPBACK_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }

#undef INET_ADDRSTRLEN
#undef INET6_ADDRSTRLEN
#define INET_ADDRSTRLEN  16
#define INET6_ADDRSTRLEN 46

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

struct in_addr { in_addr_t s_addr; };


struct in6_addr {
	union {
		uint8_t __s6_addr[16];
		uint16_t __s6_addr16[8];
		uint32_t __s6_addr32[4];
	} __in6_union;
};


struct timestamp {
	uint8_t len;
	uint8_t ptr;
#if __BYTEORDER == __LITTLE_ENDIAN
	unsigned int flags:4;
	unsigned int overflow:4;
#else
	unsigned int overflow:4;
	unsigned int flags:4;
#endif
	uint32_t data[9];
};

struct iphdr {
#if __BYTEORDER == __LITTLE_ENDIAN
	unsigned int ihl:4;
	unsigned int version:4;
#else
	unsigned int version:4;
	unsigned int ihl:4;
#endif
	uint8_t tos;
	uint16_t tot_len;
	uint16_t id;
	uint16_t frag_off;
	uint8_t ttl;
	uint8_t protocol;
	uint16_t check;
	uint32_t saddr;
	uint32_t daddr;
};

struct ethhdr {
	uint8_t h_dest[ETH_ALEN];
	uint8_t h_source[ETH_ALEN];
	uint16_t h_proto;
};



struct ip {
#if __BYTEORDER == __LITTLE_ENDIAN
	unsigned int ip_hl:4;
	unsigned int ip_v:4;
#else
	unsigned int ip_v:4;
	unsigned int ip_hl:4;
#endif
	uint8_t ip_tos;
	uint16_t ip_len;
	uint16_t ip_id;
	uint16_t ip_off;
	uint8_t ip_ttl;
	uint8_t ip_p;
	uint16_t ip_sum;
	struct in_addr ip_src, ip_dst;
};

#define  IP_RF 0x8000
#define  IP_DF 0x4000
#define  IP_MF 0x2000
#define  IP_OFFMASK 0x1fff

struct ip_timestamp {
	uint8_t ipt_code;
	uint8_t ipt_len;
	uint8_t ipt_ptr;
#if __BYTEORDER == __LITTLE_ENDIAN
	unsigned int ipt_flg:4;
	unsigned int ipt_oflw:4;
#else
	unsigned int ipt_oflw:4;
	unsigned int ipt_flg:4;
#endif
	uint32_t data[9];
};

#define  IPVERSION   4
#define  IP_MAXPACKET   65535


struct sockaddr_in {
	unsigned short sin_family;
	uint16_t sin_port;
	struct in_addr sin_addr;
	uint8_t sin_zero[8];
};

struct addrinfo {
	int ai_flags;
	int ai_family;
	int ai_socktype;
	int ai_protocol;
	socklen_t ai_addrlen;
	struct sockaddr *ai_addr;
	char *ai_canonname;
	struct addrinfo *ai_next;
};

struct ifmap {
	unsigned long mem_start;
	unsigned long mem_end;
	uint16_t base_addr;
	unsigned char irq;
	unsigned char dma;
	unsigned char port;
};

struct sockaddr_storage {
	sa_family_t  ss_family;
	uint32_t  __ss_align;
	char __ss_padding[(128  - (2 * sizeof (uint32_t ))) ];
};


#define  ETHERTYPE_PUP     0x0200
#define ETHERTYPE_SPRITE   0x0500
#define  ETHERTYPE_IP      0x0800
#define  ETHERTYPE_ARP     0x0806
#define  ETHERTYPE_REVARP  0x8035
#define ETHERTYPE_AT    0x809B
#define ETHERTYPE_AARP     0x80F3
#define  ETHERTYPE_VLAN    0x8100
#define ETHERTYPE_IPX      0x8137
#define  ETHERTYPE_IPV6    0x86dd
#define ETHERTYPE_LOOPBACK 0x9000


#define  ETHER_TYPE_LEN 2
#define  ETHER_CRC_LEN  4
#define  ETHER_HDR_LEN  ETH_HLEN
#define  ETHER_MIN_LEN  (ETH_ZLEN + ETHER_CRC_LEN)
#define  ETHER_MAX_LEN  (ETH_FRAME_LEN + ETHER_CRC_LEN)

#define  ETHER_IS_VALID_LEN(foo) \
	   ((foo) >= ETHER_MIN_LEN && (foo) <= ETHER_MAX_LEN)

#define  ETHERTYPE_TRAIL      0x1000
#define  ETHERTYPE_NTRAILER   16

#define  ETHERMTU ETH_DATA_LEN
#define  ETHERMIN (ETHER_MIN_LEN - ETHER_HDR_LEN - ETHER_CRC_LEN)



struct ether_addr {
	uint8_t ether_addr_octet[ETH_ALEN];
};

struct ether_header {
	uint8_t  ether_dhost[ETH_ALEN];
	uint8_t  ether_shost[ETH_ALEN];
	uint16_t ether_type;
};


struct ifreq {
	union
	{
		char ifrn_name[IF_NAMESIZE];    /* if name */
	} ifr_ifrn;
	union {
		struct sockaddr ifru_addr;
		struct sockaddr ifru_dstaddr;
		struct sockaddr ifru_broadaddr;
		struct sockaddr ifru_netmask;
		struct  sockaddr ifru_hwaddr;
		int16_t ifru_flags;
		int32_t ifru_ivalue;
		int32_t ifru_mtu;
		struct ifmap ifru_map;
		char ifru_slave[IF_NAMESIZE];  
		char ifru_newname[IF_NAMESIZE];
		char* ifru_data;
	} ifr_ifru;
};

// net - packet

struct sockaddr_ll {
	unsigned short sll_family, sll_protocol;
	int sll_ifindex;
	unsigned short sll_hatype;
	unsigned char sll_pkttype, sll_halen;
	unsigned char sll_addr[8];
};

struct packet_mreq {
	int mr_ifindex;
	unsigned short int mr_type,  mr_alen;
	unsigned char mr_address[8];
};

#define PACKET_HOST     	0
#define PACKET_BROADCAST   1
#define PACKET_MULTICAST   2
#define PACKET_OTHERHOST   3
#define PACKET_OUTGOING    4
#define PACKET_LOOPBACK    5
#define PACKET_FASTROUTE   6

#define PACKET_ADD_MEMBERSHIP    1
#define PACKET_DROP_MEMBERSHIP   2
#define  PACKET_RECV_OUTPUT      3
#define  PACKET_RX_RING       5
#define  PACKET_STATISTICS    6
#define PACKET_COPY_THRESH    7
#define PACKET_AUXDATA        8
#define PACKET_ORIGDEV        9
#define PACKET_VERSION        10
#define PACKET_HDRLEN         11
#define PACKET_RESERVE        12
#define PACKET_TX_RING        13
#define PACKET_LOSS           14
#define PACKET_VNET_HDR       15
#define PACKET_TX_TIMESTAMP   16
#define PACKET_TIMESTAMP      17
#define PACKET_FANOUT         18
#define PACKET_TX_HAS_OFF     19
#define PACKET_QDISC_BYPASS   20
#define PACKET_ROLLOVER_STATS 21
#define PACKET_FANOUT_DATA    22

#define PACKET_MR_MULTICAST   0
#define PACKET_MR_PROMISC     1
#define PACKET_MR_ALLMULTI    2
#define PACKET_MR_UNICAST     3


// net -route


struct rtentry {
	unsigned long int rt_pad1;
	struct sockaddr rt_dst;
	struct sockaddr rt_gateway;
	struct sockaddr rt_genmask;
	unsigned short int rt_flags;
	short int rt_pad2;
	unsigned long int rt_pad3;
	unsigned char rt_tos;
	unsigned char rt_class;
	short int rt_pad4[sizeof(long)/2-1];
	short int rt_metric;
	char *rt_dev;
	unsigned long int rt_mtu;
	unsigned long int rt_window;
	unsigned short int rt_irtt;
};

#define rt_mss rt_mtu


struct in6_rtmsg {
	struct in6_addr rtmsg_dst;
	struct in6_addr rtmsg_src;
	struct in6_addr rtmsg_gateway;
	uint32_t rtmsg_type;
	uint16_t rtmsg_dst_len;
	uint16_t rtmsg_src_len;
	uint32_t rtmsg_metric;
	unsigned long int rtmsg_info;
	uint32_t rtmsg_flags;
	int rtmsg_ifindex;
};




#define	RTF_UP		0x0001
#define	RTF_GATEWAY	0x0002

#define	RTF_HOST	0x0004
#define RTF_REINSTATE	0x0008
#define	RTF_DYNAMIC	0x0010
#define	RTF_MODIFIED	0x0020
#define RTF_MTU		0x0040
#define RTF_MSS		RTF_MTU
#define RTF_WINDOW	0x0080
#define RTF_IRTT	0x0100
#define RTF_REJECT	0x0200
#define	RTF_STATIC	0x0400
#define	RTF_XRESOLVE	0x0800
#define RTF_NOFORWARD   0x1000
#define RTF_THROW	0x2000
#define RTF_NOPMTUDISC  0x4000

#define RTF_DEFAULT	0x00010000
#define RTF_ALLONLINK	0x00020000
#define RTF_ADDRCONF	0x00040000

#define RTF_LINKRT	0x00100000
#define RTF_NONEXTHOP	0x00200000

#define RTF_CACHE	0x01000000
#define RTF_FLOW	0x02000000
#define RTF_POLICY	0x04000000

#define RTCF_VALVE	0x00200000
#define RTCF_MASQ	0x00400000
#define RTCF_NAT	0x00800000
#define RTCF_DOREDIRECT 0x01000000
#define RTCF_LOG	0x02000000
#define RTCF_DIRECTSRC	0x04000000

#define RTF_LOCAL	0x80000000
#define RTF_INTERFACE	0x40000000
#define RTF_MULTICAST	0x20000000
#define RTF_BROADCAST	0x10000000
#define RTF_NAT		0x08000000

#define RTF_ADDRCLASSMASK	0xF8000000
#define RT_ADDRCLASS(flags)	((uint32_t) flags >> 23)

#define RT_TOS(tos)		((tos) & IPTOS_TOS_MASK)

#define RT_LOCALADDR(flags)	((flags & RTF_ADDRCLASSMASK) \
				 == (RTF_LOCAL|RTF_INTERFACE))

#define RT_CLASS_UNSPEC		0
#define RT_CLASS_DEFAULT	253

#define RT_CLASS_MAIN		254
#define RT_CLASS_LOCAL		255
#define RT_CLASS_MAX		255


#define RTMSG_ACK		NLMSG_ACK
#define RTMSG_OVERRUN		NLMSG_OVERRUN

#define RTMSG_NEWDEVICE		0x11
#define RTMSG_DELDEVICE		0x12
#define RTMSG_NEWROUTE		0x21
#define RTMSG_DELROUTE		0x22
#define RTMSG_NEWRULE		0x31
#define RTMSG_DELRULE		0x32
#define RTMSG_CONTROL		0x40

#define RTMSG_AR_FAILED		0x51

#endif
