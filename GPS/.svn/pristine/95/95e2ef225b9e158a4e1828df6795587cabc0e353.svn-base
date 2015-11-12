#include "uart.h"

uint32 get_ubrr(uint32 baud)
{
	#if defined(ASYNCHRONOUS_NORMAL)
		return ASYNCHRONOUS_NORMAL/baud - 1;
	#elif defined(ASYNCHRONOUS_DOUBLE)
		return ASYNCHRONOUS_DOUBLE/baud - 1;
	#elif defined(SYNCHRONOUS_MASTER)
		return SYNCHRONOUS_MASTER/baud - 1;
	#else // default to asynchronous normal
		return ASYNCHRONOUS_NORMAL/baud - 1;
	#endif
}

void usart0_initialize(uint32 ubrr)
{
	// set the baud rate
	UBRR0H = (uint8)(ubrr>>8);
	UBRR0L = (uint8)ubrr;
	
	// enable the transmitter
	UCSR0B = (1<<TXEN0);
	// enable the receiver
	//UCSR0B = (1<<RXEN0);

	// set the frame format: 8 bit data, 1 stop bits
	UCSR0C = (1<<UCSZ01) | (1<<UCSZ00);
}

void usart1_initialize(uint32 ubrr)
{
	// set the baud rate
	UBRR1H = (uint8)(ubrr>>8);
	UBRR1L = (uint8)ubrr;
	
	// enable the transmitter
	//UCSR1B = (1<<TXEN1);
	// enable the receiver
	UCSR1B = (1<<RXEN1);
 
	// set the frame format: 8 bit data, 1 stop bits
	UCSR1C = (1<<UCSZ11) | (1<<UCSZ10); 
}


/*
uint8 usart0_rx_poll()
{
	// Wait for data to be received
	loop_until_bit_is_set(UCSR0A, RXC0);

	// Get and return received data from buffer
	return UDR0;
}

void usart0_tx_poll(uint8 data)
{
	// wait for empty transmit buffer
	loop_until_bit_is_set(UCSR0A, UDRE0); 

	// put the data into the buffer
	UDR0 = data;
}

uint8 usart1_rx_poll()
{
	// Wait for data to be received
	loop_until_bit_is_set(UCSR1A, RXC1);

	// Get and return received data from buffer
	return UDR1;
}

void usart1_tx_poll(uint8 data)
{
	// wait for empty transmit buffer
	loop_until_bit_is_set(UCSR1A, UDRE1); 

	// put the data into the buffer
	UDR1 = data;
}

*/