#ifndef cucp_def_data_h_
#define cucp_def_data_h_

#include <string.h>

inline int sizeOfBYTE32(){ return 1; }
inline int sizeOfUBYTE32(){ return 1; }
inline int sizeOfSHORT32(){ return 2; }
inline int sizeOfUSHORT32(){ return 2; }
inline int sizeOfINT32(){ return 4; }
inline int sizeOfUINT32(){ return 4; }
inline int sizeOfLONG32(){ return 4; }
inline int sizeOfULONG32(){ return 4; }
inline int sizeOfFLOAT32(){ return 4; }
inline int sizeOfDOUBLE32(){ return 8; }

#define BYTE32_SIZE		1
#define UBYTE32_SIZE	1
#define SHORT32_SIZE	2
#define USHORT32_SIZE	2
#define INT32_SIZE		4
#define UINT32_SIZE		4
#define LONG32_SIZE		4
#define ULONG32_SIZE	4
#define FLOAT32_SIZE	4
#define DOUBLE32_SIZE	8


#define NUM_SATELLITES 2

#define IMI_BYTES 23

#define NUM_PPT 4

#define NUM_PPTD 8

#define NUM_FIRINGS 30

#define NUM_GPS 3

#define GPS_BUFFER_SIZE 9

#define NUM_PANELS 8

#define MAX_CHANNELS 12

#define MAX_SATS 32

#define NUM_SUBSYSTEMS 9

#define IMG_CHUNK_SIZE 1024

#define TC_PACKET_SIZE 300

#define TC_POWER_LEVEL_HIGH 0

#define TC_POWER_LEVEL_LOW 2

#define TC_POWER_LEVEL_EL 3

#define CALL_LENGTH 7

#define VERSION_SIZE 14

#define MOMS_THS_BYTEPACK 8

#define NETWORK_ADDRESS_NUM_SUBSYSTEMS 12

#define KDU_ARGS_LENGTH 60

#define NUMBER_OF_MODES 10

#define PRESEP_SAFE_MODE 1

#define POSTSEP_SAFE_MODE 2

#define PRESEP_MODE 3

#define PRESEP_NO_CTRL_MODE 4

#define POSTSEP_XLINK_MODE 5

#define POSTSEP_CTRL_MODE 6

#define END_OF_LIFE 7

#define SURVIVAL_MODE 8

#define SEPARATION_MODE 9

#define GROUND_TEST_MODE 10

#define NO_CMD_MODE 0

#define RESET_TO_FACTORY 0xFF

#define NO_OP_COMMAND 0

#define ENABLE_ALLOW_COMMAND 1

#define DISABLE_DISALLOW_COMMAND 2

#define POWER_CYCLE_COMMAND 3

#define DISABLE_COMMAND 4

#define FAULT_NO_ACTION 0

#define FAULT_POWER_CYCLE_HW 1

#define FAULT_TURN_OFF_HW 2

#define FAULT_PREV_TURNED_OFF_HW 3

#define FAULT_TURN_ON_HW 4

#define FAULT_PREV_TURNED_ON_HW 5

#define PWR_GPS1 0xA0

#define PWR_GPS2 0xA1

#define PWR_GPS3 0xA2

#define PWR_TC 0xA3

#define PWR_CDH 0xA4

#define PWR_CAMIBFPGA 0xA5

#define PWR_HEAT1 0xA6

#define PWR_CAM1 0xA7

#define PWR_LIGHTB 0xB2

#define PWR_CAM2 0xB3

#define PWR_IMI 0xB4

#define PWR_HEAT2 0xB5

#define PWR_PPU 0xB6

#define PWR_HEATBB 0xB7

#define PPT_NOZZLE_S1A 0x01

#define PPT_NOZZLE_S1B 0x02

#define PPT_NOZZLE_S2A 0x04

#define PPT_NOZZLE_S2B 0x08

#define PPT_NOZZLE_S3A 0x10

#define PPT_NOZZLE_S3B 0x20

#define PPT_NOZZLE_S4A 0x40

#define PPT_NOZZLE_S4B 0x80

#define RESP_VERSION_SIZE 14

#define TRUE_CUCP 1

#define FALSE_CUCP 0

#define DEFAULT_POLARITY 1

#define REVERSE_POLARITY -1

/* LAST_VALID_GPS declaration GPS */
typedef struct {
	DOUBLE32 data[4];
} LAST_VALID_GPS;

#define LAST_VALID_GPS_SIZE 32
inline int sizeOfLAST_VALID_GPS() {return 32;}

/* julian representation of day and time */
inline DOUBLE32* get_LAST_VALID_GPS_mjulianDate(LAST_VALID_GPS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_LAST_VALID_GPS_mjulianDate(LAST_VALID_GPS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define LAST_VALID_GPS_mjulianDate(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* eci position */
inline FLOAT32* get_LAST_VALID_GPS_eci_pos(LAST_VALID_GPS* var) {return ((FLOAT32*)((char*)var->data+8));}
inline void set_LAST_VALID_GPS_eci_pos(LAST_VALID_GPS* var, FLOAT32* val) { memcpy(((char*)var->data+8),val,12); }
inline void set_LAST_VALID_GPS_eci_pos_ar(LAST_VALID_GPS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+8))+index),val,FLOAT32_SIZE); }
#define LAST_VALID_GPS_eci_pos(var,index) (*((FLOAT32 *)(((char *)(&(var)))+8)+index))

/* eci velocity */
inline FLOAT32* get_LAST_VALID_GPS_eci_vel(LAST_VALID_GPS* var) {return ((FLOAT32*)((char*)var->data+20));}
inline void set_LAST_VALID_GPS_eci_vel(LAST_VALID_GPS* var, FLOAT32* val) { memcpy(((char*)var->data+20),val,12); }
inline void set_LAST_VALID_GPS_eci_vel_ar(LAST_VALID_GPS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+20))+index),val,FLOAT32_SIZE); }
#define LAST_VALID_GPS_eci_vel(var,index) (*((FLOAT32 *)(((char *)(&(var)))+20)+index))

/* sentenceF00 declaration GPS F00 */
typedef struct {
	DOUBLE32 data[9];
} sentenceF00;

#define SENTENCEF00_SIZE 72
inline int sizeOfsentenceF00() {return 72;}

/* UTC second */
inline DOUBLE32* get_sentenceF00_second(sentenceF00* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_sentenceF00_second(sentenceF00* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF00_second(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* x ecef position */
inline FLOAT32* get_sentenceF00_ecef_pos_x(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+8),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_pos_x(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+8),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_pos_x(var) (*((FLOAT32 *)(((char *)(&(var)))+8)))

/* y ecef position */
inline FLOAT32* get_sentenceF00_ecef_pos_y(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+12),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_pos_y(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+12),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_pos_y(var) (*((FLOAT32 *)(((char *)(&(var)))+12)))

/* z ecef position */
inline FLOAT32* get_sentenceF00_ecef_pos_z(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+16),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_pos_z(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+16),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_pos_z(var) (*((FLOAT32 *)(((char *)(&(var)))+16)))

/* x ecef velocity */
inline FLOAT32* get_sentenceF00_ecef_vel_x(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+20),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_vel_x(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+20),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_vel_x(var) (*((FLOAT32 *)(((char *)(&(var)))+20)))

/* y ecef velocity */
inline FLOAT32* get_sentenceF00_ecef_vel_y(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+24),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_vel_y(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+24),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_vel_y(var) (*((FLOAT32 *)(((char *)(&(var)))+24)))

/* z ecef velocity */
inline FLOAT32* get_sentenceF00_ecef_vel_z(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+28),FLOAT32_SIZE); }
inline void set_sentenceF00_ecef_vel_z(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+28),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_ecef_vel_z(var) (*((FLOAT32 *)(((char *)(&(var)))+28)))

/* Geometric DOP */
inline FLOAT32* get_sentenceF00_gdop(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+32),FLOAT32_SIZE); }
inline void set_sentenceF00_gdop(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+32),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_gdop(var) (*((FLOAT32 *)(((char *)(&(var)))+32)))

/* Postional DOP */
inline FLOAT32* get_sentenceF00_pdop(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+36),FLOAT32_SIZE); }
inline void set_sentenceF00_pdop(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+36),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_pdop(var) (*((FLOAT32 *)(((char *)(&(var)))+36)))

/* Vertical DOP */
inline FLOAT32* get_sentenceF00_vdop(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+40),FLOAT32_SIZE); }
inline void set_sentenceF00_vdop(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+40),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_vdop(var) (*((FLOAT32 *)(((char *)(&(var)))+40)))

/* L1 doppler shift due to clock, Hz */
inline FLOAT32* get_sentenceF00_dopp_from_clk(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+44),FLOAT32_SIZE); }
inline void set_sentenceF00_dopp_from_clk(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+44),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_dopp_from_clk(var) (*((FLOAT32 *)(((char *)(&(var)))+44)))

/* GPS second */
inline FLOAT32* get_sentenceF00_GPS_sec(sentenceF00* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+48),FLOAT32_SIZE); }
inline void set_sentenceF00_GPS_sec(sentenceF00* var, FLOAT32 val) { memcpy(((char*)var->data+48),(void*)&val,FLOAT32_SIZE); return; }
#define sentenceF00_GPS_sec(var) (*((FLOAT32 *)(((char *)(&(var)))+48)))

/* GPS week */
inline INT32* get_sentenceF00_GPS_week(sentenceF00* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+52),INT32_SIZE); }
inline void set_sentenceF00_GPS_week(sentenceF00* var, INT32 val) { memcpy(((char*)var->data+52),(void*)&val,INT32_SIZE); return; }
#define sentenceF00_GPS_week(var) (*((INT32 *)(((char *)(&(var)))+52)))

/* UTC year */
inline SHORT32* get_sentenceF00_year(sentenceF00* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+56),SHORT32_SIZE); }
inline void set_sentenceF00_year(sentenceF00* var, SHORT32 val) { memcpy(((char*)var->data+56),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF00_year(var) (*((SHORT32 *)(((char *)(&(var)))+56)))

/* decimal part of second (milliseconds) */
inline SHORT32* get_sentenceF00_DeSecond(sentenceF00* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+58),SHORT32_SIZE); }
inline void set_sentenceF00_DeSecond(sentenceF00* var, SHORT32 val) { memcpy(((char*)var->data+58),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF00_DeSecond(var) (*((SHORT32 *)(((char *)(&(var)))+58)))

/* navigation mode */
inline BYTE32* get_sentenceF00_navmode(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+60),BYTE32_SIZE); }
inline void set_sentenceF00_navmode(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+60),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_navmode(var) (*((BYTE32 *)(((char *)(&(var)))+60)))

/* number of satellites */
inline BYTE32* get_sentenceF00_numsats(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+61),BYTE32_SIZE); }
inline void set_sentenceF00_numsats(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+61),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_numsats(var) (*((BYTE32 *)(((char *)(&(var)))+61)))

/* track type */
inline BYTE32* get_sentenceF00_tracktype(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+62),BYTE32_SIZE); }
inline void set_sentenceF00_tracktype(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+62),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_tracktype(var) (*((BYTE32 *)(((char *)(&(var)))+62)))

/* UTC day */
inline BYTE32* get_sentenceF00_day(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+63),BYTE32_SIZE); }
inline void set_sentenceF00_day(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+63),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_day(var) (*((BYTE32 *)(((char *)(&(var)))+63)))

/* UTC month */
inline BYTE32* get_sentenceF00_month(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+64),BYTE32_SIZE); }
inline void set_sentenceF00_month(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+64),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_month(var) (*((BYTE32 *)(((char *)(&(var)))+64)))

/* UTC hour */
inline BYTE32* get_sentenceF00_hour(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+65),BYTE32_SIZE); }
inline void set_sentenceF00_hour(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+65),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_hour(var) (*((BYTE32 *)(((char *)(&(var)))+65)))

/* UTC minute */
inline BYTE32* get_sentenceF00_minute(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+66),BYTE32_SIZE); }
inline void set_sentenceF00_minute(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+66),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_minute(var) (*((BYTE32 *)(((char *)(&(var)))+66)))

/* integer value of second */
inline BYTE32* get_sentenceF00_Second2(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+67),BYTE32_SIZE); }
inline void set_sentenceF00_Second2(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+67),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_Second2(var) (*((BYTE32 *)(((char *)(&(var)))+67)))

/* time type */
inline BYTE32* get_sentenceF00_time_type(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+68),BYTE32_SIZE); }
inline void set_sentenceF00_time_type(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+68),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_time_type(var) (*((BYTE32 *)(((char *)(&(var)))+68)))

/* system status */
inline BYTE32* get_sentenceF00_system_status(sentenceF00* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+69),BYTE32_SIZE); }
inline void set_sentenceF00_system_status(sentenceF00* var, BYTE32 val) { memcpy(((char*)var->data+69),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF00_system_status(var) (*((BYTE32 *)(((char *)(&(var)))+69)))

/* sentenceF03 declaration GPS F03 */
typedef struct {
	DOUBLE32 data[27];
} sentenceF03;

#define SENTENCEF03_SIZE 216
inline int sizeOfsentenceF03() {return 216;}

/* Code Lock Indicator (For Debug Purposes) */
inline LONG32* get_sentenceF03_CdLI(sentenceF03* var) {return ((LONG32*)((char*)var->data+0));}
inline void set_sentenceF03_CdLI(sentenceF03* var, LONG32* val) { memcpy(((char*)var->data+0),val,48); }
inline void set_sentenceF03_CdLI_ar(sentenceF03* var, LONG32* val, INT32 index) { memcpy((((LONG32*)((char*)var->data+0))+index),val,LONG32_SIZE); }
#define sentenceF03_CdLI(var,index) (*((LONG32 *)(((char *)(&(var)))+0)+index))

/* doppler shift */
inline INT32* get_sentenceF03_dopp(sentenceF03* var) {return ((INT32*)((char*)var->data+48));}
inline void set_sentenceF03_dopp(sentenceF03* var, INT32* val) { memcpy(((char*)var->data+48),val,48); }
inline void set_sentenceF03_dopp_ar(sentenceF03* var, INT32* val, INT32 index) { memcpy((((INT32*)((char*)var->data+48))+index),val,INT32_SIZE); }
#define sentenceF03_dopp(var,index) (*((INT32 *)(((char *)(&(var)))+48)+index))

/* azimuth */
inline SHORT32* get_sentenceF03_azi(sentenceF03* var) {return ((SHORT32*)((char*)var->data+96));}
inline void set_sentenceF03_azi(sentenceF03* var, SHORT32* val) { memcpy(((char*)var->data+96),val,24); }
inline void set_sentenceF03_azi_ar(sentenceF03* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+96))+index),val,SHORT32_SIZE); }
#define sentenceF03_azi(var,index) (*((SHORT32 *)(((char *)(&(var)))+96)+index))

/* Carrier to Noise Ratio */
inline UBYTE32* get_sentenceF03_cnr(sentenceF03* var) {return ((UBYTE32*)((char*)var->data+120));}
inline void set_sentenceF03_cnr(sentenceF03* var, UBYTE32* val) { memcpy(((char*)var->data+120),val,12); }
inline void set_sentenceF03_cnr_ar(sentenceF03* var, UBYTE32* val, INT32 index) { memcpy((((UBYTE32*)((char*)var->data+120))+index),val,UBYTE32_SIZE); }
#define sentenceF03_cnr(var,index) (*((UBYTE32 *)(((char *)(&(var)))+120)+index))

/* satellite ID */
inline BYTE32* get_sentenceF03_dispsv(sentenceF03* var) {return ((BYTE32*)((char*)var->data+132));}
inline void set_sentenceF03_dispsv(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+132),val,12); }
inline void set_sentenceF03_dispsv_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+132))+index),val,BYTE32_SIZE); }
#define sentenceF03_dispsv(var,index) (*((BYTE32 *)(((char *)(&(var)))+132)+index))

/* elevation */
inline BYTE32* get_sentenceF03_elv(sentenceF03* var) {return ((BYTE32*)((char*)var->data+144));}
inline void set_sentenceF03_elv(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+144),val,12); }
inline void set_sentenceF03_elv_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+144))+index),val,BYTE32_SIZE); }
#define sentenceF03_elv(var,index) (*((BYTE32 *)(((char *)(&(var)))+144)+index))

/* status flag */
inline BYTE32* get_sentenceF03_statflag(sentenceF03* var) {return ((BYTE32*)((char*)var->data+156));}
inline void set_sentenceF03_statflag(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+156),val,12); }
inline void set_sentenceF03_statflag_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+156))+index),val,BYTE32_SIZE); }
#define sentenceF03_statflag(var,index) (*((BYTE32 *)(((char *)(&(var)))+156)+index))

/* code lock */
inline BYTE32* get_sentenceF03_codelk(sentenceF03* var) {return ((BYTE32*)((char*)var->data+168));}
inline void set_sentenceF03_codelk(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+168),val,12); }
inline void set_sentenceF03_codelk_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+168))+index),val,BYTE32_SIZE); }
#define sentenceF03_codelk(var,index) (*((BYTE32 *)(((char *)(&(var)))+168)+index))

/* carrier lock */
inline BYTE32* get_sentenceF03_carrlk(sentenceF03* var) {return ((BYTE32*)((char*)var->data+180));}
inline void set_sentenceF03_carrlk(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+180),val,12); }
inline void set_sentenceF03_carrlk_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+180))+index),val,BYTE32_SIZE); }
#define sentenceF03_carrlk(var,index) (*((BYTE32 *)(((char *)(&(var)))+180)+index))

/* bit lock */
inline BYTE32* get_sentenceF03_bitlk(sentenceF03* var) {return ((BYTE32*)((char*)var->data+192));}
inline void set_sentenceF03_bitlk(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+192),val,12); }
inline void set_sentenceF03_bitlk_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+192))+index),val,BYTE32_SIZE); }
#define sentenceF03_bitlk(var,index) (*((BYTE32 *)(((char *)(&(var)))+192)+index))

/* frame lock */
inline BYTE32* get_sentenceF03_framelk(sentenceF03* var) {return ((BYTE32*)((char*)var->data+204));}
inline void set_sentenceF03_framelk(sentenceF03* var, BYTE32* val) { memcpy(((char*)var->data+204),val,12); }
inline void set_sentenceF03_framelk_ar(sentenceF03* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+204))+index),val,BYTE32_SIZE); }
#define sentenceF03_framelk(var,index) (*((BYTE32 *)(((char *)(&(var)))+204)+index))

/* sentenceF18 declaration GPS F18 */
typedef struct {
	DOUBLE32 data[24];
} sentenceF18;

#define SENTENCEF18_SIZE 192
inline int sizeOfsentenceF18() {return 192;}

/* pseudorange */
inline DOUBLE32* get_sentenceF18_range(sentenceF18* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_sentenceF18_range(sentenceF18* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,96); }
inline void set_sentenceF18_range_ar(sentenceF18* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define sentenceF18_range(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* carrier phase */
inline DOUBLE32* get_sentenceF18_phase(sentenceF18* var) {return ((DOUBLE32*)((char*)var->data+96));}
inline void set_sentenceF18_phase(sentenceF18* var, DOUBLE32* val) { memcpy(((char*)var->data+96),val,96); }
inline void set_sentenceF18_phase_ar(sentenceF18* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+96))+index),val,DOUBLE32_SIZE); }
#define sentenceF18_phase(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+96)+index))

/* sentenceF22 declaration GPS F22 */
typedef struct {
	DOUBLE32 data[15];
} sentenceF22;

#define SENTENCEF22_SIZE 120
inline int sizeOfsentenceF22() {return 120;}

/* Square-root of semi-major axis (m**1/2) */
inline ULONG32* get_sentenceF22_almsqrta(sentenceF22* var, ULONG32* toSet) { return (ULONG32*)memcpy(toSet,(ULONG32*)((char*)var->data+0),ULONG32_SIZE); }
inline void set_sentenceF22_almsqrta(sentenceF22* var, ULONG32 val) { memcpy(((char*)var->data+0),(void*)&val,ULONG32_SIZE); return; }
#define sentenceF22_almsqrta(var) (*((ULONG32 *)(((char *)(&(var)))+0)))

/* Right ascension at ref time (radians) */
inline LONG32* get_sentenceF22_ratoa(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+4),LONG32_SIZE); }
inline void set_sentenceF22_ratoa(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+4),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_ratoa(var) (*((LONG32 *)(((char *)(&(var)))+4)))

/* Argument of perigee at ref time (radians) */
inline LONG32* get_sentenceF22_argpg(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+8),LONG32_SIZE); }
inline void set_sentenceF22_argpg(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+8),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_argpg(var) (*((LONG32 *)(((char *)(&(var)))+8)))

/* Mean anomaly at ref time (radians) */
inline LONG32* get_sentenceF22_manom(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+12),LONG32_SIZE); }
inline void set_sentenceF22_manom(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+12),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_manom(var) (*((LONG32 *)(((char *)(&(var)))+12)))

/* Eccentricity */
inline ULONG32* get_sentenceF22_ephecc(sentenceF22* var, ULONG32* toSet) { return (ULONG32*)memcpy(toSet,(ULONG32*)((char*)var->data+16),ULONG32_SIZE); }
inline void set_sentenceF22_ephecc(sentenceF22* var, ULONG32 val) { memcpy(((char*)var->data+16),(void*)&val,ULONG32_SIZE); return; }
#define sentenceF22_ephecc(var) (*((ULONG32 *)(((char *)(&(var)))+16)))

/* Square root of the semi-major axis */
inline ULONG32* get_sentenceF22_ephsqrta(sentenceF22* var, ULONG32* toSet) { return (ULONG32*)memcpy(toSet,(ULONG32*)((char*)var->data+20),ULONG32_SIZE); }
inline void set_sentenceF22_ephsqrta(sentenceF22* var, ULONG32 val) { memcpy(((char*)var->data+20),(void*)&val,ULONG32_SIZE); return; }
#define sentenceF22_ephsqrta(var) (*((ULONG32 *)(((char *)(&(var)))+20)))

/* Mean anomaly at TOE */
inline LONG32* get_sentenceF22_m0(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+24),LONG32_SIZE); }
inline void set_sentenceF22_m0(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+24),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_m0(var) (*((LONG32 *)(((char *)(&(var)))+24)))

/* Right ascension at TOE */
inline LONG32* get_sentenceF22_om0(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+28),LONG32_SIZE); }
inline void set_sentenceF22_om0(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+28),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_om0(var) (*((LONG32 *)(((char *)(&(var)))+28)))

/* Inclination at TOE */
inline LONG32* get_sentenceF22_in0(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+32),LONG32_SIZE); }
inline void set_sentenceF22_in0(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+32),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_in0(var) (*((LONG32 *)(((char *)(&(var)))+32)))

/* Argument of perigee at TOE */
inline LONG32* get_sentenceF22_olc(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+36),LONG32_SIZE); }
inline void set_sentenceF22_olc(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+36),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_olc(var) (*((LONG32 *)(((char *)(&(var)))+36)))

/* Rate of right ascension */
inline LONG32* get_sentenceF22_omd(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+40),LONG32_SIZE); }
inline void set_sentenceF22_omd(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+40),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_omd(var) (*((LONG32 *)(((char *)(&(var)))+40)))

/* Rate of inclination */
inline LONG32* get_sentenceF22_idot(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+44),LONG32_SIZE); }
inline void set_sentenceF22_idot(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+44),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_idot(var) (*((LONG32 *)(((char *)(&(var)))+44)))

/* Clock correction polynomial coefficient */
inline LONG32* get_sentenceF22_ephaf0(sentenceF22* var, LONG32* toSet) { return (LONG32*)memcpy(toSet,(LONG32*)((char*)var->data+48),LONG32_SIZE); }
inline void set_sentenceF22_ephaf0(sentenceF22* var, LONG32 val) { memcpy(((char*)var->data+48),(void*)&val,LONG32_SIZE); return; }
#define sentenceF22_ephaf0(var) (*((LONG32 *)(((char *)(&(var)))+48)))

/* Almanac health code */
inline USHORT32* get_sentenceF22_almhlth(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+52),USHORT32_SIZE); }
inline void set_sentenceF22_almhlth(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+52),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_almhlth(var) (*((USHORT32 *)(((char *)(&(var)))+52)))

/* Reference time, GPS week */
inline USHORT32* get_sentenceF22_refweek(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+54),USHORT32_SIZE); }
inline void set_sentenceF22_refweek(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+54),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_refweek(var) (*((USHORT32 *)(((char *)(&(var)))+54)))

/* Reference time, seconds of refweek */
inline USHORT32* get_sentenceF22_toa(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+56),USHORT32_SIZE); }
inline void set_sentenceF22_toa(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+56),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_toa(var) (*((USHORT32 *)(((char *)(&(var)))+56)))

/* Orbital eccentricity */
inline USHORT32* get_sentenceF22_almecc(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+58),USHORT32_SIZE); }
inline void set_sentenceF22_almecc(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+58),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_almecc(var) (*((USHORT32 *)(((char *)(&(var)))+58)))

/* Orbital inclination (radians) */
inline SHORT32* get_sentenceF22_inclin(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+60),SHORT32_SIZE); }
inline void set_sentenceF22_inclin(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+60),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_inclin(var) (*((SHORT32 *)(((char *)(&(var)))+60)))

/* Rate of right ascension (radians/sec) */
inline SHORT32* get_sentenceF22_rora(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+62),SHORT32_SIZE); }
inline void set_sentenceF22_rora(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+62),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_rora(var) (*((SHORT32 *)(((char *)(&(var)))+62)))

/* Clock correction at ref time (seconds) */
inline SHORT32* get_sentenceF22_almaf0(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+64),SHORT32_SIZE); }
inline void set_sentenceF22_almaf0(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+64),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_almaf0(var) (*((SHORT32 *)(((char *)(&(var)))+64)))

/* Clock correction rate (seconds/second) */
inline SHORT32* get_sentenceF22_almaf1(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+66),SHORT32_SIZE); }
inline void set_sentenceF22_almaf1(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+66),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_almaf1(var) (*((SHORT32 *)(((char *)(&(var)))+66)))

/* SF 1 health code */
inline USHORT32* get_sentenceF22_s1hlth(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+68),USHORT32_SIZE); }
inline void set_sentenceF22_s1hlth(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+68),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_s1hlth(var) (*((USHORT32 *)(((char *)(&(var)))+68)))

/* Code on L2 flag */
inline USHORT32* get_sentenceF22_codeL2(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+70),USHORT32_SIZE); }
inline void set_sentenceF22_codeL2(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+70),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_codeL2(var) (*((USHORT32 *)(((char *)(&(var)))+70)))

/* GPS week at time of SF 1 reception */
inline USHORT32* get_sentenceF22_wkn(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+72),USHORT32_SIZE); }
inline void set_sentenceF22_wkn(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+72),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_wkn(var) (*((USHORT32 *)(((char *)(&(var)))+72)))

/* L2 P data flag */
inline USHORT32* get_sentenceF22_L2Pdata(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+74),USHORT32_SIZE); }
inline void set_sentenceF22_L2Pdata(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+74),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_L2Pdata(var) (*((USHORT32 *)(((char *)(&(var)))+74)))

/* Satellite's URA code */
inline USHORT32* get_sentenceF22_ura(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+76),USHORT32_SIZE); }
inline void set_sentenceF22_ura(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+76),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_ura(var) (*((USHORT32 *)(((char *)(&(var)))+76)))

/* Issue of data, clock */
inline USHORT32* get_sentenceF22_iodc(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+78),USHORT32_SIZE); }
inline void set_sentenceF22_iodc(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+78),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_iodc(var) (*((USHORT32 *)(((char *)(&(var)))+78)))

/* GPS week corresponding to toc */
inline USHORT32* get_sentenceF22_tocwk(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+80),USHORT32_SIZE); }
inline void set_sentenceF22_tocwk(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+80),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_tocwk(var) (*((USHORT32 *)(((char *)(&(var)))+80)))

/* Issue of data, ephemeris */
inline USHORT32* get_sentenceF22_iode(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+82),USHORT32_SIZE); }
inline void set_sentenceF22_iode(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+82),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_iode(var) (*((USHORT32 *)(((char *)(&(var)))+82)))

/* GPS week corresponding to toe */
inline USHORT32* get_sentenceF22_toewk(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+84),USHORT32_SIZE); }
inline void set_sentenceF22_toewk(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+84),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_toewk(var) (*((USHORT32 *)(((char *)(&(var)))+84)))

/* Fit interval */
inline USHORT32* get_sentenceF22_fti(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+86),USHORT32_SIZE); }
inline void set_sentenceF22_fti(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+86),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_fti(var) (*((USHORT32 *)(((char *)(&(var)))+86)))

/* Reference time of ephemeris data set */
inline USHORT32* get_sentenceF22_toe(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+88),USHORT32_SIZE); }
inline void set_sentenceF22_toe(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+88),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_toe(var) (*((USHORT32 *)(((char *)(&(var)))+88)))

/* Reference time of clock data parameter set */
inline USHORT32* get_sentenceF22_toc(sentenceF22* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+90),USHORT32_SIZE); }
inline void set_sentenceF22_toc(sentenceF22* var, USHORT32 val) { memcpy(((char*)var->data+90),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF22_toc(var) (*((USHORT32 *)(((char *)(&(var)))+90)))

/* Cosine harmonic corr to argument of latitude */
inline SHORT32* get_sentenceF22_cuc(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+92),SHORT32_SIZE); }
inline void set_sentenceF22_cuc(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+92),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_cuc(var) (*((SHORT32 *)(((char *)(&(var)))+92)))

/* Sine harmonic corr to argument of latitude */
inline SHORT32* get_sentenceF22_cus(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+94),SHORT32_SIZE); }
inline void set_sentenceF22_cus(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+94),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_cus(var) (*((SHORT32 *)(((char *)(&(var)))+94)))

/* Cosine harmonic corr to inclination */
inline SHORT32* get_sentenceF22_cic(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+96),SHORT32_SIZE); }
inline void set_sentenceF22_cic(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+96),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_cic(var) (*((SHORT32 *)(((char *)(&(var)))+96)))

/* Sine harmonic corr to inclination */
inline SHORT32* get_sentenceF22_cis(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+98),SHORT32_SIZE); }
inline void set_sentenceF22_cis(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+98),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_cis(var) (*((SHORT32 *)(((char *)(&(var)))+98)))

/* Cosine harmonic correction to orbital radius */
inline SHORT32* get_sentenceF22_crc(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+100),SHORT32_SIZE); }
inline void set_sentenceF22_crc(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+100),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_crc(var) (*((SHORT32 *)(((char *)(&(var)))+100)))

/* Sine harmonic correction to orbital radius */
inline SHORT32* get_sentenceF22_crs(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+102),SHORT32_SIZE); }
inline void set_sentenceF22_crs(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+102),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_crs(var) (*((SHORT32 *)(((char *)(&(var)))+102)))

/* Clock correction polynomial coefficient */
inline SHORT32* get_sentenceF22_ephaf1(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+104),SHORT32_SIZE); }
inline void set_sentenceF22_ephaf1(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+104),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_ephaf1(var) (*((SHORT32 *)(((char *)(&(var)))+104)))

/* Clock correction polynomial coefficient */
inline SHORT32* get_sentenceF22_af2(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+106),SHORT32_SIZE); }
inline void set_sentenceF22_af2(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+106),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_af2(var) (*((SHORT32 *)(((char *)(&(var)))+106)))

/* Group delay parameter */
inline SHORT32* get_sentenceF22_tgd(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+108),SHORT32_SIZE); }
inline void set_sentenceF22_tgd(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+108),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_tgd(var) (*((SHORT32 *)(((char *)(&(var)))+108)))

/* Mean motion delta from computed value */
inline SHORT32* get_sentenceF22_deltan(sentenceF22* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+110),SHORT32_SIZE); }
inline void set_sentenceF22_deltan(sentenceF22* var, SHORT32 val) { memcpy(((char*)var->data+110),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF22_deltan(var) (*((SHORT32 *)(((char *)(&(var)))+110)))

/* satellite ID */
inline BYTE32* get_sentenceF22_satID(sentenceF22* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+112),BYTE32_SIZE); }
inline void set_sentenceF22_satID(sentenceF22* var, BYTE32 val) { memcpy(((char*)var->data+112),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF22_satID(var) (*((BYTE32 *)(((char *)(&(var)))+112)))

/* phv0=Invalid, 1=Valid, 2=Not Logged */
inline UBYTE32* get_sentenceF22_almvflg(sentenceF22* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+113),UBYTE32_SIZE); }
inline void set_sentenceF22_almvflg(sentenceF22* var, UBYTE32 val) { memcpy(((char*)var->data+113),(void*)&val,UBYTE32_SIZE); return; }
#define sentenceF22_almvflg(var) (*((UBYTE32 *)(((char *)(&(var)))+113)))

/* 0=Invalid, 1=Valid, 2=Not Logged */
inline UBYTE32* get_sentenceF22_ephvflg(sentenceF22* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+114),UBYTE32_SIZE); }
inline void set_sentenceF22_ephvflg(sentenceF22* var, UBYTE32 val) { memcpy(((char*)var->data+114),(void*)&val,UBYTE32_SIZE); return; }
#define sentenceF22_ephvflg(var) (*((UBYTE32 *)(((char *)(&(var)))+114)))

/* sentenceF23 declaration GPS F23 */
typedef struct {
	DOUBLE32 data[12];
} sentenceF23;

#define SENTENCEF23_SIZE 96
inline int sizeOfsentenceF23() {return 96;}

/* AFCRL alpha parameter 0 */
inline DOUBLE32* get_sentenceF23_a0(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_sentenceF23_a0(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_a0(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* AFCRL alpha parameter 1 */
inline DOUBLE32* get_sentenceF23_a1(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_sentenceF23_a1(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_a1(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* AFCRL alpha parameter 2 */
inline DOUBLE32* get_sentenceF23_a2(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_sentenceF23_a2(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_a2(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* AFCRL alpha parameter 3 */
inline DOUBLE32* get_sentenceF23_a3(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_sentenceF23_a3(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_a3(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* AFCRL beta parameter 0 */
inline DOUBLE32* get_sentenceF23_b0(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_sentenceF23_b0(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_b0(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* AFCRL beta parameter 1 */
inline DOUBLE32* get_sentenceF23_b1(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_sentenceF23_b1(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_b1(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* AFCRL beta parameter 2 */
inline DOUBLE32* get_sentenceF23_b2(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+48),DOUBLE32_SIZE); }
inline void set_sentenceF23_b2(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+48),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_b2(var) (*((DOUBLE32 *)(((char *)(&(var)))+48)))

/* AFCRL beta parameter 3 */
inline DOUBLE32* get_sentenceF23_b3(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+56),DOUBLE32_SIZE); }
inline void set_sentenceF23_b3(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+56),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_b3(var) (*((DOUBLE32 *)(((char *)(&(var)))+56)))

/* Coeff for determining UTC time(0) */
inline DOUBLE32* get_sentenceF23_A0(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+64),DOUBLE32_SIZE); }
inline void set_sentenceF23_A0(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+64),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_A0(var) (*((DOUBLE32 *)(((char *)(&(var)))+64)))

/* Coeff for determining UTC time(1) */
inline DOUBLE32* get_sentenceF23_A1(sentenceF23* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+72),DOUBLE32_SIZE); }
inline void set_sentenceF23_A1(sentenceF23* var, DOUBLE32 val) { memcpy(((char*)var->data+72),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF23_A1(var) (*((DOUBLE32 *)(((char *)(&(var)))+72)))

/* Reference time for A0 & A1, sec of GPS week */
inline ULONG32* get_sentenceF23_tot(sentenceF23* var, ULONG32* toSet) { return (ULONG32*)memcpy(toSet,(ULONG32*)((char*)var->data+80),ULONG32_SIZE); }
inline void set_sentenceF23_tot(sentenceF23* var, ULONG32 val) { memcpy(((char*)var->data+80),(void*)&val,ULONG32_SIZE); return; }
#define sentenceF23_tot(var) (*((ULONG32 *)(((char *)(&(var)))+80)))

/* Cumulative past leap seconds */
inline SHORT32* get_sentenceF23_dtls(sentenceF23* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+84),SHORT32_SIZE); }
inline void set_sentenceF23_dtls(sentenceF23* var, SHORT32 val) { memcpy(((char*)var->data+84),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF23_dtls(var) (*((SHORT32 *)(((char *)(&(var)))+84)))

/* Day of week (1-7) when dtlsf becomes effective */
inline SHORT32* get_sentenceF23_dn(sentenceF23* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+86),SHORT32_SIZE); }
inline void set_sentenceF23_dn(sentenceF23* var, SHORT32 val) { memcpy(((char*)var->data+86),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF23_dn(var) (*((SHORT32 *)(((char *)(&(var)))+86)))

/* Scheduled future leap second event */
inline SHORT32* get_sentenceF23_dtlsf(sentenceF23* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+88),SHORT32_SIZE); }
inline void set_sentenceF23_dtlsf(sentenceF23* var, SHORT32 val) { memcpy(((char*)var->data+88),(void*)&val,SHORT32_SIZE); return; }
#define sentenceF23_dtlsf(var) (*((SHORT32 *)(((char *)(&(var)))+88)))

/* Current UTC reference week number */
inline USHORT32* get_sentenceF23_wnt(sentenceF23* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+90),USHORT32_SIZE); }
inline void set_sentenceF23_wnt(sentenceF23* var, USHORT32 val) { memcpy(((char*)var->data+90),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF23_wnt(var) (*((USHORT32 *)(((char *)(&(var)))+90)))

/* Week number when dtlsf becomes effective */
inline USHORT32* get_sentenceF23_wnlsf(sentenceF23* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+92),USHORT32_SIZE); }
inline void set_sentenceF23_wnlsf(sentenceF23* var, USHORT32 val) { memcpy(((char*)var->data+92),(void*)&val,USHORT32_SIZE); return; }
#define sentenceF23_wnlsf(var) (*((USHORT32 *)(((char *)(&(var)))+92)))

/* 0 = no valid data */
inline BYTE32* get_sentenceF23_ionvflg(sentenceF23* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+94),BYTE32_SIZE); }
inline void set_sentenceF23_ionvflg(sentenceF23* var, BYTE32 val) { memcpy(((char*)var->data+94),(void*)&val,BYTE32_SIZE); return; }
#define sentenceF23_ionvflg(var) (*((BYTE32 *)(((char *)(&(var)))+94)))

/* sentenceF24 declaration GPS F24 */
typedef struct {
	DOUBLE32 data[12];
} sentenceF24;

#define SENTENCEF24_SIZE 96
inline int sizeOfsentenceF24() {return 96;}

/* Reference time, GPS week */
inline DOUBLE32* get_sentenceF24_refweek(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_sentenceF24_refweek(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_refweek(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* Reference time, seconds of refweek */
inline DOUBLE32* get_sentenceF24_toa(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_sentenceF24_toa(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_toa(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* Orbital eccentricity */
inline DOUBLE32* get_sentenceF24_ecc(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_sentenceF24_ecc(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_ecc(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* Orbital inclination (radians) */
inline DOUBLE32* get_sentenceF24_inclin(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_sentenceF24_inclin(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_inclin(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* Rate of right ascension (radians/sec) */
inline DOUBLE32* get_sentenceF24_rora(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_sentenceF24_rora(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_rora(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* Clock correction at ref time (seconds) */
inline DOUBLE32* get_sentenceF24_af0(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_sentenceF24_af0(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_af0(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* Clock correction rate (seconds/second) */
inline DOUBLE32* get_sentenceF24_af1(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+48),DOUBLE32_SIZE); }
inline void set_sentenceF24_af1(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+48),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_af1(var) (*((DOUBLE32 *)(((char *)(&(var)))+48)))

/* Square-root of semi-major axis (m**1/2) */
inline DOUBLE32* get_sentenceF24_sqrta(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+56),DOUBLE32_SIZE); }
inline void set_sentenceF24_sqrta(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+56),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_sqrta(var) (*((DOUBLE32 *)(((char *)(&(var)))+56)))

/* Right ascension at ref time (radians) */
inline DOUBLE32* get_sentenceF24_ratoa(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+64),DOUBLE32_SIZE); }
inline void set_sentenceF24_ratoa(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+64),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_ratoa(var) (*((DOUBLE32 *)(((char *)(&(var)))+64)))

/* Argument of perigee at ref time (radians) */
inline DOUBLE32* get_sentenceF24_argpg(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+72),DOUBLE32_SIZE); }
inline void set_sentenceF24_argpg(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+72),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_argpg(var) (*((DOUBLE32 *)(((char *)(&(var)))+72)))

/* Mean anomaly at ref time (radians) */
inline DOUBLE32* get_sentenceF24_manom(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+80),DOUBLE32_SIZE); }
inline void set_sentenceF24_manom(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+80),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_manom(var) (*((DOUBLE32 *)(((char *)(&(var)))+80)))

/* longitude of ascending node */
inline DOUBLE32* get_sentenceF24_ok(sentenceF24* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+88),DOUBLE32_SIZE); }
inline void set_sentenceF24_ok(sentenceF24* var, DOUBLE32 val) { memcpy(((char*)var->data+88),(void*)&val,DOUBLE32_SIZE); return; }
#define sentenceF24_ok(var) (*((DOUBLE32 *)(((char *)(&(var)))+88)))

/* TIMESTAMP declaration  */
typedef struct {
	DOUBLE32 data[4];
} TIMESTAMP;

#define TIMESTAMP_SIZE 32
inline int sizeOfTIMESTAMP() {return 32;}

/*  */
inline INT32* get_TIMESTAMP_day(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+0),INT32_SIZE); }
inline void set_TIMESTAMP_day(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+0),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_day(var) (*((INT32 *)(((char *)(&(var)))+0)))

/*  */
inline INT32* get_TIMESTAMP_month(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+4),INT32_SIZE); }
inline void set_TIMESTAMP_month(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+4),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_month(var) (*((INT32 *)(((char *)(&(var)))+4)))

/*  */
inline INT32* get_TIMESTAMP_year(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+8),INT32_SIZE); }
inline void set_TIMESTAMP_year(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+8),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_year(var) (*((INT32 *)(((char *)(&(var)))+8)))

/*  */
inline INT32* get_TIMESTAMP_hour(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+12),INT32_SIZE); }
inline void set_TIMESTAMP_hour(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+12),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_hour(var) (*((INT32 *)(((char *)(&(var)))+12)))

/*  */
inline INT32* get_TIMESTAMP_minute(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+16),INT32_SIZE); }
inline void set_TIMESTAMP_minute(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+16),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_minute(var) (*((INT32 *)(((char *)(&(var)))+16)))

/*  */
inline INT32* get_TIMESTAMP_seconds(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+20),INT32_SIZE); }
inline void set_TIMESTAMP_seconds(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+20),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_seconds(var) (*((INT32 *)(((char *)(&(var)))+20)))

/*  */
inline INT32* get_TIMESTAMP_hundredMicroSeconds(TIMESTAMP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+24),INT32_SIZE); }
inline void set_TIMESTAMP_hundredMicroSeconds(TIMESTAMP* var, INT32 val) { memcpy(((char*)var->data+24),(void*)&val,INT32_SIZE); return; }
#define TIMESTAMP_hundredMicroSeconds(var) (*((INT32 *)(((char *)(&(var)))+24)))

/* RESP_PWR_ALL_STATUS declaration PWR telemetry from power board */
typedef struct {
	DOUBLE32 data[7];
} RESP_PWR_ALL_STATUS;

#define RESP_PWR_ALL_STATUS_SIZE 56
inline int sizeOfRESP_PWR_ALL_STATUS() {return 56;}

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS1Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS1Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS1Current(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS1Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS2Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS2Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS2Current(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+3),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+3),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS2Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+3)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS3Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+4),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS3Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+4),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS3Current(var) (*((BYTE32 *)(((char *)(&(var)))+4)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_GPS3Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+5),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_GPS3Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+5),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_GPS3Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+5)))

/* THERM02 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PWR1BoardTemp(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+6),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_PWR1BoardTemp(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+6),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_PWR1BoardTemp(var) (*((BYTE32 *)(((char *)(&(var)))+6)))

/* THERM13 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryTemp1(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+7),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryTemp1(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+7),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryTemp1(var) (*((BYTE32 *)(((char *)(&(var)))+7)))

/* THERM14 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryTemp2(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+8),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryTemp2(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+8),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryTemp2(var) (*((BYTE32 *)(((char *)(&(var)))+8)))

/* THERM15 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryTemp3(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+9),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryTemp3(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+9),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryTemp3(var) (*((BYTE32 *)(((char *)(&(var)))+9)))

/* THERM16 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryTemp4(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+10),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryTemp4(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+10),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryTemp4(var) (*((BYTE32 *)(((char *)(&(var)))+10)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_CDHBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+11),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_CDHBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+11),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_CDHBoardCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+11)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_CDHBoardVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+12),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_CDHBoardVoltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+12),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_CDHBoardVoltage(var) (*((BYTE32 *)(((char *)(&(var)))+12)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PWRBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+13),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_PWRBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+13),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_PWRBoardCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+13)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_TCBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+14),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_TCBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+14),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_TCBoardCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+14)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_CAMBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+15),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_CAMBoardCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+15),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_CAMBoardCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+15)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera1Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+16),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera1Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+16),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera1Current(var) (*((BYTE32 *)(((char *)(&(var)))+16)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera2Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+17),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera2Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+17),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera2Current(var) (*((BYTE32 *)(((char *)(&(var)))+17)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+18),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+18),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera1Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+18)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+19),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+19),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera2Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+19)))

/* THERM11 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera1Temp(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+20),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera1Temp(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+20),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera1Temp(var) (*((BYTE32 *)(((char *)(&(var)))+20)))

/* THERM12 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Camera2Temp(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+21),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Camera2Temp(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+21),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Camera2Temp(var) (*((BYTE32 *)(((char *)(&(var)))+21)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryBoxCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+22),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryBoxCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+22),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryBoxCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+22)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PropCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+23),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_PropCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+23),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_PropCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+23)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+24),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryVoltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+24),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryVoltage(var) (*((BYTE32 *)(((char *)(&(var)))+24)))

/* Used to report emergency shutdown subsystem at fault */
inline BYTE32* get_RESP_PWR_ALL_STATUS_EmergencyShutdown(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+25),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_EmergencyShutdown(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+25),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_EmergencyShutdown(var) (*((BYTE32 *)(((char *)(&(var)))+25)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PeakVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+26),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_PeakVoltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+26),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_PeakVoltage(var) (*((BYTE32 *)(((char *)(&(var)))+26)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater1Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+27),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater1Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+27),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater1Current(var) (*((BYTE32 *)(((char *)(&(var)))+27)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater2Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+28),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater2Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+28),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater2Current(var) (*((BYTE32 *)(((char *)(&(var)))+28)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater3Current(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+29),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater3Current(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+29),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater3Current(var) (*((BYTE32 *)(((char *)(&(var)))+29)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+30),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater1Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+30),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater1Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+30)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+31),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater2Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+31),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater2Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+31)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_Heater3Voltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+32),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_Heater3Voltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+32),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_Heater3Voltage(var) (*((BYTE32 *)(((char *)(&(var)))+32)))

/* Lightband */
inline BYTE32* get_RESP_PWR_ALL_STATUS_LBVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+33),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_LBVoltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+33),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_LBVoltage(var) (*((BYTE32 *)(((char *)(&(var)))+33)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_BatteryCapacity(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+34),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_BatteryCapacity(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+34),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_BatteryCapacity(var) (*((BYTE32 *)(((char *)(&(var)))+34)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PanelVoltage(RESP_PWR_ALL_STATUS* var) {return ((BYTE32*)((char*)var->data+35));}
inline void set_RESP_PWR_ALL_STATUS_PanelVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+35),val,8); }
inline void set_RESP_PWR_ALL_STATUS_PanelVoltage_ar(RESP_PWR_ALL_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+35))+index),val,BYTE32_SIZE); }
#define RESP_PWR_ALL_STATUS_PanelVoltage(var,index) (*((BYTE32 *)(((char *)(&(var)))+35)+index))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_PanelCurrent(RESP_PWR_ALL_STATUS* var) {return ((BYTE32*)((char*)var->data+43));}
inline void set_RESP_PWR_ALL_STATUS_PanelCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+43),val,8); }
inline void set_RESP_PWR_ALL_STATUS_PanelCurrent_ar(RESP_PWR_ALL_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+43))+index),val,BYTE32_SIZE); }
#define RESP_PWR_ALL_STATUS_PanelCurrent(var,index) (*((BYTE32 *)(((char *)(&(var)))+43)+index))

/* THERM17 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_RadioTemp1(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+51),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_RadioTemp1(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+51),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_RadioTemp1(var) (*((BYTE32 *)(((char *)(&(var)))+51)))

/* THERM18 */
inline BYTE32* get_RESP_PWR_ALL_STATUS_RadioTemp2(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+52),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_RadioTemp2(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+52),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_RadioTemp2(var) (*((BYTE32 *)(((char *)(&(var)))+52)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_IMIADCNSCurrent(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+53),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_IMIADCNSCurrent(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+53),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_IMIADCNSCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+53)))

/*  */
inline BYTE32* get_RESP_PWR_ALL_STATUS_IMIADCNSVoltage(RESP_PWR_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+54),BYTE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_IMIADCNSVoltage(RESP_PWR_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+54),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_IMIADCNSVoltage(var) (*((BYTE32 *)(((char *)(&(var)))+54)))

/* RESP_PWR_ALL_STATUS_SCALING declaration - Status Response */
typedef struct {
	DOUBLE32 data[53];
} RESP_PWR_ALL_STATUS_SCALING;

#define RESP_PWR_ALL_STATUS_SCALING_SIZE 424
inline int sizeOfRESP_PWR_ALL_STATUS_SCALING() {return 424;}

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS1Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS1Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS2Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS2Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS3Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS3Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS3Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_GPS3Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_GPS3Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_GPS3Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* THERM02 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_PWR1BoardTemp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+48),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_PWR1BoardTemp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+48),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_PWR1BoardTemp(var) (*((DOUBLE32 *)(((char *)(&(var)))+48)))

/* THERM13 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp1(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+56),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp1(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+56),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryTemp1(var) (*((DOUBLE32 *)(((char *)(&(var)))+56)))

/* THERM14 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp2(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+64),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp2(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+64),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryTemp2(var) (*((DOUBLE32 *)(((char *)(&(var)))+64)))

/* THERM15 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp3(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+72),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp3(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+72),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryTemp3(var) (*((DOUBLE32 *)(((char *)(&(var)))+72)))

/* THERM16 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp4(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+80),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryTemp4(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+80),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryTemp4(var) (*((DOUBLE32 *)(((char *)(&(var)))+80)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_CDHBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+88),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_CDHBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+88),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_CDHBoardCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+88)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_CDHBoardVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+96),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_CDHBoardVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+96),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_CDHBoardVoltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+96)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_PWRBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+104),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_PWRBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+104),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_PWRBoardCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+104)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_TCBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+112),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_TCBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+112),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_TCBoardCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+112)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_CAMBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+120),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_CAMBoardCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+120),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_CAMBoardCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+120)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+128),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+128),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera1Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+128)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+136),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+136),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera2Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+136)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+144),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+144),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera1Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+144)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+152),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+152),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera2Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+152)))

/* THERM11 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera1Temp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+160),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera1Temp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+160),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera1Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+160)))

/* THERM12 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Camera2Temp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+168),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Camera2Temp(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+168),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Camera2Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+168)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryBoxCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+176),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryBoxCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+176),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryBoxCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+176)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_PropCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+184),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_PropCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+184),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_PropCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+184)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+192),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+192),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryVoltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+192)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+200),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater1Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+200),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater1Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+200)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+208),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater2Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+208),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater2Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+208)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater3Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+216),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater3Current(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+216),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater3Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+216)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+224),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater1Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+224),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater1Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+224)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+232),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater2Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+232),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater2Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+232)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_Heater3Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+240),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_Heater3Voltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+240),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_Heater3Voltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+240)))

/* Lightband */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_LBVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+248),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_LBVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+248),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_LBVoltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+248)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_BatteryCapacity(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+256),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_BatteryCapacity(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+256),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_BatteryCapacity(var) (*((DOUBLE32 *)(((char *)(&(var)))+256)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_PanelVoltage(RESP_PWR_ALL_STATUS_SCALING* var) {return ((DOUBLE32*)((char*)var->data+264));}
inline void set_RESP_PWR_ALL_STATUS_SCALING_PanelVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* val) { memcpy(((char*)var->data+264),val,64); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_PanelVoltage_ar(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+264))+index),val,DOUBLE32_SIZE); }
#define RESP_PWR_ALL_STATUS_SCALING_PanelVoltage(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+264)+index))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_PanelCurrent(RESP_PWR_ALL_STATUS_SCALING* var) {return ((DOUBLE32*)((char*)var->data+328));}
inline void set_RESP_PWR_ALL_STATUS_SCALING_PanelCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* val) { memcpy(((char*)var->data+328),val,64); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_PanelCurrent_ar(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+328))+index),val,DOUBLE32_SIZE); }
#define RESP_PWR_ALL_STATUS_SCALING_PanelCurrent(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+328)+index))

/* THERM17 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_RadioTemp1(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+392),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_RadioTemp1(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+392),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_RadioTemp1(var) (*((DOUBLE32 *)(((char *)(&(var)))+392)))

/* THERM18 */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_RadioTemp2(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+400),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_RadioTemp2(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+400),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_RadioTemp2(var) (*((DOUBLE32 *)(((char *)(&(var)))+400)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_IMIADCNSCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+408),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_IMIADCNSCurrent(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+408),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_IMIADCNSCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+408)))

/*  */
inline DOUBLE32* get_RESP_PWR_ALL_STATUS_SCALING_IMIADCNSVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+416),DOUBLE32_SIZE); }
inline void set_RESP_PWR_ALL_STATUS_SCALING_IMIADCNSVoltage(RESP_PWR_ALL_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+416),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PWR_ALL_STATUS_SCALING_IMIADCNSVoltage(var) (*((DOUBLE32 *)(((char *)(&(var)))+416)))

/* RESP_PPT_STATUS declaration PROP Status Response */
typedef struct {
	DOUBLE32 data[1];
} RESP_PPT_STATUS;

#define RESP_PPT_STATUS_SIZE 8
inline int sizeOfRESP_PPT_STATUS() {return 8;}

/* PPU box temperature (THERM10) */
inline BYTE32* get_RESP_PPT_STATUS_PPUTemp(RESP_PPT_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_PPT_STATUS_PPUTemp(RESP_PPT_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PPT_STATUS_PPUTemp(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* temperature for each PPT (in order, THERM19-22) */
inline BYTE32* get_RESP_PPT_STATUS_PPTTemp(RESP_PPT_STATUS* var) {return ((BYTE32*)((char*)var->data+1));}
inline void set_RESP_PPT_STATUS_PPTTemp(RESP_PPT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+1),val,4); }
inline void set_RESP_PPT_STATUS_PPTTemp_ar(RESP_PPT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+1))+index),val,BYTE32_SIZE); }
#define RESP_PPT_STATUS_PPTTemp(var,index) (*((BYTE32 *)(((char *)(&(var)))+1)+index))

/* Output of a random comparator...not meaningful! */
inline BYTE32* get_RESP_PPT_STATUS_PPTCurrent(RESP_PPT_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+5),BYTE32_SIZE); }
inline void set_RESP_PPT_STATUS_PPTCurrent(RESP_PPT_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+5),(void*)&val,BYTE32_SIZE); return; }
#define RESP_PPT_STATUS_PPTCurrent(var) (*((BYTE32 *)(((char *)(&(var)))+5)))

/* RESP_PPT_STATUS_SCALING declaration - Status Response */
typedef struct {
	DOUBLE32 data[6];
} RESP_PPT_STATUS_SCALING;

#define RESP_PPT_STATUS_SCALING_SIZE 48
inline int sizeOfRESP_PPT_STATUS_SCALING() {return 48;}

/* PPU box temperature (THERM10) */
inline DOUBLE32* get_RESP_PPT_STATUS_SCALING_PPUTemp(RESP_PPT_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_PPT_STATUS_SCALING_PPUTemp(RESP_PPT_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PPT_STATUS_SCALING_PPUTemp(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* temperature for each PPT (in order, THERM19-22) */
inline DOUBLE32* get_RESP_PPT_STATUS_SCALING_PPTTemp(RESP_PPT_STATUS_SCALING* var) {return ((DOUBLE32*)((char*)var->data+8));}
inline void set_RESP_PPT_STATUS_SCALING_PPTTemp(RESP_PPT_STATUS_SCALING* var, DOUBLE32* val) { memcpy(((char*)var->data+8),val,32); }
inline void set_RESP_PPT_STATUS_SCALING_PPTTemp_ar(RESP_PPT_STATUS_SCALING* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+8))+index),val,DOUBLE32_SIZE); }
#define RESP_PPT_STATUS_SCALING_PPTTemp(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+8)+index))

/* current drawn by PPU or (when charging), charging cap */
inline DOUBLE32* get_RESP_PPT_STATUS_SCALING_PPTCurrent(RESP_PPT_STATUS_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_RESP_PPT_STATUS_SCALING_PPTCurrent(RESP_PPT_STATUS_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_PPT_STATUS_SCALING_PPTCurrent(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* RESP_STATUS declaration ALL response status codes, per Table 18 of the Comm ICD */
typedef struct {
	DOUBLE32 data[1];
} RESP_STATUS;

#define RESP_STATUS_SIZE 8
inline int sizeOfRESP_STATUS() {return 8;}

/*  */
inline BYTE32* get_RESP_STATUS_myStatus(RESP_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_STATUS_myStatus(RESP_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_STATUS_myStatus(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* RESP_ALL_STATUS declaration  */
typedef struct {
	DOUBLE32 data[2];
} RESP_ALL_STATUS;

#define RESP_ALL_STATUS_SIZE 16
inline int sizeOfRESP_ALL_STATUS() {return 16;}

/*  */
inline BYTE32* get_RESP_ALL_STATUS_CDHIB(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_CDHIB(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_CDHIB(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_CAMERA(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_CAMERA(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_CAMERA(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_GPS1(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_GPS1(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_GPS1(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_GPS2(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+3),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_GPS2(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+3),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_GPS2(var) (*((BYTE32 *)(((char *)(&(var)))+3)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_GPS3(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+4),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_GPS3(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+4),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_GPS3(var) (*((BYTE32 *)(((char *)(&(var)))+4)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_TC1(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+5),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_TC1(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+5),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_TC1(var) (*((BYTE32 *)(((char *)(&(var)))+5)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_TC2(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+6),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_TC2(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+6),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_TC2(var) (*((BYTE32 *)(((char *)(&(var)))+6)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_POWER(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+7),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_POWER(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+7),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_POWER(var) (*((BYTE32 *)(((char *)(&(var)))+7)))

/*  */
inline BYTE32* get_RESP_ALL_STATUS_PROPULSION(RESP_ALL_STATUS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+8),BYTE32_SIZE); }
inline void set_RESP_ALL_STATUS_PROPULSION(RESP_ALL_STATUS* var, BYTE32 val) { memcpy(((char*)var->data+8),(void*)&val,BYTE32_SIZE); return; }
#define RESP_ALL_STATUS_PROPULSION(var) (*((BYTE32 *)(((char *)(&(var)))+8)))

/* RESP_TELEM declaration ALL telemetry data to be used by all other subsystems */
typedef struct {
	DOUBLE32 data[1];
} RESP_TELEM;

#define RESP_TELEM_SIZE 8
inline int sizeOfRESP_TELEM() {return 8;}

/*  */
inline BYTE32* get_RESP_TELEM_Temp(RESP_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_TELEM_Temp(RESP_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TELEM_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RESP_TELEM_Volt(RESP_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_TELEM_Volt(RESP_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TELEM_Volt(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/*  */
inline BYTE32* get_RESP_TELEM_Current(RESP_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_TELEM_Current(RESP_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TELEM_Current(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/* RESP_TELEM_SCALING declaration - */
typedef struct {
	DOUBLE32 data[3];
} RESP_TELEM_SCALING;

#define RESP_TELEM_SCALING_SIZE 24
inline int sizeOfRESP_TELEM_SCALING() {return 24;}

/*  */
inline DOUBLE32* get_RESP_TELEM_SCALING_Temp(RESP_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_TELEM_SCALING_Temp(RESP_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TELEM_SCALING_Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/*  */
inline DOUBLE32* get_RESP_TELEM_SCALING_Volt(RESP_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_RESP_TELEM_SCALING_Volt(RESP_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TELEM_SCALING_Volt(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/*  */
inline DOUBLE32* get_RESP_TELEM_SCALING_Current(RESP_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_RESP_TELEM_SCALING_Current(RESP_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TELEM_SCALING_Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* RESP_CAM_TELEM declaration CAM telemetry data to be used by all other subsystems */
typedef struct {
	DOUBLE32 data[1];
} RESP_CAM_TELEM;

#define RESP_CAM_TELEM_SIZE 8
inline int sizeOfRESP_CAM_TELEM() {return 8;}

/*  */
inline BYTE32* get_RESP_CAM_TELEM_Temp(RESP_CAM_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_CAM_TELEM_Temp(RESP_CAM_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_CAM_TELEM_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RESP_CAM_TELEM_Volt(RESP_CAM_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_CAM_TELEM_Volt(RESP_CAM_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_CAM_TELEM_Volt(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/*  */
inline BYTE32* get_RESP_CAM_TELEM_Current(RESP_CAM_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_CAM_TELEM_Current(RESP_CAM_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_CAM_TELEM_Current(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/* RESP_CAM_TELEM_SCALING declaration - */
typedef struct {
	DOUBLE32 data[3];
} RESP_CAM_TELEM_SCALING;

#define RESP_CAM_TELEM_SCALING_SIZE 24
inline int sizeOfRESP_CAM_TELEM_SCALING() {return 24;}

/*  */
inline DOUBLE32* get_RESP_CAM_TELEM_SCALING_Temp(RESP_CAM_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_CAM_TELEM_SCALING_Temp(RESP_CAM_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_CAM_TELEM_SCALING_Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/*  */
inline DOUBLE32* get_RESP_CAM_TELEM_SCALING_Volt(RESP_CAM_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_RESP_CAM_TELEM_SCALING_Volt(RESP_CAM_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_CAM_TELEM_SCALING_Volt(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/*  */
inline DOUBLE32* get_RESP_CAM_TELEM_SCALING_Current(RESP_CAM_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_RESP_CAM_TELEM_SCALING_Current(RESP_CAM_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_CAM_TELEM_SCALING_Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* RESP_GPS_TELEM declaration GPS telemetry data for each GPS unit */
typedef struct {
	DOUBLE32 data[1];
} RESP_GPS_TELEM;

#define RESP_GPS_TELEM_SIZE 8
inline int sizeOfRESP_GPS_TELEM() {return 8;}

/* voltage read off the 3V line */
inline BYTE32* get_RESP_GPS_TELEM_Voltage_3(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_Voltage_3(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_Voltage_3(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* voltage read off the 5V line */
inline BYTE32* get_RESP_GPS_TELEM_Voltage_35(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_Voltage_35(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_Voltage_35(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/*  */
inline BYTE32* get_RESP_GPS_TELEM_Current(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_Current(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_Current(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/*  */
inline BYTE32* get_RESP_GPS_TELEM_Temp(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+3),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_Temp(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+3),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+3)))

/*  */
inline BYTE32* get_RESP_GPS_TELEM_lastCommand(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+4),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_lastCommand(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+4),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_lastCommand(var) (*((BYTE32 *)(((char *)(&(var)))+4)))

/*  */
inline BYTE32* get_RESP_GPS_TELEM_commandSuccess(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+5),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_commandSuccess(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+5),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_commandSuccess(var) (*((BYTE32 *)(((char *)(&(var)))+5)))

/*  */
inline BYTE32* get_RESP_GPS_TELEM_lastSat(RESP_GPS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+6),BYTE32_SIZE); }
inline void set_RESP_GPS_TELEM_lastSat(RESP_GPS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+6),(void*)&val,BYTE32_SIZE); return; }
#define RESP_GPS_TELEM_lastSat(var) (*((BYTE32 *)(((char *)(&(var)))+6)))

/* RESP_ALL_GPS_TELEM declaration GPS */
typedef struct {
	DOUBLE32 data[3];
} RESP_ALL_GPS_TELEM;

#define RESP_ALL_GPS_TELEM_SIZE 24
inline int sizeOfRESP_ALL_GPS_TELEM() {return 24;}

/*  */
inline RESP_GPS_TELEM* get_RESP_ALL_GPS_TELEM_GpsTelem(RESP_ALL_GPS_TELEM* var) {return ((RESP_GPS_TELEM*)((char*)var->data+0));}
inline void set_RESP_ALL_GPS_TELEM_GpsTelem(RESP_ALL_GPS_TELEM* var, RESP_GPS_TELEM* val) { memcpy(((char*)var->data+0),val,24); }
inline void set_RESP_ALL_GPS_TELEM_GpsTelem_ar(RESP_ALL_GPS_TELEM* var, RESP_GPS_TELEM* val, INT32 index) { memcpy((((RESP_GPS_TELEM*)((char*)var->data+0))+index),val,RESP_GPS_TELEM_SIZE); }
#define RESP_ALL_GPS_TELEM_GpsTelem(var,index) (*((RESP_GPS_TELEM *)(((char *)(&(var)))+0)+index))

/* RESP_GPS_TELEM_SCALING declaration - telemetry data for each GPS unit */
typedef struct {
	DOUBLE32 data[7];
} RESP_GPS_TELEM_SCALING;

#define RESP_GPS_TELEM_SCALING_SIZE 56
inline int sizeOfRESP_GPS_TELEM_SCALING() {return 56;}

/* voltage read off the 3V line */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_Voltage_3(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_Voltage_3(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_Voltage_3(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* voltage read off the 5V line */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_Voltage_35(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_Voltage_35(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_Voltage_35(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/*  */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_Current(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_Current(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_Current(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/*  */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_Temp(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_Temp(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/*  */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_lastCommand(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_lastCommand(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_lastCommand(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/*  */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_commandSuccess(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_commandSuccess(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_commandSuccess(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/*  */
inline DOUBLE32* get_RESP_GPS_TELEM_SCALING_lastSat(RESP_GPS_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+48),DOUBLE32_SIZE); }
inline void set_RESP_GPS_TELEM_SCALING_lastSat(RESP_GPS_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+48),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_GPS_TELEM_SCALING_lastSat(var) (*((DOUBLE32 *)(((char *)(&(var)))+48)))

/* RESP_TC_TELEM declaration TC telemetry data for T&C */
typedef struct {
	DOUBLE32 data[1];
} RESP_TC_TELEM;

#define RESP_TC_TELEM_SIZE 8
inline int sizeOfRESP_TC_TELEM() {return 8;}

/* voltage read off the 3.3V line */
inline BYTE32* get_RESP_TC_TELEM_Voltage_33(RESP_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RESP_TC_TELEM_Voltage_33(RESP_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TC_TELEM_Voltage_33(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* voltage read off the 6V line */
inline BYTE32* get_RESP_TC_TELEM_Voltage_6(RESP_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+1),BYTE32_SIZE); }
inline void set_RESP_TC_TELEM_Voltage_6(RESP_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TC_TELEM_Voltage_6(var) (*((BYTE32 *)(((char *)(&(var)))+1)))

/* voltage read off the 5V line */
inline BYTE32* get_RESP_TC_TELEM_Voltage_5(RESP_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_RESP_TC_TELEM_Voltage_5(RESP_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TC_TELEM_Voltage_5(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/* current drawn on the 6V rail */
inline BYTE32* get_RESP_TC_TELEM_Current_6V(RESP_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+3),BYTE32_SIZE); }
inline void set_RESP_TC_TELEM_Current_6V(RESP_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+3),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TC_TELEM_Current_6V(var) (*((BYTE32 *)(((char *)(&(var)))+3)))

/*  */
inline BYTE32* get_RESP_TC_TELEM_Temp(RESP_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+4),BYTE32_SIZE); }
inline void set_RESP_TC_TELEM_Temp(RESP_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+4),(void*)&val,BYTE32_SIZE); return; }
#define RESP_TC_TELEM_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+4)))

/* RESP_TC_TELEM_SCALING declaration - telemetry data for T&C */
typedef struct {
	DOUBLE32 data[5];
} RESP_TC_TELEM_SCALING;

#define RESP_TC_TELEM_SCALING_SIZE 40
inline int sizeOfRESP_TC_TELEM_SCALING() {return 40;}

/* voltage read off the 3.3V line */
inline DOUBLE32* get_RESP_TC_TELEM_SCALING_Voltage_33(RESP_TC_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_RESP_TC_TELEM_SCALING_Voltage_33(RESP_TC_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TC_TELEM_SCALING_Voltage_33(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* voltage read off the 6V line */
inline DOUBLE32* get_RESP_TC_TELEM_SCALING_Voltage_6(RESP_TC_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_RESP_TC_TELEM_SCALING_Voltage_6(RESP_TC_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TC_TELEM_SCALING_Voltage_6(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* voltage read off the 5V line */
inline DOUBLE32* get_RESP_TC_TELEM_SCALING_Voltage_5(RESP_TC_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_RESP_TC_TELEM_SCALING_Voltage_5(RESP_TC_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TC_TELEM_SCALING_Voltage_5(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* current drawn on the 6V rail */
inline DOUBLE32* get_RESP_TC_TELEM_SCALING_Current_6V(RESP_TC_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_RESP_TC_TELEM_SCALING_Current_6V(RESP_TC_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TC_TELEM_SCALING_Current_6V(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/*  */
inline DOUBLE32* get_RESP_TC_TELEM_SCALING_Temp(RESP_TC_TELEM_SCALING* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_RESP_TC_TELEM_SCALING_Temp(RESP_TC_TELEM_SCALING* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define RESP_TC_TELEM_SCALING_Temp(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* PLD_PWRX declaration ALL */
typedef struct {
	DOUBLE32 data[1];
} PLD_PWRX;

#define PLD_PWRX_SIZE 8
inline int sizeOfPLD_PWRX() {return 8;}

/* power element to control */
inline BYTE32* get_PLD_PWRX_x(PLD_PWRX* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_PLD_PWRX_x(PLD_PWRX* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define PLD_PWRX_x(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* MOMS_THS_PACKET declaration ADCNS */
typedef struct {
	DOUBLE32 data[1];
} MOMS_THS_PACKET;

#define MOMS_THS_PACKET_SIZE 8
inline int sizeOfMOMS_THS_PACKET() {return 8;}

/*  */
inline BYTE32* get_MOMS_THS_PACKET_vals(MOMS_THS_PACKET* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_MOMS_THS_PACKET_vals(MOMS_THS_PACKET* var, BYTE32* val) { memcpy(((char*)var->data+0),val,8); }
inline void set_MOMS_THS_PACKET_vals_ar(MOMS_THS_PACKET* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define MOMS_THS_PACKET_vals(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* CDGPS_VECTORS declaration ADCNS */
typedef struct {
	DOUBLE32 data[10];
} CDGPS_VECTORS;

#define CDGPS_VECTORS_SIZE 80
inline int sizeOfCDGPS_VECTORS() {return 80;}

/* Timestamp, mjd */
inline DOUBLE32* get_CDGPS_VECTORS_mjdTime(CDGPS_VECTORS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_CDGPS_VECTORS_mjdTime(CDGPS_VECTORS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_VECTORS_mjdTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* 3x1 CDGPS body vector from antenna 1 to antenna 2 */
inline FLOAT32* get_CDGPS_VECTORS_vec21(CDGPS_VECTORS* var) {return ((FLOAT32*)((char*)var->data+8));}
inline void set_CDGPS_VECTORS_vec21(CDGPS_VECTORS* var, FLOAT32* val) { memcpy(((char*)var->data+8),val,12); }
inline void set_CDGPS_VECTORS_vec21_ar(CDGPS_VECTORS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+8))+index),val,FLOAT32_SIZE); }
#define CDGPS_VECTORS_vec21(var,index) (*((FLOAT32 *)(((char *)(&(var)))+8)+index))

/* 3x1 CDGPS body vector from antenna 1 to antenna 3 */
inline FLOAT32* get_CDGPS_VECTORS_vec31(CDGPS_VECTORS* var) {return ((FLOAT32*)((char*)var->data+20));}
inline void set_CDGPS_VECTORS_vec31(CDGPS_VECTORS* var, FLOAT32* val) { memcpy(((char*)var->data+20),val,12); }
inline void set_CDGPS_VECTORS_vec31_ar(CDGPS_VECTORS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+20))+index),val,FLOAT32_SIZE); }
#define CDGPS_VECTORS_vec31(var,index) (*((FLOAT32 *)(((char *)(&(var)))+20)+index))

/* 3x1 CDGPS body vector from antenna 2 to antenna 3 */
inline FLOAT32* get_CDGPS_VECTORS_vec32(CDGPS_VECTORS* var) {return ((FLOAT32*)((char*)var->data+32));}
inline void set_CDGPS_VECTORS_vec32(CDGPS_VECTORS* var, FLOAT32* val) { memcpy(((char*)var->data+32),val,12); }
inline void set_CDGPS_VECTORS_vec32_ar(CDGPS_VECTORS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+32))+index),val,FLOAT32_SIZE); }
#define CDGPS_VECTORS_vec32(var,index) (*((FLOAT32 *)(((char *)(&(var)))+32)+index))

/* constant control torque at time of CDGPS measurements */
inline FLOAT32* get_CDGPS_VECTORS_Nc(CDGPS_VECTORS* var) {return ((FLOAT32*)((char*)var->data+44));}
inline void set_CDGPS_VECTORS_Nc(CDGPS_VECTORS* var, FLOAT32* val) { memcpy(((char*)var->data+44),val,12); }
inline void set_CDGPS_VECTORS_Nc_ar(CDGPS_VECTORS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+44))+index),val,FLOAT32_SIZE); }
#define CDGPS_VECTORS_Nc(var,index) (*((FLOAT32 *)(((char *)(&(var)))+44)+index))

/* Angular momentum vector of the WHEELS at time of CDGPS measurements */
inline FLOAT32* get_CDGPS_VECTORS_H(CDGPS_VECTORS* var) {return ((FLOAT32*)((char*)var->data+56));}
inline void set_CDGPS_VECTORS_H(CDGPS_VECTORS* var, FLOAT32* val) { memcpy(((char*)var->data+56),val,12); }
inline void set_CDGPS_VECTORS_H_ar(CDGPS_VECTORS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+56))+index),val,FLOAT32_SIZE); }
#define CDGPS_VECTORS_H(var,index) (*((FLOAT32 *)(((char *)(&(var)))+56)+index))

/* {enum CUCP_BOOLEAN} for vec21: 1 for valid GPS data, 0 for invalid GPS data */
inline BYTE32* get_CDGPS_VECTORS_valid_g21(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+68),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_valid_g21(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+68),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_valid_g21(var) (*((BYTE32 *)(((char *)(&(var)))+68)))

/* {enum CUCP_BOOLEAN} for vec31: 1 for valid GPS data, 0 for invalid GPS data */
inline BYTE32* get_CDGPS_VECTORS_valid_g31(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+69),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_valid_g31(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+69),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_valid_g31(var) (*((BYTE32 *)(((char *)(&(var)))+69)))

/* {enum CUCP_BOOLEAN} for vec32: 1 for valid GPS data, 0 for invalid GPS data */
inline BYTE32* get_CDGPS_VECTORS_valid_g32(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+70),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_valid_g32(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+70),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_valid_g32(var) (*((BYTE32 *)(((char *)(&(var)))+70)))

/* {enum CUCP_BOOLEAN} for vec21: 1 if the cdgps algorithm needs to be reset, 0 otherwise */
inline BYTE32* get_CDGPS_VECTORS_reset21(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+71),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_reset21(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+71),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_reset21(var) (*((BYTE32 *)(((char *)(&(var)))+71)))

/* {enum CUCP_BOOLEAN} for vec31: 1 if the cdgps algorithm needs to be reset, 0 otherwise */
inline BYTE32* get_CDGPS_VECTORS_reset31(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+72),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_reset31(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+72),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_reset31(var) (*((BYTE32 *)(((char *)(&(var)))+72)))

/* {enum CUCP_BOOLEAN} for vec32: 1 if the cdgps algorithm needs to be reset, 0 otherwise */
inline BYTE32* get_CDGPS_VECTORS_reset32(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+73),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_reset32(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+73),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_reset32(var) (*((BYTE32 *)(((char *)(&(var)))+73)))

/*  */
inline BYTE32* get_CDGPS_VECTORS_failedCounter21(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+74),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_failedCounter21(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+74),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_failedCounter21(var) (*((BYTE32 *)(((char *)(&(var)))+74)))

/*  */
inline BYTE32* get_CDGPS_VECTORS_failedCounter31(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+75),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_failedCounter31(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+75),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_failedCounter31(var) (*((BYTE32 *)(((char *)(&(var)))+75)))

/*  */
inline BYTE32* get_CDGPS_VECTORS_failedCounter32(CDGPS_VECTORS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+76),BYTE32_SIZE); }
inline void set_CDGPS_VECTORS_failedCounter32(CDGPS_VECTORS* var, BYTE32 val) { memcpy(((char*)var->data+76),(void*)&val,BYTE32_SIZE); return; }
#define CDGPS_VECTORS_failedCounter32(var) (*((BYTE32 *)(((char *)(&(var)))+76)))

/* PLD_TC_TELEM declaration TC */
typedef struct {
	DOUBLE32 data[36];
} PLD_TC_TELEM;

#define PLD_TC_TELEM_SIZE 288
inline int sizeOfPLD_TC_TELEM() {return 288;}

/* current sat time in mjd format */
inline DOUBLE32* get_PLD_TC_TELEM_mjdTime(PLD_TC_TELEM* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_PLD_TC_TELEM_mjdTime(PLD_TC_TELEM* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define PLD_TC_TELEM_mjdTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/*  */
inline RESP_PWR_ALL_STATUS* get_PLD_TC_TELEM_pwr(PLD_TC_TELEM* var, RESP_PWR_ALL_STATUS* toSet) { return (RESP_PWR_ALL_STATUS*)memcpy(toSet,(RESP_PWR_ALL_STATUS*)((char*)var->data+8),RESP_PWR_ALL_STATUS_SIZE); }
inline void set_PLD_TC_TELEM_pwr(PLD_TC_TELEM* var, RESP_PWR_ALL_STATUS val) { memcpy(((char*)var->data+8),(void*)&val,RESP_PWR_ALL_STATUS_SIZE); return; }
#define PLD_TC_TELEM_pwr(var) (*((RESP_PWR_ALL_STATUS *)(((char *)(&(var)))+8)))

/*  */
inline CDGPS_VECTORS* get_PLD_TC_TELEM_cdgps_vecs(PLD_TC_TELEM* var, CDGPS_VECTORS* toSet) { return (CDGPS_VECTORS*)memcpy(toSet,(CDGPS_VECTORS*)((char*)var->data+64),CDGPS_VECTORS_SIZE); }
inline void set_PLD_TC_TELEM_cdgps_vecs(PLD_TC_TELEM* var, CDGPS_VECTORS val) { memcpy(((char*)var->data+64),(void*)&val,CDGPS_VECTORS_SIZE); return; }
#define PLD_TC_TELEM_cdgps_vecs(var) (*((CDGPS_VECTORS *)(((char *)(&(var)))+64)))

/* moms state data to be downlinked */
inline MOMS_THS_PACKET* get_PLD_TC_TELEM_moms_data(PLD_TC_TELEM* var, MOMS_THS_PACKET* toSet) { return (MOMS_THS_PACKET*)memcpy(toSet,(MOMS_THS_PACKET*)((char*)var->data+144),MOMS_THS_PACKET_SIZE); }
inline void set_PLD_TC_TELEM_moms_data(PLD_TC_TELEM* var, MOMS_THS_PACKET val) { memcpy(((char*)var->data+144),(void*)&val,MOMS_THS_PACKET_SIZE); return; }
#define PLD_TC_TELEM_moms_data(var) (*((MOMS_THS_PACKET *)(((char *)(&(var)))+144)))

/* last valid gps reading x,v,mjd */
inline LAST_VALID_GPS* get_PLD_TC_TELEM_lastValidGps(PLD_TC_TELEM* var, LAST_VALID_GPS* toSet) { return (LAST_VALID_GPS*)memcpy(toSet,(LAST_VALID_GPS*)((char*)var->data+152),LAST_VALID_GPS_SIZE); }
inline void set_PLD_TC_TELEM_lastValidGps(PLD_TC_TELEM* var, LAST_VALID_GPS val) { memcpy(((char*)var->data+152),(void*)&val,LAST_VALID_GPS_SIZE); return; }
#define PLD_TC_TELEM_lastValidGps(var) (*((LAST_VALID_GPS *)(((char *)(&(var)))+152)))

/* KFATT estimated attitude quaternion */
inline FLOAT32* get_PLD_TC_TELEM_q(PLD_TC_TELEM* var) {return ((FLOAT32*)((char*)var->data+184));}
inline void set_PLD_TC_TELEM_q(PLD_TC_TELEM* var, FLOAT32* val) { memcpy(((char*)var->data+184),val,16); }
inline void set_PLD_TC_TELEM_q_ar(PLD_TC_TELEM* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+184))+index),val,FLOAT32_SIZE); }
#define PLD_TC_TELEM_q(var,index) (*((FLOAT32 *)(((char *)(&(var)))+184)+index))

/* KFATT estimated rates (x, y, z) */
inline FLOAT32* get_PLD_TC_TELEM_w(PLD_TC_TELEM* var) {return ((FLOAT32*)((char*)var->data+200));}
inline void set_PLD_TC_TELEM_w(PLD_TC_TELEM* var, FLOAT32* val) { memcpy(((char*)var->data+200),val,12); }
inline void set_PLD_TC_TELEM_w_ar(PLD_TC_TELEM* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+200))+index),val,FLOAT32_SIZE); }
#define PLD_TC_TELEM_w(var,index) (*((FLOAT32 *)(((char *)(&(var)))+200)+index))

/* Signed number of MS: (lastValidGps(mjdTime) - mjd_time_from_kfatt) */
inline INT32* get_PLD_TC_TELEM_dt_gps_kfatt(PLD_TC_TELEM* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+212),INT32_SIZE); }
inline void set_PLD_TC_TELEM_dt_gps_kfatt(PLD_TC_TELEM* var, INT32 val) { memcpy(((char*)var->data+212),(void*)&val,INT32_SIZE); return; }
#define PLD_TC_TELEM_dt_gps_kfatt(var) (*((INT32 *)(((char *)(&(var)))+212)))

/* Last NonTransac, Clear, or ExClear GSL Message ID received by the satellite (from sender GROUND) */
inline USHORT32* get_PLD_TC_TELEM_GSL_MsgID_Rcvd(PLD_TC_TELEM* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+216),USHORT32_SIZE); }
inline void set_PLD_TC_TELEM_GSL_MsgID_Rcvd(PLD_TC_TELEM* var, USHORT32 val) { memcpy(((char*)var->data+216),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TC_TELEM_GSL_MsgID_Rcvd(var) (*((USHORT32 *)(((char *)(&(var)))+216)))

/* Index of last logfile compressed (updated after .cu* created) */
inline USHORT32* get_PLD_TC_TELEM_LOG_Last_Index(PLD_TC_TELEM* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+218),USHORT32_SIZE); }
inline void set_PLD_TC_TELEM_LOG_Last_Index(PLD_TC_TELEM* var, USHORT32 val) { memcpy(((char*)var->data+218),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TC_TELEM_LOG_Last_Index(var) (*((USHORT32 *)(((char *)(&(var)))+218)))

/* Index of last Picture file written (updated after jp2 created) */
inline USHORT32* get_PLD_TC_TELEM_PIC_Last_Index(PLD_TC_TELEM* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+220),USHORT32_SIZE); }
inline void set_PLD_TC_TELEM_PIC_Last_Index(PLD_TC_TELEM* var, USHORT32 val) { memcpy(((char*)var->data+220),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TC_TELEM_PIC_Last_Index(var) (*((USHORT32 *)(((char *)(&(var)))+220)))

/* All subsystem statuses... */
inline BYTE32* get_PLD_TC_TELEM_STAT_CDHIB(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+222),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_CDHIB(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+222),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_CDHIB(var) (*((BYTE32 *)(((char *)(&(var)))+222)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_CAMERA(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+223),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_CAMERA(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+223),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_CAMERA(var) (*((BYTE32 *)(((char *)(&(var)))+223)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_GPS1(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+224),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_GPS1(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+224),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_GPS1(var) (*((BYTE32 *)(((char *)(&(var)))+224)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_GPS2(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+225),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_GPS2(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+225),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_GPS2(var) (*((BYTE32 *)(((char *)(&(var)))+225)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_GPS3(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+226),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_GPS3(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+226),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_GPS3(var) (*((BYTE32 *)(((char *)(&(var)))+226)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_TC1(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+227),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_TC1(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+227),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_TC1(var) (*((BYTE32 *)(((char *)(&(var)))+227)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_TC2(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+228),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_TC2(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+228),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_TC2(var) (*((BYTE32 *)(((char *)(&(var)))+228)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_POWER(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+229),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_POWER(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+229),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_POWER(var) (*((BYTE32 *)(((char *)(&(var)))+229)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_STAT_PROPULSION(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+230),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_STAT_PROPULSION(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+230),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_STAT_PROPULSION(var) (*((BYTE32 *)(((char *)(&(var)))+230)))

/* All PPT status... */
inline BYTE32* get_PLD_TC_TELEM_PPU_Temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+231),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_PPU_Temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+231),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_PPU_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+231)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_PPT_Temp(PLD_TC_TELEM* var) {return ((BYTE32*)((char*)var->data+232));}
inline void set_PLD_TC_TELEM_PPT_Temp(PLD_TC_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+232),val,4); }
inline void set_PLD_TC_TELEM_PPT_Temp_ar(PLD_TC_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+232))+index),val,BYTE32_SIZE); }
#define PLD_TC_TELEM_PPT_Temp(var,index) (*((BYTE32 *)(((char *)(&(var)))+232)+index))

/*  */
inline BYTE32* get_PLD_TC_TELEM_PPU_Curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+236),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_PPU_Curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+236),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_PPU_Curr(var) (*((BYTE32 *)(((char *)(&(var)))+236)))

/* All GPS status... */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_Volt3(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+237),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_Volt3(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+237),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_Volt3(var) (*((BYTE32 *)(((char *)(&(var)))+237)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_Volt35(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+238),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_Volt35(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+238),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_Volt35(var) (*((BYTE32 *)(((char *)(&(var)))+238)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_Curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+239),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_Curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+239),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_Curr(var) (*((BYTE32 *)(((char *)(&(var)))+239)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_Temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+240),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_Temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+240),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+240)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_lastCmd(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+241),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_lastCmd(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+241),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_lastCmd(var) (*((BYTE32 *)(((char *)(&(var)))+241)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_cmdSucc(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+242),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_cmdSucc(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+242),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_cmdSucc(var) (*((BYTE32 *)(((char *)(&(var)))+242)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_1_lastSat(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+243),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_1_lastSat(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+243),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_1_lastSat(var) (*((BYTE32 *)(((char *)(&(var)))+243)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_Volt3(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+244),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_Volt3(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+244),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_Volt3(var) (*((BYTE32 *)(((char *)(&(var)))+244)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_Volt35(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+245),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_Volt35(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+245),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_Volt35(var) (*((BYTE32 *)(((char *)(&(var)))+245)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_Curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+246),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_Curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+246),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_Curr(var) (*((BYTE32 *)(((char *)(&(var)))+246)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_Temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+247),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_Temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+247),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+247)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_lastCmd(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+248),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_lastCmd(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+248),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_lastCmd(var) (*((BYTE32 *)(((char *)(&(var)))+248)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_cmdSucc(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+249),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_cmdSucc(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+249),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_cmdSucc(var) (*((BYTE32 *)(((char *)(&(var)))+249)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_2_lastSat(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+250),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_2_lastSat(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+250),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_2_lastSat(var) (*((BYTE32 *)(((char *)(&(var)))+250)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_Volt3(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+251),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_Volt3(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+251),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_Volt3(var) (*((BYTE32 *)(((char *)(&(var)))+251)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_Volt35(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+252),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_Volt35(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+252),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_Volt35(var) (*((BYTE32 *)(((char *)(&(var)))+252)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_Curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+253),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_Curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+253),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_Curr(var) (*((BYTE32 *)(((char *)(&(var)))+253)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_Temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+254),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_Temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+254),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_Temp(var) (*((BYTE32 *)(((char *)(&(var)))+254)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_lastCmd(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+255),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_lastCmd(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+255),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_lastCmd(var) (*((BYTE32 *)(((char *)(&(var)))+255)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_cmdSucc(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+256),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_cmdSucc(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+256),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_cmdSucc(var) (*((BYTE32 *)(((char *)(&(var)))+256)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_GPS_3_lastSat(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+257),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_GPS_3_lastSat(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+257),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_GPS_3_lastSat(var) (*((BYTE32 *)(((char *)(&(var)))+257)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CDH_temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+258),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CDH_temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+258),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CDH_temp(var) (*((BYTE32 *)(((char *)(&(var)))+258)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CDH_volt(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+259),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CDH_volt(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+259),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CDH_volt(var) (*((BYTE32 *)(((char *)(&(var)))+259)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CDH_curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+260),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CDH_curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+260),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CDH_curr(var) (*((BYTE32 *)(((char *)(&(var)))+260)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CAM_temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+261),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CAM_temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+261),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CAM_temp(var) (*((BYTE32 *)(((char *)(&(var)))+261)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CAM_volt(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+262),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CAM_volt(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+262),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CAM_volt(var) (*((BYTE32 *)(((char *)(&(var)))+262)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_CAM_curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+263),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_CAM_curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+263),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_CAM_curr(var) (*((BYTE32 *)(((char *)(&(var)))+263)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_1_6V(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+264),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_1_6V(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+264),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_1_6V(var) (*((BYTE32 *)(((char *)(&(var)))+264)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_1_5V(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+265),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_1_5V(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+265),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_1_5V(var) (*((BYTE32 *)(((char *)(&(var)))+265)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_1_6V_curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+266),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_1_6V_curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+266),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_1_6V_curr(var) (*((BYTE32 *)(((char *)(&(var)))+266)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_1_temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+267),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_1_temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+267),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_1_temp(var) (*((BYTE32 *)(((char *)(&(var)))+267)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_2_6V(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+268),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_2_6V(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+268),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_2_6V(var) (*((BYTE32 *)(((char *)(&(var)))+268)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_2_5V(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+269),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_2_5V(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+269),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_2_5V(var) (*((BYTE32 *)(((char *)(&(var)))+269)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_2_6V_curr(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+270),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_2_6V_curr(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+270),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_2_6V_curr(var) (*((BYTE32 *)(((char *)(&(var)))+270)))

/*  */
inline BYTE32* get_PLD_TC_TELEM_TC_2_temp(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+271),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_TC_2_temp(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+271),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_TC_2_temp(var) (*((BYTE32 *)(((char *)(&(var)))+271)))

/* Flag for whether or not to use state estimate, 1 for yes, 0 for no */
inline BYTE32* get_PLD_TC_TELEM_useEstimateFlag(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+272),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_useEstimateFlag(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+272),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_useEstimateFlag(var) (*((BYTE32 *)(((char *)(&(var)))+272)))

/* current version info */
inline BYTE32* get_PLD_TC_TELEM_version(PLD_TC_TELEM* var) {return ((BYTE32*)((char*)var->data+273));}
inline void set_PLD_TC_TELEM_version(PLD_TC_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+273),val,14); }
inline void set_PLD_TC_TELEM_version_ar(PLD_TC_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+273))+index),val,BYTE32_SIZE); }
#define PLD_TC_TELEM_version(var,index) (*((BYTE32 *)(((char *)(&(var)))+273)+index))

/* which satellite this data is from */
inline BYTE32* get_PLD_TC_TELEM_satelliteID(PLD_TC_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+287),BYTE32_SIZE); }
inline void set_PLD_TC_TELEM_satelliteID(PLD_TC_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+287),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_TELEM_satelliteID(var) (*((BYTE32 *)(((char *)(&(var)))+287)))

/* RADIO_PACKET declaration - */
typedef struct {
	DOUBLE32 data[38];
} RADIO_PACKET;

#define RADIO_PACKET_SIZE 304
inline int sizeOfRADIO_PACKET() {return 304;}

/* 1 for a valid packet, 0 for empty struct */
inline BYTE32* get_RADIO_PACKET_isValid(RADIO_PACKET* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_RADIO_PACKET_isValid(RADIO_PACKET* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define RADIO_PACKET_isValid(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RADIO_PACKET_data(RADIO_PACKET* var) {return ((BYTE32*)((char*)var->data+1));}
inline void set_RADIO_PACKET_data(RADIO_PACKET* var, BYTE32* val) { memcpy(((char*)var->data+1),val,300); }
inline void set_RADIO_PACKET_data_ar(RADIO_PACKET* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+1))+index),val,BYTE32_SIZE); }
#define RADIO_PACKET_data(var,index) (*((BYTE32 *)(((char *)(&(var)))+1)+index))

/* sender, uses GSL_SENDER_GROUND or GSL_SENDER_CROSSLINK */
inline BYTE32* get_RADIO_PACKET_sender(RADIO_PACKET* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+301),BYTE32_SIZE); }
inline void set_RADIO_PACKET_sender(RADIO_PACKET* var, BYTE32 val) { memcpy(((char*)var->data+301),(void*)&val,BYTE32_SIZE); return; }
#define RADIO_PACKET_sender(var) (*((BYTE32 *)(((char *)(&(var)))+301)))

/* PLD_TC_CALLSIGN declaration - */
typedef struct {
	DOUBLE32 data[3];
} PLD_TC_CALLSIGN;

#define PLD_TC_CALLSIGN_SIZE 24
inline int sizeOfPLD_TC_CALLSIGN() {return 24;}

/*  */
inline BYTE32* get_PLD_TC_CALLSIGN_ground(PLD_TC_CALLSIGN* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_PLD_TC_CALLSIGN_ground(PLD_TC_CALLSIGN* var, BYTE32* val) { memcpy(((char*)var->data+0),val,7); }
inline void set_PLD_TC_CALLSIGN_ground_ar(PLD_TC_CALLSIGN* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define PLD_TC_CALLSIGN_ground(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/*  */
inline BYTE32* get_PLD_TC_CALLSIGN_cross(PLD_TC_CALLSIGN* var) {return ((BYTE32*)((char*)var->data+7));}
inline void set_PLD_TC_CALLSIGN_cross(PLD_TC_CALLSIGN* var, BYTE32* val) { memcpy(((char*)var->data+7),val,7); }
inline void set_PLD_TC_CALLSIGN_cross_ar(PLD_TC_CALLSIGN* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+7))+index),val,BYTE32_SIZE); }
#define PLD_TC_CALLSIGN_cross(var,index) (*((BYTE32 *)(((char *)(&(var)))+7)+index))

/*  */
inline BYTE32* get_PLD_TC_CALLSIGN_mine(PLD_TC_CALLSIGN* var) {return ((BYTE32*)((char*)var->data+14));}
inline void set_PLD_TC_CALLSIGN_mine(PLD_TC_CALLSIGN* var, BYTE32* val) { memcpy(((char*)var->data+14),val,7); }
inline void set_PLD_TC_CALLSIGN_mine_ar(PLD_TC_CALLSIGN* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+14))+index),val,BYTE32_SIZE); }
#define PLD_TC_CALLSIGN_mine(var,index) (*((BYTE32 *)(((char *)(&(var)))+14)+index))

/* PLD_TC_FREQUENCY declaration - */
typedef struct {
	DOUBLE32 data[2];
} PLD_TC_FREQUENCY;

#define PLD_TC_FREQUENCY_SIZE 16
inline int sizeOfPLD_TC_FREQUENCY() {return 16;}

/*  */
inline BYTE32* get_PLD_TC_FREQUENCY_frequency(PLD_TC_FREQUENCY* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_PLD_TC_FREQUENCY_frequency(PLD_TC_FREQUENCY* var, BYTE32* val) { memcpy(((char*)var->data+0),val,14); }
inline void set_PLD_TC_FREQUENCY_frequency_ar(PLD_TC_FREQUENCY* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define PLD_TC_FREQUENCY_frequency(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* PLD_TC_POWER_LEVEL declaration - */
typedef struct {
	DOUBLE32 data[1];
} PLD_TC_POWER_LEVEL;

#define PLD_TC_POWER_LEVEL_SIZE 8
inline int sizeOfPLD_TC_POWER_LEVEL() {return 8;}

/* 0 through 5, refer to CUSAT-D-TC-001 appendix */
inline BYTE32* get_PLD_TC_POWER_LEVEL_level(PLD_TC_POWER_LEVEL* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_PLD_TC_POWER_LEVEL_level(PLD_TC_POWER_LEVEL* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_POWER_LEVEL_level(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* PLD_TC_SQUELCH_LEVEL declaration - */
typedef struct {
	DOUBLE32 data[1];
} PLD_TC_SQUELCH_LEVEL;

#define PLD_TC_SQUELCH_LEVEL_SIZE 8
inline int sizeOfPLD_TC_SQUELCH_LEVEL() {return 8;}

/* 0 through 5, refer to CUSAT-D-TC-001 appendix */
inline BYTE32* get_PLD_TC_SQUELCH_LEVEL_level(PLD_TC_SQUELCH_LEVEL* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_PLD_TC_SQUELCH_LEVEL_level(PLD_TC_SQUELCH_LEVEL* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define PLD_TC_SQUELCH_LEVEL_level(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* PLD_TC_BEACON_INTERVAL declaration - */
typedef struct {
	DOUBLE32 data[1];
} PLD_TC_BEACON_INTERVAL;

#define PLD_TC_BEACON_INTERVAL_SIZE 8
inline int sizeOfPLD_TC_BEACON_INTERVAL() {return 8;}

/* interval in seconds between THS beacons, zero means off */
inline USHORT32* get_PLD_TC_BEACON_INTERVAL_interval(PLD_TC_BEACON_INTERVAL* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+0),USHORT32_SIZE); }
inline void set_PLD_TC_BEACON_INTERVAL_interval(PLD_TC_BEACON_INTERVAL* var, USHORT32 val) { memcpy(((char*)var->data+0),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TC_BEACON_INTERVAL_interval(var) (*((USHORT32 *)(((char *)(&(var)))+0)))

/* RESP_TC_GET_CMD declaration - */
typedef struct {
	DOUBLE32 data[38];
} RESP_TC_GET_CMD;

#define RESP_TC_GET_CMD_SIZE 304
inline int sizeOfRESP_TC_GET_CMD() {return 304;}

/* Packet from antenna. */
inline BYTE32* get_RESP_TC_GET_CMD_data(RESP_TC_GET_CMD* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_RESP_TC_GET_CMD_data(RESP_TC_GET_CMD* var, BYTE32* val) { memcpy(((char*)var->data+0),val,300); }
inline void set_RESP_TC_GET_CMD_data_ar(RESP_TC_GET_CMD* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define RESP_TC_GET_CMD_data(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* IMI_DATA declaration - */
typedef struct {
	DOUBLE32 data[3];
} IMI_DATA;

#define IMI_DATA_SIZE 24
inline int sizeOfIMI_DATA() {return 24;}

/* must be bytepacked according to the Comm ICD */
inline BYTE32* get_IMI_DATA_response(IMI_DATA* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_IMI_DATA_response(IMI_DATA* var, BYTE32* val) { memcpy(((char*)var->data+0),val,23); }
inline void set_IMI_DATA_response_ar(IMI_DATA* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define IMI_DATA_response(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* PLD_TAKE_PICTURE declaration - payload for instructing the camera to take a picture */
typedef struct {
	DOUBLE32 data[1];
} PLD_TAKE_PICTURE;

#define PLD_TAKE_PICTURE_SIZE 8
inline int sizeOfPLD_TAKE_PICTURE() {return 8;}

/* x coordinate to begin ROI */
inline USHORT32* get_PLD_TAKE_PICTURE_start_x(PLD_TAKE_PICTURE* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+0),USHORT32_SIZE); }
inline void set_PLD_TAKE_PICTURE_start_x(PLD_TAKE_PICTURE* var, USHORT32 val) { memcpy(((char*)var->data+0),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TAKE_PICTURE_start_x(var) (*((USHORT32 *)(((char *)(&(var)))+0)))

/* y coordinate to begin ROI */
inline USHORT32* get_PLD_TAKE_PICTURE_start_y(PLD_TAKE_PICTURE* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+2),USHORT32_SIZE); }
inline void set_PLD_TAKE_PICTURE_start_y(PLD_TAKE_PICTURE* var, USHORT32 val) { memcpy(((char*)var->data+2),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TAKE_PICTURE_start_y(var) (*((USHORT32 *)(((char *)(&(var)))+2)))

/* width of ROI */
inline USHORT32* get_PLD_TAKE_PICTURE_width(PLD_TAKE_PICTURE* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+4),USHORT32_SIZE); }
inline void set_PLD_TAKE_PICTURE_width(PLD_TAKE_PICTURE* var, USHORT32 val) { memcpy(((char*)var->data+4),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TAKE_PICTURE_width(var) (*((USHORT32 *)(((char *)(&(var)))+4)))

/* height of ROI */
inline USHORT32* get_PLD_TAKE_PICTURE_height(PLD_TAKE_PICTURE* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+6),USHORT32_SIZE); }
inline void set_PLD_TAKE_PICTURE_height(PLD_TAKE_PICTURE* var, USHORT32 val) { memcpy(((char*)var->data+6),(void*)&val,USHORT32_SIZE); return; }
#define PLD_TAKE_PICTURE_height(var) (*((USHORT32 *)(((char *)(&(var)))+6)))

/* PLD_CAM_SWITCH_CAM declaration - tells which camera to switch to for a switch cam command */
typedef struct {
	DOUBLE32 data[1];
} PLD_CAM_SWITCH_CAM;

#define PLD_CAM_SWITCH_CAM_SIZE 8
inline int sizeOfPLD_CAM_SWITCH_CAM() {return 8;}

/* 1 for cam 1, 2 for cam 2, ignored otherwise */
inline BYTE32* get_PLD_CAM_SWITCH_CAM_camera(PLD_CAM_SWITCH_CAM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+0),BYTE32_SIZE); }
inline void set_PLD_CAM_SWITCH_CAM_camera(PLD_CAM_SWITCH_CAM* var, BYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CAM_SWITCH_CAM_camera(var) (*((BYTE32 *)(((char *)(&(var)))+0)))

/* PLD_CAM_COMMAND declaration - Commands for the camera */
typedef struct {
	DOUBLE32 data[32];
} PLD_CAM_COMMAND;

#define PLD_CAM_COMMAND_SIZE 256
inline int sizeOfPLD_CAM_COMMAND() {return 256;}

/* length of string to send in the payload data (max = 254) */
inline UBYTE32* get_PLD_CAM_COMMAND_pldLen(PLD_CAM_COMMAND* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+0),UBYTE32_SIZE); }
inline void set_PLD_CAM_COMMAND_pldLen(PLD_CAM_COMMAND* var, UBYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,UBYTE32_SIZE); return; }
#define PLD_CAM_COMMAND_pldLen(var) (*((UBYTE32 *)(((char *)(&(var)))+0)))

/* length of response to send */
inline UBYTE32* get_PLD_CAM_COMMAND_respLen(PLD_CAM_COMMAND* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+1),UBYTE32_SIZE); }
inline void set_PLD_CAM_COMMAND_respLen(PLD_CAM_COMMAND* var, UBYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,UBYTE32_SIZE); return; }
#define PLD_CAM_COMMAND_respLen(var) (*((UBYTE32 *)(((char *)(&(var)))+1)))

/* payload data */
inline BYTE32* get_PLD_CAM_COMMAND_payload(PLD_CAM_COMMAND* var) {return ((BYTE32*)((char*)var->data+2));}
inline void set_PLD_CAM_COMMAND_payload(PLD_CAM_COMMAND* var, BYTE32* val) { memcpy(((char*)var->data+2),val,254); }
inline void set_PLD_CAM_COMMAND_payload_ar(PLD_CAM_COMMAND* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+2))+index),val,BYTE32_SIZE); }
#define PLD_CAM_COMMAND_payload(var,index) (*((BYTE32 *)(((char *)(&(var)))+2)+index))

/* RESP_CAM_COMMAND declaration - Command response from the camera */
typedef struct {
	DOUBLE32 data[32];
} RESP_CAM_COMMAND;

#define RESP_CAM_COMMAND_SIZE 256
inline int sizeOfRESP_CAM_COMMAND() {return 256;}

/*  */
inline BYTE32* get_RESP_CAM_COMMAND_response(RESP_CAM_COMMAND* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_RESP_CAM_COMMAND_response(RESP_CAM_COMMAND* var, BYTE32* val) { memcpy(((char*)var->data+0),val,256); }
inline void set_RESP_CAM_COMMAND_response_ar(RESP_CAM_COMMAND* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define RESP_CAM_COMMAND_response(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* RESP_IMG_CHUNK declaration - Img Chunk Response, used for retrieving parts of images */
typedef struct {
	DOUBLE32 data[129];
} RESP_IMG_CHUNK;

#define RESP_IMG_CHUNK_SIZE 1032
inline int sizeOfRESP_IMG_CHUNK() {return 1032;}

/*  */
inline INT32* get_RESP_IMG_CHUNK_count(RESP_IMG_CHUNK* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+0),INT32_SIZE); }
inline void set_RESP_IMG_CHUNK_count(RESP_IMG_CHUNK* var, INT32 val) { memcpy(((char*)var->data+0),(void*)&val,INT32_SIZE); return; }
#define RESP_IMG_CHUNK_count(var) (*((INT32 *)(((char *)(&(var)))+0)))

/*  */
inline BYTE32* get_RESP_IMG_CHUNK_chunk(RESP_IMG_CHUNK* var) {return ((BYTE32*)((char*)var->data+4));}
inline void set_RESP_IMG_CHUNK_chunk(RESP_IMG_CHUNK* var, BYTE32* val) { memcpy(((char*)var->data+4),val,1024); }
inline void set_RESP_IMG_CHUNK_chunk_ar(RESP_IMG_CHUNK* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+4))+index),val,BYTE32_SIZE); }
#define RESP_IMG_CHUNK_chunk(var,index) (*((BYTE32 *)(((char *)(&(var)))+4)+index))

/* RESP_GPS_DATA declaration GPS GPS Data Response, see gps structs further down for clarification */
typedef struct {
	DOUBLE32 data[87];
} RESP_GPS_DATA;

#define RESP_GPS_DATA_SIZE 696
inline int sizeOfRESP_GPS_DATA() {return 696;}

/*  */
inline sentenceF00* get_RESP_GPS_DATA_f1(RESP_GPS_DATA* var, sentenceF00* toSet) { return (sentenceF00*)memcpy(toSet,(sentenceF00*)((char*)var->data+0),SENTENCEF00_SIZE); }
inline void set_RESP_GPS_DATA_f1(RESP_GPS_DATA* var, sentenceF00 val) { memcpy(((char*)var->data+0),(void*)&val,SENTENCEF00_SIZE); return; }
#define RESP_GPS_DATA_f1(var) (*((sentenceF00 *)(((char *)(&(var)))+0)))

/*  */
inline sentenceF03* get_RESP_GPS_DATA_f2(RESP_GPS_DATA* var, sentenceF03* toSet) { return (sentenceF03*)memcpy(toSet,(sentenceF03*)((char*)var->data+72),SENTENCEF03_SIZE); }
inline void set_RESP_GPS_DATA_f2(RESP_GPS_DATA* var, sentenceF03 val) { memcpy(((char*)var->data+72),(void*)&val,SENTENCEF03_SIZE); return; }
#define RESP_GPS_DATA_f2(var) (*((sentenceF03 *)(((char *)(&(var)))+72)))

/*  */
inline sentenceF18* get_RESP_GPS_DATA_f3(RESP_GPS_DATA* var, sentenceF18* toSet) { return (sentenceF18*)memcpy(toSet,(sentenceF18*)((char*)var->data+288),SENTENCEF18_SIZE); }
inline void set_RESP_GPS_DATA_f3(RESP_GPS_DATA* var, sentenceF18 val) { memcpy(((char*)var->data+288),(void*)&val,SENTENCEF18_SIZE); return; }
#define RESP_GPS_DATA_f3(var) (*((sentenceF18 *)(((char *)(&(var)))+288)))

/*  */
inline sentenceF22* get_RESP_GPS_DATA_f4(RESP_GPS_DATA* var, sentenceF22* toSet) { return (sentenceF22*)memcpy(toSet,(sentenceF22*)((char*)var->data+480),SENTENCEF22_SIZE); }
inline void set_RESP_GPS_DATA_f4(RESP_GPS_DATA* var, sentenceF22 val) { memcpy(((char*)var->data+480),(void*)&val,SENTENCEF22_SIZE); return; }
#define RESP_GPS_DATA_f4(var) (*((sentenceF22 *)(((char *)(&(var)))+480)))

/*  */
inline sentenceF23* get_RESP_GPS_DATA_f5(RESP_GPS_DATA* var, sentenceF23* toSet) { return (sentenceF23*)memcpy(toSet,(sentenceF23*)((char*)var->data+600),SENTENCEF23_SIZE); }
inline void set_RESP_GPS_DATA_f5(RESP_GPS_DATA* var, sentenceF23 val) { memcpy(((char*)var->data+600),(void*)&val,SENTENCEF23_SIZE); return; }
#define RESP_GPS_DATA_f5(var) (*((sentenceF23 *)(((char *)(&(var)))+600)))

/* CROSS_GPS_DATA declaration GPS GPS data, KFATT and other data necessary for crosslink */
typedef struct {
	DOUBLE32 data[61];
} CROSS_GPS_DATA;

#define CROSS_GPS_DATA_SIZE 488
inline int sizeOfCROSS_GPS_DATA() {return 488;}

/*  */
inline sentenceF00* get_CROSS_GPS_DATA_f1(CROSS_GPS_DATA* var, sentenceF00* toSet) { return (sentenceF00*)memcpy(toSet,(sentenceF00*)((char*)var->data+0),SENTENCEF00_SIZE); }
inline void set_CROSS_GPS_DATA_f1(CROSS_GPS_DATA* var, sentenceF00 val) { memcpy(((char*)var->data+0),(void*)&val,SENTENCEF00_SIZE); return; }
#define CROSS_GPS_DATA_f1(var) (*((sentenceF00 *)(((char *)(&(var)))+0)))

/*  */
inline sentenceF03* get_CROSS_GPS_DATA_f2(CROSS_GPS_DATA* var, sentenceF03* toSet) { return (sentenceF03*)memcpy(toSet,(sentenceF03*)((char*)var->data+72),SENTENCEF03_SIZE); }
inline void set_CROSS_GPS_DATA_f2(CROSS_GPS_DATA* var, sentenceF03 val) { memcpy(((char*)var->data+72),(void*)&val,SENTENCEF03_SIZE); return; }
#define CROSS_GPS_DATA_f2(var) (*((sentenceF03 *)(((char *)(&(var)))+72)))

/*  */
inline sentenceF18* get_CROSS_GPS_DATA_f3(CROSS_GPS_DATA* var, sentenceF18* toSet) { return (sentenceF18*)memcpy(toSet,(sentenceF18*)((char*)var->data+288),SENTENCEF18_SIZE); }
inline void set_CROSS_GPS_DATA_f3(CROSS_GPS_DATA* var, sentenceF18 val) { memcpy(((char*)var->data+288),(void*)&val,SENTENCEF18_SIZE); return; }
#define CROSS_GPS_DATA_f3(var) (*((sentenceF18 *)(((char *)(&(var)))+288)))

/* 1 if T&C has already given this data before to CDH */
inline BYTE32* get_CROSS_GPS_DATA_isNew(CROSS_GPS_DATA* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+480),BYTE32_SIZE); }
inline void set_CROSS_GPS_DATA_isNew(CROSS_GPS_DATA* var, BYTE32 val) { memcpy(((char*)var->data+480),(void*)&val,BYTE32_SIZE); return; }
#define CROSS_GPS_DATA_isNew(var) (*((BYTE32 *)(((char *)(&(var)))+480)))

/* PLD_CROSS_DATA1 declaration GPS Packet 1 of 3 containing GPS data for remote satellite */
typedef struct {
	DOUBLE32 data[35];
} PLD_CROSS_DATA1;

#define PLD_CROSS_DATA1_SIZE 280
inline int sizeOfPLD_CROSS_DATA1() {return 280;}

/*  */
inline sentenceF00* get_PLD_CROSS_DATA1_f00(PLD_CROSS_DATA1* var, sentenceF00* toSet) { return (sentenceF00*)memcpy(toSet,(sentenceF00*)((char*)var->data+0),SENTENCEF00_SIZE); }
inline void set_PLD_CROSS_DATA1_f00(PLD_CROSS_DATA1* var, sentenceF00 val) { memcpy(((char*)var->data+0),(void*)&val,SENTENCEF00_SIZE); return; }
#define PLD_CROSS_DATA1_f00(var) (*((sentenceF00 *)(((char *)(&(var)))+0)))

/*  */
inline sentenceF18* get_PLD_CROSS_DATA1_f18(PLD_CROSS_DATA1* var, sentenceF18* toSet) { return (sentenceF18*)memcpy(toSet,(sentenceF18*)((char*)var->data+72),SENTENCEF18_SIZE); }
inline void set_PLD_CROSS_DATA1_f18(PLD_CROSS_DATA1* var, sentenceF18 val) { memcpy(((char*)var->data+72),(void*)&val,SENTENCEF18_SIZE); return; }
#define PLD_CROSS_DATA1_f18(var) (*((sentenceF18 *)(((char *)(&(var)))+72)))

/* Timestamp of data */
inline DOUBLE32* get_PLD_CROSS_DATA1_gpsTime(PLD_CROSS_DATA1* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+264),DOUBLE32_SIZE); }
inline void set_PLD_CROSS_DATA1_gpsTime(PLD_CROSS_DATA1* var, DOUBLE32 val) { memcpy(((char*)var->data+264),(void*)&val,DOUBLE32_SIZE); return; }
#define PLD_CROSS_DATA1_gpsTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+264)))

/*  */
inline BYTE32* get_PLD_CROSS_DATA1_isNew(PLD_CROSS_DATA1* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+272),BYTE32_SIZE); }
inline void set_PLD_CROSS_DATA1_isNew(PLD_CROSS_DATA1* var, BYTE32 val) { memcpy(((char*)var->data+272),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CROSS_DATA1_isNew(var) (*((BYTE32 *)(((char *)(&(var)))+272)))

/* Receiver that this packet was sent from */
inline BYTE32* get_PLD_CROSS_DATA1_rcvr(PLD_CROSS_DATA1* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+273),BYTE32_SIZE); }
inline void set_PLD_CROSS_DATA1_rcvr(PLD_CROSS_DATA1* var, BYTE32 val) { memcpy(((char*)var->data+273),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CROSS_DATA1_rcvr(var) (*((BYTE32 *)(((char *)(&(var)))+273)))

/* PLD_CROSS_DATA2 declaration GPS Packet 2 of 3 containing GPS data for remote satellite */
typedef struct {
	DOUBLE32 data[29];
} PLD_CROSS_DATA2;

#define PLD_CROSS_DATA2_SIZE 232
inline int sizeOfPLD_CROSS_DATA2() {return 232;}

/*  */
inline sentenceF03* get_PLD_CROSS_DATA2_f03(PLD_CROSS_DATA2* var, sentenceF03* toSet) { return (sentenceF03*)memcpy(toSet,(sentenceF03*)((char*)var->data+0),SENTENCEF03_SIZE); }
inline void set_PLD_CROSS_DATA2_f03(PLD_CROSS_DATA2* var, sentenceF03 val) { memcpy(((char*)var->data+0),(void*)&val,SENTENCEF03_SIZE); return; }
#define PLD_CROSS_DATA2_f03(var) (*((sentenceF03 *)(((char *)(&(var)))+0)))

/* Timestamp of data */
inline DOUBLE32* get_PLD_CROSS_DATA2_gpsTime(PLD_CROSS_DATA2* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+216),DOUBLE32_SIZE); }
inline void set_PLD_CROSS_DATA2_gpsTime(PLD_CROSS_DATA2* var, DOUBLE32 val) { memcpy(((char*)var->data+216),(void*)&val,DOUBLE32_SIZE); return; }
#define PLD_CROSS_DATA2_gpsTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+216)))

/*  */
inline BYTE32* get_PLD_CROSS_DATA2_isNew(PLD_CROSS_DATA2* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+224),BYTE32_SIZE); }
inline void set_PLD_CROSS_DATA2_isNew(PLD_CROSS_DATA2* var, BYTE32 val) { memcpy(((char*)var->data+224),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CROSS_DATA2_isNew(var) (*((BYTE32 *)(((char *)(&(var)))+224)))

/* Receiver that this packet was sent from */
inline BYTE32* get_PLD_CROSS_DATA2_rcvr(PLD_CROSS_DATA2* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+225),BYTE32_SIZE); }
inline void set_PLD_CROSS_DATA2_rcvr(PLD_CROSS_DATA2* var, BYTE32 val) { memcpy(((char*)var->data+225),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CROSS_DATA2_rcvr(var) (*((BYTE32 *)(((char *)(&(var)))+225)))

/* PLD_CROSS_DATA3 declaration GPS Packet 3 of 3 containing GPS data for remote satellite */
typedef struct {
	DOUBLE32 data[29];
} PLD_CROSS_DATA3;

#define PLD_CROSS_DATA3_SIZE 232
inline int sizeOfPLD_CROSS_DATA3() {return 232;}

/*  */
inline sentenceF22* get_PLD_CROSS_DATA3_f22(PLD_CROSS_DATA3* var, sentenceF22* toSet) { return (sentenceF22*)memcpy(toSet,(sentenceF22*)((char*)var->data+0),SENTENCEF22_SIZE); }
inline void set_PLD_CROSS_DATA3_f22(PLD_CROSS_DATA3* var, sentenceF22 val) { memcpy(((char*)var->data+0),(void*)&val,SENTENCEF22_SIZE); return; }
#define PLD_CROSS_DATA3_f22(var) (*((sentenceF22 *)(((char *)(&(var)))+0)))

/*  */
inline sentenceF23* get_PLD_CROSS_DATA3_f23(PLD_CROSS_DATA3* var, sentenceF23* toSet) { return (sentenceF23*)memcpy(toSet,(sentenceF23*)((char*)var->data+120),SENTENCEF23_SIZE); }
inline void set_PLD_CROSS_DATA3_f23(PLD_CROSS_DATA3* var, sentenceF23 val) { memcpy(((char*)var->data+120),(void*)&val,SENTENCEF23_SIZE); return; }
#define PLD_CROSS_DATA3_f23(var) (*((sentenceF23 *)(((char *)(&(var)))+120)))

/* Timestamp of data */
inline DOUBLE32* get_PLD_CROSS_DATA3_gpsTime(PLD_CROSS_DATA3* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+216),DOUBLE32_SIZE); }
inline void set_PLD_CROSS_DATA3_gpsTime(PLD_CROSS_DATA3* var, DOUBLE32 val) { memcpy(((char*)var->data+216),(void*)&val,DOUBLE32_SIZE); return; }
#define PLD_CROSS_DATA3_gpsTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+216)))

/*  */
inline BYTE32* get_PLD_CROSS_DATA3_isNew(PLD_CROSS_DATA3* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+224),BYTE32_SIZE); }
inline void set_PLD_CROSS_DATA3_isNew(PLD_CROSS_DATA3* var, BYTE32 val) { memcpy(((char*)var->data+224),(void*)&val,BYTE32_SIZE); return; }
#define PLD_CROSS_DATA3_isNew(var) (*((BYTE32 *)(((char *)(&(var)))+224)))

/* PRESS_GPS_DATA declaration GPS Data from GPS. See GPS structs for more clarification */
typedef struct {
	DOUBLE32 data[504];
} PRESS_GPS_DATA;

#define PRESS_GPS_DATA_SIZE 4032
inline int sizeOfPRESS_GPS_DATA() {return 4032;}

/*  */
inline sentenceF22* get_PRESS_GPS_DATA_ff4(PRESS_GPS_DATA* var) {return ((sentenceF22*)((char*)var->data+0));}
inline void set_PRESS_GPS_DATA_ff4(PRESS_GPS_DATA* var, sentenceF22* val) { memcpy(((char*)var->data+0),val,3840); }
inline void set_PRESS_GPS_DATA_ff4_ar(PRESS_GPS_DATA* var, sentenceF22* val, INT32 index) { memcpy((((sentenceF22*)((char*)var->data+0))+index),val,SENTENCEF22_SIZE); }
#define PRESS_GPS_DATA_ff4(var,index) (*((sentenceF22 *)(((char *)(&(var)))+0)+index))

/*  */
inline sentenceF23* get_PRESS_GPS_DATA_ff5(PRESS_GPS_DATA* var, sentenceF23* toSet) { return (sentenceF23*)memcpy(toSet,(sentenceF23*)((char*)var->data+3840),SENTENCEF23_SIZE); }
inline void set_PRESS_GPS_DATA_ff5(PRESS_GPS_DATA* var, sentenceF23 val) { memcpy(((char*)var->data+3840),(void*)&val,SENTENCEF23_SIZE); return; }
#define PRESS_GPS_DATA_ff5(var) (*((sentenceF23 *)(((char *)(&(var)))+3840)))

/*  */
inline sentenceF24* get_PRESS_GPS_DATA_ff6(PRESS_GPS_DATA* var, sentenceF24* toSet) { return (sentenceF24*)memcpy(toSet,(sentenceF24*)((char*)var->data+3936),SENTENCEF24_SIZE); }
inline void set_PRESS_GPS_DATA_ff6(PRESS_GPS_DATA* var, sentenceF24 val) { memcpy(((char*)var->data+3936),(void*)&val,SENTENCEF24_SIZE); return; }
#define PRESS_GPS_DATA_ff6(var) (*((sentenceF24 *)(((char *)(&(var)))+3936)))

/* PLD_PROP_FIRE declaration PROP Payload sent along with NET_CMD_PROP_FIRE_PPT command */
typedef struct {
	DOUBLE32 data[1];
} PLD_PROP_FIRE;

#define PLD_PROP_FIRE_SIZE 8
inline int sizeOfPLD_PROP_FIRE() {return 8;}

/* Amount of time to allow for charging (in 10s of milliseconds) */
inline SHORT32* get_PLD_PROP_FIRE_charge_time(PLD_PROP_FIRE* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+0),SHORT32_SIZE); }
inline void set_PLD_PROP_FIRE_charge_time(PLD_PROP_FIRE* var, SHORT32 val) { memcpy(((char*)var->data+0),(void*)&val,SHORT32_SIZE); return; }
#define PLD_PROP_FIRE_charge_time(var) (*((SHORT32 *)(((char *)(&(var)))+0)))

/* Some or'd combination of PPT_THRUSTERS constants specifying which nozzle(s) to fire */
inline BYTE32* get_PLD_PROP_FIRE_ppt(PLD_PROP_FIRE* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+2),BYTE32_SIZE); }
inline void set_PLD_PROP_FIRE_ppt(PLD_PROP_FIRE* var, BYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,BYTE32_SIZE); return; }
#define PLD_PROP_FIRE_ppt(var) (*((BYTE32 *)(((char *)(&(var)))+2)))

/* PLD_PROP_SEQUENCE declaration PROP Payload sent along with NET_CMD_PROP_SEQ_FIRE command */
typedef struct {
	DOUBLE32 data[32];
} PLD_PROP_SEQUENCE;

#define PLD_PROP_SEQUENCE_SIZE 256
inline int sizeOfPLD_PROP_SEQUENCE() {return 256;}

/* Weird array thing */
inline BYTE32* get_PLD_PROP_SEQUENCE_sequence(PLD_PROP_SEQUENCE* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_PLD_PROP_SEQUENCE_sequence(PLD_PROP_SEQUENCE* var, BYTE32* val) { memcpy(((char*)var->data+0),val,256); }
inline void set_PLD_PROP_SEQUENCE_sequence_ar(PLD_PROP_SEQUENCE* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define PLD_PROP_SEQUENCE_sequence(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* PLD_PROP_WARMUP declaration PROP */
typedef struct {
	DOUBLE32 data[1];
} PLD_PROP_WARMUP;

#define PLD_PROP_WARMUP_SIZE 8
inline int sizeOfPLD_PROP_WARMUP() {return 8;}

/* How much time to spend warming up */
inline INT32* get_PLD_PROP_WARMUP_time(PLD_PROP_WARMUP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+0),INT32_SIZE); }
inline void set_PLD_PROP_WARMUP_time(PLD_PROP_WARMUP* var, INT32 val) { memcpy(((char*)var->data+0),(void*)&val,INT32_SIZE); return; }
#define PLD_PROP_WARMUP_time(var) (*((INT32 *)(((char *)(&(var)))+0)))

/* How many times to fire */
inline INT32* get_PLD_PROP_WARMUP_firings(PLD_PROP_WARMUP* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+4),INT32_SIZE); }
inline void set_PLD_PROP_WARMUP_firings(PLD_PROP_WARMUP* var, INT32 val) { memcpy(((char*)var->data+4),(void*)&val,INT32_SIZE); return; }
#define PLD_PROP_WARMUP_firings(var) (*((INT32 *)(((char *)(&(var)))+4)))

/* REPROGRAM_PAGE declaration - datatype for MCU reprogramming payload; 1 page of data at a time is sent to the MCU */
typedef struct {
	DOUBLE32 data[32];
} REPROGRAM_PAGE;

#define REPROGRAM_PAGE_SIZE 256
inline int sizeOfREPROGRAM_PAGE() {return 256;}

/*  */
inline BYTE32* get_REPROGRAM_PAGE_page(REPROGRAM_PAGE* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_REPROGRAM_PAGE_page(REPROGRAM_PAGE* var, BYTE32* val) { memcpy(((char*)var->data+0),val,256); }
inline void set_REPROGRAM_PAGE_page_ar(REPROGRAM_PAGE* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define REPROGRAM_PAGE_page(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* GSL_CUCP_COMMAND declaration - DO NOT CHANGE THIS STRUCT WITHOUT CHECKING THAT DATA IS STILL THE LAST FIELD */
typedef struct {
	DOUBLE32 data[2];
} GSL_CUCP_COMMAND;

#define GSL_CUCP_COMMAND_SIZE 16
inline int sizeOfGSL_CUCP_COMMAND() {return 16;}

/*  */
inline INT32* get_GSL_CUCP_COMMAND_outLength(GSL_CUCP_COMMAND* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+0),INT32_SIZE); }
inline void set_GSL_CUCP_COMMAND_outLength(GSL_CUCP_COMMAND* var, INT32 val) { memcpy(((char*)var->data+0),(void*)&val,INT32_SIZE); return; }
#define GSL_CUCP_COMMAND_outLength(var) (*((INT32 *)(((char *)(&(var)))+0)))

/*  */
inline INT32* get_GSL_CUCP_COMMAND_payloadLen(GSL_CUCP_COMMAND* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+4),INT32_SIZE); }
inline void set_GSL_CUCP_COMMAND_payloadLen(GSL_CUCP_COMMAND* var, INT32 val) { memcpy(((char*)var->data+4),(void*)&val,INT32_SIZE); return; }
#define GSL_CUCP_COMMAND_payloadLen(var) (*((INT32 *)(((char *)(&(var)))+4)))

/* {enum NETWORK_ADDRESSES} */
inline BYTE32* get_GSL_CUCP_COMMAND_addr(GSL_CUCP_COMMAND* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+8),BYTE32_SIZE); }
inline void set_GSL_CUCP_COMMAND_addr(GSL_CUCP_COMMAND* var, BYTE32 val) { memcpy(((char*)var->data+8),(void*)&val,BYTE32_SIZE); return; }
#define GSL_CUCP_COMMAND_addr(var) (*((BYTE32 *)(((char *)(&(var)))+8)))

/* {enum CUCP_CMDS} */
inline BYTE32* get_GSL_CUCP_COMMAND_cmd(GSL_CUCP_COMMAND* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+9),BYTE32_SIZE); }
inline void set_GSL_CUCP_COMMAND_cmd(GSL_CUCP_COMMAND* var, BYTE32 val) { memcpy(((char*)var->data+9),(void*)&val,BYTE32_SIZE); return; }
#define GSL_CUCP_COMMAND_cmd(var) (*((BYTE32 *)(((char *)(&(var)))+9)))

/* GSL response type */
inline BYTE32* get_GSL_CUCP_COMMAND_responseType(GSL_CUCP_COMMAND* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+10),BYTE32_SIZE); }
inline void set_GSL_CUCP_COMMAND_responseType(GSL_CUCP_COMMAND* var, BYTE32 val) { memcpy(((char*)var->data+10),(void*)&val,BYTE32_SIZE); return; }
#define GSL_CUCP_COMMAND_responseType(var) (*((BYTE32 *)(((char *)(&(var)))+10)))

/* first element of data field, use &data for array */
inline BYTE32* get_GSL_CUCP_COMMAND_data(GSL_CUCP_COMMAND* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+11),BYTE32_SIZE); }
inline void set_GSL_CUCP_COMMAND_data(GSL_CUCP_COMMAND* var, BYTE32 val) { memcpy(((char*)var->data+11),(void*)&val,BYTE32_SIZE); return; }
#define GSL_CUCP_COMMAND_data(var) (*((BYTE32 *)(((char *)(&(var)))+11)))

/* CDGPS_PARAMS declaration ADCNS */
typedef struct {
	DOUBLE32 data[12];
} CDGPS_PARAMS;

#define CDGPS_PARAMS_SIZE 96
inline int sizeOfCDGPS_PARAMS() {return 96;}

/* the difference in mjds timetags which are "equal" */
inline DOUBLE32* get_CDGPS_PARAMS_k_time_offset_max(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_k_time_offset_max(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_k_time_offset_max(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* minimum time between solutions */
inline DOUBLE32* get_CDGPS_PARAMS_k_min_time_btw_solns(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_k_min_time_btw_solns(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_k_min_time_btw_solns(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* how close measurement times need to be to be "equal" */
inline DOUBLE32* get_CDGPS_PARAMS_measTimeEqTol(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_measTimeEqTol(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_measTimeEqTol(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* if the last measurement is this far back, reset cdgps */
inline DOUBLE32* get_CDGPS_PARAMS_measOldResetTime(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_measOldResetTime(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_measOldResetTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* if the last measurement for multi-body is this far back, reset cdgps **new */
inline DOUBLE32* get_CDGPS_PARAMS_multiMeasOldResetTime(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_multiMeasOldResetTime(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_multiMeasOldResetTime(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* the difference in mjds timetags which are "equal" for multi-body **new */
inline DOUBLE32* get_CDGPS_PARAMS_multik_time_offset_max(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_multik_time_offset_max(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_multik_time_offset_max(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* minimum time between solutions for multi-body **new */
inline DOUBLE32* get_CDGPS_PARAMS_multik_min_time_btw_solns(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+48),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_multik_min_time_btw_solns(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+48),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_multik_min_time_btw_solns(var) (*((DOUBLE32 *)(((char *)(&(var)))+48)))

/* tolerance for convergence between two multi-body vectors */
inline DOUBLE32* get_CDGPS_PARAMS_multiBaselineTol(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+56),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_multiBaselineTol(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+56),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_multiBaselineTol(var) (*((DOUBLE32 *)(((char *)(&(var)))+56)))

/* tolerance for angle between two multi-body vectors */
inline DOUBLE32* get_CDGPS_PARAMS_multiAngleTol(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+64),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_multiAngleTol(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+64),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_multiAngleTol(var) (*((DOUBLE32 *)(((char *)(&(var)))+64)))

/* allowable MJD time difference for 2 successive crosslink packets from same timestep */
inline DOUBLE32* get_CDGPS_PARAMS_pktTimeDiff(CDGPS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+72),DOUBLE32_SIZE); }
inline void set_CDGPS_PARAMS_pktTimeDiff(CDGPS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+72),(void*)&val,DOUBLE32_SIZE); return; }
#define CDGPS_PARAMS_pktTimeDiff(var) (*((DOUBLE32 *)(((char *)(&(var)))+72)))

/* if the onboard baseline is this long, it will reset the cdgps algorithm */
inline FLOAT32* get_CDGPS_PARAMS_onboardBaselineNormResetTol(CDGPS_PARAMS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+80),FLOAT32_SIZE); }
inline void set_CDGPS_PARAMS_onboardBaselineNormResetTol(CDGPS_PARAMS* var, FLOAT32 val) { memcpy(((char*)var->data+80),(void*)&val,FLOAT32_SIZE); return; }
#define CDGPS_PARAMS_onboardBaselineNormResetTol(var) (*((FLOAT32 *)(((char *)(&(var)))+80)))

/* how close the baseline magnitude needs to be considered valid */
inline FLOAT32* get_CDGPS_PARAMS_baselineNormTol(CDGPS_PARAMS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+84),FLOAT32_SIZE); }
inline void set_CDGPS_PARAMS_baselineNormTol(CDGPS_PARAMS* var, FLOAT32 val) { memcpy(((char*)var->data+84),(void*)&val,FLOAT32_SIZE); return; }
#define CDGPS_PARAMS_baselineNormTol(var) (*((FLOAT32 *)(((char *)(&(var)))+84)))

/* sleep length */
inline INT32* get_CDGPS_PARAMS_cdgpsThreadSleep(CDGPS_PARAMS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+88),INT32_SIZE); }
inline void set_CDGPS_PARAMS_cdgpsThreadSleep(CDGPS_PARAMS* var, INT32 val) { memcpy(((char*)var->data+88),(void*)&val,INT32_SIZE); return; }
#define CDGPS_PARAMS_cdgpsThreadSleep(var) (*((INT32 *)(((char *)(&(var)))+88)))

/* KFATT_ESTIMATE declaration ADCNS */
typedef struct {
	DOUBLE32 data[26];
} KFATT_ESTIMATE;

#define KFATT_ESTIMATE_SIZE 208
inline int sizeOfKFATT_ESTIMATE() {return 208;}

/* Time of the KFATT estimate */
inline DOUBLE32* get_KFATT_ESTIMATE_timeOfEst(KFATT_ESTIMATE* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_KFATT_ESTIMATE_timeOfEst(KFATT_ESTIMATE* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define KFATT_ESTIMATE_timeOfEst(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* Time of previous call */
inline DOUBLE32* get_KFATT_ESTIMATE_previousT(KFATT_ESTIMATE* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_KFATT_ESTIMATE_previousT(KFATT_ESTIMATE* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define KFATT_ESTIMATE_previousT(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* Time of last estimate made w/ measurements (not a propagation) */
inline DOUBLE32* get_KFATT_ESTIMATE_timeOfLastEstwMeas(KFATT_ESTIMATE* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_KFATT_ESTIMATE_timeOfLastEstwMeas(KFATT_ESTIMATE* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define KFATT_ESTIMATE_timeOfLastEstwMeas(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* KFATT estimated attitude quaternion */
inline FLOAT32* get_KFATT_ESTIMATE_q(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+24));}
inline void set_KFATT_ESTIMATE_q(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+24),val,16); }
inline void set_KFATT_ESTIMATE_q_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+24))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_q(var,index) (*((FLOAT32 *)(((char *)(&(var)))+24)+index))

/* KFATT estimated rates (x, y, z) */
inline FLOAT32* get_KFATT_ESTIMATE_w(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+40));}
inline void set_KFATT_ESTIMATE_w(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+40),val,12); }
inline void set_KFATT_ESTIMATE_w_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+40))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_w(var,index) (*((FLOAT32 *)(((char *)(&(var)))+40)+index))

/* KFATT estimated disturbance torques (x, y, z) */
inline FLOAT32* get_KFATT_ESTIMATE_Nd(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+52));}
inline void set_KFATT_ESTIMATE_Nd(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+52),val,12); }
inline void set_KFATT_ESTIMATE_Nd_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+52))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_Nd(var,index) (*((FLOAT32 *)(((char *)(&(var)))+52)+index))

/* Diagonal components of the filtered covariance matrix */
inline FLOAT32* get_KFATT_ESTIMATE_CovDiag(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+64));}
inline void set_KFATT_ESTIMATE_CovDiag(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+64),val,36); }
inline void set_KFATT_ESTIMATE_CovDiag_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+64))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_CovDiag(var,index) (*((FLOAT32 *)(((char *)(&(var)))+64)+index))

/* Diagonal components of the predicted covariance matrix */
inline FLOAT32* get_KFATT_ESTIMATE_PredictCovDiag(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+100));}
inline void set_KFATT_ESTIMATE_PredictCovDiag(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+100),val,36); }
inline void set_KFATT_ESTIMATE_PredictCovDiag_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+100))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_PredictCovDiag(var,index) (*((FLOAT32 *)(((char *)(&(var)))+100)+index))

/* Predicted attitude quaternion */
inline FLOAT32* get_KFATT_ESTIMATE_qPredict(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+136));}
inline void set_KFATT_ESTIMATE_qPredict(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+136),val,16); }
inline void set_KFATT_ESTIMATE_qPredict_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+136))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_qPredict(var,index) (*((FLOAT32 *)(((char *)(&(var)))+136)+index))

/* Predicted rates */
inline FLOAT32* get_KFATT_ESTIMATE_wPredict(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+152));}
inline void set_KFATT_ESTIMATE_wPredict(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+152),val,12); }
inline void set_KFATT_ESTIMATE_wPredict_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+152))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_wPredict(var,index) (*((FLOAT32 *)(((char *)(&(var)))+152)+index))

/* Estimate residual vector */
inline FLOAT32* get_KFATT_ESTIMATE_wholeRes(KFATT_ESTIMATE* var) {return ((FLOAT32*)((char*)var->data+164));}
inline void set_KFATT_ESTIMATE_wholeRes(KFATT_ESTIMATE* var, FLOAT32* val) { memcpy(((char*)var->data+164),val,36); }
inline void set_KFATT_ESTIMATE_wholeRes_ar(KFATT_ESTIMATE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+164))+index),val,FLOAT32_SIZE); }
#define KFATT_ESTIMATE_wholeRes(var,index) (*((FLOAT32 *)(((char *)(&(var)))+164)+index))

/* Norm of current estimate residual */
inline FLOAT32* get_KFATT_ESTIMATE_residual(KFATT_ESTIMATE* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+200),FLOAT32_SIZE); }
inline void set_KFATT_ESTIMATE_residual(KFATT_ESTIMATE* var, FLOAT32 val) { memcpy(((char*)var->data+200),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_ESTIMATE_residual(var) (*((FLOAT32 *)(((char *)(&(var)))+200)))

/* Current state of attitude estimator */
inline BYTE32* get_KFATT_ESTIMATE_kfattState(KFATT_ESTIMATE* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+204),BYTE32_SIZE); }
inline void set_KFATT_ESTIMATE_kfattState(KFATT_ESTIMATE* var, BYTE32 val) { memcpy(((char*)var->data+204),(void*)&val,BYTE32_SIZE); return; }
#define KFATT_ESTIMATE_kfattState(var) (*((BYTE32 *)(((char *)(&(var)))+204)))

/* Flag for whether or not to use state estimate, 1 for yes, 0 for no */
inline BYTE32* get_KFATT_ESTIMATE_useEstimateFlag(KFATT_ESTIMATE* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+205),BYTE32_SIZE); }
inline void set_KFATT_ESTIMATE_useEstimateFlag(KFATT_ESTIMATE* var, BYTE32 val) { memcpy(((char*)var->data+205),(void*)&val,BYTE32_SIZE); return; }
#define KFATT_ESTIMATE_useEstimateFlag(var) (*((BYTE32 *)(((char *)(&(var)))+205)))

/* ADCNS_PHYS_CONSTS declaration ADCNS */
typedef struct {
	DOUBLE32 data[45];
} ADCNS_PHYS_CONSTS;

#define ADCNS_PHYS_CONSTS_SIZE 360
inline int sizeOfADCNS_PHYS_CONSTS() {return 360;}

/* 3x3 top spacecraft inertia matrix (kg*m^2), read row by row (top to bottom) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_InertiaTop(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_ADCNS_PHYS_CONSTS_InertiaTop(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,72); }
inline void set_ADCNS_PHYS_CONSTS_InertiaTop_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_InertiaTop(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* 3x3 bottom spacecraft inertia matrix (kg*m^2), read row by row (top to bottom) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_InertiaBottom(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+72));}
inline void set_ADCNS_PHYS_CONSTS_InertiaBottom(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+72),val,72); }
inline void set_ADCNS_PHYS_CONSTS_InertiaBottom_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+72))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_InertiaBottom(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+72)+index))

/* 3x3 stacked spacecraft inertia matrix (kg*m^2), read row by row (top to bottom) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_InertiaStacked(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+144));}
inline void set_ADCNS_PHYS_CONSTS_InertiaStacked(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+144),val,72); }
inline void set_ADCNS_PHYS_CONSTS_InertiaStacked_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+144))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_InertiaStacked(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+144)+index))

/* astronomical constant for earth */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_mu(ADCNS_PHYS_CONSTS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+216),DOUBLE32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_mu(ADCNS_PHYS_CONSTS* var, DOUBLE32 val) { memcpy(((char*)var->data+216),(void*)&val,DOUBLE32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_mu(var) (*((DOUBLE32 *)(((char *)(&(var)))+216)))

/* mass of satellite (kg) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_mass_sat(ADCNS_PHYS_CONSTS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+224),DOUBLE32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_mass_sat(ADCNS_PHYS_CONSTS* var, DOUBLE32 val) { memcpy(((char*)var->data+224),(void*)&val,DOUBLE32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_mass_sat(var) (*((DOUBLE32 *)(((char *)(&(var)))+224)))

/* 3x1 top spacecraft center of mass (meters) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_r_com_top(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+232));}
inline void set_ADCNS_PHYS_CONSTS_r_com_top(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+232),val,24); }
inline void set_ADCNS_PHYS_CONSTS_r_com_top_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+232))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_r_com_top(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+232)+index))

/* 3x1 bottom spacecraft center of mass (meters) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_r_com_bot(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+256));}
inline void set_ADCNS_PHYS_CONSTS_r_com_bot(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+256),val,24); }
inline void set_ADCNS_PHYS_CONSTS_r_com_bot_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+256))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_r_com_bot(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+256)+index))

/* 3x1 stacked spacecraft center of mass (meters) */
inline DOUBLE32* get_ADCNS_PHYS_CONSTS_r_com_stacked(ADCNS_PHYS_CONSTS* var) {return ((DOUBLE32*)((char*)var->data+280));}
inline void set_ADCNS_PHYS_CONSTS_r_com_stacked(ADCNS_PHYS_CONSTS* var, DOUBLE32* val) { memcpy(((char*)var->data+280),val,24); }
inline void set_ADCNS_PHYS_CONSTS_r_com_stacked_ar(ADCNS_PHYS_CONSTS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+280))+index),val,DOUBLE32_SIZE); }
#define ADCNS_PHYS_CONSTS_r_com_stacked(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+280)+index))

/* g21 body reference vector (meters) */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g21_body(ADCNS_PHYS_CONSTS* var) {return ((FLOAT32*)((char*)var->data+304));}
inline void set_ADCNS_PHYS_CONSTS_g21_body(ADCNS_PHYS_CONSTS* var, FLOAT32* val) { memcpy(((char*)var->data+304),val,12); }
inline void set_ADCNS_PHYS_CONSTS_g21_body_ar(ADCNS_PHYS_CONSTS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+304))+index),val,FLOAT32_SIZE); }
#define ADCNS_PHYS_CONSTS_g21_body(var,index) (*((FLOAT32 *)(((char *)(&(var)))+304)+index))

/* g31 body reference vector (meters) */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g31_body(ADCNS_PHYS_CONSTS* var) {return ((FLOAT32*)((char*)var->data+316));}
inline void set_ADCNS_PHYS_CONSTS_g31_body(ADCNS_PHYS_CONSTS* var, FLOAT32* val) { memcpy(((char*)var->data+316),val,12); }
inline void set_ADCNS_PHYS_CONSTS_g31_body_ar(ADCNS_PHYS_CONSTS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+316))+index),val,FLOAT32_SIZE); }
#define ADCNS_PHYS_CONSTS_g31_body(var,index) (*((FLOAT32 *)(((char *)(&(var)))+316)+index))

/* g32 body reference vector (meters) */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g32_body(ADCNS_PHYS_CONSTS* var) {return ((FLOAT32*)((char*)var->data+328));}
inline void set_ADCNS_PHYS_CONSTS_g32_body(ADCNS_PHYS_CONSTS* var, FLOAT32* val) { memcpy(((char*)var->data+328),val,12); }
inline void set_ADCNS_PHYS_CONSTS_g32_body_ar(ADCNS_PHYS_CONSTS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+328))+index),val,FLOAT32_SIZE); }
#define ADCNS_PHYS_CONSTS_g32_body(var,index) (*((FLOAT32 *)(((char *)(&(var)))+328)+index))

/* norm of the g21 body vector */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g21_norm(ADCNS_PHYS_CONSTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+340),FLOAT32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_g21_norm(ADCNS_PHYS_CONSTS* var, FLOAT32 val) { memcpy(((char*)var->data+340),(void*)&val,FLOAT32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_g21_norm(var) (*((FLOAT32 *)(((char *)(&(var)))+340)))

/* norm of the g31 body vector */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g31_norm(ADCNS_PHYS_CONSTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+344),FLOAT32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_g31_norm(ADCNS_PHYS_CONSTS* var, FLOAT32 val) { memcpy(((char*)var->data+344),(void*)&val,FLOAT32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_g31_norm(var) (*((FLOAT32 *)(((char *)(&(var)))+344)))

/* norm of the g32 body vector */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_g32_norm(ADCNS_PHYS_CONSTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+348),FLOAT32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_g32_norm(ADCNS_PHYS_CONSTS* var, FLOAT32 val) { memcpy(((char*)var->data+348),(void*)&val,FLOAT32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_g32_norm(var) (*((FLOAT32 *)(((char *)(&(var)))+348)))

/* inertia of each wheel (kg*m^2) */
inline FLOAT32* get_ADCNS_PHYS_CONSTS_wheel_inertia(ADCNS_PHYS_CONSTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+352),FLOAT32_SIZE); }
inline void set_ADCNS_PHYS_CONSTS_wheel_inertia(ADCNS_PHYS_CONSTS* var, FLOAT32 val) { memcpy(((char*)var->data+352),(void*)&val,FLOAT32_SIZE); return; }
#define ADCNS_PHYS_CONSTS_wheel_inertia(var) (*((FLOAT32 *)(((char *)(&(var)))+352)))

/* KFATT_CONSTANTS declaration ADCNS */
typedef struct {
	DOUBLE32 data[9];
} KFATT_CONSTANTS;

#define KFATT_CONSTANTS_SIZE 72
inline int sizeOfKFATT_CONSTANTS() {return 72;}

/* Intended Delay of CDGPS measurements */
inline DOUBLE32* get_KFATT_CONSTANTS_IntendedDelay(KFATT_CONSTANTS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_KFATT_CONSTANTS_IntendedDelay(KFATT_CONSTANTS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define KFATT_CONSTANTS_IntendedDelay(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* Process noise constant for attitude and rate */
inline FLOAT32* get_KFATT_CONSTANTS_nqwProcessNoise(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+8),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_nqwProcessNoise(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+8),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_nqwProcessNoise(var) (*((FLOAT32 *)(((char *)(&(var)))+8)))

/* Process noise constant for disturbance torques */
inline FLOAT32* get_KFATT_CONSTANTS_nNdProcessNoise(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+12),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_nNdProcessNoise(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+12),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_nNdProcessNoise(var) (*((FLOAT32 *)(((char *)(&(var)))+12)))

/* Measurement noise constant for CDGPS */
inline FLOAT32* get_KFATT_CONSTANTS_cdgpsAngleError(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+16),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_cdgpsAngleError(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+16),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_cdgpsAngleError(var) (*((FLOAT32 *)(((char *)(&(var)))+16)))

/* Initial covariance of attitude quaternions */
inline FLOAT32* get_KFATT_CONSTANTS_PKinitialQ(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+20),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_PKinitialQ(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+20),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_PKinitialQ(var) (*((FLOAT32 *)(((char *)(&(var)))+20)))

/* Initial covariance of rate */
inline FLOAT32* get_KFATT_CONSTANTS_PKinitialW(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+24),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_PKinitialW(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+24),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_PKinitialW(var) (*((FLOAT32 *)(((char *)(&(var)))+24)))

/* Initial covariance of disturbance torques */
inline FLOAT32* get_KFATT_CONSTANTS_PKinitialND(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+28),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_PKinitialND(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+28),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_PKinitialND(var) (*((FLOAT32 *)(((char *)(&(var)))+28)))

/* Propagation integration step size */
inline FLOAT32* get_KFATT_CONSTANTS_IntStepSize(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+32),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_IntStepSize(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+32),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_IntStepSize(var) (*((FLOAT32 *)(((char *)(&(var)))+32)))

/* Integration length */
inline FLOAT32* get_KFATT_CONSTANTS_DefaultDeltaT(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+36),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_DefaultDeltaT(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+36),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_DefaultDeltaT(var) (*((FLOAT32 *)(((char *)(&(var)))+36)))

/* Filter residual count limit */
inline INT32* get_KFATT_CONSTANTS_ResidualCountLimit(KFATT_CONSTANTS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+40),INT32_SIZE); }
inline void set_KFATT_CONSTANTS_ResidualCountLimit(KFATT_CONSTANTS* var, INT32 val) { memcpy(((char*)var->data+40),(void*)&val,INT32_SIZE); return; }
#define KFATT_CONSTANTS_ResidualCountLimit(var) (*((INT32 *)(((char *)(&(var)))+40)))

/* Maximum residual for convergence */
inline FLOAT32* get_KFATT_CONSTANTS_MaximumResidual(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+44),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_MaximumResidual(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+44),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_MaximumResidual(var) (*((FLOAT32 *)(((char *)(&(var)))+44)))

/* Maximum covariance trace used for resetting */
inline FLOAT32* get_KFATT_CONSTANTS_MaxCovarianceTrace(KFATT_CONSTANTS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+48),FLOAT32_SIZE); }
inline void set_KFATT_CONSTANTS_MaxCovarianceTrace(KFATT_CONSTANTS* var, FLOAT32 val) { memcpy(((char*)var->data+48),(void*)&val,FLOAT32_SIZE); return; }
#define KFATT_CONSTANTS_MaxCovarianceTrace(var) (*((FLOAT32 *)(((char *)(&(var)))+48)))

/* Maximum wait time for setting previousT */
inline INT32* get_KFATT_CONSTANTS_MaxWaitTime(KFATT_CONSTANTS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+52),INT32_SIZE); }
inline void set_KFATT_CONSTANTS_MaxWaitTime(KFATT_CONSTANTS* var, INT32 val) { memcpy(((char*)var->data+52),(void*)&val,INT32_SIZE); return; }
#define KFATT_CONSTANTS_MaxWaitTime(var) (*((INT32 *)(((char *)(&(var)))+52)))

/* A priori estimate of the spin rate */
inline FLOAT32* get_KFATT_CONSTANTS_initialW(KFATT_CONSTANTS* var) {return ((FLOAT32*)((char*)var->data+56));}
inline void set_KFATT_CONSTANTS_initialW(KFATT_CONSTANTS* var, FLOAT32* val) { memcpy(((char*)var->data+56),val,12); }
inline void set_KFATT_CONSTANTS_initialW_ar(KFATT_CONSTANTS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+56))+index),val,FLOAT32_SIZE); }
#define KFATT_CONSTANTS_initialW(var,index) (*((FLOAT32 *)(((char *)(&(var)))+56)+index))

/* GenPar declaration ADCNS */
typedef struct {
	DOUBLE32 data[25];
} GenPar;

#define GENPAR_SIZE 200
inline int sizeOfGenPar() {return 200;}

/* surface area of local sat */
inline DOUBLE32* get_GenPar_localSurfaceArea(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_GenPar_localSurfaceArea(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_localSurfaceArea(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* mass of local sat */
inline DOUBLE32* get_GenPar_localMass(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_GenPar_localMass(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_localMass(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* drag coefficient of local sat */
inline DOUBLE32* get_GenPar_localDragCoeff(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_GenPar_localDragCoeff(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_localDragCoeff(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* surface area of remote sat */
inline DOUBLE32* get_GenPar_remoteSurfaceArea(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_GenPar_remoteSurfaceArea(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_remoteSurfaceArea(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* mass of remote sat */
inline DOUBLE32* get_GenPar_remoteMass(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_GenPar_remoteMass(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_remoteMass(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* drag coefficient of remote sat */
inline DOUBLE32* get_GenPar_remoteDragCoeff(GenPar* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+40),DOUBLE32_SIZE); }
inline void set_GenPar_remoteDragCoeff(GenPar* var, DOUBLE32 val) { memcpy(((char*)var->data+40),(void*)&val,DOUBLE32_SIZE); return; }
#define GenPar_remoteDragCoeff(var) (*((DOUBLE32 *)(((char *)(&(var)))+40)))

/* top satellite antenna offsets */
inline DOUBLE32* get_GenPar_TOP_ANT_OFFSET(GenPar* var) {return ((DOUBLE32*)((char*)var->data+48));}
inline void set_GenPar_TOP_ANT_OFFSET(GenPar* var, DOUBLE32* val) { memcpy(((char*)var->data+48),val,72); }
inline void set_GenPar_TOP_ANT_OFFSET_ar(GenPar* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+48))+index),val,DOUBLE32_SIZE); }
#define GenPar_TOP_ANT_OFFSET(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+48)+index))

/* bottom satellite antenna offsets */
inline DOUBLE32* get_GenPar_BOT_ANT_OFFSET(GenPar* var) {return ((DOUBLE32*)((char*)var->data+120));}
inline void set_GenPar_BOT_ANT_OFFSET(GenPar* var, DOUBLE32* val) { memcpy(((char*)var->data+120),val,72); }
inline void set_GenPar_BOT_ANT_OFFSET_ar(GenPar* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+120))+index),val,DOUBLE32_SIZE); }
#define GenPar_BOT_ANT_OFFSET(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+120)+index))

/* if satellites are separated = true, if stacked = false */
inline BYTE32* get_GenPar_separated(GenPar* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+192),BYTE32_SIZE); }
inline void set_GenPar_separated(GenPar* var, BYTE32 val) { memcpy(((char*)var->data+192),(void*)&val,BYTE32_SIZE); return; }
#define GenPar_separated(var) (*((BYTE32 *)(((char *)(&(var)))+192)))

/* local satellite id */
inline UBYTE32* get_GenPar_localSat(GenPar* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+193),UBYTE32_SIZE); }
inline void set_GenPar_localSat(GenPar* var, UBYTE32 val) { memcpy(((char*)var->data+193),(void*)&val,UBYTE32_SIZE); return; }
#define GenPar_localSat(var) (*((UBYTE32 *)(((char *)(&(var)))+193)))

/* remote satellite id */
inline UBYTE32* get_GenPar_remoteSat(GenPar* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+194),UBYTE32_SIZE); }
inline void set_GenPar_remoteSat(GenPar* var, UBYTE32 val) { memcpy(((char*)var->data+194),(void*)&val,UBYTE32_SIZE); return; }
#define GenPar_remoteSat(var) (*((UBYTE32 *)(((char *)(&(var)))+194)))

/* FAULT_PARAMETERS declaration ADCNS Tolerance levels for measured variables */
typedef struct {
	DOUBLE32 data[24];
} FAULT_PARAMETERS;

#define FAULT_PARAMETERS_SIZE 192
inline int sizeOfFAULT_PARAMETERS() {return 192;}

/* Values for RESP_CAM_TELEM */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+0),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+0),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+0)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+1),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+1),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+1)))

/* 1 = Perform this test. 0 = Don't perform this test. */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+2),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+2),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+2)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Volt_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+3),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Volt_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+3),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Volt_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+3)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Volt_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+4),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Volt_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+4),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Volt_High(var) (*((UBYTE32 *)(((char *)(&(var)))+4)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Volt_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+5),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Volt_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+5),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Volt_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+5)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+6),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+6),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+6)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+7),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+7),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+7)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RCT_Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+8),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RCT_Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+8),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RCT_Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+8)))

/* Values for RESP_PPT_STATUS */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+9),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+9),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+9)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+10),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+10),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+10)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+11),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+11),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+11)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPUTemp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+12),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPUTemp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+12),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPUTemp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+12)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPUTemp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+13),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPUTemp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+13),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPUTemp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+13)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPUTemp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+14),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPUTemp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+14),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPUTemp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+14)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTTemp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+15),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTTemp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+15),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTTemp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+15)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTTemp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+16),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTTemp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+16),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTTemp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+16)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPS_PPTTemp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+17),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPS_PPTTemp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+17),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPS_PPTTemp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+17)))

/* Values for RESP_POWER_ALL_STATUS */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+18),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+18),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+18)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+19),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+19),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+19)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+20),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+20),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryBoxCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+20)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp1_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+21),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp1_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+21),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp1_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+21)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp1_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+22),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp1_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+22),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp1_High(var) (*((UBYTE32 *)(((char *)(&(var)))+22)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp1_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+23),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp1_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+23),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp1_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+23)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp2_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+24),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp2_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+24),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp2_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+24)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp2_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+25),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp2_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+25),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp2_High(var) (*((UBYTE32 *)(((char *)(&(var)))+25)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp2_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+26),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp2_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+26),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp2_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+26)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp3_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+27),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp3_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+27),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp3_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+27)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp3_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+28),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp3_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+28),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp3_High(var) (*((UBYTE32 *)(((char *)(&(var)))+28)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp3_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+29),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp3_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+29),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp3_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+29)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp4_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+30),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp4_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+30),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp4_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+30)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp4_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+31),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp4_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+31),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp4_High(var) (*((UBYTE32 *)(((char *)(&(var)))+31)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryTemp4_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+32),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryTemp4_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+32),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryTemp4_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+32)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryVoltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+33),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryVoltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+33),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryVoltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+33)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryVoltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+34),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryVoltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+34),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryVoltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+34)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryVoltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+35),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryVoltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+35),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryVoltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+35)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryCapacity_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+36),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryCapacity_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+36),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryCapacity_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+36)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryCapacity_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+37),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryCapacity_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+37),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryCapacity_High(var) (*((UBYTE32 *)(((char *)(&(var)))+37)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_BatteryCapacity_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+38),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_BatteryCapacity_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+38),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_BatteryCapacity_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+38)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CamBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+39),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CamBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+39),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CamBoardCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+39)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CamBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+40),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CamBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+40),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CamBoardCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+40)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CamBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+41),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CamBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+41),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CamBoardCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+41)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+42),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+42),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+42)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+43),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+43),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+43)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+44),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+44),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+44)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+45),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+45),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+45)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+46),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+46),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+46)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+47),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+47),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+47)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+48),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+48),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+48)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+49),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+49),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+49)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera1Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+50),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera1Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+50),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera1Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+50)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+51),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+51),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+51)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+52),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+52),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+52)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+53),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+53),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+53)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+54),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+54),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+54)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+55),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+55),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+55)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+56),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+56),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+56)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+57),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+57),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+57)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+58),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+58),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+58)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Camera2Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+59),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Camera2Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+59),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Camera2Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+59)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+60),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+60),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+60)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+61),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+61),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+61)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+62),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+62),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+62)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+63),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+63),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+63)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+64),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+64),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardVoltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+64)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+65),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+65),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_CDHBoardVoltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+65)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+66),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+66),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+66)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+67),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+67),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+67)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+68),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+68),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+68)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+69),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+69),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+69)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+70),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+70),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+70)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS1Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+71),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS1Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+71),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS1Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+71)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+72),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+72),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+72)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+73),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+73),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+73)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+74),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+74),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+74)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+75),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+75),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+75)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+76),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+76),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+76)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS2Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+77),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS2Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+77),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS2Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+77)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+78),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+78),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+78)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+79),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+79),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+79)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+80),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+80),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+80)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+81),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+81),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+81)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+82),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+82),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+82)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_GPS3Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+83),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_GPS3Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+83),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_GPS3Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+83)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_LBVoltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+84),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_LBVoltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+84),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_LBVoltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+84)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_LBVoltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+85),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_LBVoltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+85),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_LBVoltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+85)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_LBVoltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+86),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_LBVoltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+86),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_LBVoltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+86)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PropCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+87),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PropCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+87),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PropCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+87)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PropCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+88),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PropCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+88),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PropCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+88)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PropCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+89),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PropCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+89),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PropCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+89)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+90),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+90),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+90)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+91),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+91),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWR1BoardTemp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+91)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+92),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+92),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWR1BoardTemp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+92)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+93),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+93),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+93)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+94),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+94),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWRBoardCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+94)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+95),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+95),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PWRBoardCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+95)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_TCBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+96),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_TCBoardCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+96),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_TCBoardCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+96)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_TCBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+97),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_TCBoardCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+97),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_TCBoardCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+97)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_TCBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+98),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_TCBoardCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+98),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_TCBoardCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+98)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelCurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+99),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelCurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+99),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelCurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+99)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelCurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+100),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelCurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+100),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelCurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+100)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelCurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+101),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelCurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+101),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelCurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+101)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelVoltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+102),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelVoltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+102),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelVoltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+102)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelVoltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+103),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelVoltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+103),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelVoltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+103)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_PanelVoltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+104),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_PanelVoltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+104),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_PanelVoltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+104)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp1_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+105),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp1_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+105),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp1_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+105)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp1_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+106),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp1_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+106),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp1_High(var) (*((UBYTE32 *)(((char *)(&(var)))+106)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp1_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+107),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp1_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+107),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp1_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+107)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp2_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+108),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp2_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+108),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp2_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+108)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp2_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+109),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp2_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+109),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp2_High(var) (*((UBYTE32 *)(((char *)(&(var)))+109)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_RadioTemp2_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+110),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_RadioTemp2_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+110),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_RadioTemp2_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+110)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+111),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+111),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+111)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+112),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+112),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+112)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+113),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+113),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+113)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Voltage_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+114),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Voltage_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+114),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Voltage_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+114)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Voltage_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+115),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Voltage_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+115),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Voltage_High(var) (*((UBYTE32 *)(((char *)(&(var)))+115)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_Heater3Voltage_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+116),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_Heater3Voltage_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+116),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_Heater3Voltage_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+116)))

/* Values for RESP_TELEM AKA CDH_TELEM */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+117),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+117),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+117)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+118),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+118),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+118)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+119),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+119),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+119)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+120),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+120),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+120)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+121),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+121),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+121)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+122),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+122),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+122)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Volt_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+123),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Volt_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+123),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Volt_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+123)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Volt_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+124),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Volt_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+124),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Volt_High(var) (*((UBYTE32 *)(((char *)(&(var)))+124)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RT_Volt_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+125),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RT_Volt_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+125),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RT_Volt_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+125)))

/* Values for RESP_TC_TELEM */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt6_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+126),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt6_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+126),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt6_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+126)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt6_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+127),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt6_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+127),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt6_High(var) (*((UBYTE32 *)(((char *)(&(var)))+127)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt6_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+128),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt6_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+128),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt6_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+128)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt5_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+129),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt5_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+129),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt5_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+129)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt5_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+130),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt5_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+130),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt5_High(var) (*((UBYTE32 *)(((char *)(&(var)))+130)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Volt5_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+131),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Volt5_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+131),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Volt5_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+131)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Current6_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+132),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Current6_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+132),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Current6_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+132)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Current6_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+133),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Current6_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+133),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Current6_High(var) (*((UBYTE32 *)(((char *)(&(var)))+133)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Current6_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+134),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Current6_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+134),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Current6_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+134)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+135),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+135),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+135)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+136),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+136),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+136)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RTT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+137),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RTT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+137),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RTT_Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+137)))

/* Values for RESP_GPS_TELEM */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Volt35_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+138),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Volt35_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+138),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Volt35_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+138)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Volt35_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+139),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Volt35_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+139),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Volt35_High(var) (*((UBYTE32 *)(((char *)(&(var)))+139)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Volt35_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+140),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Volt35_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+140),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Volt35_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+140)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT1_Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+141),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT1_Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+141),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT1_Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+141)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT1_Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+142),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT1_Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+142),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT1_Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+142)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT1_Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+143),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT1_Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+143),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT1_Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+143)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT2_Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+144),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT2_Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+144),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT2_Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+144)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT2_Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+145),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT2_Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+145),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT2_Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+145)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT2_Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+146),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT2_Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+146),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT2_Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+146)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT3_Current_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+147),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT3_Current_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+147),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT3_Current_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+147)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT3_Current_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+148),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT3_Current_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+148),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT3_Current_High(var) (*((UBYTE32 *)(((char *)(&(var)))+148)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT3_Current_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+149),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT3_Current_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+149),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT3_Current_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+149)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+150),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Temp_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+150),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Temp_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+150)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Temp_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+151),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Temp_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+151),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Temp_High(var) (*((UBYTE32 *)(((char *)(&(var)))+151)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RGT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+152),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RGT_Temp_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+152),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RGT_Temp_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+152)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMIVolt_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+153),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMIVolt_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+153),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMIVolt_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+153)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMIVolt_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+154),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMIVolt_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+154),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMIVolt_High(var) (*((UBYTE32 *)(((char *)(&(var)))+154)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMIVolt_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+155),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMIVolt_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+155),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMIVolt_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+155)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMICurrent_Low(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+156),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMICurrent_Low(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+156),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMICurrent_Low(var) (*((UBYTE32 *)(((char *)(&(var)))+156)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMICurrent_High(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+157),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMICurrent_High(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+157),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMICurrent_High(var) (*((UBYTE32 *)(((char *)(&(var)))+157)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_RPAS_IMICurrent_Test(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+158),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_RPAS_IMICurrent_Test(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+158),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_RPAS_IMICurrent_Test(var) (*((UBYTE32 *)(((char *)(&(var)))+158)))

/* {enum CUCP_BOOLEAN} 1 = logging on. 0 = logging off. */
inline BYTE32* get_FAULT_PARAMETERS_logging(FAULT_PARAMETERS* var) {return ((BYTE32*)((char*)var->data+159));}
inline void set_FAULT_PARAMETERS_logging(FAULT_PARAMETERS* var, BYTE32* val) { memcpy(((char*)var->data+159),val,12); }
inline void set_FAULT_PARAMETERS_logging_ar(FAULT_PARAMETERS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+159))+index),val,BYTE32_SIZE); }
#define FAULT_PARAMETERS_logging(var,index) (*((BYTE32 *)(((char *)(&(var)))+159)+index))

/* {enum CUCP_BOOLEAN} 1 = respond on. 0 = respond off. */
inline BYTE32* get_FAULT_PARAMETERS_respond(FAULT_PARAMETERS* var) {return ((BYTE32*)((char*)var->data+171));}
inline void set_FAULT_PARAMETERS_respond(FAULT_PARAMETERS* var, BYTE32* val) { memcpy(((char*)var->data+171),val,12); }
inline void set_FAULT_PARAMETERS_respond_ar(FAULT_PARAMETERS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+171))+index),val,BYTE32_SIZE); }
#define FAULT_PARAMETERS_respond(var,index) (*((BYTE32 *)(((char *)(&(var)))+171)+index))

/* Value of current which determines if HW is on or off */
inline UBYTE32* get_FAULT_PARAMETERS_CAM1CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+183),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_CAM1CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+183),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_CAM1CurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+183)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_CAM2CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+184),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_CAM2CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+184),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_CAM2CurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+184)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_TCBoardCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+185),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_TCBoardCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+185),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_TCBoardCurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+185)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_GPS1CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+186),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_GPS1CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+186),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_GPS1CurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+186)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_GPS2CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+187),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_GPS2CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+187),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_GPS2CurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+187)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_GPS3CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+188),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_GPS3CurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+188),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_GPS3CurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+188)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_IMICurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+189),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_IMICurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+189),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_IMICurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+189)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_CAMBoardCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+190),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_CAMBoardCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+190),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_CAMBoardCurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+190)))

/*  */
inline UBYTE32* get_FAULT_PARAMETERS_PPTCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+191),UBYTE32_SIZE); }
inline void set_FAULT_PARAMETERS_PPTCurrentOnOff(FAULT_PARAMETERS* var, UBYTE32 val) { memcpy(((char*)var->data+191),(void*)&val,UBYTE32_SIZE); return; }
#define FAULT_PARAMETERS_PPTCurrentOnOff(var) (*((UBYTE32 *)(((char *)(&(var)))+191)))

/* FAULT_STATUS declaration ADCNS Status of each variable for logging purposes */
typedef struct {
	DOUBLE32 data[15];
} FAULT_STATUS;

#define FAULT_STATUS_SIZE 120
inline int sizeOfFAULT_STATUS() {return 120;}

/* Status of each hardware unit for power cycling purposes */
inline BYTE32* get_FAULT_STATUS_power_cycle_status(FAULT_STATUS* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_FAULT_STATUS_power_cycle_status(FAULT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+0),val,76); }
inline void set_FAULT_STATUS_power_cycle_status_ar(FAULT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define FAULT_STATUS_power_cycle_status(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/* status of each hardware unit for checking against enable flags */
inline BYTE32* get_FAULT_STATUS_on_off_status(FAULT_STATUS* var) {return ((BYTE32*)((char*)var->data+76));}
inline void set_FAULT_STATUS_on_off_status(FAULT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+76),val,11); }
inline void set_FAULT_STATUS_on_off_status_ar(FAULT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+76))+index),val,BYTE32_SIZE); }
#define FAULT_STATUS_on_off_status(var,index) (*((BYTE32 *)(((char *)(&(var)))+76)+index))

/* keeps track of consecutive hardware errors for response purposes */
inline BYTE32* get_FAULT_STATUS_lastHwStatus(FAULT_STATUS* var) {return ((BYTE32*)((char*)var->data+87));}
inline void set_FAULT_STATUS_lastHwStatus(FAULT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+87),val,11); }
inline void set_FAULT_STATUS_lastHwStatus_ar(FAULT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+87))+index),val,BYTE32_SIZE); }
#define FAULT_STATUS_lastHwStatus(var,index) (*((BYTE32 *)(((char *)(&(var)))+87)+index))

/* puts the s/c in survival mode if hw does not respond for a while */
inline BYTE32* get_FAULT_STATUS_badHwCounter(FAULT_STATUS* var) {return ((BYTE32*)((char*)var->data+98));}
inline void set_FAULT_STATUS_badHwCounter(FAULT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+98),val,11); }
inline void set_FAULT_STATUS_badHwCounter_ar(FAULT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+98))+index),val,BYTE32_SIZE); }
#define FAULT_STATUS_badHwCounter(var,index) (*((BYTE32 *)(((char *)(&(var)))+98)+index))

/* stops responses to hw that have repetitive faults until they start working */
inline BYTE32* get_FAULT_STATUS_stopHwResponse(FAULT_STATUS* var) {return ((BYTE32*)((char*)var->data+109));}
inline void set_FAULT_STATUS_stopHwResponse(FAULT_STATUS* var, BYTE32* val) { memcpy(((char*)var->data+109),val,11); }
inline void set_FAULT_STATUS_stopHwResponse_ar(FAULT_STATUS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+109))+index),val,BYTE32_SIZE); }
#define FAULT_STATUS_stopHwResponse(var,index) (*((BYTE32 *)(((char *)(&(var)))+109)+index))

/* FAULT_SW_PARAMS declaration ADCNS */
typedef struct {
	DOUBLE32 data[18];
} FAULT_SW_PARAMS;

#define FAULT_SW_PARAMS_SIZE 144
inline int sizeOfFAULT_SW_PARAMS() {return 144;}

/* Time spent in or out of eclipse */
inline DOUBLE32* get_FAULT_SW_PARAMS_eclipse_time(FAULT_SW_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_FAULT_SW_PARAMS_eclipse_time(FAULT_SW_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define FAULT_SW_PARAMS_eclipse_time(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* Max time in eclipse */
inline DOUBLE32* get_FAULT_SW_PARAMS_max_eclipse_time(FAULT_SW_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_eclipse_time(FAULT_SW_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_eclipse_time(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* Max time in sun */
inline DOUBLE32* get_FAULT_SW_PARAMS_max_sun_time(FAULT_SW_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_sun_time(FAULT_SW_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_sun_time(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* Number of times bigger the z magnitude must be bigger than the x and y magnitudes */
inline DOUBLE32* get_FAULT_SW_PARAMS_kfatt_z_factor(FAULT_SW_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_FAULT_SW_PARAMS_kfatt_z_factor(FAULT_SW_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define FAULT_SW_PARAMS_kfatt_z_factor(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* Tolerance of magnitude of single body cdgps vectors */
inline FLOAT32* get_FAULT_SW_PARAMS_mag_tolerance(FAULT_SW_PARAMS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+32),FLOAT32_SIZE); }
inline void set_FAULT_SW_PARAMS_mag_tolerance(FAULT_SW_PARAMS* var, FLOAT32 val) { memcpy(((char*)var->data+32),(void*)&val,FLOAT32_SIZE); return; }
#define FAULT_SW_PARAMS_mag_tolerance(var) (*((FLOAT32 *)(((char *)(&(var)))+32)))

/* Max torque that can be commanded to the imi */
inline FLOAT32* get_FAULT_SW_PARAMS_max_torque(FAULT_SW_PARAMS* var, FLOAT32* toSet) { return (FLOAT32*)memcpy(toSet,(FLOAT32*)((char*)var->data+36),FLOAT32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_torque(FAULT_SW_PARAMS* var, FLOAT32 val) { memcpy(((char*)var->data+36),(void*)&val,FLOAT32_SIZE); return; }
#define FAULT_SW_PARAMS_max_torque(var) (*((FLOAT32 *)(((char *)(&(var)))+36)))

/* Use Lightband separation verification */
inline INT32* get_FAULT_SW_PARAMS_sepVerLB(FAULT_SW_PARAMS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+40),INT32_SIZE); }
inline void set_FAULT_SW_PARAMS_sepVerLB(FAULT_SW_PARAMS* var, INT32 val) { memcpy(((char*)var->data+40),(void*)&val,INT32_SIZE); return; }
#define FAULT_SW_PARAMS_sepVerLB(var) (*((INT32 *)(((char *)(&(var)))+40)))

/* Use pressLink separation verification */
inline INT32* get_FAULT_SW_PARAMS_sepVerPL(FAULT_SW_PARAMS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+44),INT32_SIZE); }
inline void set_FAULT_SW_PARAMS_sepVerPL(FAULT_SW_PARAMS* var, INT32 val) { memcpy(((char*)var->data+44),(void*)&val,INT32_SIZE); return; }
#define FAULT_SW_PARAMS_sepVerPL(var) (*((INT32 *)(((char *)(&(var)))+44)))

/* Maximum number of bad hw statuses before fault is triggered */
inline INT32* get_FAULT_SW_PARAMS_maxBadHwStatus(FAULT_SW_PARAMS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+48),INT32_SIZE); }
inline void set_FAULT_SW_PARAMS_maxBadHwStatus(FAULT_SW_PARAMS* var, INT32 val) { memcpy(((char*)var->data+48),(void*)&val,INT32_SIZE); return; }
#define FAULT_SW_PARAMS_maxBadHwStatus(var) (*((INT32 *)(((char *)(&(var)))+48)))

/* Maximum number of bad hw status after being reset before going to safe mode */
inline INT32* get_FAULT_SW_PARAMS_maxHwReset(FAULT_SW_PARAMS* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+52),INT32_SIZE); }
inline void set_FAULT_SW_PARAMS_maxHwReset(FAULT_SW_PARAMS* var, INT32 val) { memcpy(((char*)var->data+52),(void*)&val,INT32_SIZE); return; }
#define FAULT_SW_PARAMS_maxHwReset(var) (*((INT32 *)(((char *)(&(var)))+52)))

/* Maximum number of iterations of singleCPGPS algorithm to get convergence */
inline BYTE32* get_FAULT_SW_PARAMS_max_iterations(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+56),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_iterations(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+56),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_iterations(var) (*((BYTE32 *)(((char *)(&(var)))+56)))

/* Battery voltage when battery is nearly full */
inline BYTE32* get_FAULT_SW_PARAMS_battVFull(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+57),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_battVFull(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+57),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_battVFull(var) (*((BYTE32 *)(((char *)(&(var)))+57)))

/* Battery voltage when battery is nearly empty */
inline BYTE32* get_FAULT_SW_PARAMS_battVEmpty(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+58),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_battVEmpty(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+58),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_battVEmpty(var) (*((BYTE32 *)(((char *)(&(var)))+58)))

/* Maximum number of times estimated rate can be a certain # of times bigger than x and y */
inline BYTE32* get_FAULT_SW_PARAMS_max_kfatt_errors(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+59),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_kfatt_errors(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+59),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_kfatt_errors(var) (*((BYTE32 *)(((char *)(&(var)))+59)))

/* Maximum number of iterations of multibody CDGPS algortihm to get convergence */
inline BYTE32* get_FAULT_SW_PARAMS_max_iterations_multi(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+60),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_iterations_multi(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+60),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_iterations_multi(var) (*((BYTE32 *)(((char *)(&(var)))+60)))

/* Counter for kfatt rate errors */
inline BYTE32* get_FAULT_SW_PARAMS_kfatt_startup_errors(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+61),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_kfatt_startup_errors(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+61),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_kfatt_startup_errors(var) (*((BYTE32 *)(((char *)(&(var)))+61)))

/* Maximum number of consecutive times residual can exceed its maximum */
inline BYTE32* get_FAULT_SW_PARAMS_max_residual_errors(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+62),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_max_residual_errors(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+62),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_max_residual_errors(var) (*((BYTE32 *)(((char *)(&(var)))+62)))

/* Number of consecutive KFATT residual errors */
inline BYTE32* get_FAULT_SW_PARAMS_residual_error_cnt(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+63),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_residual_error_cnt(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+63),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_residual_error_cnt(var) (*((BYTE32 *)(((char *)(&(var)))+63)))

/* Max number of consecutive errors in each telemetry point */
inline BYTE32* get_FAULT_SW_PARAMS_maxTelemErrors(FAULT_SW_PARAMS* var) {return ((BYTE32*)((char*)var->data+64));}
inline void set_FAULT_SW_PARAMS_maxTelemErrors(FAULT_SW_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+64),val,76); }
inline void set_FAULT_SW_PARAMS_maxTelemErrors_ar(FAULT_SW_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+64))+index),val,BYTE32_SIZE); }
#define FAULT_SW_PARAMS_maxTelemErrors(var,index) (*((BYTE32 *)(((char *)(&(var)))+64)+index))

/* Number of times hardware with telemetry errors will be cycled before being turned off */
inline BYTE32* get_FAULT_SW_PARAMS_hwOffLimit(FAULT_SW_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+140),BYTE32_SIZE); }
inline void set_FAULT_SW_PARAMS_hwOffLimit(FAULT_SW_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+140),(void*)&val,BYTE32_SIZE); return; }
#define FAULT_SW_PARAMS_hwOffLimit(var) (*((BYTE32 *)(((char *)(&(var)))+140)))

/* MOMS_PARAMS declaration ADCNS */
typedef struct {
	DOUBLE32 data[40];
} MOMS_PARAMS;

#define MOMS_PARAMS_SIZE 320
inline int sizeOfMOMS_PARAMS() {return 320;}

/* threshold time since last att. est. to run controller */
inline DOUBLE32* get_MOMS_PARAMS_k_att_cont_time_thresh(MOMS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_MOMS_PARAMS_k_att_cont_time_thresh(MOMS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define MOMS_PARAMS_k_att_cont_time_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* threshold between current time and next activation time to turn on systems */
inline DOUBLE32* get_MOMS_PARAMS_k_active_time_thres(MOMS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_MOMS_PARAMS_k_active_time_thres(MOMS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define MOMS_PARAMS_k_active_time_thres(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* if system time is past this point, and other conditions are met (batt charge,canSeparate,in sepWindow), will separate */
inline DOUBLE32* get_MOMS_PARAMS_k_sepAfterTime_mjd(MOMS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_MOMS_PARAMS_k_sepAfterTime_mjd(MOMS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define MOMS_PARAMS_k_sepAfterTime_mjd(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* window for which the sepAfterTime is considered valid. */
inline DOUBLE32* get_MOMS_PARAMS_k_sepWindow_mjd(MOMS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_MOMS_PARAMS_k_sepWindow_mjd(MOMS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define MOMS_PARAMS_k_sepWindow_mjd(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* counter threshold for copying global memory to local data. global memory is managed by state saver */
inline UINT32* get_MOMS_PARAMS_k_gbl_refresh_thres(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+32),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_gbl_refresh_thres(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+32),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_gbl_refresh_thres(var) (*((UINT32 *)(((char *)(&(var)))+32)))

/* counter threshold for refreshing T&C radios */
inline UINT32* get_MOMS_PARAMS_k_tc_refresh_thres(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+36),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_tc_refresh_thres(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+36),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_tc_refresh_thres(var) (*((UINT32 *)(((char *)(&(var)))+36)))

/* time to allow separation mode to try to get determined att/power/etc for separation (seconds) */
inline UINT32* get_MOMS_PARAMS_k_sep_mode_timeout(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+40),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_sep_mode_timeout(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+40),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_sep_mode_timeout(var) (*((UINT32 *)(((char *)(&(var)))+40)))

/* number of cycles for att. control being low before disabling it temporarily */
inline UINT32* get_MOMS_PARAMS_k_att_cont_timeout(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+44),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_att_cont_timeout(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+44),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_att_cont_timeout(var) (*((UINT32 *)(((char *)(&(var)))+44)))

/* number of cycles for pos. control being low before disabling it temporarily */
inline UINT32* get_MOMS_PARAMS_k_pos_cont_timeout(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+48),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_pos_cont_timeout(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+48),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_pos_cont_timeout(var) (*((UINT32 *)(((char *)(&(var)))+48)))

/* number of firings allowed before alternating charge times */
inline UINT32* get_MOMS_PARAMS_k_ppt_num_per_charge(MOMS_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+52),UINT32_SIZE); }
inline void set_MOMS_PARAMS_k_ppt_num_per_charge(MOMS_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+52),(void*)&val,UINT32_SIZE); return; }
#define MOMS_PARAMS_k_ppt_num_per_charge(var) (*((UINT32 *)(((char *)(&(var)))+52)))

/* maximum angular momentum difference from desired allowed for separation */
inline FLOAT32* get_MOMS_PARAMS_k_sep_att_thresh(MOMS_PARAMS* var) {return ((FLOAT32*)((char*)var->data+56));}
inline void set_MOMS_PARAMS_k_sep_att_thresh(MOMS_PARAMS* var, FLOAT32* val) { memcpy(((char*)var->data+56),val,12); }
inline void set_MOMS_PARAMS_k_sep_att_thresh_ar(MOMS_PARAMS* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+56))+index),val,FLOAT32_SIZE); }
#define MOMS_PARAMS_k_sep_att_thresh(var,index) (*((FLOAT32 *)(((char *)(&(var)))+56)+index))

/* slower charge time required before a PPT thruster firing */
inline SHORT32* get_MOMS_PARAMS_k_ppt_charge_time_slow(MOMS_PARAMS* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+68),SHORT32_SIZE); }
inline void set_MOMS_PARAMS_k_ppt_charge_time_slow(MOMS_PARAMS* var, SHORT32 val) { memcpy(((char*)var->data+68),(void*)&val,SHORT32_SIZE); return; }
#define MOMS_PARAMS_k_ppt_charge_time_slow(var) (*((SHORT32 *)(((char *)(&(var)))+68)))

/* faster charge time required before a PPT thruster firing */
inline SHORT32* get_MOMS_PARAMS_k_ppt_charge_time_fast(MOMS_PARAMS* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+70),SHORT32_SIZE); }
inline void set_MOMS_PARAMS_k_ppt_charge_time_fast(MOMS_PARAMS* var, SHORT32 val) { memcpy(((char*)var->data+70),(void*)&val,SHORT32_SIZE); return; }
#define MOMS_PARAMS_k_ppt_charge_time_fast(var) (*((SHORT32 *)(((char *)(&(var)))+70)))

/* variable that represents the time between MOMS execution cycles, in milliseconds */
inline USHORT32* get_MOMS_PARAMS_executionPeriod(MOMS_PARAMS* var) {return ((USHORT32*)((char*)var->data+72));}
inline void set_MOMS_PARAMS_executionPeriod(MOMS_PARAMS* var, USHORT32* val) { memcpy(((char*)var->data+72),val,20); }
inline void set_MOMS_PARAMS_executionPeriod_ar(MOMS_PARAMS* var, USHORT32* val, INT32 index) { memcpy((((USHORT32*)((char*)var->data+72))+index),val,USHORT32_SIZE); }
#define MOMS_PARAMS_executionPeriod(var,index) (*((USHORT32 *)(((char *)(&(var)))+72)+index))

/* slowest allowable MOMS execution period */
inline USHORT32* get_MOMS_PARAMS_slowestExecPeriod(MOMS_PARAMS* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+92),USHORT32_SIZE); }
inline void set_MOMS_PARAMS_slowestExecPeriod(MOMS_PARAMS* var, USHORT32 val) { memcpy(((char*)var->data+92),(void*)&val,USHORT32_SIZE); return; }
#define MOMS_PARAMS_slowestExecPeriod(var) (*((USHORT32 *)(((char *)(&(var)))+92)))

/* fastest allowable MOMS execution period */
inline USHORT32* get_MOMS_PARAMS_fastestExecPeriod(MOMS_PARAMS* var, USHORT32* toSet) { return (USHORT32*)memcpy(toSet,(USHORT32*)((char*)var->data+94),USHORT32_SIZE); }
inline void set_MOMS_PARAMS_fastestExecPeriod(MOMS_PARAMS* var, USHORT32 val) { memcpy(((char*)var->data+94),(void*)&val,USHORT32_SIZE); return; }
#define MOMS_PARAMS_fastestExecPeriod(var) (*((USHORT32 *)(((char *)(&(var)))+94)))

/* mode that MOMS enters upon boot-up */
inline BYTE32* get_MOMS_PARAMS_initial_mode(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+96),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_initial_mode(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+96),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_initial_mode(var) (*((BYTE32 *)(((char *)(&(var)))+96)))

/* minimum amount of power above threshold for which a GPS board can be operated */
inline BYTE32* get_MOMS_PARAMS_k_min_pwr_for_gps(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+97),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_min_pwr_for_gps(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+97),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_min_pwr_for_gps(var) (*((BYTE32 *)(((char *)(&(var)))+97)))

/* minimum amount of power above threshold for which a ACS can be operated (PPU + PPTs + IMI) */
inline BYTE32* get_MOMS_PARAMS_k_min_pwr_for_acs(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+98),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_min_pwr_for_acs(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+98),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_min_pwr_for_acs(var) (*((BYTE32 *)(((char *)(&(var)))+98)))

/* minimum amount of power above threshold for which position control (PPU + PPTS) */
inline BYTE32* get_MOMS_PARAMS_k_min_pwr_for_pos_ctrl(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+99),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_min_pwr_for_pos_ctrl(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+99),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_min_pwr_for_pos_ctrl(var) (*((BYTE32 *)(((char *)(&(var)))+99)))

/* minimum amount of power above threshold for which a CAM can be operated */
inline BYTE32* get_MOMS_PARAMS_k_min_pwr_for_cam(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+100),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_min_pwr_for_cam(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+100),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_min_pwr_for_cam(var) (*((BYTE32 *)(((char *)(&(var)))+100)))

/* minimum amount of power above threshold needed for a separation */
inline BYTE32* get_MOMS_PARAMS_k_min_pwr_for_sep(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+101),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_min_pwr_for_sep(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+101),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_min_pwr_for_sep(var) (*((BYTE32 *)(((char *)(&(var)))+101)))

/* power threshold for which charging should begin */
inline BYTE32* get_MOMS_PARAMS_k_start_charge_thres(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+102),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_start_charge_thres(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+102),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_start_charge_thres(var) (*((BYTE32 *)(((char *)(&(var)))+102)))

/* power threshold for which charging can complete */
inline BYTE32* get_MOMS_PARAMS_k_stop_charge_thres(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+103),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_stop_charge_thres(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+103),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_stop_charge_thres(var) (*((BYTE32 *)(((char *)(&(var)))+103)))

/* solar array voltage threshold for eclipse detection (below this means no power) */
inline BYTE32* get_MOMS_PARAMS_k_eclipse_thresh_v(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+104),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_eclipse_thresh_v(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+104),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_eclipse_thresh_v(var) (*((BYTE32 *)(((char *)(&(var)))+104)))

/* solar array current threshold for eclipse detection (below this means no power) */
inline BYTE32* get_MOMS_PARAMS_k_eclipse_thresh_i(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+105),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_k_eclipse_thresh_i(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+105),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_k_eclipse_thresh_i(var) (*((BYTE32 *)(((char *)(&(var)))+105)))

/* flag that specifies if the spacecraft is allowed to separate */
inline BYTE32* get_MOMS_PARAMS_canSeparate(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+106),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_canSeparate(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+106),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_canSeparate(var) (*((BYTE32 *)(((char *)(&(var)))+106)))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in ground test mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_groundTest(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+107));}
inline void set_MOMS_PARAMS_swAllowFlags_groundTest(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+107),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_groundTest_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+107))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_groundTest(var,index) (*((BYTE32 *)(((char *)(&(var)))+107)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in presep safe mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_preSepSafe(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+116));}
inline void set_MOMS_PARAMS_swAllowFlags_preSepSafe(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+116),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_preSepSafe_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+116))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_preSepSafe(var,index) (*((BYTE32 *)(((char *)(&(var)))+116)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in postsep safe mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_postSepSafe(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+125));}
inline void set_MOMS_PARAMS_swAllowFlags_postSepSafe(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+125),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_postSepSafe_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+125))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_postSepSafe(var,index) (*((BYTE32 *)(((char *)(&(var)))+125)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in presep no control mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_preSep(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+134));}
inline void set_MOMS_PARAMS_swAllowFlags_preSep(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+134),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_preSep_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+134))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_preSep(var,index) (*((BYTE32 *)(((char *)(&(var)))+134)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in postsep control mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_preSepNoCtrl(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+143));}
inline void set_MOMS_PARAMS_swAllowFlags_preSepNoCtrl(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+143),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_preSepNoCtrl_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+143))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_preSepNoCtrl(var,index) (*((BYTE32 *)(((char *)(&(var)))+143)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in postsep crosslink mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_postSepXlink(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+152));}
inline void set_MOMS_PARAMS_swAllowFlags_postSepXlink(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+152),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_postSepXlink_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+152))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_postSepXlink(var,index) (*((BYTE32 *)(((char *)(&(var)))+152)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in postsep control mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_postSepCtrl(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+161));}
inline void set_MOMS_PARAMS_swAllowFlags_postSepCtrl(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+161),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_postSepCtrl_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+161))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_postSepCtrl(var,index) (*((BYTE32 *)(((char *)(&(var)))+161)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in end of life mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_EOL(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+170));}
inline void set_MOMS_PARAMS_swAllowFlags_EOL(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+170),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_EOL_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+170))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_EOL(var,index) (*((BYTE32 *)(((char *)(&(var)))+170)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in survival mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_survival(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+179));}
inline void set_MOMS_PARAMS_swAllowFlags_survival(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+179),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_survival_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+179))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_survival(var,index) (*((BYTE32 *)(((char *)(&(var)))+179)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what software routines are allowed to run in separation mode, changeable via ground commanding ONLY */
inline BYTE32* get_MOMS_PARAMS_swAllowFlags_separation(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+188));}
inline void set_MOMS_PARAMS_swAllowFlags_separation(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+188),val,9); }
inline void set_MOMS_PARAMS_swAllowFlags_separation_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+188))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_swAllowFlags_separation(var,index) (*((BYTE32 *)(((char *)(&(var)))+188)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in ground test mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_groundTest(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+197));}
inline void set_MOMS_PARAMS_hwAllowFlags_groundTest(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+197),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_groundTest_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+197))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_groundTest(var,index) (*((BYTE32 *)(((char *)(&(var)))+197)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in presep safe mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_preSepSafe(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+209));}
inline void set_MOMS_PARAMS_hwAllowFlags_preSepSafe(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+209),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_preSepSafe_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+209))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_preSepSafe(var,index) (*((BYTE32 *)(((char *)(&(var)))+209)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in postsep safe mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_postSepSafe(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+221));}
inline void set_MOMS_PARAMS_hwAllowFlags_postSepSafe(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+221),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_postSepSafe_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+221))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_postSepSafe(var,index) (*((BYTE32 *)(((char *)(&(var)))+221)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in presep mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_preSep(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+233));}
inline void set_MOMS_PARAMS_hwAllowFlags_preSep(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+233),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_preSep_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+233))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_preSep(var,index) (*((BYTE32 *)(((char *)(&(var)))+233)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in presep no control mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_preSepNoCtrl(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+245));}
inline void set_MOMS_PARAMS_hwAllowFlags_preSepNoCtrl(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+245),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_preSepNoCtrl_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+245))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_preSepNoCtrl(var,index) (*((BYTE32 *)(((char *)(&(var)))+245)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in postsep mode xlink, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_postSepXlink(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+257));}
inline void set_MOMS_PARAMS_hwAllowFlags_postSepXlink(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+257),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_postSepXlink_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+257))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_postSepXlink(var,index) (*((BYTE32 *)(((char *)(&(var)))+257)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in postsep ctrl mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_postSepCtrl(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+269));}
inline void set_MOMS_PARAMS_hwAllowFlags_postSepCtrl(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+269),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_postSepCtrl_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+269))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_postSepCtrl(var,index) (*((BYTE32 *)(((char *)(&(var)))+269)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in end of life mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_EOL(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+281));}
inline void set_MOMS_PARAMS_hwAllowFlags_EOL(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+281),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_EOL_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+281))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_EOL(var,index) (*((BYTE32 *)(((char *)(&(var)))+281)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in survival mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_survival(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+293));}
inline void set_MOMS_PARAMS_hwAllowFlags_survival(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+293),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_survival_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+293))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_survival(var,index) (*((BYTE32 *)(((char *)(&(var)))+293)+index))

/* {enum CUCP_BOOLEAN} flags that indicate what hardware are enabled in separation mode, changeable via ground commanding ONLY. Note: There are only 11 not 12 */
inline BYTE32* get_MOMS_PARAMS_hwAllowFlags_separation(MOMS_PARAMS* var) {return ((BYTE32*)((char*)var->data+305));}
inline void set_MOMS_PARAMS_hwAllowFlags_separation(MOMS_PARAMS* var, BYTE32* val) { memcpy(((char*)var->data+305),val,12); }
inline void set_MOMS_PARAMS_hwAllowFlags_separation_ar(MOMS_PARAMS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+305))+index),val,BYTE32_SIZE); }
#define MOMS_PARAMS_hwAllowFlags_separation(var,index) (*((BYTE32 *)(((char *)(&(var)))+305)+index))

/* flag to indicate if moms should run, 0 = don't run, 1 = run */
inline BYTE32* get_MOMS_PARAMS_runMOMS(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+317),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_runMOMS(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+317),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_runMOMS(var) (*((BYTE32 *)(((char *)(&(var)))+317)))

/* A byte indicating which GPS receiver's data to send over crosslink when in POST_SEP_XLINK mode. Can be 1,2,or 3 */
inline BYTE32* get_MOMS_PARAMS_cdgpsRcvrToUse(MOMS_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+318),BYTE32_SIZE); }
inline void set_MOMS_PARAMS_cdgpsRcvrToUse(MOMS_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+318),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_PARAMS_cdgpsRcvrToUse(var) (*((BYTE32 *)(((char *)(&(var)))+318)))

/* MOMS_COMMANDS declaration ADCNS */
typedef struct {
	DOUBLE32 data[26];
} MOMS_COMMANDS;

#define MOMS_COMMANDS_SIZE 208
inline int sizeOfMOMS_COMMANDS() {return 208;}

/*  */
inline DOUBLE32* get_MOMS_COMMANDS_activationTimes(MOMS_COMMANDS* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_MOMS_COMMANDS_activationTimes(MOMS_COMMANDS* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,160); }
inline void set_MOMS_COMMANDS_activationTimes_ar(MOMS_COMMANDS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define MOMS_COMMANDS_activationTimes(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* flag for whether or not there is an update */
inline BYTE32* get_MOMS_COMMANDS_update_flag(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+160),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_update_flag(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+160),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_update_flag(var) (*((BYTE32 *)(((char *)(&(var)))+160)))

/* set mode value command */
inline BYTE32* get_MOMS_COMMANDS_mode_transition(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+161),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_mode_transition(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+161),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_mode_transition(var) (*((BYTE32 *)(((char *)(&(var)))+161)))

/* command to set the separation allow flag high */
inline BYTE32* get_MOMS_COMMANDS_separation_enable(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+162),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_separation_enable(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+162),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_separation_enable(var) (*((BYTE32 *)(((char *)(&(var)))+162)))

/* commands for hardware state (0 = no-op, 1 = enable/allow/power on, 2 = disable/disallow/off, 3 = power cycle) */
inline BYTE32* get_MOMS_COMMANDS_hardware_command(MOMS_COMMANDS* var) {return ((BYTE32*)((char*)var->data+163));}
inline void set_MOMS_COMMANDS_hardware_command(MOMS_COMMANDS* var, BYTE32* val) { memcpy(((char*)var->data+163),val,11); }
inline void set_MOMS_COMMANDS_hardware_command_ar(MOMS_COMMANDS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+163))+index),val,BYTE32_SIZE); }
#define MOMS_COMMANDS_hardware_command(var,index) (*((BYTE32 *)(((char *)(&(var)))+163)+index))

/* commands for software algorithms (0 = no-op, 1 = enable/allow, 2 = disable/disallow) */
inline BYTE32* get_MOMS_COMMANDS_algorithm_enable(MOMS_COMMANDS* var) {return ((BYTE32*)((char*)var->data+174));}
inline void set_MOMS_COMMANDS_algorithm_enable(MOMS_COMMANDS* var, BYTE32* val) { memcpy(((char*)var->data+174),val,9); }
inline void set_MOMS_COMMANDS_algorithm_enable_ar(MOMS_COMMANDS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+174))+index),val,BYTE32_SIZE); }
#define MOMS_COMMANDS_algorithm_enable(var,index) (*((BYTE32 *)(((char *)(&(var)))+174)+index))

/* command for enabling or disabling fault responses and/or logging */
inline BYTE32* get_MOMS_COMMANDS_faultCommand(MOMS_COMMANDS* var) {return ((BYTE32*)((char*)var->data+183));}
inline void set_MOMS_COMMANDS_faultCommand(MOMS_COMMANDS* var, BYTE32* val) { memcpy(((char*)var->data+183),val,12); }
inline void set_MOMS_COMMANDS_faultCommand_ar(MOMS_COMMANDS* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+183))+index),val,BYTE32_SIZE); }
#define MOMS_COMMANDS_faultCommand(var,index) (*((BYTE32 *)(((char *)(&(var)))+183)+index))

/* command for resetting KFATT */
inline BYTE32* get_MOMS_COMMANDS_resetKFATT(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+195),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_resetKFATT(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+195),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_resetKFATT(var) (*((BYTE32 *)(((char *)(&(var)))+195)))

/* command for resetting single-body CDGPS filter */
inline BYTE32* get_MOMS_COMMANDS_resetCDGPS_sing(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+196),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_resetCDGPS_sing(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+196),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_resetCDGPS_sing(var) (*((BYTE32 *)(((char *)(&(var)))+196)))

/* command for resetting multi-body CDGPS filter */
inline BYTE32* get_MOMS_COMMANDS_resetCDGPS_mult(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+197),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_resetCDGPS_mult(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+197),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_resetCDGPS_mult(var) (*((BYTE32 *)(((char *)(&(var)))+197)))

/* command for resetting relnav filter */
inline BYTE32* get_MOMS_COMMANDS_resetRelNav(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+198),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_resetRelNav(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+198),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_resetRelNav(var) (*((BYTE32 *)(((char *)(&(var)))+198)))

/* command for starting or stopping charging */
inline BYTE32* get_MOMS_COMMANDS_chargeCMD(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+199),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_chargeCMD(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+199),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_chargeCMD(var) (*((BYTE32 *)(((char *)(&(var)))+199)))

/* command for entering/exiting an eclipse mode (1=enter, 2=exit, 3=disable, 4=enable) */
inline BYTE32* get_MOMS_COMMANDS_eclipseCMD(MOMS_COMMANDS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+200),BYTE32_SIZE); }
inline void set_MOMS_COMMANDS_eclipseCMD(MOMS_COMMANDS* var, BYTE32 val) { memcpy(((char*)var->data+200),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_COMMANDS_eclipseCMD(var) (*((BYTE32 *)(((char *)(&(var)))+200)))

/* MOMS_TELEM declaration ADCNS */
typedef struct {
	DOUBLE32 data[12];
} MOMS_TELEM;

#define MOMS_TELEM_SIZE 96
inline int sizeOfMOMS_TELEM() {return 96;}

/*  */
inline DOUBLE32* get_MOMS_TELEM_sep_mode_start_MJD(MOMS_TELEM* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_MOMS_TELEM_sep_mode_start_MJD(MOMS_TELEM* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define MOMS_TELEM_sep_mode_start_MJD(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/*  */
inline UINT32* get_MOMS_TELEM_gbl_refresh_counter(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+8),UINT32_SIZE); }
inline void set_MOMS_TELEM_gbl_refresh_counter(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+8),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_gbl_refresh_counter(var) (*((UINT32 *)(((char *)(&(var)))+8)))

/*  */
inline UINT32* get_MOMS_TELEM_tc_refresh_counter(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+12),UINT32_SIZE); }
inline void set_MOMS_TELEM_tc_refresh_counter(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+12),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_tc_refresh_counter(var) (*((UINT32 *)(((char *)(&(var)))+12)))

/*  */
inline UINT32* get_MOMS_TELEM_sep_mode_time(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+16),UINT32_SIZE); }
inline void set_MOMS_TELEM_sep_mode_time(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+16),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_sep_mode_time(var) (*((UINT32 *)(((char *)(&(var)))+16)))

/*  */
inline UINT32* get_MOMS_TELEM_att_cont_low_count(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+20),UINT32_SIZE); }
inline void set_MOMS_TELEM_att_cont_low_count(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+20),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_att_cont_low_count(var) (*((UINT32 *)(((char *)(&(var)))+20)))

/*  */
inline UINT32* get_MOMS_TELEM_pos_cont_low_count(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+24),UINT32_SIZE); }
inline void set_MOMS_TELEM_pos_cont_low_count(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+24),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_pos_cont_low_count(var) (*((UINT32 *)(((char *)(&(var)))+24)))

/*  */
inline UINT32* get_MOMS_TELEM_active_times_index(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+28),UINT32_SIZE); }
inline void set_MOMS_TELEM_active_times_index(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+28),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_active_times_index(var) (*((UINT32 *)(((char *)(&(var)))+28)))

/* number of ppt firing executed so far */
inline UINT32* get_MOMS_TELEM_ppt_firings(MOMS_TELEM* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+32),UINT32_SIZE); }
inline void set_MOMS_TELEM_ppt_firings(MOMS_TELEM* var, UINT32 val) { memcpy(((char*)var->data+32),(void*)&val,UINT32_SIZE); return; }
#define MOMS_TELEM_ppt_firings(var) (*((UINT32 *)(((char *)(&(var)))+32)))

/* {enum MOMS_MODES} current s/c mode */
inline UBYTE32* get_MOMS_TELEM_mode(MOMS_TELEM* var, UBYTE32* toSet) { return (UBYTE32*)memcpy(toSet,(UBYTE32*)((char*)var->data+36),UBYTE32_SIZE); }
inline void set_MOMS_TELEM_mode(MOMS_TELEM* var, UBYTE32 val) { memcpy(((char*)var->data+36),(void*)&val,UBYTE32_SIZE); return; }
#define MOMS_TELEM_mode(var) (*((UBYTE32 *)(((char *)(&(var)))+36)))

/* {enum CUCP_BOOLEAN} flag to indicate if moms is ready for separation */
inline BYTE32* get_MOMS_TELEM_sep_ready(MOMS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+37),BYTE32_SIZE); }
inline void set_MOMS_TELEM_sep_ready(MOMS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+37),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_TELEM_sep_ready(var) (*((BYTE32 *)(((char *)(&(var)))+37)))

/* {enum CUCP_BOOLEAN} flag to indicate if moms is allowed to separate, this is set by the ground */
inline BYTE32* get_MOMS_TELEM_sep_allowed(MOMS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+38),BYTE32_SIZE); }
inline void set_MOMS_TELEM_sep_allowed(MOMS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+38),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_TELEM_sep_allowed(var) (*((BYTE32 *)(((char *)(&(var)))+38)))

/* {enum CUCP_BOOLEAN} flag to indicate that s/c is in eclipse and is in a low power state */
inline BYTE32* get_MOMS_TELEM_eclipse(MOMS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+39),BYTE32_SIZE); }
inline void set_MOMS_TELEM_eclipse(MOMS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+39),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_TELEM_eclipse(var) (*((BYTE32 *)(((char *)(&(var)))+39)))

/* {enum CUCP_BOOLEAN} flag to indicate that s/c is charging and in a low power state */
inline BYTE32* get_MOMS_TELEM_charging(MOMS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+40),BYTE32_SIZE); }
inline void set_MOMS_TELEM_charging(MOMS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+40),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_TELEM_charging(var) (*((BYTE32 *)(((char *)(&(var)))+40)))

/* {enum CUCP_BOOLEAN} flag that indicates what software routines are allowed to run in current moms mode (updated each timestep) */
inline BYTE32* get_MOMS_TELEM_swAllowFlags(MOMS_TELEM* var) {return ((BYTE32*)((char*)var->data+41));}
inline void set_MOMS_TELEM_swAllowFlags(MOMS_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+41),val,9); }
inline void set_MOMS_TELEM_swAllowFlags_ar(MOMS_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+41))+index),val,BYTE32_SIZE); }
#define MOMS_TELEM_swAllowFlags(var,index) (*((BYTE32 *)(((char *)(&(var)))+41)+index))

/* {enum CUCP_BOOLEAN} flag that indicates what software routines are enabled and running in moms (updated each timestep) */
inline BYTE32* get_MOMS_TELEM_swEnableFlags(MOMS_TELEM* var) {return ((BYTE32*)((char*)var->data+50));}
inline void set_MOMS_TELEM_swEnableFlags(MOMS_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+50),val,9); }
inline void set_MOMS_TELEM_swEnableFlags_ar(MOMS_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+50))+index),val,BYTE32_SIZE); }
#define MOMS_TELEM_swEnableFlags(var,index) (*((BYTE32 *)(((char *)(&(var)))+50)+index))

/* {enum CUCP_BOOLEAN} flag that indicates what hardware is allowed to be on in current moms mode (updated each timestep) */
inline BYTE32* get_MOMS_TELEM_hwAllowFlags(MOMS_TELEM* var) {return ((BYTE32*)((char*)var->data+59));}
inline void set_MOMS_TELEM_hwAllowFlags(MOMS_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+59),val,11); }
inline void set_MOMS_TELEM_hwAllowFlags_ar(MOMS_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+59))+index),val,BYTE32_SIZE); }
#define MOMS_TELEM_hwAllowFlags(var,index) (*((BYTE32 *)(((char *)(&(var)))+59)+index))

/* {enum CUCP_BOOLEAN} flag that indicates what hardware is currently enabled in current moms mode (updated each timestep) */
inline BYTE32* get_MOMS_TELEM_hwEnableFlags(MOMS_TELEM* var) {return ((BYTE32*)((char*)var->data+70));}
inline void set_MOMS_TELEM_hwEnableFlags(MOMS_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+70),val,11); }
inline void set_MOMS_TELEM_hwEnableFlags_ar(MOMS_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+70))+index),val,BYTE32_SIZE); }
#define MOMS_TELEM_hwEnableFlags(var,index) (*((BYTE32 *)(((char *)(&(var)))+70)+index))

/* {enum CUCP_BOOLEAN} flag that indicates whether or not hardware is good */
inline BYTE32* get_MOMS_TELEM_hardwareStatus(MOMS_TELEM* var) {return ((BYTE32*)((char*)var->data+81));}
inline void set_MOMS_TELEM_hardwareStatus(MOMS_TELEM* var, BYTE32* val) { memcpy(((char*)var->data+81),val,11); }
inline void set_MOMS_TELEM_hardwareStatus_ar(MOMS_TELEM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+81))+index),val,BYTE32_SIZE); }
#define MOMS_TELEM_hardwareStatus(var,index) (*((BYTE32 *)(((char *)(&(var)))+81)+index))

/* flag that indicates if hw should be activated, 0 = inactive, 1 = active, 2 = ignore activation times */
inline BYTE32* get_MOMS_TELEM_activated(MOMS_TELEM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+92),BYTE32_SIZE); }
inline void set_MOMS_TELEM_activated(MOMS_TELEM* var, BYTE32 val) { memcpy(((char*)var->data+92),(void*)&val,BYTE32_SIZE); return; }
#define MOMS_TELEM_activated(var) (*((BYTE32 *)(((char *)(&(var)))+92)))

/* INSPECTION_PARAMS declaration ADCNS */
typedef struct {
	DOUBLE32 data[14];
} INSPECTION_PARAMS;

#define INSPECTION_PARAMS_SIZE 112
inline int sizeOfINSPECTION_PARAMS() {return 112;}

/* maximum distance between satellites to consider a inspection opportunity */
inline DOUBLE32* get_INSPECTION_PARAMS_k_max_dist_inspection(INSPECTION_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_INSPECTION_PARAMS_k_max_dist_inspection(INSPECTION_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define INSPECTION_PARAMS_k_max_dist_inspection(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* threshold for horizontal angle to determine if s/c is in camera FOV */
inline DOUBLE32* get_INSPECTION_PARAMS_k_x_theta_thresh(INSPECTION_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_INSPECTION_PARAMS_k_x_theta_thresh(INSPECTION_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define INSPECTION_PARAMS_k_x_theta_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* threshold for vertical angle to determine if s/c is in camera FOV */
inline DOUBLE32* get_INSPECTION_PARAMS_k_z_theta_thresh(INSPECTION_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+16),DOUBLE32_SIZE); }
inline void set_INSPECTION_PARAMS_k_z_theta_thresh(INSPECTION_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+16),(void*)&val,DOUBLE32_SIZE); return; }
#define INSPECTION_PARAMS_k_z_theta_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+16)))

/* angular distance in cosine space for extra distance between s/c center and image side */
inline DOUBLE32* get_INSPECTION_PARAMS_k_image_pad(INSPECTION_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+24),DOUBLE32_SIZE); }
inline void set_INSPECTION_PARAMS_k_image_pad(INSPECTION_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+24),(void*)&val,DOUBLE32_SIZE); return; }
#define INSPECTION_PARAMS_k_image_pad(var) (*((DOUBLE32 *)(((char *)(&(var)))+24)))

/* DCM of body frame to camera 1 frame */
inline DOUBLE32* get_INSPECTION_PARAMS_q_BCBF_2_cam1(INSPECTION_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+32));}
inline void set_INSPECTION_PARAMS_q_BCBF_2_cam1(INSPECTION_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+32),val,32); }
inline void set_INSPECTION_PARAMS_q_BCBF_2_cam1_ar(INSPECTION_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+32))+index),val,DOUBLE32_SIZE); }
#define INSPECTION_PARAMS_q_BCBF_2_cam1(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+32)+index))

/* DCM of body frame to camera 2 frame */
inline DOUBLE32* get_INSPECTION_PARAMS_q_BCBF_2_cam2(INSPECTION_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+64));}
inline void set_INSPECTION_PARAMS_q_BCBF_2_cam2(INSPECTION_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+64),val,32); }
inline void set_INSPECTION_PARAMS_q_BCBF_2_cam2_ar(INSPECTION_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+64))+index),val,DOUBLE32_SIZE); }
#define INSPECTION_PARAMS_q_BCBF_2_cam2(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+64)+index))

/* index for which camera is the bottom camera (1 = cam1, 2 = cam2) */
inline UINT32* get_INSPECTION_PARAMS_k_bot_cam(INSPECTION_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+96),UINT32_SIZE); }
inline void set_INSPECTION_PARAMS_k_bot_cam(INSPECTION_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+96),(void*)&val,UINT32_SIZE); return; }
#define INSPECTION_PARAMS_k_bot_cam(var) (*((UINT32 *)(((char *)(&(var)))+96)))

/* time in seconds it takes to turn on the FPGA board */
inline UINT32* get_INSPECTION_PARAMS_k_fpga_on_time(INSPECTION_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+100),UINT32_SIZE); }
inline void set_INSPECTION_PARAMS_k_fpga_on_time(INSPECTION_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+100),(void*)&val,UINT32_SIZE); return; }
#define INSPECTION_PARAMS_k_fpga_on_time(var) (*((UINT32 *)(((char *)(&(var)))+100)))

/* time in seconds it takes to turn on the camera */
inline UINT32* get_INSPECTION_PARAMS_k_cam_on_time(INSPECTION_PARAMS* var, UINT32* toSet) { return (UINT32*)memcpy(toSet,(UINT32*)((char*)var->data+104),UINT32_SIZE); }
inline void set_INSPECTION_PARAMS_k_cam_on_time(INSPECTION_PARAMS* var, UINT32 val) { memcpy(((char*)var->data+104),(void*)&val,UINT32_SIZE); return; }
#define INSPECTION_PARAMS_k_cam_on_time(var) (*((UINT32 *)(((char *)(&(var)))+104)))

/* POS_CTRL_PARAMS declaration POSCTRL */
typedef struct {
	DOUBLE32 data[21];
} POS_CTRL_PARAMS;

#define POS_CTRL_PARAMS_SIZE 168
inline int sizeOfPOS_CTRL_PARAMS() {return 168;}

/* gain for semimajor axis control */
inline DOUBLE32* get_POS_CTRL_PARAMS_Kp(POS_CTRL_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+0),DOUBLE32_SIZE); }
inline void set_POS_CTRL_PARAMS_Kp(POS_CTRL_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+0),(void*)&val,DOUBLE32_SIZE); return; }
#define POS_CTRL_PARAMS_Kp(var) (*((DOUBLE32 *)(((char *)(&(var)))+0)))

/* gain for inclination control */
inline DOUBLE32* get_POS_CTRL_PARAMS_inc_gain(POS_CTRL_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+8),DOUBLE32_SIZE); }
inline void set_POS_CTRL_PARAMS_inc_gain(POS_CTRL_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+8),(void*)&val,DOUBLE32_SIZE); return; }
#define POS_CTRL_PARAMS_inc_gain(var) (*((DOUBLE32 *)(((char *)(&(var)))+8)))

/* gains for torque error commands */
inline DOUBLE32* get_POS_CTRL_PARAMS_K_torque(POS_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+16));}
inline void set_POS_CTRL_PARAMS_K_torque(POS_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+16),val,32); }
inline void set_POS_CTRL_PARAMS_K_torque_ar(POS_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+16))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_PARAMS_K_torque(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+16)+index))

/* desired angular momentum for the satellites before separation (in SI) */
inline DOUBLE32* get_POS_CTRL_PARAMS_Hc_stacked(POS_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+48));}
inline void set_POS_CTRL_PARAMS_Hc_stacked(POS_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+48),val,24); }
inline void set_POS_CTRL_PARAMS_Hc_stacked_ar(POS_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+48))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_PARAMS_Hc_stacked(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+48)+index))

/* desired angular momentum for the top satellite after separation (in SI) */
inline DOUBLE32* get_POS_CTRL_PARAMS_Hc_top(POS_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+72));}
inline void set_POS_CTRL_PARAMS_Hc_top(POS_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+72),val,24); }
inline void set_POS_CTRL_PARAMS_Hc_top_ar(POS_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+72))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_PARAMS_Hc_top(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+72)+index))

/* desired angular momentum for the bottom satellite after separation (in SI) */
inline DOUBLE32* get_POS_CTRL_PARAMS_Hc_bot(POS_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+96));}
inline void set_POS_CTRL_PARAMS_Hc_bot(POS_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+96),val,24); }
inline void set_POS_CTRL_PARAMS_Hc_bot_ar(POS_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+96))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_PARAMS_Hc_bot(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+96)+index))

/* max allowed time between CDGPS meas to compute relative vel (in sec) */
inline DOUBLE32* get_POS_CTRL_PARAMS_t_delta_meas_thresh(POS_CTRL_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+120),DOUBLE32_SIZE); }
inline void set_POS_CTRL_PARAMS_t_delta_meas_thresh(POS_CTRL_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+120),(void*)&val,DOUBLE32_SIZE); return; }
#define POS_CTRL_PARAMS_t_delta_meas_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+120)))

/* max allowed time since last CDGPS meas for pos control (in sec) */
inline DOUBLE32* get_POS_CTRL_PARAMS_t_new_meas_thresh(POS_CTRL_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+128),DOUBLE32_SIZE); }
inline void set_POS_CTRL_PARAMS_t_new_meas_thresh(POS_CTRL_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+128),(void*)&val,DOUBLE32_SIZE); return; }
#define POS_CTRL_PARAMS_t_new_meas_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+128)))

/* 3x1 vector in N-m-s of the intentional orbital anguler momentum bias uploaded by the ground operators. Has the affect of bring the spacecraft together. Polarity matters. */
inline DOUBLE32* get_POS_CTRL_PARAMS_hBias(POS_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+136));}
inline void set_POS_CTRL_PARAMS_hBias(POS_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+136),val,24); }
inline void set_POS_CTRL_PARAMS_hBias_ar(POS_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+136))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_PARAMS_hBias(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+136)+index))

/* polarity of the force for PPT */
inline SHORT32* get_POS_CTRL_PARAMS_PPTforcePolarity(POS_CTRL_PARAMS* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+160),SHORT32_SIZE); }
inline void set_POS_CTRL_PARAMS_PPTforcePolarity(POS_CTRL_PARAMS* var, SHORT32 val) { memcpy(((char*)var->data+160),(void*)&val,SHORT32_SIZE); return; }
#define POS_CTRL_PARAMS_PPTforcePolarity(var) (*((SHORT32 *)(((char *)(&(var)))+160)))

/* 0xff if firing ppt's is allowed, disallowed otherwise */
inline BYTE32* get_POS_CTRL_PARAMS_ppt_allowed(POS_CTRL_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+162),BYTE32_SIZE); }
inline void set_POS_CTRL_PARAMS_ppt_allowed(POS_CTRL_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+162),(void*)&val,BYTE32_SIZE); return; }
#define POS_CTRL_PARAMS_ppt_allowed(var) (*((BYTE32 *)(((char *)(&(var)))+162)))

/* Binary value that specifies which mode the angular momemntum matching takes on: 0/False for Perpendicular-Only H Matching, 1/True for Full H Matching (modified). Full H Matching matches the direction AND magnitude of the orbital angular momentum vectors for inclination feedback control. The default case, Perpendicular H Matching, only matches the directions (not the magnitudes, i.e. it only takes into consideration the perpendicular component of the deltah vector. */
inline BYTE32* get_POS_CTRL_PARAMS_fullHMatch(POS_CTRL_PARAMS* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+163),BYTE32_SIZE); }
inline void set_POS_CTRL_PARAMS_fullHMatch(POS_CTRL_PARAMS* var, BYTE32 val) { memcpy(((char*)var->data+163),(void*)&val,BYTE32_SIZE); return; }
#define POS_CTRL_PARAMS_fullHMatch(var) (*((BYTE32 *)(((char *)(&(var)))+163)))

/* OTS_PARAMS declaration POSCTRL */
typedef struct {
	DOUBLE32 data[96];
} OTS_PARAMS;

#define OTS_PARAMS_SIZE 768
inline int sizeOfOTS_PARAMS() {return 768;}

/* direction of applied ppt force (8x3) */
inline DOUBLE32* get_OTS_PARAMS_force_dir(OTS_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_OTS_PARAMS_force_dir(OTS_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,192); }
inline void set_OTS_PARAMS_force_dir_ar(OTS_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define OTS_PARAMS_force_dir(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* location of each ppt (8x3) */
inline DOUBLE32* get_OTS_PARAMS_ri(OTS_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+192));}
inline void set_OTS_PARAMS_ri(OTS_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+192),val,192); }
inline void set_OTS_PARAMS_ri_ar(OTS_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+192))+index),val,DOUBLE32_SIZE); }
#define OTS_PARAMS_ri(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+192)+index))

/* relative position between origin of bottom and top when stacked */
inline DOUBLE32* get_OTS_PARAMS_delta_r(OTS_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+384));}
inline void set_OTS_PARAMS_delta_r(OTS_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+384),val,24); }
inline void set_OTS_PARAMS_delta_r_ar(OTS_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+384))+index),val,DOUBLE32_SIZE); }
#define OTS_PARAMS_delta_r(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+384)+index))

/* impulse for single ppt */
inline DOUBLE32* get_OTS_PARAMS_impulse(OTS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+408),DOUBLE32_SIZE); }
inline void set_OTS_PARAMS_impulse(OTS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+408),(void*)&val,DOUBLE32_SIZE); return; }
#define OTS_PARAMS_impulse(var) (*((DOUBLE32 *)(((char *)(&(var)))+408)))

/* threshold ratio between imparted deltav and target deltav */
inline DOUBLE32* get_OTS_PARAMS_goodness_ratio_thresh(OTS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+416),DOUBLE32_SIZE); }
inline void set_OTS_PARAMS_goodness_ratio_thresh(OTS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+416),(void*)&val,DOUBLE32_SIZE); return; }
#define OTS_PARAMS_goodness_ratio_thresh(var) (*((DOUBLE32 *)(((char *)(&(var)))+416)))

/* scale for torque input */
inline DOUBLE32* get_OTS_PARAMS_weight_factor(OTS_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+424),DOUBLE32_SIZE); }
inline void set_OTS_PARAMS_weight_factor(OTS_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+424),(void*)&val,DOUBLE32_SIZE); return; }
#define OTS_PARAMS_weight_factor(var) (*((DOUBLE32 *)(((char *)(&(var)))+424)))

/* ppt combos for separated case (column 1) */
inline SHORT32* get_OTS_PARAMS_sep_ppts_col1(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+432));}
inline void set_OTS_PARAMS_sep_ppts_col1(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+432),val,56); }
inline void set_OTS_PARAMS_sep_ppts_col1_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+432))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_sep_ppts_col1(var,index) (*((SHORT32 *)(((char *)(&(var)))+432)+index))

/* ppt combos for separated case (column 2) */
inline SHORT32* get_OTS_PARAMS_sep_ppts_col2(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+488));}
inline void set_OTS_PARAMS_sep_ppts_col2(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+488),val,56); }
inline void set_OTS_PARAMS_sep_ppts_col2_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+488))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_sep_ppts_col2(var,index) (*((SHORT32 *)(((char *)(&(var)))+488)+index))

/* ppt combo for top sat stacked case (col 1) */
inline SHORT32* get_OTS_PARAMS_top_ppts_col1(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+544));}
inline void set_OTS_PARAMS_top_ppts_col1(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+544),val,56); }
inline void set_OTS_PARAMS_top_ppts_col1_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+544))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_top_ppts_col1(var,index) (*((SHORT32 *)(((char *)(&(var)))+544)+index))

/* ppt combo for top sat stacked case (col 2) */
inline SHORT32* get_OTS_PARAMS_top_ppts_col2(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+600));}
inline void set_OTS_PARAMS_top_ppts_col2(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+600),val,56); }
inline void set_OTS_PARAMS_top_ppts_col2_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+600))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_top_ppts_col2(var,index) (*((SHORT32 *)(((char *)(&(var)))+600)+index))

/* ppt combo for bottom sat stacked case (col 1) */
inline SHORT32* get_OTS_PARAMS_bot_ppts_col1(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+656));}
inline void set_OTS_PARAMS_bot_ppts_col1(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+656),val,56); }
inline void set_OTS_PARAMS_bot_ppts_col1_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+656))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_bot_ppts_col1(var,index) (*((SHORT32 *)(((char *)(&(var)))+656)+index))

/* ppt combo for bottom sat stacked case (col 2) */
inline SHORT32* get_OTS_PARAMS_bot_ppts_col2(OTS_PARAMS* var) {return ((SHORT32*)((char*)var->data+712));}
inline void set_OTS_PARAMS_bot_ppts_col2(OTS_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+712),val,56); }
inline void set_OTS_PARAMS_bot_ppts_col2_ar(OTS_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+712))+index),val,SHORT32_SIZE); }
#define OTS_PARAMS_bot_ppts_col2(var,index) (*((SHORT32 *)(((char *)(&(var)))+712)+index))

/* POS_CTRL_DATA declaration POSCTRL */
typedef struct {
	DOUBLE32 data[32];
} POS_CTRL_DATA;

#define POS_CTRL_DATA_SIZE 256
inline int sizeOfPOS_CTRL_DATA() {return 256;}

/* Local satellite position last input into position controller */
inline DOUBLE32* get_POS_CTRL_DATA_r1(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_POS_CTRL_DATA_r1(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,24); }
inline void set_POS_CTRL_DATA_r1_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_r1(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* Local satellite velocity last input into position controller */
inline DOUBLE32* get_POS_CTRL_DATA_rdot1(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+24));}
inline void set_POS_CTRL_DATA_rdot1(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+24),val,24); }
inline void set_POS_CTRL_DATA_rdot1_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+24))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_rdot1(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+24)+index))

/* Remote satellite position last input into position controller */
inline DOUBLE32* get_POS_CTRL_DATA_r2(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+48));}
inline void set_POS_CTRL_DATA_r2(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+48),val,24); }
inline void set_POS_CTRL_DATA_r2_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+48))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_r2(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+48)+index))

/* Remote satellite velocity last input into position controller */
inline DOUBLE32* get_POS_CTRL_DATA_rdot2(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+72));}
inline void set_POS_CTRL_DATA_rdot2(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+72),val,24); }
inline void set_POS_CTRL_DATA_rdot2_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+72))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_rdot2(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+72)+index))

/* 1:3 = resulting delta_v, 4:6 = resulting delta_h */
inline DOUBLE32* get_POS_CTRL_DATA_delta_have(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+96));}
inline void set_POS_CTRL_DATA_delta_have(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+96),val,48); }
inline void set_POS_CTRL_DATA_delta_have_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+96))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_delta_have(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+96)+index))

/* Force output from chosen thruster combination */
inline DOUBLE32* get_POS_CTRL_DATA_output_force(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+144));}
inline void set_POS_CTRL_DATA_output_force(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+144),val,24); }
inline void set_POS_CTRL_DATA_output_force_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+144))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_output_force(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+144)+index))

/* Torque output from chosen thruster combination */
inline DOUBLE32* get_POS_CTRL_DATA_output_torque(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+168));}
inline void set_POS_CTRL_DATA_output_torque(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+168),val,24); }
inline void set_POS_CTRL_DATA_output_torque_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+168))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_output_torque(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+168)+index))

/* ratio between imparted deltav and target deltav */
inline DOUBLE32* get_POS_CTRL_DATA_goodness_ratio(POS_CTRL_DATA* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+192),DOUBLE32_SIZE); }
inline void set_POS_CTRL_DATA_goodness_ratio(POS_CTRL_DATA* var, DOUBLE32 val) { memcpy(((char*)var->data+192),(void*)&val,DOUBLE32_SIZE); return; }
#define POS_CTRL_DATA_goodness_ratio(var) (*((DOUBLE32 *)(((char *)(&(var)))+192)))

/* desired deltav and deltah */
inline DOUBLE32* get_POS_CTRL_DATA_wanted_matrix(POS_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+200));}
inline void set_POS_CTRL_DATA_wanted_matrix(POS_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+200),val,48); }
inline void set_POS_CTRL_DATA_wanted_matrix_ar(POS_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+200))+index),val,DOUBLE32_SIZE); }
#define POS_CTRL_DATA_wanted_matrix(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+200)+index))

/* PPTs selected to fire by position controller */
inline SHORT32* get_POS_CTRL_DATA_fire_thrusters(POS_CTRL_DATA* var) {return ((SHORT32*)((char*)var->data+248));}
inline void set_POS_CTRL_DATA_fire_thrusters(POS_CTRL_DATA* var, SHORT32* val) { memcpy(((char*)var->data+248),val,4); }
inline void set_POS_CTRL_DATA_fire_thrusters_ar(POS_CTRL_DATA* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+248))+index),val,SHORT32_SIZE); }
#define POS_CTRL_DATA_fire_thrusters(var,index) (*((SHORT32 *)(((char *)(&(var)))+248)+index))

/* ATT_CTRL_PARAMS declaration ATTCTRL */
typedef struct {
	DOUBLE32 data[6];
} ATT_CTRL_PARAMS;

#define ATT_CTRL_PARAMS_SIZE 48
inline int sizeOfATT_CTRL_PARAMS() {return 48;}

/* Nutation control gain: 0,1 = k1,k4 presept, 2,3 = k1,k4 postsep */
inline DOUBLE32* get_ATT_CTRL_PARAMS_Kn(ATT_CTRL_PARAMS* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_ATT_CTRL_PARAMS_Kn(ATT_CTRL_PARAMS* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,32); }
inline void set_ATT_CTRL_PARAMS_Kn_ar(ATT_CTRL_PARAMS* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define ATT_CTRL_PARAMS_Kn(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* Momentum minimizing gain */
inline DOUBLE32* get_ATT_CTRL_PARAMS_Kh(ATT_CTRL_PARAMS* var, DOUBLE32* toSet) { return (DOUBLE32*)memcpy(toSet,(DOUBLE32*)((char*)var->data+32),DOUBLE32_SIZE); }
inline void set_ATT_CTRL_PARAMS_Kh(ATT_CTRL_PARAMS* var, DOUBLE32 val) { memcpy(((char*)var->data+32),(void*)&val,DOUBLE32_SIZE); return; }
#define ATT_CTRL_PARAMS_Kh(var) (*((DOUBLE32 *)(((char *)(&(var)))+32)))

/* Indicates the correct orientation of the wheel axis */
inline SHORT32* get_ATT_CTRL_PARAMS_wheelOrder(ATT_CTRL_PARAMS* var) {return ((SHORT32*)((char*)var->data+40));}
inline void set_ATT_CTRL_PARAMS_wheelOrder(ATT_CTRL_PARAMS* var, SHORT32* val) { memcpy(((char*)var->data+40),val,6); }
inline void set_ATT_CTRL_PARAMS_wheelOrder_ar(ATT_CTRL_PARAMS* var, SHORT32* val, INT32 index) { memcpy((((SHORT32*)((char*)var->data+40))+index),val,SHORT32_SIZE); }
#define ATT_CTRL_PARAMS_wheelOrder(var,index) (*((SHORT32 *)(((char *)(&(var)))+40)+index))

/* The polarity of the torques for IMI */
inline SHORT32* get_ATT_CTRL_PARAMS_IMItorquePolarity(ATT_CTRL_PARAMS* var, SHORT32* toSet) { return (SHORT32*)memcpy(toSet,(SHORT32*)((char*)var->data+46),SHORT32_SIZE); }
inline void set_ATT_CTRL_PARAMS_IMItorquePolarity(ATT_CTRL_PARAMS* var, SHORT32 val) { memcpy(((char*)var->data+46),(void*)&val,SHORT32_SIZE); return; }
#define ATT_CTRL_PARAMS_IMItorquePolarity(var) (*((SHORT32 *)(((char *)(&(var)))+46)))

/* ATT_CTRL_DATA declaration ATTCTRL */
typedef struct {
	DOUBLE32 data[6];
} ATT_CTRL_DATA;

#define ATT_CTRL_DATA_SIZE 48
inline int sizeOfATT_CTRL_DATA() {return 48;}

/* Input spacecraft spin rates used by nutation controller */
inline DOUBLE32* get_ATT_CTRL_DATA_omega(ATT_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+0));}
inline void set_ATT_CTRL_DATA_omega(ATT_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+0),val,24); }
inline void set_ATT_CTRL_DATA_omega_ar(ATT_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+0))+index),val,DOUBLE32_SIZE); }
#define ATT_CTRL_DATA_omega(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+0)+index))

/* Torque command given to wheels by nutation controller */
inline DOUBLE32* get_ATT_CTRL_DATA_tau_wheel(ATT_CTRL_DATA* var) {return ((DOUBLE32*)((char*)var->data+24));}
inline void set_ATT_CTRL_DATA_tau_wheel(ATT_CTRL_DATA* var, DOUBLE32* val) { memcpy(((char*)var->data+24),val,24); }
inline void set_ATT_CTRL_DATA_tau_wheel_ar(ATT_CTRL_DATA* var, DOUBLE32* val, INT32 index) { memcpy((((DOUBLE32*)((char*)var->data+24))+index),val,DOUBLE32_SIZE); }
#define ATT_CTRL_DATA_tau_wheel(var,index) (*((DOUBLE32 *)(((char *)(&(var)))+24)+index))

/* ATT_CTRL_WHEEL_TORQUE declaration ATTCTRL */
typedef struct {
	DOUBLE32 data[2];
} ATT_CTRL_WHEEL_TORQUE;

#define ATT_CTRL_WHEEL_TORQUE_SIZE 16
inline int sizeOfATT_CTRL_WHEEL_TORQUE() {return 16;}

/*  */
inline FLOAT32* get_ATT_CTRL_WHEEL_TORQUE_IMI_torque(ATT_CTRL_WHEEL_TORQUE* var) {return ((FLOAT32*)((char*)var->data+0));}
inline void set_ATT_CTRL_WHEEL_TORQUE_IMI_torque(ATT_CTRL_WHEEL_TORQUE* var, FLOAT32* val) { memcpy(((char*)var->data+0),val,12); }
inline void set_ATT_CTRL_WHEEL_TORQUE_IMI_torque_ar(ATT_CTRL_WHEEL_TORQUE* var, FLOAT32* val, INT32 index) { memcpy((((FLOAT32*)((char*)var->data+0))+index),val,FLOAT32_SIZE); }
#define ATT_CTRL_WHEEL_TORQUE_IMI_torque(var,index) (*((FLOAT32 *)(((char *)(&(var)))+0)+index))

/* RADIOCOMM_PARAM declaration RADIOCOMM */
typedef struct {
	DOUBLE32 data[4];
} RADIOCOMM_PARAM;

#define RADIOCOMM_PARAM_SIZE 32
inline int sizeOfRADIOCOMM_PARAM() {return 32;}

/*  */
inline BYTE32* get_RADIOCOMM_PARAM_ground(RADIOCOMM_PARAM* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_RADIOCOMM_PARAM_ground(RADIOCOMM_PARAM* var, BYTE32* val) { memcpy(((char*)var->data+0),val,7); }
inline void set_RADIOCOMM_PARAM_ground_ar(RADIOCOMM_PARAM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define RADIOCOMM_PARAM_ground(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/*  */
inline BYTE32* get_RADIOCOMM_PARAM_cross(RADIOCOMM_PARAM* var) {return ((BYTE32*)((char*)var->data+7));}
inline void set_RADIOCOMM_PARAM_cross(RADIOCOMM_PARAM* var, BYTE32* val) { memcpy(((char*)var->data+7),val,7); }
inline void set_RADIOCOMM_PARAM_cross_ar(RADIOCOMM_PARAM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+7))+index),val,BYTE32_SIZE); }
#define RADIOCOMM_PARAM_cross(var,index) (*((BYTE32 *)(((char *)(&(var)))+7)+index))

/*  */
inline BYTE32* get_RADIOCOMM_PARAM_mine(RADIOCOMM_PARAM* var) {return ((BYTE32*)((char*)var->data+14));}
inline void set_RADIOCOMM_PARAM_mine(RADIOCOMM_PARAM* var, BYTE32* val) { memcpy(((char*)var->data+14),val,7); }
inline void set_RADIOCOMM_PARAM_mine_ar(RADIOCOMM_PARAM* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+14))+index),val,BYTE32_SIZE); }
#define RADIOCOMM_PARAM_mine(var,index) (*((BYTE32 *)(((char *)(&(var)))+14)+index))

/* tc board to use to talk to the ground */
inline BYTE32* get_RADIOCOMM_PARAM_tc_for_ground(RADIOCOMM_PARAM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+21),BYTE32_SIZE); }
inline void set_RADIOCOMM_PARAM_tc_for_ground(RADIOCOMM_PARAM* var, BYTE32 val) { memcpy(((char*)var->data+21),(void*)&val,BYTE32_SIZE); return; }
#define RADIOCOMM_PARAM_tc_for_ground(var) (*((BYTE32 *)(((char *)(&(var)))+21)))

/* tc board to use to talk over crosslink */
inline BYTE32* get_RADIOCOMM_PARAM_tc_for_crosslink(RADIOCOMM_PARAM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+22),BYTE32_SIZE); }
inline void set_RADIOCOMM_PARAM_tc_for_crosslink(RADIOCOMM_PARAM* var, BYTE32 val) { memcpy(((char*)var->data+22),(void*)&val,BYTE32_SIZE); return; }
#define RADIOCOMM_PARAM_tc_for_crosslink(var) (*((BYTE32 *)(((char *)(&(var)))+22)))

/* cycles to skip between ths updates */
inline BYTE32* get_RADIOCOMM_PARAM_ths_refresh_rate(RADIOCOMM_PARAM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+23),BYTE32_SIZE); }
inline void set_RADIOCOMM_PARAM_ths_refresh_rate(RADIOCOMM_PARAM* var, BYTE32 val) { memcpy(((char*)var->data+23),(void*)&val,BYTE32_SIZE); return; }
#define RADIOCOMM_PARAM_ths_refresh_rate(var) (*((BYTE32 *)(((char *)(&(var)))+23)))

/* cycles to skip between crosslink updates */
inline BYTE32* get_RADIOCOMM_PARAM_crosslink_rate(RADIOCOMM_PARAM* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+24),BYTE32_SIZE); }
inline void set_RADIOCOMM_PARAM_crosslink_rate(RADIOCOMM_PARAM* var, BYTE32 val) { memcpy(((char*)var->data+24),(void*)&val,BYTE32_SIZE); return; }
#define RADIOCOMM_PARAM_crosslink_rate(var) (*((BYTE32 *)(((char *)(&(var)))+24)))

/* GPS_Valid declaration  */
typedef struct {
	DOUBLE32 data[4];
} GPS_Valid;

#define GPS_VALID_SIZE 32
inline int sizeOfGPS_Valid() {return 32;}

/*  */
inline BYTE32* get_GPS_Valid_buff0(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+0));}
inline void set_GPS_Valid_buff0(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+0),val,3); }
inline void set_GPS_Valid_buff0_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+0))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff0(var,index) (*((BYTE32 *)(((char *)(&(var)))+0)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff1(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+3));}
inline void set_GPS_Valid_buff1(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+3),val,3); }
inline void set_GPS_Valid_buff1_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+3))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff1(var,index) (*((BYTE32 *)(((char *)(&(var)))+3)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff2(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+6));}
inline void set_GPS_Valid_buff2(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+6),val,3); }
inline void set_GPS_Valid_buff2_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+6))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff2(var,index) (*((BYTE32 *)(((char *)(&(var)))+6)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff3(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+9));}
inline void set_GPS_Valid_buff3(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+9),val,3); }
inline void set_GPS_Valid_buff3_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+9))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff3(var,index) (*((BYTE32 *)(((char *)(&(var)))+9)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff4(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+12));}
inline void set_GPS_Valid_buff4(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+12),val,3); }
inline void set_GPS_Valid_buff4_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+12))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff4(var,index) (*((BYTE32 *)(((char *)(&(var)))+12)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff5(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+15));}
inline void set_GPS_Valid_buff5(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+15),val,3); }
inline void set_GPS_Valid_buff5_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+15))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff5(var,index) (*((BYTE32 *)(((char *)(&(var)))+15)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff6(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+18));}
inline void set_GPS_Valid_buff6(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+18),val,3); }
inline void set_GPS_Valid_buff6_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+18))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff6(var,index) (*((BYTE32 *)(((char *)(&(var)))+18)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff7(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+21));}
inline void set_GPS_Valid_buff7(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+21),val,3); }
inline void set_GPS_Valid_buff7_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+21))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff7(var,index) (*((BYTE32 *)(((char *)(&(var)))+21)+index))

/*  */
inline BYTE32* get_GPS_Valid_buff8(GPS_Valid* var) {return ((BYTE32*)((char*)var->data+24));}
inline void set_GPS_Valid_buff8(GPS_Valid* var, BYTE32* val) { memcpy(((char*)var->data+24),val,3); }
inline void set_GPS_Valid_buff8_ar(GPS_Valid* var, BYTE32* val, INT32 index) { memcpy((((BYTE32*)((char*)var->data+24))+index),val,BYTE32_SIZE); }
#define GPS_Valid_buff8(var,index) (*((BYTE32 *)(((char *)(&(var)))+24)+index))

/* ALLsentenceF00 declaration One array for each buffer, each buffer contains a sentence from each board */
typedef struct {
	DOUBLE32 data[243];
} ALLsentenceF00;

#define ALLSENTENCEF00_SIZE 1944
inline int sizeOfALLsentenceF00() {return 1944;}

/*  */
inline sentenceF00* get_ALLsentenceF00_buff0(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+0));}
inline void set_ALLsentenceF00_buff0(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+0),val,216); }
inline void set_ALLsentenceF00_buff0_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+0))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff0(var,index) (*((sentenceF00 *)(((char *)(&(var)))+0)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff1(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+216));}
inline void set_ALLsentenceF00_buff1(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+216),val,216); }
inline void set_ALLsentenceF00_buff1_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+216))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff1(var,index) (*((sentenceF00 *)(((char *)(&(var)))+216)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff2(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+432));}
inline void set_ALLsentenceF00_buff2(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+432),val,216); }
inline void set_ALLsentenceF00_buff2_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+432))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff2(var,index) (*((sentenceF00 *)(((char *)(&(var)))+432)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff3(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+648));}
inline void set_ALLsentenceF00_buff3(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+648),val,216); }
inline void set_ALLsentenceF00_buff3_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+648))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff3(var,index) (*((sentenceF00 *)(((char *)(&(var)))+648)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff4(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+864));}
inline void set_ALLsentenceF00_buff4(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+864),val,216); }
inline void set_ALLsentenceF00_buff4_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+864))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff4(var,index) (*((sentenceF00 *)(((char *)(&(var)))+864)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff5(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+1080));}
inline void set_ALLsentenceF00_buff5(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+1080),val,216); }
inline void set_ALLsentenceF00_buff5_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+1080))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff5(var,index) (*((sentenceF00 *)(((char *)(&(var)))+1080)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff6(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+1296));}
inline void set_ALLsentenceF00_buff6(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+1296),val,216); }
inline void set_ALLsentenceF00_buff6_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+1296))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff6(var,index) (*((sentenceF00 *)(((char *)(&(var)))+1296)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff7(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+1512));}
inline void set_ALLsentenceF00_buff7(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+1512),val,216); }
inline void set_ALLsentenceF00_buff7_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+1512))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff7(var,index) (*((sentenceF00 *)(((char *)(&(var)))+1512)+index))

/*  */
inline sentenceF00* get_ALLsentenceF00_buff8(ALLsentenceF00* var) {return ((sentenceF00*)((char*)var->data+1728));}
inline void set_ALLsentenceF00_buff8(ALLsentenceF00* var, sentenceF00* val) { memcpy(((char*)var->data+1728),val,216); }
inline void set_ALLsentenceF00_buff8_ar(ALLsentenceF00* var, sentenceF00* val, INT32 index) { memcpy((((sentenceF00*)((char*)var->data+1728))+index),val,SENTENCEF00_SIZE); }
#define ALLsentenceF00_buff8(var,index) (*((sentenceF00 *)(((char *)(&(var)))+1728)+index))

/* ALLsentenceF03 declaration  */
typedef struct {
	DOUBLE32 data[729];
} ALLsentenceF03;

#define ALLSENTENCEF03_SIZE 5832
inline int sizeOfALLsentenceF03() {return 5832;}

/*  */
inline sentenceF03* get_ALLsentenceF03_buff0(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+0));}
inline void set_ALLsentenceF03_buff0(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+0),val,648); }
inline void set_ALLsentenceF03_buff0_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+0))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff0(var,index) (*((sentenceF03 *)(((char *)(&(var)))+0)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff1(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+648));}
inline void set_ALLsentenceF03_buff1(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+648),val,648); }
inline void set_ALLsentenceF03_buff1_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+648))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff1(var,index) (*((sentenceF03 *)(((char *)(&(var)))+648)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff2(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+1296));}
inline void set_ALLsentenceF03_buff2(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+1296),val,648); }
inline void set_ALLsentenceF03_buff2_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+1296))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff2(var,index) (*((sentenceF03 *)(((char *)(&(var)))+1296)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff3(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+1944));}
inline void set_ALLsentenceF03_buff3(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+1944),val,648); }
inline void set_ALLsentenceF03_buff3_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+1944))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff3(var,index) (*((sentenceF03 *)(((char *)(&(var)))+1944)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff4(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+2592));}
inline void set_ALLsentenceF03_buff4(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+2592),val,648); }
inline void set_ALLsentenceF03_buff4_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+2592))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff4(var,index) (*((sentenceF03 *)(((char *)(&(var)))+2592)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff5(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+3240));}
inline void set_ALLsentenceF03_buff5(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+3240),val,648); }
inline void set_ALLsentenceF03_buff5_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+3240))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff5(var,index) (*((sentenceF03 *)(((char *)(&(var)))+3240)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff6(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+3888));}
inline void set_ALLsentenceF03_buff6(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+3888),val,648); }
inline void set_ALLsentenceF03_buff6_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+3888))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff6(var,index) (*((sentenceF03 *)(((char *)(&(var)))+3888)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff7(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+4536));}
inline void set_ALLsentenceF03_buff7(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+4536),val,648); }
inline void set_ALLsentenceF03_buff7_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+4536))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff7(var,index) (*((sentenceF03 *)(((char *)(&(var)))+4536)+index))

/*  */
inline sentenceF03* get_ALLsentenceF03_buff8(ALLsentenceF03* var) {return ((sentenceF03*)((char*)var->data+5184));}
inline void set_ALLsentenceF03_buff8(ALLsentenceF03* var, sentenceF03* val) { memcpy(((char*)var->data+5184),val,648); }
inline void set_ALLsentenceF03_buff8_ar(ALLsentenceF03* var, sentenceF03* val, INT32 index) { memcpy((((sentenceF03*)((char*)var->data+5184))+index),val,SENTENCEF03_SIZE); }
#define ALLsentenceF03_buff8(var,index) (*((sentenceF03 *)(((char *)(&(var)))+5184)+index))

/* ALLsentenceF18 declaration  */
typedef struct {
	DOUBLE32 data[648];
} ALLsentenceF18;

#define ALLSENTENCEF18_SIZE 5184
inline int sizeOfALLsentenceF18() {return 5184;}

/*  */
inline sentenceF18* get_ALLsentenceF18_buff0(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+0));}
inline void set_ALLsentenceF18_buff0(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+0),val,576); }
inline void set_ALLsentenceF18_buff0_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+0))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff0(var,index) (*((sentenceF18 *)(((char *)(&(var)))+0)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff1(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+576));}
inline void set_ALLsentenceF18_buff1(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+576),val,576); }
inline void set_ALLsentenceF18_buff1_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+576))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff1(var,index) (*((sentenceF18 *)(((char *)(&(var)))+576)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff2(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+1152));}
inline void set_ALLsentenceF18_buff2(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+1152),val,576); }
inline void set_ALLsentenceF18_buff2_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+1152))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff2(var,index) (*((sentenceF18 *)(((char *)(&(var)))+1152)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff3(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+1728));}
inline void set_ALLsentenceF18_buff3(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+1728),val,576); }
inline void set_ALLsentenceF18_buff3_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+1728))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff3(var,index) (*((sentenceF18 *)(((char *)(&(var)))+1728)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff4(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+2304));}
inline void set_ALLsentenceF18_buff4(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+2304),val,576); }
inline void set_ALLsentenceF18_buff4_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+2304))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff4(var,index) (*((sentenceF18 *)(((char *)(&(var)))+2304)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff5(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+2880));}
inline void set_ALLsentenceF18_buff5(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+2880),val,576); }
inline void set_ALLsentenceF18_buff5_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+2880))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff5(var,index) (*((sentenceF18 *)(((char *)(&(var)))+2880)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff6(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+3456));}
inline void set_ALLsentenceF18_buff6(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+3456),val,576); }
inline void set_ALLsentenceF18_buff6_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+3456))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff6(var,index) (*((sentenceF18 *)(((char *)(&(var)))+3456)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff7(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+4032));}
inline void set_ALLsentenceF18_buff7(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+4032),val,576); }
inline void set_ALLsentenceF18_buff7_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+4032))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff7(var,index) (*((sentenceF18 *)(((char *)(&(var)))+4032)+index))

/*  */
inline sentenceF18* get_ALLsentenceF18_buff8(ALLsentenceF18* var) {return ((sentenceF18*)((char*)var->data+4608));}
inline void set_ALLsentenceF18_buff8(ALLsentenceF18* var, sentenceF18* val) { memcpy(((char*)var->data+4608),val,576); }
inline void set_ALLsentenceF18_buff8_ar(ALLsentenceF18* var, sentenceF18* val, INT32 index) { memcpy((((sentenceF18*)((char*)var->data+4608))+index),val,SENTENCEF18_SIZE); }
#define ALLsentenceF18_buff8(var,index) (*((sentenceF18 *)(((char *)(&(var)))+4608)+index))

/* ephemeris declaration  */
typedef struct {
	DOUBLE32 data[481];
} ephemeris;

#define EPHEMERIS_SIZE 3848
inline int sizeOfephemeris() {return 3848;}

/*  */
inline sentenceF22* get_ephemeris_ephemeris(ephemeris* var) {return ((sentenceF22*)((char*)var->data+0));}
inline void set_ephemeris_ephemeris(ephemeris* var, sentenceF22* val) { memcpy(((char*)var->data+0),val,3840); }
inline void set_ephemeris_ephemeris_ar(ephemeris* var, sentenceF22* val, INT32 index) { memcpy((((sentenceF22*)((char*)var->data+0))+index),val,SENTENCEF22_SIZE); }
#define ephemeris_ephemeris(var,index) (*((sentenceF22 *)(((char *)(&(var)))+0)+index))

/* The last index of the ephemeris array set */
inline BYTE32* get_ephemeris_indexLastF22(ephemeris* var, BYTE32* toSet) { return (BYTE32*)memcpy(toSet,(BYTE32*)((char*)var->data+3840),BYTE32_SIZE); }
inline void set_ephemeris_indexLastF22(ephemeris* var, BYTE32 val) { memcpy(((char*)var->data+3840),(void*)&val,BYTE32_SIZE); return; }
#define ephemeris_indexLastF22(var) (*((BYTE32 *)(((char *)(&(var)))+3840)))

/* Ionosphere_Data declaration  */
typedef struct {
	DOUBLE32 data[37];
} Ionosphere_Data;

#define IONOSPHERE_DATA_SIZE 296
inline int sizeOfIonosphere_Data() {return 296;}

/*  */
inline sentenceF23* get_Ionosphere_Data_buff0(Ionosphere_Data* var) {return ((sentenceF23*)((char*)var->data+0));}
inline void set_Ionosphere_Data_buff0(Ionosphere_Data* var, sentenceF23* val) { memcpy(((char*)var->data+0),val,288); }
inline void set_Ionosphere_Data_buff0_ar(Ionosphere_Data* var, sentenceF23* val, INT32 index) { memcpy((((sentenceF23*)((char*)var->data+0))+index),val,SENTENCEF23_SIZE); }
#define Ionosphere_Data_buff0(var,index) (*((sentenceF23 *)(((char *)(&(var)))+0)+index))

/*  */
inline INT32* get_Ionosphere_Data_gps_data_current_idx(Ionosphere_Data* var, INT32* toSet) { return (INT32*)memcpy(toSet,(INT32*)((char*)var->data+288),INT32_SIZE); }
inline void set_Ionosphere_Data_gps_data_current_idx(Ionosphere_Data* var, INT32 val) { memcpy(((char*)var->data+288),(void*)&val,INT32_SIZE); return; }
#define Ionosphere_Data_gps_data_current_idx(var) (*((INT32 *)(((char *)(&(var)))+288)))

#define GSL_SENDER_GROUND 0x00

#define GSL_SENDER_CROSSLINK 0x01

#define IGSL_SUCCESS 0

#define IGSL_GEN_ERR 1

#define IGSL_MEM_ERR 2

#define IGSL_ERR_MSG 4

#define GSL_TYPE_WAIT 0x00

#define GSL_TYPE_THS 0x01

#define GSL_TYPE_DM 0x02

#define GSL_TYPE_TRANS_CMD 0x03

#define GSL_TYPE_NTRANS_CMD 0x04

#define GSL_TYPE_CMD_FAILURE 0x05

#define GSL_TYPE_CONFIRM_CMD 0x06

#define GSL_TYPE_EX_CLEAR 0x07

#define GSL_TYPE_CLEAR 0x08

#define GSL_TYPE_RESEND_LIST 0x09

#define GSL_CMD_ERROR 0x0A

#define GSL_CMD_CUCP 0x0B

#define GSL_CMD_RESET_SUBSYSTEM_STATUS 0x0C

#define GSL_CMD_REPROGRAM 0x0D

#define GSL_CMD_PRESSLINK_PING_RESP 0x0E

#define GSL_CMD_PRESSLINK_PING 0x0F

#define GSL_CMD_DOWNLINK 0x10

#define GSL_CMD_SHELL 0x11

#define GSL_CMD_PRESSLINK_COMMAND 0x12

#define GSL_CMD_PRESSLINK_ACTIVE 0x13

#define GSL_CMD_PRESSLINK_CLEAR_RESPONSE 0x14

#define GSL_CMD_REBOOT 0x15

#define GSL_CMD_UPLOAD_FILE 0x16

#define GSL_CMD_TAKE_PICTURE 0x17

#define GSL_RESPONSE_PKTS_RECEIVED 0x18

#define GSL_CMD_UPLINK 0x19

#define GSL_CMD_TEST_PPT 0x1B

#define GSL_CMD_TEST_IMI 0x1C

#define GSL_CMD_TCAP 0x1D

#define GSL_CMD_LIST_PICTURES 0x1E

#define GSL_CMD_GET_PICTURE 0x1F

#define GSL_NO_SUBTYPE 0x20

#define GSL_DOWNLINK_LOG 0x21

#define GSL_DOWNLINK_VERSION 0x22

#define GSL_DOWNLINK_PWRTELEM 0x23

#define GSL_DOWNLINK_CAMTELEM 0x24

#define GSL_DOWNLINK_PRESSLINK 0x25

#define GSL_DOWNLINK_CDHTELEM 0x26

#define GSL_DOWNLINK_GPSTELEM 0x27

#define GSL_DOWNLINK_PPTSTATUS 0x28

#define GSL_DOWNLINK_sentenceF00 0x2A

#define GSL_DOWNLINK_sentenceF03 0x2B

#define GSL_DOWNLINK_sentenceF18 0x2C

#define GSL_DOWNLINK_sentenceF22 0x2D

#define GSL_DOWNLINK_sentenceF23 0x2E

#define GSL_DOWNLINK_GPSVALID 0x2F

#define GSL_DOWNLINK_INDEXLASTF22 0x30

#define GSL_DOWNLINK_GPSindex 0x31

#define GSL_DOWNLINK_RESPSTATUS 0x32

#define GSL_DOWNLINK_crossGPSDATA_local 0x33

#define GSL_DOWNLINK_crossGPSDATA_remote 0x34

#define GSL_DOWNLINK_pressGPSDATA 0x35

#define GSL_DOWNLINK_CDGPSVECTORS 0x36

#define GSL_DOWNLINK_KFATTESTIMATE 0x37

#define GSL_DOWNLINK_ADCNSconstants 0x38

#define GSL_DOWNLINK_KFATTconstants 0x39

#define GSL_DOWNLINK_MOMSPARAMS 0x3B

#define GSL_DOWNLINK_CDGPSPARAMS 0x3C

#define GSL_DOWNLINK_MOMSTELEM 0x3D

#define GSL_DOWNLINK_TIME 0x3E

#define GSL_DOWNLINK_FILE 0x3F

#define GSL_DOWNLINK_MULTICDGPSVECTORS 0x5D

#define GSL_DOWNLINK_RADIOCOMM_PARAM 0x60

#define GSL_DOWNLINK_CUCP_STATUS 0x29

#define GSL_DOWNLINK_THS 0x40

#define GSL_DOWNLINK_IMIDATA 0x72

#define GSL_DOWNLINK_POSCTRL_DATA 0x67

#define GSL_DOWNLINK_FAULT_STATUS 0x68

#define GSL_DOWNLINK_FAULT_SWPARAMS 0x69

#define GSL_DOWNLINK_FAULT_PARAMETERS 0x6A

#define GSL_DOWNLINK_GENPAR 0x6D

#define GSL_DOWNLINK_INSPECTIONPARAMS 0x6E

#define GSL_DOWNLINK_OTSPARAMS 0x6F

#define GSL_DOWNLINK_POSCTRL_PARAMS 0x70

#define GSL_DOWNLINK_KDU_ARGS 0x71

#define GSL_UPLINK_PRESSLINK 0x43

#define GSL_UPLINK_crossGPSDATA1 0x51

#define GSL_UPLINK_crossGPSDATA2 0x5E

#define GSL_UPLINK_crossGPSDATA3 0x5F

#define GSL_UPLINK_pressGPSDATA 0x52

#define GSL_UPLINK_ADCNSconstants 0x55

#define GSL_UPLINK_KFATTconstants 0x56

#define GSL_UPLINK_GENPAR 0x57

#define GSL_UPLINK_MOMSPARAMS 0x58

#define GSL_UPLINK_CDGPSPARAMS 0x59

#define GSL_UPLINK_MOMSCMD 0x5A

#define GSL_UPLINK_TIME 0x5B

#define GSL_UPLINK_INSPECTIONPARAMS 0x61

#define GSL_UPLINK_OTSPARAMS 0x62

#define GSL_UPLINK_POSCTRL_PARAMS 0x63

#define GSL_UPLINK_FAULT_STATUS 0x64

#define GSL_UPLINK_FAULT_SWPARAMS 0x65

#define GSL_UPLINK_FAULT_PARAMETERS 0x66

#define GSL_UPLINK_KDU_ARGS 0x6C

#define GSL_UPLINK_RADIOCOMM_PARAM 0x6B


#endif /* end if _cucp_def_data_h_ */
