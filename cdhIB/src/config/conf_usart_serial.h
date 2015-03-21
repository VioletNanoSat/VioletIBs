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
 *	CDH IB Rev. 3 connected USARTs:
 *
 * *	CDH 1.......................Pins............USART
 * *	Power.......................22,23............C1
 * *	GPS.........................38,39............E0
 * *	Radio.......................32,33............D1
 * *	Flight Computer.............28,29............D0
 * *	Star Tracker................42,43............E1
 *
 *
 * *	CDH 2.......................Pins............USART
 * *	Power.......................18,19............C0
 * *	GPS.........................22,23............C1
 * *	Radio.......................42,43............E1
 * *	Flight Computer.............38,39............E0
 * *	sun Sensor..................28,29............D0
 *
*/

#ifdef MCU_CDH_1 
		// Power 
		#define POWER_UART 							USARTC1
		#define POWER_UART_RXC_vect					USARTC1_RXC_vect
		#define DMA_CH_TRIGSRC_POWER_UART_DRE_gc	DMA_CH_TRIGSRC_USARTC1_DRE_gc
		// GPS
		#define GPS_UART 							USARTE0
		#define GPS_UART_RXC_vect					USARTE0_RXC_vect
		#define DMA_CH_TRIGSRC_GPS_UART_DRE_gc		DMA_CH_TRIGSRC_USARTE0_DRE_gc
		// Radio
		#define RADIO_UART 							USARTD1
		#define RADIO_UART_RXC_vect					USARTD1_RXC_vect
		#define DMA_CH_TRIGSRC_RADIO_UART_DRE_gc	DMA_CH_TRIGSRC_USARTD1_DRE_gc
		// FC
		#define FC_UART 							USARTD0
		#define FC_UART_RXC_vect					USARTD0_RXC_vect
		#define DMA_CH_TRIGSRC_FC_UART_DRE_gc		DMA_CH_TRIGSRC_USARTD0_DRE_gc
		// Star Tracker
		#define STAR_UART 							USARTE1
		#define STAR_UART_RXC_vect					USARTE1_RXC_vect
		#define DMA_CH_TRIGSRC_STAR_UART_DRE_gc		DMA_CH_TRIGSRC_USARTE1_DRE_gc

#elif defined MCU_CDH_2
		// Power
		#define POWER_UART 							USARTC0
		#define POWER_UART_RXC_vect					USARTC0_RXC_vect
		#define DMA_CH_TRIGSRC_POWER_UART_DRE_gc	DMA_CH_TRIGSRC_USARTC0_DRE_gc
		// GPS
		#define GPS_UART 							USARTC1
		#define GPS_UART_RXC_vect					USARTC1_RXC_vect
		#define DMA_CH_TRIGSRC_GPS_UART_DRE_gc		DMA_CH_TRIGSRC_USARTC1_DRE_gc
		// Radio
		#define RADIO_UART 							USARTE1
		#define RADIO_UART_RXC_vect					USARTE1_RXC_vect
		#define DMA_CH_TRIGSRC_RADIO_UART_DRE_gc	DMA_CH_TRIGSRC_USARTE1_DRE_gc
		// FC
		#define FC_UART 							USARTE0
		#define FC_UART_RXC_vect					USARTE0_RXC_vect
		#define DMA_CH_TRIGSRC_FC_UART_DRE_gc		DMA_CH_TRIGSRC_USARTE0_DRE_gc
		// Sun Sensor
		#define SUN_UART 							USARTD0
		#define SUN_UART_RXC_vect					USARTD0_RXC_vect
		#define DMA_CH_TRIGSRC_SUN_UART_DRE_gc		DMA_CH_TRIGSRC_USARTD0_DRE_gc

#else
	#error MCU not defined in conf_board.h	
#endif


// Baud Rates for the different USARTS
#define POWER_UART_BAUDRATE		9600		///< Power USART Baud rate
#define GPS_UART_BAUDRATE		9600		///< GPS USART Baud rate
#define RADIO_UART_BAUDRATE		9600		///< Radio USART Baud rate
#define FC_UART_BAUDRATE		9600		///< Flight Computer USART Baud rate
#define STAR_UART_BAUDRATE		9600		///< Star Tracker USART Baud rate NOT SURE THESE SHOULD BE 9600
#define SUN_UART_BAUDRATE		57600		///< Sun Sensor USART Baud rate NOT SURE THESE SHOULD BE 9600


#endif /* CONF_USART_SERIAL_H_INCLUDED */
