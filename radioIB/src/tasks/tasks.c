/** \file
 * tasks.c
 * \brief Tasks source file
 *
 *  Author: Liran
 */ 

#include <asf.h>
#include "tasks.h"


#ifdef DEBUG

#define		DEBUG_PACKETS	20
#define		PACKET_LENGTH	100
uint16_t	j, i;
uint8_t		errors;
Bool		debug_check = false;
uint16_t	num_of_debug_packets;

#endif


#ifdef DEBUG
/**
 * Name         : debug_task
 *
 * Synopsis     : void debug_task	(void)
 *
 * Description  : Task for debug only. Runs when DEBUG is defined in conf_board.h
 * 
 */
void debug_task	(void)
{

	PORTA.OUTSET =	PIN2_bm;	
	for(;;)
	{		
		radio_task();
		cdhib_task();
	}
	
	
	for(;;);	// Need this loop if running debug task so program can't exit
}
#endif // DEBUG




/**
 * Name         : cdhib_task
 *
 * Synopsis     : void cdhib_task	(void)
 *
 * Description  : CDHIB Task
 * *			Read the CDHIB USART receive buffer
 * *			Construct Li-1 header on RADIO Peripheral transmit buffer
 * *			Copy packet over to that buffer. DMA transmit. 
 * 
 */
void cdhib_task	(void)
{
		if (!radio.tx_data_ready)
		{
			read_CDH_receive_buff();
		}
		
		if(cdhib.tx_data_ready)
		{
			uint8_t res;
			uint16_t size = RADIO_TRANSMIT_MESSAGE_BUFF_SIZE;
			cdhib.tx_byte_count = cdhib.tx_byte_count-LI_HDR-LI_FTR-AX_HDR-AX_FTR;
			if(cdhib.dest_address == VCP_FC)
			{
				//FC packet
				res = Create_VCP_frame(cdhib.tx_data,&size,cdhib.dest_address,cdhib.radio_pre_vcp,cdhib.tx_byte_count);
			}
			else
			{
				//Direct Command
				cdhib.tx_byte_count = cdhib.tx_byte_count - 1;
				res = Create_VCP_frame(cdhib.tx_data,&size,cdhib.dest_address,cdhib.radio_pre_vcp,cdhib.tx_byte_count);
			}
			
			cdhib.tx_byte_count = size;//cdhib.tx_byte_count + 5;
			if(res == VCP_TERM)
			{
				DMA_transmit(&cdhib);
			}
			else
			{
				cdhib.tx_status = VCP_CREAT_ERR;
				//send_radio_error();
			}
			
			cdhib.tx_data_ready = false;
			cdhib.tx_byte_count = 0;
			cdhib.dest_address = 0;
			cdhib.tx_status = 0;
		}
}




/**
 * Name         : radio_task
 *
 * Synopsis     : void radio_task	(void)
 *
 * Description  : Radio Task
 * *			Read the Radio USART receive buffer
 * *			Construct VCP and copy packet if not CCSDS on CDH tx_buffer
 * *			Copy packet over to CDH tx_buffer if CCSDS
 * *			DMA Transmit
 * 
 */
void radio_task	(void)
{
	if(!cdhib.tx_data_ready)
	{
		read_radio_receive_buff();
	}
	if(radio.tx_data_ready)
	{
		DMA_transmit(&radio);
		radio.tx_data_ready = false;
		cdhib.cdh_state = 0;
		radio.tx_byte_count = 0;
		radio.tx_status = 0;
	}
}
