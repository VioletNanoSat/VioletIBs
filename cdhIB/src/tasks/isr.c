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
volatile uint8_t flag;
volatile uint8_t fendi;
uint8_t pax = 0;
			

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

/// Power USART Receive interrupt handler
ISR(POWER_UART_RXC_vect)
{
	if (RingBuffer_IsFull(&power.rx_ringbuff))
	{
		volatile uint8_t temp = power.USART->DATA;					// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		power.rx_ringbuff_overflow++;								// buffer overflow
	}
	else
	{
		RingBuffer_Insert(&power.rx_ringbuff, power.USART->DATA);	// read received byte into the ring buffer
	}
}

/// GPS USART Receive interrupt handler
ISR(GPS_UART_RXC_vect)
{
	if (RingBuffer_IsFull(&gps.rx_ringbuff))
	{
		volatile uint8_t temp = gps.USART->DATA;					// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		gps.rx_ringbuff_overflow++;									// buffer overflow
	}
	else
	{
		RingBuffer_Insert(&gps.rx_ringbuff, gps.USART->DATA);		// read received byte into the ring buffer
	}
}
	
/// Radio USART Receive interrupt handler		
ISR(RADIO_UART_RXC_vect)
{
	//flag++;
	if (RingBuffer_IsFull(&radio.rx_ringbuff))
	{
		volatile uint8_t temp = radio.USART->DATA;					// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		radio.rx_ringbuff_overflow++;								// buffer overflow
	}
	else
	{
		RingBuffer_Insert(&radio.rx_ringbuff, radio.USART->DATA);	// read received byte into the ring buffer
	}

}
	
/// FC USART Receive interrupt handler
ISR(FC_UART_RXC_vect)
{
	flag++;
	//uint8_t data;
	if (RingBuffer_IsFull(&fc.rx_ringbuff))
	{
		volatile uint8_t temp = fc.USART->DATA;						// clear interrupt flag
		temp++;														// Remove unused variable compiler warning
		fc.rx_ringbuff_overflow++;									// buffer overflow
	}
	else
	{
		/*if(fc.USART->DATA == 0xC0){
			fendi++;
		}else{
			fendi = 0;
		}
		if(fendi<3){*/
			RingBuffer_Insert(&fc.rx_ringbuff, fc.USART->DATA);			// read received byte into the ring buffer
			pax++;
		//}
		//data = fc.USART->DATA;
	}
	if(flag == 8){
		flag = 10;
	}
	
	
}

#ifdef STAR_UART
	/// Star Tracker USART Receive interrupt handler
	ISR(STAR_UART_RXC_vect)
	{
		if (RingBuffer_IsFull(&star.rx_ringbuff))
		{
			volatile uint8_t temp = star.USART->DATA;				// clear interrupt flag
			temp++;													// Remove unused variable compiler warning
			star.rx_ringbuff_overflow++;							// buffer overflow
		}
		else
		{
			RingBuffer_Insert(&star.rx_ringbuff, star.USART->DATA);	// read received byte into the ring buffer
			pax++;
		}				
	}
#endif

#ifdef SUN_UART
	/// Sun Sensor USART Receive interrupt handler
	ISR(SUN_UART_RXC_vect)
	{
		if (RingBuffer_IsFull(&sun.rx_ringbuff))
		{
			volatile uint8_t temp = sun.USART->DATA;				// clear interrupt flag
			temp++;													// Remove unused variable compiler warning
			sun.rx_ringbuff_overflow++;								// buffer overflow
		}
		else
		{
			RingBuffer_Insert(&sun.rx_ringbuff, sun.USART->DATA);	// read received byte into the ring buffer
		}				
	}
#endif
