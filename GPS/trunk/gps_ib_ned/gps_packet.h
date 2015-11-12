#include "common.h"

#ifndef gps_packet_h
#define gps_packet_h

/*
 * gps_timestamp
 *
 * Used to interpret a gps timestamp packet
 */
typedef struct
{
	sint32 day;
	sint32 month;
	sint32 year;
	sint32 hour;
	sint32 minute;
	sint32 second;
	sint32 hundred_microsecond;
	uint8  reserved[4];
} __attribute__((__packed__)) gps_timestamp;

/*
 * gps_f00 72 Bytes
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	float64	second;
	float32	ecef_pos_x;
	float32	ecef_pos_y;
	float32	ecef_pos_z;
	float32	ecef_vel_x;
	float32	ecef_vel_y;
	float32	ecef_vel_z;
	float32	gdop;
	float32	pdop;
	float32	vdop;
	float32	dopp_from_clk;
	float32	GPS_sec;
	sint32	GPS_week;
	sint16	year;
	sint16	DeSecond;
	sint8	navmode;
	sint8	numsats;
	sint8	tracktype;
	sint8	day;
	sint8	month;
	sint8	hour;
	sint8	minute;
	sint8	Second2;
	sint8	time_type;
	sint8	system_status;
	uint8	reserved[2];
} __attribute__((__packed__)) gps_f00;

/*
 * gps_f03 264 Bytes
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	sint32	CdLI[12];
	sint32	dopp[12];
	sint16	azi[12];
	uint8	cnr[12];
	sint8	dispsy[12];
	sint8	elv[12];
	sint8	statflag[12];
	sint8	codeelk[12];
	sint8	carrlk[12];
	sint8	bitlk[12];
	sint8	framelk[12];
	uint8	reserved[48];
} __attribute__((__packed__)) gps_f03;

/*
 * gps_f18 192 Bytes
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	float64	range[12];
	float64	phase[12];
} __attribute__((__packed__)) gps_f18;

/*
 * gps_f22 115
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	uint32	almsqrta;
	sint32	ratoa;
	sint32	argpg;
	sint32	manom;
	uint32	ephecc;
	uint32	ephsqrta;
	sint32	m0;
	sint32	om0;
	sint32	in0;
	sint32	olc;
	sint32	omd;
	sint32	idot;
	sint32	ephaf0;
	uint16	almhlth;
	uint16	refweek;
	uint16	toa;
	uint16	almecc;
	sint16	inclin;
	sint16	rora;
	sint16	almaf0;
	sint16	almaf1;
	uint16	s1hlth;
	uint16	codeL2;
	uint16	wkn;
	uint16	L2Pdata;
	uint16	ura;
	uint16	iodc;
	uint16	tocwk;
	uint16	iode;
	uint16	toewk;
	uint16	fti;
	uint16	toe;
	uint16	toc;
	sint16	cuc;
	sint16	cus;
	sint16	cic;
	sint16	cis;
	sint16	crc;
	sint16	crs;
	sint16	ephafl;
	sint16	af2;
	sint16	tgd;
	sint16	deltan;
	sint8	satID;
	uint8	almvflg;
	uint8	ephvflg;
	uint8	reserved[5];
} __attribute__((__packed__)) gps_f22;

/*
 * gps_f23 97
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	float64	a[4];
	float64	b[4];
	float64	A[2];
	uint32	tot;
	sint16	dtls;
	sint16	dn;
	sint16	dtlsf;
	uint16	wnt;
	uint16	wnlsf;
	sint8	ionvflg;
	uint8	reserved;
} __attribute__((__packed__)) gps_f23;

/*
 * gps_f24
 *
 * Used to parse the data of a gps_packet
 */
typedef struct
{
	float64 refweek;
	float64 toa;
	float64 ecc;
	float64 inclin;
	float64 rora;
	float64 af0;
	float64 af1;
	float64 sqrta;
	float64 ratoa;
	float64 argpg;
	float64 manom;
	float64 ok;
} __attribute__((__packed__)) gps_f24;

/*
 * gps_telem
 *
 * The purpose of this structure is to
 * interpret gps hardware telemetry.
 */
typedef struct
{
	sint8 voltage3;
	sint8 voltage5;
	sint8 current;
	sint8 gps_temp;
	sint8 radio_temp;
	sint8 last_command;
	sint8 command_success;
	sint8 last_satellite;
} __attribute__((__packed__)) gps_telem;

/*
 * gps_packet
 *
 * This is the overall packet for the GPS
 * all of the gps_f** structures are defined
 * to parse the data field
 */
typedef struct
{
	sint8		sentence[2];
	uint8ptr	data;
} __attribute__((__packed__)) gps_packet;

#endif
