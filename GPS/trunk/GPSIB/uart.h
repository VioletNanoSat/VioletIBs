#ifndef uart_h
#define uart_h

#include <stdio.h>
#include <avr/io.h>
#include "main.h"
#include "common.h"

#define ASYNCHRONOUS_NORMAL CLOCK_SPEED/16
#define RECEIVER_BAUD_RATE	76800
#define CDHIB_BAUD_RATE		9600//115200//9600

uint32 get_ubrr(uint32 baud);

// usart0
void usart0_initialize(uint32 ubrr);

inline void usart0_rx_interrupt_enable()  { UCSR0B |= (1<<RXCIE0);	}
inline void usart0_rx_interrupt_disable() { UCSR0B &= ~(1<<RXCIE0);	}
inline void usart0_tx_interrupt_enable()  { UCSR0B |= (1<<UDRIE0);	}
inline void usart0_tx_interrupt_disable() { UCSR0B &= ~(1<<UDRIE0);	}


// usart1
void usart1_initialize(uint32 ubrr);

inline void usart1_rx_interrupt_enable()  { UCSR1B |= (1<<RXCIE1);	}
inline void usart1_rx_interrupt_disable() { UCSR1B &= ~(1<<RXCIE1);	}
inline void usart1_tx_interrupt_enable()  { UCSR1B |= (1<<UDRIE1);	}
inline void usart1_tx_interrupt_disable() { UCSR1B &= ~(1<<UDRIE1);	}

#endif
