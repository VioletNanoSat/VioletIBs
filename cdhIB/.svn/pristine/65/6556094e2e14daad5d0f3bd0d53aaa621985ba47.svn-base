/** \file
 * cdhib.h
 * \brief CDH IB header file
 *
 * Created: 3/5/2012
 *  Author: Liran
 */ 


#ifndef CDHIB_H_
#define CDHIB_H_

#define CDHIB_COMMAND_PACKET_SIZE	3			///< Size in bytes of the command packet
#define NOOP_COMMAND				0x00		///< No Op command code from FC
#define THS_CHANGE_INTERVAL_COMMAND	0xF0		///< THS interval change command code
#define FC_TELEMETRY_PACKET			0x0F		///< FC Telemetry packet 
#define ACK_SIZE					3			///< Size in bytes of the Acknowledge packet
#define PWR_WDOG_TX_INTERVAL		600			///< Interval (in seconds) between watchdog transmissions to power mcu
#define	POWER_NOOP_SIZE				1			///< Size in bytes of the power noop packet
#define FC_TELEMETRY_SIZE			30			///< Size in bytes of FC telemetry packet


typedef struct {
	
	uint8_t			Command_Header;						///< 8 bit header of the command packet
	uint16_t		Command_Argument; 					///< 16 bit argument of the command packet
	uint8_t			FC_Telemetry[FC_TELEMETRY_SIZE];	///< Telemetry packet from the FC
	
} FC_Packet_t;											///< Structure of the Flight Computer command packet

FC_Packet_t			FC_packet;							///< Buffer for Packet from the Flight Computer

typedef struct {
	
	uint8_t			Command_Header;				///< 8 bit header of the command packet
	uint16_t		Command_Argument; 			///< 16 bit argument of the command packet
	
} Radio_Packet_t;								///< Structure of the Radio command packet

Radio_Packet_t		Radio_Command_packet;		///< Command packet from the Radio (Ground)

uint8_t						ACK[ACK_SIZE];				///< Buffer to hold the Ack packet
uint8_t						PWR_NOOP[POWER_NOOP_SIZE];	///< Buffer to hold the Power noop packet
Bool						FC_command_received;		///< Flag to indicate a command packet from the Flight Computer
Bool						Radio_command_received;		///< Flag to indicate a command packet from the Radio (Ground)
volatile extern uint16_t	PWR_WDOG_Seconds_counter;	///< Power WatchDog Interval Seconds counter
	
#endif /* CDHIB_H_ */