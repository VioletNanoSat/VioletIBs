/* - - - - - - - - - - - - - - -                   *
 *                    cucp_def.h                   *
 *  This file contains global header information   *
 *  that shall be included on ALL microcontrollers *
 *  and ALL flight code operations.                *
 *  Before including this file, NET_ADDR should be *
 *  defined according to PROCESSOR ADDRESSES.      *
 *                   - - - - - - - - - - - - - - - */

#ifndef _CUCP_DEF_H
#define _CUCP_DEF_H


/* Error checking. */
#ifndef NET_ADDR
#error "Define NET_ADDR before including this file - if you are on a normal computer (or the Viper), it should be NETWORK_ADDRESS_VIPER."
#else

#define HIGH 0
#define LOW 1


#define NETWORK_ADDRESS_CDHIB		0x00    /* this is the CDH interface board */
#define NETWORK_ADDRESS_CAMERA		0x01    /* this is the CAM interface board */
#define NETWORK_ADDRESS_GPS1	        0x02    /* this is GPS IB1 */
#define NETWORK_ADDRESS_GPS2	        0x03    /* this is GPS IB2 */
#define NETWORK_ADDRESS_GPS3	        0x04    /* this is GPS IB3 */
#define NETWORK_ADDRESS_POWER		0x05    /* this is the power board */
#define NETWORK_ADDRESS_PROPULSION	0x06    /* this is the PPU control board */
#define NETWORK_ADDRESS_TC1		0x07    /* this is the first T&C board, U1 */
#define NETWORK_ADDRESS_TC2		0x08    /* this is the second T&C board, U2 */
#define NETWORK_ADDRESS_VIPER           0x09    /* Use for 32-bit processors. */
#define NETWORK_ADDRESS_DUMMY2		0x0A	/*for MATLAB ground testing DO NOT USE IN FLIGHT EXECUTABLES! */
#define NETWORK_ADDRESS_MATLAB		0x0B	/*for MATLAB ground testing DO NOT USE IN FLIGHT EXECUTABLES! */
#define NETWORK_ADDRESS_DUMMY		0xFF    /* this is the dummy address */


#define CRC_ACK             0xFF
#define CRC_NACK            0x00

/* #define data types for Viper board */
#if NET_ADDR == NETWORK_ADDRESS_VIPER
    typedef signed char		BYTE32;   /* 1 byte */
    typedef unsigned char	UBYTE32;  /* 1 */
    typedef signed short	SHORT32;  /* 2 */
    typedef unsigned short	USHORT32; /* 2 */
    typedef signed int		INT32;    /* 4 */
    typedef unsigned int	UINT32;   /* 4 */
    typedef signed int		LONG32;   /* 4 */
    typedef unsigned int	ULONG32;  /* 4 */
    typedef float		FLOAT32;  /* 4 */
    typedef double		DOUBLE32; /* 8 */
/* #define data types for Slave MCUs */
#else
    typedef signed char		BYTE32;   /* 1 byte */
    typedef unsigned char	UBYTE32;  /* 1 */
    typedef signed int		SHORT32;  /* 2 */
    typedef unsigned int	USHORT32; /* 2 */
    typedef signed long		INT32;    /* 4 */
    typedef unsigned long	UINT32;   /* 4 */
    typedef signed long		LONG32;   /* 4 */
    typedef unsigned long	ULONG32;  /* 4 */
    typedef double		FLOAT32;  /* 4 */
    typedef struct {
        double v[2];
    }				DOUBLE32; /* 8 */
#endif
// TODO Add an error for whatever status codes fault checks with magic numbers
#if NET_ADDR == NETWORK_ADDRESS_CDHIB
	#define STAT_OK           0b00000000
	#define STAT_General      0b00000001
#elif NET_ADDR == NETWORK_ADDRESS_CAMERA
	#define STAT_OK           0b00000000
	#define STAT_Camera       0b00000001
	#define STAT_BadID        0b00000010
	#define STAT_BadMode      0b00000100
	#define STAT_General      0b00001000
#elif NET_ADDR == NETWORK_ADDRESS_GPS1
	#define STAT_OK           0b00000000
	#define STAT_Down         0b00000001
	#define STAT_PGOOD        0b00000010
	#define STAT_General      0b00000100
#elif NET_ADDR == NETWORK_ADDRESS_GPS2
	#define STAT_OK           0b00000000
	#define STAT_Down         0b00000001
	#define STAT_PGOOD        0b00000010
	#define STAT_General      0b00000100
#elif NET_ADDR == NETWORK_ADDRESS_GPS3
	#define STAT_OK           0b00000000
	#define STAT_Down         0b00000001
	#define STAT_PGOOD        0b00000010
	#define STAT_General      0b00000100
#elif NET_ADDR == NETWORK_ADDRESS_POWER
	#define STAT_OK           0b00000000
	#define STAT_BatteryFault 0b00000001
	#define STAT_Lightband    0b00000010
	#define STAT_TCAPEvent    0b00000100
	#define	STAT_LowBattery   0b00001000
	#define STAT_EmShut	      0b00010000
	#define STAT_FullBattery  0b00100000
	#define STAT_WatchdogRst  0b01000000
	#define STAT_General      0b10000000
#elif NET_ADDR == NETWORK_ADDRESS_PROPULSION
	#define STAT_OK           0b00000000
	#define STAT_Needs_Warmup 0b00000001
	#define STAT_Warming_Up   0b00000010
	#define STAT_Invalid_Cmd  0b00000100
	#define STAT_General      0b00001000
#elif NET_ADDR == NETWORK_ADDRESS_TC1
	#define STAT_OK           0b00000000
	#define STAT_RadioFailure 0b00000001
	#define STAT_TCAPError    0b00000010
	#define STAT_BuffNotReady 0b00000100
	#define STAT_RadioNotReady 0b00001000
	#define STAT_WatchdogRst  0b00010000
	#define STAT_General      0b00100000
	#define STAT_TX_DIS       0b01000000
#if STAT_TX_DIS != 0b01000000
#error don't change this status code, please
#endif
#elif NET_ADDR == NETWORK_ADDRESS_TC2
	#define STAT_OK           0b00000000
	#define STAT_RadioFailure 0b00000001
	#define STAT_TCAPError    0b00000010
	#define STAT_BuffNotReady 0b00000100
	#define STAT_RadioNotReady 0b00001000
	#define STAT_WatchdogRst  0b00010000
	#define STAT_General      0b00100000
	#define STAT_TX_DIS       0b01000000
#if STAT_TX_DIS != 0b01000000
#error don't change this status code, please
#endif
#endif


// Global commands
#define NET_CMD_PING        0x01
#define NET_CMD_GET_STATUS  0x02
#define NET_CMD_SILENCE     0x03
#define NET_CMD_REPROGRAM   0x04    /* reprogram MCU */
#define NET_CMD_SET_TIME    0x05
#define NET_CMD_VERSION     0x06

// CDH-IB commands
#define NET_CMD_CDHIB_IMI			0x11
#define NET_CMD_CDHIB_GET_TELEM                 0x12
#define NET_CMD_CDHIB_ENABLE_VIPER_TX           0x13
#define NET_CMD_CDHIB_DISABLE_VIPER_TX          0x14

// CAM commands
#define NET_CMD_CAM_PICTURE_1  0x21
#define NET_CMD_CAM_PICTURE_2  0x22
#define NET_CMD_CAM_SEND_NEXT  0x23
#define NET_CMD_CAM_GET_TELEM  0x24
#define NET_CMD_GET_CAM_ID     0x25
#define NET_CMD_CAM_CONTROL    0x26
#define NET_CMD_CAM_SWITCH_CAM 0x27
#define NET_CMD_CAM_PICTURE    0x28
#define NET_CMD_CAM_SEND_CHUNK 0x29
#define NET_CMD_CAM_LOAD_NEXT  0x2A
#define NET_CMD_CAM_MODE_0     0x2D
#define NET_CMD_CAM_GET_MODE   0x2E
#define NET_CMD_CAM_MODE_1     0x2F

// GPS commands
#define NET_CMD_GPS_GET_TIME    0x31
#define NET_CMD_GPS_GET_DATA    0x32
#define NET_CMD_GPS_GET_TELEM   0x33
#define NET_CMD_GPS_SPEC_CMD    0x34

// Prop commands
#define NET_CMD_PROP_GET_ALL        0x41 // Get all telemetry from ADC (returns RESP_
#define NET_CMD_PROP_FIRE_PPT       0x42 // Fire one set of PPTs
#define NET_CMD_PROP_SEQUENCE		0x43 // Arbitrary firing sequence
#define NET_CMD_PROP_FIRE_IMM		0x44 // Hit the fire button IMMEDIATELY
#define NET_CMD_WARMUP				0x45 // Warm up the power board and the capacitors

// Power commands
#define NET_CMD_PWR_GET_ALL     0x51
#define NET_CMD_PWR_CYCLE       0x52
#define NET_CMD_PWR_POWER_DOWN  0x53
#define NET_CMD_PWR_POWER_UP    0x54
#define NET_CMD_PWR_CLEAR_STATUS 0x55
#define NET_CMD_PWR_WATCHDOG    0x5A
#define NET_CMD_PWR_DEBUG		0x5B

// T&C commands
#define NET_CMD_TC_UPDATE_THS		0x61
#define NET_CMD_TC_SEND_THS			0x62
#define NET_CMD_TC_SEND_PACKET		0x63
#define NET_CMD_TC_GET_PACKET		0x64
#define NET_CMD_TC_CHANGE_FREQ		0x65
#define NET_CMD_TC_CHANGE_CALLSIGN 	0x66
#define NET_CMD_TC_RADIO_ON			0x67
#define NET_CMD_TC_RADIO_OFF		0x68
#define NET_CMD_TC_POWER_LEVEL		0x69
#define NET_CMD_TC_BEACON_INTERVAL	0x6A
#define NET_CMD_TC_GET_TELEM        0x6B
#define NET_CMD_TC_SQUELCH_LEVEL	0x6C
#define NET_CMD_TC_TCAP_TEST		0x6D
#define NET_CMD_TC_TX_EN			0x6E
#define NET_CMD_TC_TX_DIS			0x6F

// Ground commands
#define NET_CMD_GSL_SEPARATE             0x71
#define NET_CMD_GSL_SET_STATE            0x72
#define NET_CMD_GSL_DIS_STATE_SWITCH	 0x73
#define NET_CMD_GSL_ENABLE_STATE_SWITCH  0x74
#define NET_CMD_GSL_SET_MASTER           0x75
#define NET_CMD_GSL_SET_CONSTANTS        0x76

// PRESSLink commands
#define NET_CMD_PRESS_SEND_GPS        0x81
#define NET_CMD_PRESS_GET_SOLAR_DATA  0x82
#define NET_CMD_PRESS_SEND_SOLAR_DATA 0x83
#define NET_CMD_PRESS_SHUT_DOWN       0x84

/* limited data typedefs */
typedef BYTE32 STATE;
typedef BYTE32* LOGBUFFER; /* pointer to the log so that it can be variable length */
typedef BYTE32* PLD_CMD_RESP_PLD;
typedef BYTE32* GPS_PLD; /* Payload for special GPS Commands */
typedef BYTE32 GSL_MASTER; /* 0 for set recipient to slave, other sat to master, 1 for set recipient to master, other sat to slave */
typedef BYTE32 RESP_TC_STAT_CHANGE; /* 1 if to switch master/slave, 0 else */



#endif /* end NET_ADDR defined */
#endif /* end not header file not already defined */
