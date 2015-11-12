#ifndef uart_h
#define uart_h

#include <stdio.h>
#include <avr/io.h>
#include "vcplib.h"

#define ASYNCHRONOUS_NORMAL CLOCK_SPEED/16
//#define ASYNCHRONOUS_DOUBLE CLOCK_SPEED/8
//#define SYNCHRONOUS_MASTER CLOCK_SPEED/2

uint32 get_ubrr(uint32 baud);

// usart0
void usart0_initialize(uint32 ubrr);

inline void usart0_rxen_int()  { UCSR0B |= _BV(RXCIE0); }
inline void usart0_rxdis_int() { UCSR0B ^= _BV(RXCIE0); }
inline void usart0_txen_int()  { UCSR0B |= _BV(UDRIE0); }
inline void usart0_txdis_int() { UCSR0B ^= _BV(UDRIE0); }

inline void  usart0_tx_int(uint8 data){ UDR0 = data; }
inline uint8 usart0_rx_int()		  { return UDR0; }

void  usart0_tx_poll(uint8 data);
uint8 usart0_rx_poll();

// usart1
void usart1_initialize(uint32 ubrr);

inline void usart1_rxen_int()  { UCSR1B |= _BV(RXCIE1); }
inline void usart1_rxdis_int() { UCSR1B ^= _BV(RXCIE1); }
inline void usart1_txen_int()  { UCSR1B |= _BV(UDRIE1); }
inline void usart1_txdis_int() { UCSR1B ^= _BV(UDRIE1); }

inline void  usart1_tx_int(uint8 data){ UDR1 = data; }
inline uint8 usart1_rx_int()		  { return UDR1; }

void  usart1_tx_poll(uint8 data);
uint8 usart1_rx_poll();

#endif
