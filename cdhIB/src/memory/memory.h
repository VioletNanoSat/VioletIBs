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
#include "../tasks/ths.h"
#include "../tasks/cdhib.h"
#include "../vcp/vcp_library.h"


// Non-VCP receive Buffers size
#define POWER_RECEIVE_MESSAGE_BUFF_SIZE		110			///< Power receive buffer size(non - VCP)
#define GPS_RECEIVE_MESSAGE_BUFF_SIZE		90			///< GPS receive buffer size(non - VCP)
#define RADIO_RECEIVE_MESSAGE_BUFF_SIZE		270			///< Radio receive buffer size(non - VCP)
#define STAR_RECEIVE_MESSAGE_BUFF_SIZE		256			///< Star Tracker receive buffer size(non - VCP)
#define SUN_RECEIVE_MESSAGE_BUFF_SIZE		256			///< Sun Sensor receive buffer size(non - VCP)
#define FC_RECEIVE_MESSAGE_BUFF_SIZE		100			///< Flight Computer receive buffer size(non - VCP)

// VCP transmit Buffers size
#define POWER_TRANSMIT_MESSAGE_BUFF_SIZE	200			///< Power transmit buffer size (VCP)
#define FC_TRANSMIT_MESSAGE_BUFF_SIZE		520			///< Flight Computer transmit buffer size (VCP)
#define RADIO_TRANSMIT_MESSAGE_BUFF_SIZE	520			///< Radio transmit buffer size (VCP)

// Non-VCP transmit buffers
#define STAR_TRANSMIT_MESSAGE_BUFF_SIZE		256			///< Star Tracker transmit buffer size(non - VCP)
#define SUN_TRANSMIT_MESSAGE_BUFF_SIZE		256			///< Sun Sensor transmit buffer size(non - VCP)


/// Peripheral structure
typedef struct {
	
	// Hardware
	USART_t *					USART;						///< USART associated with this peripheral
	volatile DMA_CH_t *			DMA_channel;				///< DMA channel for data transmission
	
	// Buffers
	Receive_RingBuff_t 			rx_ringbuff;				///< ring buffer to receive from USART
	vcp_ptrbuffer				vcp_rx_msg;					///< VCP buffer pointer
	uint8ptr					rx_data;					///< linear buffer for non VCP received data
	uint16_t					rx_data_buffer_size;		///< allocated size of receive buffer
	uint8ptr					tx_data;					///< linear buffer for VCP frame ready to transmit
	uint16_t					tx_data_buffer_size;		///< allocated size of transmit buffer
	
	// Flags and Counters
	volatile uint8_t			rx_ringbuff_overflow;		///< counts receive ring buffer overflow
	uint16_t					rx_byte_count;				///< number of received bytes after VCP decoding (actual data size)
	Bool						rx_data_ready;				///< flag for VCP decoding done and non-VCP data ready 
	uint16_t					tx_byte_count;				///< bytes to tx in transmit buffer (actual data size)

	// VCP
	uint8_t						VCP_address;				///< VCP address
	uint8_t						rx_data_destination;		///< destination for received data (VCP address from received packet)
	uint8_t						VCP_rx_status;				///< VCP receive status register
	uint8_t						VCP_tx_status;				///< VCP transmit status register
	uint16_t					rx_packet_count;			///< keeps track of number of packets received from this peripheral 
	uint16_t					rejected_rx_packet_count;	///< keeps track of number of rejected packets received from this peripheral 
	uint16_t					tx_packet_count;			///< keeps track of number of packets transmitted to this peripheral 

	#ifdef DEBUG
		uint8_t					tx_LED_pin;					///< DEUBG - STK LED pin	
		uint8_t					rx_LED_pin;					///< DEUBG - STK LED pin
	#endif
	
} peripheral_t;

// Declare peripheral structures
peripheral_t					fc;							///< Flight Computer Peripheral
peripheral_t					power;						///< Power Peripheral
peripheral_t					gps;						///< GPS Peripheral
peripheral_t					radio;						///< Radio Peripheral
peripheral_t					cdhib;						///< CDHIB (Self) Peripheral - enables the use of all the peripheral functions
#ifdef STAR_UART
peripheral_t					star;						///< Star Tracker Peripheral
#endif
#ifdef SUN_UART
peripheral_t					sun;						///< Sun Sensor Peripheral
#endif

// FC and Radio transmit queue ring buffers
Queue_RingBuff_t 				fc_queue_ringbuff;			///< Flight Computer Queue ring buffer
Queue_RingBuff_t 				radio_queue_ringbuff;		///< Radio Queue ring buffer

// Data buffers allocation
uint8_t fc_rx_data				[FC_RECEIVE_MESSAGE_BUFF_SIZE];		///< Flight Computer receive buffer allocation
uint8_t fc_tx_data				[FC_TRANSMIT_MESSAGE_BUFF_SIZE];	///< Flight Computer transmit buffer allocation
uint8_t power_rx_data			[POWER_RECEIVE_MESSAGE_BUFF_SIZE];	///< Power receive buffer allocation
uint8_t power_tx_data			[POWER_TRANSMIT_MESSAGE_BUFF_SIZE];	///< Power transmit buffer allocation
uint8_t gps_rx_data				[GPS_RECEIVE_MESSAGE_BUFF_SIZE];	///< GPS receive buffer allocation
uint8_t radio_rx_data			[RADIO_RECEIVE_MESSAGE_BUFF_SIZE];	///< Radio receive buffer allocation
uint8_t radio_tx_data			[RADIO_TRANSMIT_MESSAGE_BUFF_SIZE];	///< Radio transmit buffer allocation
#ifdef STAR_UART
	uint8_t star_rx_data		[STAR_RECEIVE_MESSAGE_BUFF_SIZE];	///< Star Tracker receive buffer allocation
	uint8_t star_tx_data		[STAR_TRANSMIT_MESSAGE_BUFF_SIZE];	///< Star Tracker transmit buffer allocation
#endif
#ifdef SUN_UART
	uint8_t sun_rx_data			[SUN_RECEIVE_MESSAGE_BUFF_SIZE];	///< Sun Sensor receive buffer allocation
	uint8_t sun_tx_data			[SUN_TRANSMIT_MESSAGE_BUFF_SIZE];	///< Sun Sensor transmit buffer allocation
#endif


// Functions
void clock_init					(void);												///< See init.c
void memory_init				(void);												///< See memory.c
void dma_init					(void);												///< See memory.c
void read_VCP_receive_buff		(peripheral_t* Peripheral);							///< See memory.c
void read_Non_VCP_receive_buff	(peripheral_t* Peripheral);							///< See memory.c
void DMA_transmit				(peripheral_t* Peripheral);							///< See memory.c
void Buffer_DMA_transmit		(void);
void VCP_DMA_transmit			(peripheral_t* source, peripheral_t* destination);	///< See memory.c
void Sun_DMA_transmit			(peripheral_t* source, peripheral_t* destination);	///< See memory.c           
void switch_to_ext_osc			(void);												///< See init.c
#endif /* MEMORY_H_ */