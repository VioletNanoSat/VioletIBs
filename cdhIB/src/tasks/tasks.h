/** \file
 * tasks.h
 * \brief Tasks header file
 *
 * Created: 12/13/2011
 *  Author: Liran
 */ 

#ifndef TASKS_H_
#define TASKS_H_

#include <asf.h>
#include "../config/conf_board.h"
#include "../memory/memory.h"


volatile extern Bool xosc_recovey;						///< Flag for attempt to recover from external oscillator failure

// VCP address
// All other addresses are defined in vcplib.h
#ifdef MCU_CDH_1 
	#define VCP_RADIO				VCP_RADIO_1			///< VCP address of radio connected to CDH MCU 1
	#define VCP_GPS					VCP_GPS_1			///< VCP address of GPS connected to CDH MCU 1
	#define VCP_CDHIB				VCP_CDHIB_1			///< VCP address of CDH MCU 1
#else	
	#define VCP_RADIO				VCP_RADIO_2			///< VCP address of radio connected to CDH MCU 2
	#define VCP_GPS					VCP_GPS_2			///< VCP address of GPS connected to CDH MCU 2
	#define VCP_CDHIB				VCP_CDHIB_2			///< VCP address of CDH MCU 2
#endif
#ifndef VCP_FC
#define		VCP_FC					0x0B 
#endif
#define		VCP_BAD_ADDRESS			0xAA 


void power_task						(void);				///< See tasks.c			
void gps_task						(void);				///< See tasks.c
void radio_task						(void);				///< See tasks.c
void fc_task						(void);				///< See tasks.c
void ths_task						(void);				///< See tasks.c
void cdhib_task						(void);				///< See tasks.c
void tcap_task						(void);				///< See tasks.c
void kamakaze_send					(void);				///< See tasks.c
#ifdef STAR_UART
void star_task						(void);				///< See tasks.c
#endif
#ifdef SUN_UART
void sun_task						(void);				///< See tasks.c
#endif
#ifdef DEBUG
void debug_task						(void);				///< See tasks.c
#endif

#endif /* TASKS_H_ */