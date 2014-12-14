/**
 * \file
 *
 * \brief User board definition template
 *
 */

#ifndef USER_BOARD_H
#define USER_BOARD_H

/* This file is intended to contain definitions and configuration details for
 * features and devices that are available on the board, e.g., frequency and
 * startup time for an external crystal, external memory devices, LED and USART
 * pins.
 */

extern void interrupts_init		(void);	///< See init.c
extern void usart_init			(void);	///< See init.c
extern void io_init				(void);	///< See init.c
extern void timers_init			(void);	///< See init.c
extern void cdhib_init			(void);	///< See init.c
#endif // USER_BOARD_H
