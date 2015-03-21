/** \file
 * conf_scheduler.h
 *
 * \brief Scheduler configuration
 *
 *	SCHEDULER CONFIGURATION 
 * *	Define the appropriate tasks and their order for each MCU
 * *	If there are more than 10 tasks, add ifdefs in scheduler.c and scheduler.h
 * *	Tasks are in tasks.c
 *
 *  Author: Liran
 */ 

#ifndef _CONF_SCHEDULER_H_
#define _CONF_SCHEDULER_H_

#include "conf_board.h"

#ifdef MCU_CDH_1 
	#define Scheduler_task_1        power_task
	#define Scheduler_task_2        gps_task
	#define Scheduler_task_3        radio_task
	#define Scheduler_task_4        fc_task
	#define Scheduler_task_5        star_task
	//#define Scheduler_task_6        ths_task
	#define Scheduler_task_7        cdhib_task
	#define Scheduler_task_8        tcap_task
	
#elif defined MCU_CDH_2
	//#define Scheduler_task_1        power_task
	#define Scheduler_task_2        gps_task
	#define Scheduler_task_3        radio_task
	#define Scheduler_task_4        fc_task
	#define Scheduler_task_5        sun_task
	//#define Scheduler_task_6        ths_task
	#define Scheduler_task_7        cdhib_task
	#define Scheduler_task_8        tcap_task
		
#else
	#error MCU not defined in conf_board.h	
#endif

#endif  //! _CONF_SCHEDULER_H_

