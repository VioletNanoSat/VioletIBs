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


#define Scheduler_task_1        radio_task
#define Scheduler_task_2        cdhib_task

		

#endif  //! _CONF_SCHEDULER_H_

