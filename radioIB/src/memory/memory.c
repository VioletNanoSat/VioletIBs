/** \file
 * memory.c
 * \brief Memory source file
 *
 * Created: 12/15/2011
 *  Author: Liran
 */ 

#include "memory.h"
#include "../lithium/lithium.h"

/**
 * Name         : memory_init
 *
 * Synopsis     : void memory_init (void)
 *
 * Description  : Initialize structure members and buffers for all the Peripherals
 * 
 */
void memory_init (void)
{
	// CDHIB
	RingBuffer_InitBuffer			(&cdhib.rx_ringbuff);	
	cdhib.USART =					&CDHIB_UART;
	cdhib.DMA_channel =				&DMA.CH0;
	cdhib.tx_data =					cdhib_tx_data;
	cdhib.tx_data_ready =			false;
	cdhib.tx_data_buffer_size =		CDHIB_TRANSMIT_MESSAGE_BUFF_SIZE;
	cdhib.tx_byte_count = 0;
	cdhib.radio_packet_size = 0;
	cdhib.cdh_state = 0;
	cdhib.radio_pre_vcp = radio_non_vcp;
	cdhib.VCP_address =				VCP_CDHIB; 
	
	// Radio
	RingBuffer_InitBuffer			(&radio.rx_ringbuff);	
	radio.USART =					&RADIO_UART; 
	radio.DMA_channel =				&DMA.CH2;
	radio.tx_data =					radio_tx_data;
	radio.tx_data_ready =			false;
	radio.tx_data_buffer_size =		RADIO_TRANSMIT_MESSAGE_BUFF_SIZE;
	radio.tx_byte_count = 0;
	radio.radio_packet_size = 0;
	radio.cdh_state = 0;
	radio.radio_pre_vcp = NULL;
	radio.VCP_address =				VCP_RADIO;
	

	// Don't have an address for radioib
	radioib.VCP_address =				VCP_BAD_ADDRESS; 	
}


/**
 * Name         : dma_init
 *
 * Synopsis     : void dma_init (void)
 *
 * Description  : Initialize and enable DMA for all Peripheral USARTs
 * 
 */
void dma_init (void)
{
	// Enable clock to the DMA
	sysclk_enable_peripheral_clock(&DMA);
	
	DMA_Enable();
	DMA_SetPriority(DMA_PRIMODE_CH0RR123_gc);				// Channel 0 (FC) > Round Robin on channels 1/2/3
	
	// CDHIB
	DMA_EnableSingleShot(cdhib.DMA_channel);					// Single shot - every trigger pulls one byte 
    DMA_SetTriggerSource(cdhib.DMA_channel, 
						DMA_CH_TRIGSRC_CDHIB_UART_DRE_gc);		// USART Trigger source - Data Register Empty
	
	// Radio
	DMA_EnableSingleShot(radio.DMA_channel);
    DMA_SetTriggerSource(radio.DMA_channel, 
						DMA_CH_TRIGSRC_RADIO_UART_DRE_gc);	
}


/**
 * Name         : read_CDH_receive_buff
 *
 * Synopsis     : void read_CDH_receive_buff(void)
 *
 *	\param	Peripheral	Address to the peripheral which is the source of the transmission
 *
 * Description  : This function reads a vcp packet from the CDHIB ringbuffer.
 *				  It adds a Li-header and footer to the packet and sends to radio tx_buffer
 * 
 */
void read_CDH_receive_buff(void)
{
	uint16_t ctr = radio.tx_byte_count;
	
	//Setup Li-Header for Transmit
	if(cdhib.cdh_state == 0)
	{
		ctr = 8;
	}

	while(!RingBuffer_IsEmpty(&cdhib.rx_ringbuff))
	{
		
		// Get byte from receive ring buffer
		uint8_t rx_byte = RingBuffer_Remove(&cdhib.rx_ringbuff);
		
		//Checking number of FEND bytes to determine if packet read
		if(rx_byte == FEND && cdhib.cdh_state == 0)
		{
			cdhib.cdh_state++;
		}
		else if(cdhib.cdh_state == 1)
		{
			cdhib.cdh_state++;
		}
		else if(cdhib.cdh_state == 2 && rx_byte == HE)
		{
			cdhib.cdh_state = 3;
		}
		else if(cdhib.cdh_state == 2 && rx_byte != HE)
		{
			cdhib.cdh_state = 5;
		}
		else if(cdhib.cdh_state == 3 && rx_byte == LO)
		{
			cdhib.cdh_state = 4;
			radio.tx_data[0] = HE;
			ctr = 1;
		}
		else if(cdhib.cdh_state == 3)
		{
			radio.tx_data[ctr-1] = HE;
			cdhib.cdh_state = 5;
		}
		else if(rx_byte == FEND && cdhib.cdh_state == 5)
		{
			cdhib.cdh_state = 6;
		}
		else if(rx_byte == FEND && cdhib.cdh_state == 4)
		{
			cdhib.cdh_state = 7;
		}
		
		if(cdhib.cdh_state > 2)
		{
			radio.tx_data[ctr] = rx_byte;
			ctr++;
		}
		
		if (cdhib.cdh_state == 6) // Packet completely read
		{
			radio.tx_data_ready = true;		// Data ready
			ctr = ctr - 3;
			// Add to transmitting packet count
			radio.tx_packet_count++;
			
			radio.tx_data[0] = HE;
			radio.tx_data[1] = LO;
			radio.tx_data[2] = 0x10;//TRANSMIT;
			radio.tx_data[3] = 0x03;//TELEMETRY;
			radio.tx_data[4] = (uint8_t)((ctr - LI_HDR) >> 8);
			radio.tx_data[5] = (uint8_t)((ctr - LI_HDR));
			
			//Finish header checksum
			uint8_t first = 0;
			uint8_t second = 0;
			//Don't include HE and LO bits
			uint16_t i = 2;
			
			while(i < LI_HDR - 2)
			{
				first = first + radio.tx_data[i];
				second = second + first;
				i++;
			}
			
			radio.tx_data[6] = (first & 0xff);
			radio.tx_data[7] = (second & 0xff);
			
			//Data checksum
			i = LI_HDR;
			first = 0;
			second = 0;
			while(i < ctr)
			{
				first = first + radio.tx_data[i];
				second = second + first;
				i++;
			}
			//Insert Checksum
			radio.tx_data[ctr] = (first & 0xff);
			ctr++;
			radio.tx_data[ctr] = (second & 0xff);
			ctr++;
			// Toggle the RX LED to show packet received
			#ifdef DEBUG
				PORTA.OUTTGL = radio.rx_LED_pin;
			#endif
			// Exit the while loop
			break;
		}
		else if(cdhib.cdh_state == 7) 
		{
			radio.tx_data_ready = true;		// Data ready
			ctr = ctr - 3;
			radio.tx_packet_count++;
			#ifdef DEBUG
				PORTA.OUTTGL = radio.rx_LED_pin;
			#endif
			// Exit the while loop
			break;
		}
	}
	radio.tx_byte_count = ctr;	
}

void send_radio_error(void)
{
	//TODO Send a message from radio saying error happened
	radio.rejected_packets = radio.rejected_packets + 1;
	cdhib.tx_data_ready = false;
	cdhib.tx_byte_count = 0;
	cdhib.dest_address = 0;
	cdhib.tx_status = 0;
}

void read_radio_receive_buff	(void)
{
	uint16_t ctr = cdhib.tx_byte_count;
	// read only if packet not already queued to go out
	while(!RingBuffer_IsEmpty(&radio.rx_ringbuff))
	{
		// read byte
		uint8_t rx_byte = RingBuffer_Remove(&radio.rx_ringbuff);
		
		//random errors
		if(ctr == 0 && rx_byte != HE)
		{
			//cdhib.tx_status = HE_ERR;
			//send_radio_error();
		}
		else if(ctr == 1 && rx_byte != LO)
		{
			//cdhib.tx_status = LO_ERR;
			//send_radio_error();
		}
		
		if(ctr == 4)
		{
			//get packet size! Important
			cdhib.radio_packet_size = (rx_byte << 8);
		}
		else if(ctr == 5)
		{
			//Same deal
			cdhib.radio_packet_size = cdhib.radio_packet_size + rx_byte;
		}
		else if(ctr == LI_HDR + AX_HDR )
		{
			if(rx_byte == FC_MSG || rx_byte == FC_CMD)
			{
				cdhib.dest_address = VCP_FC;
			}
			else if(rx_byte == CDH_MSG || rx_byte == CDH_CMD)
			{
				cdhib.dest_address = VCP_CDHIB;
			}
			else if(rx_byte == PWB_MSG || rx_byte == PWB_CMD)
			{
				cdhib.dest_address = VCP_POWER;
			}
			else
			{
				//cdhib.tx_status = VCP_CREAT_ERR;
				//send_radio_error();
			}
		}
			
		//Once you reach the payload
		if(cdhib.dest_address == VCP_FC)
		{
			//Copy entire packet over
			if((ctr >= LI_HDR + AX_HDR) && (ctr < (cdhib.radio_packet_size + LI_HDR - AX_FTR)))
			{
				cdhib.radio_pre_vcp[ctr - (LI_HDR + AX_HDR)] = rx_byte;
			}
		}
		else
		{
			//Direct Command, Create VCP Frame. 
			if((ctr > LI_HDR + AX_HDR) && (ctr < (cdhib.radio_packet_size + LI_HDR - AX_FTR)))
			{
				cdhib.radio_pre_vcp[ctr - (LI_HDR + AX_HDR + 1)] = rx_byte;
			}
		}
			
		if(ctr == (cdhib.radio_packet_size + LI_HDR + LI_FTR - 1))
		{
			cdhib.tx_data_ready = true;
		}
		ctr++;
	}
	
	if(ctr != 0)
	{
		cdhib.tx_byte_count = ctr;
	}
	
}
	



/**
 * Name         : DMA_transmit
 *
 * Synopsis     : void DMA_transmit(peripheral_t*	Peripheral)
 *
 * \param	Peripheral	Address to the peripheral which is the destination for the transmission
 *
 * Description  : Transmit data block through USART using DMA
 * 
 */
void DMA_transmit(peripheral_t*	Peripheral)
{
	// Set up the block transfer
	DMA_SetupBlock(	Peripheral->DMA_channel,				// DMA Channel
					Peripheral->tx_data,					// Source buffer address
					DMA_CH_SRCRELOAD_NONE_gc,				// No reload
					DMA_CH_SRCDIR_INC_gc,					// Source address direction - Increment address
					(void *)&Peripheral->USART->DATA,		// Destination - USART DATA reg
					DMA_CH_DESTRELOAD_NONE_gc,				// No reload
					DMA_CH_DESTDIR_FIXED_gc,				// Destination address direction - Fixed address
					Peripheral->tx_byte_count,				// Block size
					DMA_CH_BURSTLEN_1BYTE_gc,				// 1 byte per transfer
					0,										// No repeat
					false);									// No repeat

	// Enable channel - the channel will be automatically disabled when a transfer is finished
	DMA_EnableChannel(Peripheral->DMA_channel);
	
	// Toggle the TX LED to show packet sent
	#ifdef DEBUG
		PORTA.OUTTGL = Peripheral->tx_LED_pin;
	#endif
		
	// Add to transmit packet count
	Peripheral->tx_packet_count++;
}