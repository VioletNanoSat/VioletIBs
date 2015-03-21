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
      #ifdef Scheduler_task_3
         Scheduler_task_3();
      #endif
      #ifdef Scheduler_task_4
         Scheduler_task_4();
      #endif
      #ifdef Scheduler_task_5
         Scheduler_task_5();
      #endif
      #ifdef Scheduler_task_6
         Scheduler_task_6();
      #endif
      #ifdef Scheduler_task_7
         Scheduler_task_7();
      #endif
      #ifdef Scheduler_task_8
         Scheduler_task_8();
      #endif
      #ifdef Scheduler_task_9
         Scheduler_task_9();
      #endif
      #ifdef Scheduler_task_10
         Scheduler_task_10();
      #endif
   }
#endif
}

