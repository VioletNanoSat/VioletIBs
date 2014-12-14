/** \file
 * scheduler.h
 * \brief Scheduler header file
 *
 *  Author: Liran
 */ 


#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "config/conf_scheduler.h"
#include "../tasks/tasks.h"

#ifdef DEBUG
  extern  void debug_task       (void);
#endif

// Define scheduler tasks
#ifdef Scheduler_task_1
  extern  void Scheduler_task_1 (void);
#endif
#ifdef Scheduler_task_2
  extern  void Scheduler_task_2 (void);
#endif

void scheduler					(void);	///< See Scheduler.c

#endif //! _SCHEDULER_H_ 

