/** \file
 * ths.h
 * \brief THS header file
 *
 * Created: 3/5/2012
 *  Author: Liran
 */ 


#ifndef THS_H_
#define THS_H_

#include "../config/conf_usart_serial.h"
#include "cdhib.h"

#define		DEFAULT_THS_INTERVAL_SECONDS	60				///< Default time interval between THS beacon transmissions (in Seconds)
#define		MINIMUM_THS_INTERVAL_SECONDS	20				///< Minimum time interval between THS beacon transmissions (in Seconds)
#define		MAXIMUM_THS_INTERVAL_SECONDS	300				///< Maximum time interval between THS beacon transmissions (in Seconds)

#define		THS_POWER_TELEMETRY_SIZE		96				///< Power telemetry size in bytes

/// GPS F00 Stucture
typedef struct {
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
} GPS_F00_t;

/// GPS Telemetry structure
typedef struct {
	uint8	gps_temp;
	uint8	gpsib_temp;
	uint8	radio_temp;
	uint8	last_command;
	uint8	command_success;
	uint8	last_satellite;
	uint8	telem_reserved;	
} GPS_telem_t;

/// GPS packet structure
typedef struct {
	uint8		packet_status;
	GPS_telem_t	packet_telem;
	GPS_F00_t 	packet_f00;
} GPS_packet_t;

/// Power telemetry packet structure
typedef struct {
	uint8		Telemetry[THS_POWER_TELEMETRY_SIZE];
} Power_telemetry_t;

/// FC telemetry packet structure
typedef struct {
	uint8		Telemetry[FC_TELEMETRY_SIZE];
} FC_telemetry_t;

/// THS beacon structure
typedef struct {

	// Fill this up with beacon structure
	GPS_packet_t		GPS_Packet;			///< Holds Telemetry packet from the GPS  
	FC_telemetry_t		FC_Telemetry;		///< Holds Telemetry packet from the FC
	Power_telemetry_t	Power_Telemetry;	///< Holds Telemetry packet from the Power board
	
} THS_Beacon_t;								///< THS beacon structure

THS_Beacon_t THS_Beacon;					///< Buffer to hold the THS data

uint16_t					THS_interval_seconds;			///< Actual THS interval
uint16_t					Commanded_THS_interval_seconds;	///< Interval recieved by command packet 
Bool						External_THS_trigger;			///< Trigger to force THS beacon transmission
volatile extern uint16_t	THS_Seconds_counter;			///< Count seconds in Timer ISR

void Collect_THS_data(void); 								///< See memory.c

#endif /* THS_H_ */