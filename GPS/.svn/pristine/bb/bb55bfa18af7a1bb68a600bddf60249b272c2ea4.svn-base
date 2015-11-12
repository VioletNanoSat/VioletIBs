#ifndef gps_h
#define gps_h

// gpsi frame defines
#define GPSI_START	0x02
#define GPSI_END	0x03

// gpsi state defines
#define GPSI_UNKNOWN 0x04
#define GPSI_PRELIM1 0x08
#define GPSI_PRELIM2 0x0C
#define GPSI_PRELIM3 0x10
#define GPSI_ID1	 0x14
#define GPSI_ID2	 0x18
#define GPSI_ID3	 0x1C
#define GPSI_S1		 0x20
#define GPSI_S2		 0x24
#define GPSI_S3		 0x28
#define GPSI_S4		 0x2C
#define GPSI_S5		 0x30
#define GPSI_CHKS1A	 0x34
#define GPSI_CHKS1B	 0x38
#define GPSI_CHKS2A	 0x3C
#define GPSI_CHKS2B	 0x40
#define GPSI_CHKS3A	 0x44
#define GPSI_CHKS3B	 0x48
#define GPSI_CHKS4A	 0x4C
#define GPSI_CHKS4B	 0x50
#define GPSI_CHKS5A	 0x54
#define GPSI_CHKS5B	 0x58
#define GPSI_DONE	 0x5C

// gpsi error defines
#define GPSI_ERR_DEAD	0x01
#define GPSI_ERR_PGOOD	0x02
#define GPSI_ERR_GEN	0x04
#define GPSI_ERR_1		0x08
#define GPSI_ERR_2		0x10
#define GPSI_ERR_3		0x20
#define GPSI_ERR_4		0x40
#define GSPI_ERR_5		0x80

// gpsi packet order defines
#define GPSI_ORDER_F00 0x00
#define GPSI_ORDER_F03 0x03
#define GPSI_ORDER_F18 0x18
#define GPSI_ORDER_F22 0x22
#define GPSI_ORDER_F23 0x23
#define GPSI_ORDER_NON 0xFF

typedef struct
{
	sint8	data[4];
	sint16	index;
} __attribute__ ((__packed__)) ma4;

#endif
