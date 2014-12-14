/** \file
 * memory.h
 * \brief Memory header file
 *
 *  Author: Liran
 */ 


#ifndef MEMORY_H_
#define MEMORY_H_

#include <asf.h>
#include "../vcp/common.h"
#include "LightweightRingBuff.h"
#include "dma_driver.h"
#include "../tasks/tasks.h"
#include "config/conf_usart_serial.h"
#include "../vcp/vcp_library.h"
#include "../lithium/lithium.h"


// VCP transmit Buffers size
#define CDHIB_TRANSMIT_MESSAGE_BUFF_SIZE	520			///< Flight Computer transmit buffer size (VCP)
#define RADIO_TRANSMIT_MESSAGE_BUFF_SIZE	520			///< Radio transmit buffer size (VCP)


/// Peripheral structure
typedef struct {
	
	// Hardware
	USART_t *					USART;						///< USART associated with this peripheral
	volatile DMA_CH_t *			DMA_channel;				///< DMA channel for data transmission
	
	// Buffers
	Receive_RingBuff_t 			rx_ringbuff;				///< ring buffer to receive from USART
	uint8ptr					tx_data;					///< linear buffer for VCP frame ready to transmit
	uint16_t					tx_data_buffer_size;		///< allocated size of transmit buffer
	
	// Flags and Counters
	volatile uint8_t			rx_ringbuff_overflow;		///< counts receive ring buffer overflow
	Bool						tx_data_ready;				///< flag for VCP decoding done and non-VCP data ready 
	uint16_t					tx_byte_count;				///< bytes to tx in transmit buffer (actual data size)

	// VCP
	uint8_t						VCP_address;				///< VCP address
	uint8_t						tx_status;				///< VCP transmit status register
	uint16_t					tx_packet_count;			///< keeps track of number of packets transmitted to this peripheral
	
	uint8_t						cdh_state;
	uint8_t						dummy;
	
	uint8ptr					radio_pre_vcp;
	uint16_t					radio_packet_size;
	uint8_t						dest_address;
	uint8_t						rejected_packets; 

	#ifdef DEBUG
		uint8_t					tx_LED_pin;					///< DEUBG - STK LED pin	
		uint8_t					rx_LED_pin;					///< DEUBG - STK LED pin
	#endif
	
} peripheral_t;

// Declare peripheral structures
peripheral_t					cdhib;							///< Flight Computer Peripheral
peripheral_t					radio;						///< Radio Peripheral
peripheral_t					radioib;						///< CDHIB (Self) Peripheral - enables the use of all the peripheral functions



// Data buffers allocation
uint8_t cdhib_tx_data			[CDHIB_TRANSMIT_MESSAGE_BUFF_SIZE];		///< Flight Computer transmit buffer allocation
uint8_t radio_non_vcp			[RADIO_TRANSMIT_MESSAGE_BUFF_SIZE];		///< To CDHIB non VCPd packets
uint8_t radio_tx_data			[RADIO_TRANSMIT_MESSAGE_BUFF_SIZE];		///< Radio transmit buffer allocation


// Functions
void clock_init					(void);												///< See init.c
void memory_init				(void);												///< See memory.c
void dma_init					(void);												///< See memory.c
void read_CDH_receive_buff		(void);												///< See memory.c
void read_radio_receive_buff	(void);												///< See memory.c
void send_radio_error			(void);												///< See memory.c
void DMA_transmit				(peripheral_t* Peripheral);							///< See memory.c
void switch_to_ext_osc			(void);												///< See init.c
#endif /* MEMORY_H_ */