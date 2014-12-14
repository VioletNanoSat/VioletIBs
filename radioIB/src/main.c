/**
 * \file main.c
 *
 *  Author: Liran
*/

/*
 * Include header files for all drivers that have been imported from
 * AVR Software Framework (ASF).
 */
#include <asf.h>

/*
 * Includes
*/
#include "scheduler/scheduler.h"

/**
 * Name         : main
 *
 * Synopsis     : int main()
 *
 * Description  : Entry point. Initialize the board and run the scheduler. 
 * 
 */
int main (void)
{

	// Init - in init.c
	board_init();
			
	// Run scheduler - in scheduler.c
	scheduler();
}

/* TODO


*/
