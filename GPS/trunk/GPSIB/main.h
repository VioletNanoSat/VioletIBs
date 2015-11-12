#ifndef main_h
#define main_h

#include <avr/io.h>
#include <avr/interrupt.h>

// Define COMM_DEBUG when transmitting to a computer
// When not defined, the IB will transmit in VCP 
#define COMM_DEBUG

// Define the MCU target board - GPSIB Rev.2, GPSIB Rev.3, or STK500
//#define STK500
//#define GPSIB_REV_2
#define GPSIB_REV_3

// Define clock frequency and I/Os depending on target
#if defined (STK500)
	#define CLOCK_SPEED				14745600UL		// 14.7456 MHz
	#define ADC_THERM_GPS_CHANNEL	0
	#define ADC_THERM_RADIO_CHANNEL	1
	#define ADC_THERM_GPSIB_CHANNEL	2
#elif defined (GPSIB_REV_2)
	#define CLOCK_SPEED				14745600UL		// 16 MHz? - measured 14.7456 on scope
	#define ADC_THERM_GPS_CHANNEL	3
	#define ADC_THERM_RADIO_CHANNEL	4
	#define ADC_THERM_GPSIB_CHANNEL	1
#elif defined (GPSIB_REV_3)	
	#define CLOCK_SPEED				14745600UL		// 14.7456 MHz
	#define ADC_THERM_GPS_CHANNEL	0
	#define ADC_THERM_RADIO_CHANNEL	1
	#define ADC_THERM_GPSIB_CHANNEL	2
#else 
	#error Must define target Board!	
#endif

#define RECEIVER_DEAD_TIME 			300 // seconds of no time sync before receiver declared dead
#define IB_TRANSMIT_TRIGGER_TIME	3 	// seconds of no time sync before IB triggers transmission

// general state variables
// bytes 0 and 1 are reserved for uart maintenance
// bytes 2 through 7 can be used by other entities though
#define USART_RX_READY    0x01
#define USART_TX_COMPLETE 0x02

#define set_usart_state(a, b)	(a = (a^(a&0xFC))|b) // remove the current state and set the new one
#define get_usart_state(a)		(a & 0xFC)			  // get the current state

#define set_gen_state(a, b)		(a |= b)
#define rem_gen_state(a, b)		(a &= ~b)
#define get_gen_state(a, b)		((a & b) != 0)


// Functions - see main.c
void send				(char *str, int len);
void send_VCP_data		(void);
void initialize			(void);
void retrieve_gps_data	(void);
void check_pgood		(void);
void check_time			(void);

#endif
