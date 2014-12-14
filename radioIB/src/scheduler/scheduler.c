/** \file
 * scheduler.c
 * \brief Scheduler source file
 *
 *  Author: Liran
 */ 

#include "scheduler.h"                      // scheduler definition 

/**
 * Name         : scheduler
 *
 * Synopsis     : void scheduler (void)
 *
 * Description  : Task execution scheduler.
 *				  Tasks are defined in conf_scheduler.h
 * 
 */
void scheduler (void)
{

#ifdef DEBUG	// Will only run debug task
	debug_task();
#else			// Run tasks as defined in conf_scheduler.h	
   for(;;)
   {
      #ifdef Scheduler_task_1
         Scheduler_task_1();
      #endif
      #ifdef Scheduler_task_2
         Scheduler_task_2();
      #endif
   }
#endif
}

