/*! \file *********************************************************************
 *
 * \brief USART Serial configuration
 *
 * Copyright (C) 2011 Atmel Corporation. All rights reserved.
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 * Atmel AVR product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */
 
#ifndef CONF_USART_SERIAL_H_INCLUDED
#define CONF_USART_SERIAL_H_INCLUDED

#include "conf_board.h"

/**
 *	
 *	Radio IB Rev. 4 connected USARTs:
 *
 * *	Device.......................Pins............USART
 * *	Radio.......................??,??............C0
 * *	CDHIB.......................??,??............D0
 *
*/

// BEGIN UARTS
// Radio
#define RADIO_UART 							USARTC0
#define RADIO_UART_RXC_vect					USARTC0_RXC_vect
#define DMA_CH_TRIGSRC_RADIO_UART_DRE_gc	DMA_CH_TRIGSRC_USARTC0_DRE_gc
// FC
#define CDHIB_UART 							USARTD0
#define CDHIB_UART_RXC_vect					USARTD0_RXC_vect
#define DMA_CH_TRIGSRC_CDHIB_UART_DRE_gc	DMA_CH_TRIGSRC_USARTD0_DRE_gc
// END UARTS

// Baud Rates for the different USARTS
#define RADIO_UART_BAUDRATE		9600		///< Radio USART Baud rate
#define CDHIB_UART_BAUDRATE		9600		///< CDHIB USART Baud rate


#endif /* CONF_USART_SERIAL_H_INCLUDED */
