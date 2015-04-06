/** \file
 * memory.c
 * \brief Memory source file
 *
 * Created: 12/15/2011
 *  Author: Liran
 */ 

#include "memory.h"
#include "../tasks/cdhib.h"

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
	// FC
	RingBuffer_InitBuffer			(&fc.rx_ringbuff);	
	Queue_RingBuffer_InitBuffer		(&fc_queue_ringbuff);
	fc.USART =						&FC_UART;
	fc.DMA_channel =				&DMA.CH0;
	fc.rx_data =					fc_rx_data;
	fc.rx_data_buffer_size =		FC_RECEIVE_MESSAGE_BUFF_SIZE;
	fc.tx_data =					fc_tx_data;
	fc.tx_data_buffer_size =		FC_TRANSMIT_MESSAGE_BUFF_SIZE;
	fc.VCP_address =				VCP_FC; 
	
	// Power
	RingBuffer_InitBuffer			(&power.rx_ringbuff);	
	power.USART =					&POWER_UART;
	power.DMA_channel =				&DMA.CH1;
	power.rx_data =					power_rx_data;
	power.rx_data_buffer_size =		POWER_RECEIVE_MESSAGE_BUFF_SIZE;
	power.tx_data =					power_tx_data;
	power.tx_data_buffer_size =		POWER_TRANSMIT_MESSAGE_BUFF_SIZE;
	power.VCP_address =				VCP_POWER;
	
	// GPS
	RingBuffer_InitBuffer			(&gps.rx_ringbuff);	
	gps.USART =						&GPS_UART;
	gps.rx_data =					gps_rx_data;
	gps.rx_data_buffer_size =		GPS_RECEIVE_MESSAGE_BUFF_SIZE;
	gps.VCP_address =				VCP_GPS;
	
	// Radio
	RingBuffer_InitBuffer			(&radio.rx_ringbuff);	
	Queue_RingBuffer_InitBuffer		(&radio_queue_ringbuff);
	radio.USART =					&RADIO_UART; 
	radio.DMA_channel =				&DMA.CH2;
	radio.rx_data =					radio_rx_data;
	radio.rx_data_buffer_size =		RADIO_RECEIVE_MESSAGE_BUFF_SIZE;
	radio.tx_data =					radio_tx_data;
	radio.tx_data_buffer_size =		RADIO_TRANSMIT_MESSAGE_BUFF_SIZE;
	radio.VCP_address =				VCP_RADIO;
	
	// Star
	#ifdef STAR_UART
		RingBuffer_InitBuffer		(&star.rx_ringbuff);	
		star.USART =				&STAR_UART; 
		star.DMA_channel =			&DMA.CH3;
		star.rx_data =				star_rx_data;
		star.rx_data_buffer_size =	STAR_RECEIVE_MESSAGE_BUFF_SIZE;
		star.tx_data =				star_tx_data;
		star.tx_data_buffer_size =	STAR_TRANSMIT_MESSAGE_BUFF_SIZE;
		star.VCP_address =			VCP_STAR_TRACKER;
	#endif
	
	// Sun
	#ifdef SUN_UART
		RingBuffer_InitBuffer		(&sun.rx_ringbuff);	
		sun.USART =					&SUN_UART; 
		sun.DMA_channel =			&DMA.CH3;
		sun.rx_data =				sun_rx_data;
		sun.rx_data_buffer_size =	SUN_RECEIVE_MESSAGE_BUFF_SIZE;
		sun.tx_data =				sun_tx_data;
		sun.tx_data_buffer_size =	SUN_TRANSMIT_MESSAGE_BUFF_SIZE;
		sun.VCP_address =			VCP_SUN_SENSOR;
	#endif

	// CDHIB
	cdhib.VCP_address =				VCP_CDHIB;	
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
	
	// FC
	DMA_EnableSingleShot(fc.DMA_channel);					// Single shot - every trigger pulls one byte 
    DMA_SetTriggerSource(fc.DMA_channel, 
						DMA_CH_TRIGSRC_FC_UART_DRE_gc);		// USART Trigger source - Data Register Empty
	
	// Power			
	DMA_EnableSingleShot(power.DMA_channel);				 
    DMA_SetTriggerSource(power.DMA_channel,
						DMA_CH_TRIGSRC_POWER_UART_DRE_gc);
	
	// Radio
	DMA_EnableSingleShot(radio.DMA_channel);
    DMA_SetTriggerSource(radio.DMA_channel, 
						DMA_CH_TRIGSRC_RADIO_UART_DRE_gc);	
	
	#ifdef STAR_UART
	DMA_EnableSingleShot(star.DMA_channel);
    DMA_SetTriggerSource(star.DMA_channel, 
						DMA_CH_TRIGSRC_STAR_UART_DRE_gc);	
	#endif

	#ifdef SUN_UART				
	DMA_EnableSingleShot(sun.DMA_channel);
    DMA_SetTriggerSource(sun.DMA_channel, 
						DMA_CH_TRIGSRC_SUN_UART_DRE_gc);	
	#endif
}

/**
 * Name         : read_VCP_receive_buff
 *
 * Synopsis     : void read_VCP_receive_buff(peripheral_t* Peripheral)
 *
 *	\param	Peripheral	Address to the peripheral which is the source of the transmission
 *
 * Description  : This function reads a VCP peripheral ring buffer into a linear non-VCP buffer.
 *				  When data is ready, raises flag or inserts an entry to the FC or Radio queue.
 * 
 */
uint8_t errz = 0;
void read_VCP_receive_buff(peripheral_t* Peripheral)
{
	/*volatile uint8_t stuff = 0;
	if(RingBuffer_IsEmpty(&Peripheral->rx_ringbuff)){
		stuff = 0;
	}else if(!RingBuffer_IsEmpty(&Peripheral->rx_ringbuff)){
		stuff = 1;
	}else{
		stuff = 2;
	}*/
	while(!RingBuffer_IsEmpty(&Peripheral->rx_ringbuff))
	{
		//stuff++;
		//if there's no vcp buffer, initialize it
		if (Peripheral->vcp_rx_msg.message == NULL)
		{
			vcpptr_init(&(Peripheral->vcp_rx_msg), Peripheral->rx_data, Peripheral->rx_data_buffer_size);
			Peripheral->rx_byte_count = 0;
		}
		// Get byte from receive ring buffer
		uint8_t rx_byte = RingBuffer_Remove(&Peripheral->rx_ringbuff);
		// decode VCP
		Peripheral->VCP_rx_status = Receive_VCP_byte(&(Peripheral->vcp_rx_msg), rx_byte);

		if (Peripheral->VCP_rx_status == VCP_NULL_ERR)	{
			errz++;	
		}	// null buffer, will init and try again
		/*if (Peripheral->VCP_rx_status & VCP_OVR_ERR		||	// received packet too long
			Peripheral->VCP_rx_status & VCP_CRC_ERR		||	// CRC error
			Peripheral->VCP_rx_status & VCP_ADDR_ERR	||	// Wrong VCP address
			Peripheral->VCP_rx_status & VCP_ESC_ERR		)	// escaping error in packet
		{
			// Add to rejected received packet count
			Peripheral->rejected_rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;			
		}*/
		if (Peripheral->VCP_rx_status == VCP_OVR_ERR){
			// Add to rejected received packet count
			Peripheral->rejected_rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;	
		}else if(Peripheral->VCP_rx_status == VCP_CRC_ERR){
			// Add to rejected received packet count
			Peripheral->rejected_rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;	
		}else if(Peripheral->VCP_rx_status == VCP_ADDR_ERR){
			// Add to rejected received packet count
			Peripheral->rejected_rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;	
		}else if(Peripheral->VCP_rx_status == VCP_ESC_ERR){
			// Add to rejected received packet count
			Peripheral->rejected_rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;	
		}
		
		if (Peripheral->VCP_rx_status == VCP_TERM) // Done with no errors
		{
			// save received byte count
			Peripheral->rx_byte_count = Peripheral->vcp_rx_msg.index;
			Peripheral->rx_data_ready = true;											// Data ready
			if (Peripheral == &fc || Peripheral == &radio)								// FC or Radio is the source
			{	
				Peripheral->rx_data_destination = Peripheral->vcp_rx_msg.address;		// Destination from VCP address field
			}
			else																		// Other peripherals - going to FC
				Queue_RingBuffer_Insert(&fc_queue_ringbuff, Peripheral->VCP_address);	// Insert to fc transmit queue
					
			// Add to received packet count
			Peripheral->rx_packet_count++;
			// kill VCP buffer
			Peripheral->vcp_rx_msg.message = NULL;
			
			// Toggle the RX LED to show packet received
			#ifdef DEBUG
				PORTA.OUTTGL = Peripheral->rx_LED_pin;
			#endif
			
			// Exit the while loop
			break;
		}	
	}		
}

/**
 * Name         : read_Non_VCP_receive_buff
 *
 * Synopsis     : void read_Non_VCP_receive_buff(peripheral_t* Peripheral)
 *
 * \param	Peripheral	Address to the peripheral which is the source of the transmission
 *
 * Description  : This function reads a NON-VCP peripheral ring buffer into a linear non-VCP buffer
 *				  and inserts an entry to the FC queue.
 * 
 */
uint8_t haveQueued = 0;
void read_Non_VCP_receive_buff(peripheral_t* Peripheral)
{
	
	while(!RingBuffer_IsEmpty(&Peripheral->rx_ringbuff))
	{
		// Get byte from receive ring buffer
		Peripheral->rx_data[Peripheral->rx_byte_count] = RingBuffer_Remove(&Peripheral->rx_ringbuff);
		Peripheral->rx_byte_count++;
		//haveQueued = 1;
		haveQueued++;
	}
	
	//if(Peripheral->rx_byte_count != 0){
	if(haveQueued > 0){
		// Insert to fc transmit queue
		haveQueued = 0;
		Queue_RingBuffer_Insert(&fc_queue_ringbuff, Peripheral->VCP_address);	
	    //Peripheral->rx_byte_count = 0;
		// Add to received packet count
		Peripheral->rx_packet_count++;	
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

#ifdef SUN_UART 
void Buffer_DMA_transmit()
{
	uint8_t buffer[7];
	buffer[0]=0xc0;
	buffer[1]=0x38;
	buffer[2]=0x11;
	buffer[3]=0xa0;
	buffer[4]=0x1c;
	buffer[5]=0x50;
	buffer[6]=0xc0;
	DMA_SetupBlock( sun.DMA_channel,
					buffer,
					DMA_CH_SRCRELOAD_NONE_gc,
					DMA_CH_SRCDIR_INC_gc,
					(void *)&sun.USART->DATA,
					DMA_CH_DESTRELOAD_NONE_gc,
					DMA_CH_DESTDIR_FIXED_gc,
					7,
					DMA_CH_BURSTLEN_1BYTE_gc,
					0,
					false);
					
	DMA_EnableChannel(sun.DMA_channel);
	
	sun.tx_packet_count++;
}

#endif

void Sun_DMA_transmit(peripheral_t* source, peripheral_t* destination)
{
	// Reset transmit data count to full buffer size
	destination->tx_byte_count = destination->tx_data_buffer_size;
	// create VCP frame in the peripheral transmit buffer
	destination->VCP_tx_status = Create_VCP_frame(	destination->tx_data,
													(uint16ptr)&destination->tx_byte_count,
													destination->VCP_address,
													source->rx_data,
													source->rx_byte_count);

	if (destination->VCP_tx_status == VCP_OVR_ERR)	{}
	if (destination->VCP_tx_status == VCP_NULL_ERR)	{}
	if (destination->VCP_tx_status == VCP_ADDR_ERR)	{}
	if (destination->VCP_tx_status == VCP_TERM)			// Done with no errors
	{

		#ifndef DEBUG
		// Reset the source received byte count
		source->rx_byte_count = 0;
		#endif
		
		
		// Transmit with DMA
		DMA_transmit(destination);
	}

}

/**
 * Name         : VCP_DMA_transmit
 *
 * Synopsis     : void VCP_DMA_transmit(peripheral_t* source, peripheral_t* destination)
 *
 * \param	source			Address to the peripheral which is the source of the transmission
 * \param	destination		Address to the peripheral which is the destination for the transmission
 *
 * Description  : Package a packet from a source peripheral rx buffer
 *				  to a destination peripheral tx buffer in VCP frame and transmit using DMA
 * 
 */
uint8_t errd = 0;
void VCP_DMA_transmit(peripheral_t* source, peripheral_t* destination)
{
	// Reset transmit data count to full buffer size
	destination->tx_byte_count = destination->tx_data_buffer_size;
	
	// create VCP frame in the peripheral transmit buffer
	destination->VCP_tx_status = Create_VCP_frame(	destination->tx_data, 
													(uint16ptr)&destination->tx_byte_count, 
													source->VCP_address, 
													source->rx_data, 
													source->rx_byte_count);

	if (destination->VCP_tx_status == VCP_OVR_ERR)	{
		errd++;
	}
	if (destination->VCP_tx_status == VCP_NULL_ERR)	{
		errd++;
	}
	if (destination->VCP_tx_status == VCP_ADDR_ERR)	{
		errd++;
	}
	if (destination->VCP_tx_status == VCP_TERM)			// Done with no errors
	{

		#ifndef DEBUG
		// Reset the source received byte count
		source->rx_byte_count = 0;
		#endif
		
		// Transmit with DMA
		DMA_transmit(destination);
	}		

}

/**
 * Name         : Collect_THS_data
 *
 * Synopsis     : void Collect_THS_data(void)
 *
 * Description  : Collect THS data from different locations into THS_Beacon
 * 
 */
void Collect_THS_data(void)
{
	// Complete updating THS Beacon...
	// FC, Power and GPS data is updated every time those telemetries are received
}