/** \file
 * isr.c
 * \brief Interrupt Service Routines source file
 *
 *  Author: Liran
 */ 

#include <asf.h>
#include "tasks.h"

volatile uint16_t mSeconds;						///< mSeconds counter
volatile uint16_t THS_Seconds_counter;			///< THS Interval Seconds counter
volatile uint16_t PWR_WDOG_Seconds_counter;		///< Power WatchDog Interval Seconds counter
volatile uint16_t i,j;
volatile Bool xosc_recovey;		
volatile uint16_t flag;		

/// External oscillator failure interrupt handler
ISR(OSC_XOSCF_vect)
{
	clock_init (); // Init clock and use internal 32MHz osc
}

/// Timer 1KHz interrupt handler
ISR(TCC0_OVF_vect)
{
	mSeconds++;
	
	if (mSeconds >= 999)
		{
			mSeconds =		0;
			
			// Advance seconds counters
			THS_Seconds_counter++;
			PWR_WDOG_Seconds_counter++;

			#ifdef DEBUG
				PORTA.OUTTGL =	PIN0_bm; // Toggle LED at 1Hz
			#endif
		}				
}


	
/// Radio USART Receive interrupt handler		
ISR(RADIO_UART_RXC_vect)
{
	if (RingBuffer_IsFull(&radio.rx_ringbuff))
	{
		volatile uint8_t temp = radio.USART->DATA;					// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		radio.rx_ringbuff_overflow++;								// buffer overflow
	}
	else
	{
		//if(radio.USART->DATA != 0xC0){
			RingBuffer_Insert(&radio.rx_ringbuff, radio.USART->DATA);	// read received byte into the ring buffer
		//}
	}

}
	
/// CDHIB USART Receive interrupt handler
ISR(CDHIB_UART_RXC_vect)
{
	if (RingBuffer_IsFull(&cdhib.rx_ringbuff))
	{
		volatile uint8_t temp = cdhib.USART->DATA;						// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		cdhib.rx_ringbuff_overflow++;									// buffer overflow
	}
	else
	{
		RingBuffer_Insert(&cdhib.rx_ringbuff, cdhib.USART->DATA);			// read received byte into the ring buffer
	}		
}
