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

	for(;;)
	{
		radio_task();
		fc_task();
		//star_task();
		//sun_task();
		//gps_task();
	}

	
	
	for(;;);	// Need this loop if running debug task so program can't exit
}
#endif // DEBUG


/**
 * Name         : gps_task
 *
 * Synopsis     : void gps_task	(void)
 *
 * Description  : GPS Task 
 * *			Read the GPS USART receive buffer
 * *			When packet is ready copy it to a buffer
 * 
 */
void gps_task	(void)
{
	read_VCP_receive_buff(&gps);	
	
	if (gps.rx_data_ready)
	{
		// copy relevant data from gps to THS  
		memcpy(&THS_Beacon.GPS_Packet, gps.rx_data, sizeof(GPS_packet_t));
	}
}

/**
 * Name         : power_task
 *
 * Synopsis     : void power_task	(void)
 *
 * Description  : Power Board Task
 * *			Read the Power USART receive buffer
 * *			When packet is ready copy it to the THS buffer
 * 
 */
void power_task	(void)
{
	read_VCP_receive_buff(&power);
	
	if (power.rx_data_ready)
	{
		// copy relevant data from power to THS  	
		memcpy(&THS_Beacon.Power_Telemetry, power.rx_data, sizeof(Power_telemetry_t));
	}
}

/**
 * Name         : fc_task
 *
 * Synopsis     : void fc_task	(void)
 *
 * Description  : Flight Computer Task
 * *			Read the FC USART receive buffer
 * *			Check for received FC data and transmit to the destination Peripheral
 * *			Check the FC transmit queue, and transmit data to the FC if available
 * 
 */
void fc_task	(void)
{
	read_VCP_receive_buff(&fc);
	
	if (fc.rx_data_ready)											// New data from FC ready
	{  
		fc.rx_data_ready =		false;
		FC_command_received =	false;
		
		switch(fc.rx_data_destination)								// where is it going?
		{
		case VCP_POWER:
			VCP_DMA_transmit(&fc, &power);
			PWR_WDOG_Seconds_counter = 0;							// Reset watchdog counter
			break;
		#ifdef STAR_UART
		case VCP_STAR_TRACKER:
			memcpy(star.tx_data, fc.rx_data, fc.rx_byte_count);		// copy fc rx buffer to star tx buffer
			star.tx_byte_count = fc.rx_byte_count;					// set block size
			DMA_transmit(&star);									// DMA
			break;
		#endif
		#ifdef SUN_UART
		case VCP_SUN_SENSOR:
			memcpy(sun.tx_data, fc.rx_data, fc.rx_byte_count);		// copy fc rx buffer to sun tx buffer
			sun.tx_byte_count = fc.rx_byte_count;					// set block size
			//Sun_DMA_transmit(&fc,&sun);								// DMA
			Buffer_DMA_transmit();
			break;
		#endif	
		case VCP_RADIO:
			Queue_RingBuffer_Insert(&radio_queue_ringbuff, VCP_FC);	// Insert to radio transmit queue	
			break;
		case VCP_CDHIB:
			memcpy(&FC_packet, fc.rx_data, sizeof(FC_packet));		// copy the received packet to the FC packet buffer
			FC_command_received = true;								// Destination is this MCU	
			break;
		default:
			// Unknown address.
			Queue_RingBuffer_Insert(&radio_queue_ringbuff, VCP_BROKEN);	// Insert to radio transmit queue
			break;
		}
	}
	
	
	// Check transmit queue and transmit to FC 
	if (!Queue_RingBuffer_IsEmpty(&fc_queue_ringbuff))				// There's something in the queue
	{

		peripheral_t	source_peripheral;
		uint8			source_vcp_address = Queue_RingBuffer_Remove(&fc_queue_ringbuff); // what's the source for this data?

		switch (source_vcp_address)		
		{
		case VCP_POWER:
			source_peripheral =		power;	
			break;
		case VCP_GPS:
			source_peripheral =		gps;
			break;
		#ifdef STAR_UART
		case VCP_STAR_TRACKER:
			source_peripheral =		star;	
			break;
		#endif
		#ifdef SUN_UART
		case VCP_SUN_SENSOR:
			source_peripheral =		sun;	
			break;
		#endif	
		case VCP_RADIO:
			source_peripheral =		radio;	
			break;
		case VCP_CDHIB:
			source_peripheral =		cdhib;	
			cdhib.rx_data =			ACK;
			cdhib.rx_byte_count =	ACK_SIZE;	
			break;
		default:	
			source_vcp_address =	VCP_BAD_ADDRESS;	// something is wrong with the address field
			break;
		}
		
		if (source_vcp_address == VCP_BAD_ADDRESS) {}	// Do something
		else
		{
			VCP_DMA_transmit(&source_peripheral, &fc);	// build VCP frame and transmit with DMA 
			#ifdef DEBUG
			debug_check = true;
			#endif
		}		
	}	
}

/**
 * Name         : cdhib_task
 *
 * Synopsis     : void cdhib_task	(void)
 *
 * Description  : CDH IB (Local) Task
 * *			Check for new command from FC and execute
 * *			Check for new command from Radio and execute
 * *			If internal oscillator is used as clock source - try to switch to external oscillator
 * *			Transmit watchdog noop packets to power mcu 
 * 
 */
void cdhib_task	(void)
{
	if (FC_command_received)
	{
		FC_command_received = false;
		// Decode fc command ...
		switch(FC_packet.Command_Header)
		{
			case NOOP_COMMAND:
				// ACK to FC
				//cdhib.rx_data =			ACK;
				//cdhib.rx_byte_count =	ACK_SIZE;
				Queue_RingBuffer_Insert(&fc_queue_ringbuff, VCP_CDHIB);		// Insert to fc transmit queue
				break;
			case THS_CHANGE_INTERVAL_COMMAND:
				// Check if new interval is valid
				if (	FC_packet.Command_Argument >= MINIMUM_THS_INTERVAL_SECONDS 
					&&	FC_packet.Command_Argument <= MAXIMUM_THS_INTERVAL_SECONDS )
				{
				Commanded_THS_interval_seconds = FC_packet.Command_Argument;
				}				
				External_THS_trigger = true; 
				break;
			case FC_TELEMETRY_PACKET:
				// Copy FC telemetry to THS beacon 
				memcpy(&THS_Beacon.FC_Telemetry, &FC_packet.FC_Telemetry, FC_TELEMETRY_SIZE);
				break;
			default:
				break;
		}
	}

	if (Radio_command_received)
	{
		Radio_command_received = false;
		// Decode radio command ...
		switch(Radio_Command_packet.Command_Header)
		{
			case THS_CHANGE_INTERVAL_COMMAND:
				Commanded_THS_interval_seconds = Radio_Command_packet.Command_Argument;
				External_THS_trigger = true; 
				break;
			default:
				break;
		}
	}
	
	// In case internal oscillator is used - try to switch to external oscillator
	if (xosc_recovey)
	{
		switch_to_ext_osc ();
	}
	
	// If need to transmit a noop command to the power board	
	if (PWR_WDOG_Seconds_counter >= PWR_WDOG_TX_INTERVAL)
	{
		// transmit to power mcu
		cdhib.rx_data =			PWR_NOOP;
		cdhib.rx_byte_count =	POWER_NOOP_SIZE;
		VCP_DMA_transmit(&cdhib, &power);
		
		// Reset watchdog counter
		PWR_WDOG_Seconds_counter = 0;
	}
}




/**
 * Name         : radio_task
 *
 * Synopsis     : void radio_task	(void)
 *
 * Description  : Radio Task
 * *			Read the Radio USART receive buffer
 * *			Check for received Radio data and transmit to the destination Peripheral
 * *			Check the Radio transmit queue, and transmit data to the Radio if available
 * 
 */
void radio_task	(void)
{
	read_VCP_receive_buff(&radio); // receive radio data here
	
	if (radio.rx_data_ready)	// New data from Radio ready
	{
		radio.rx_data_ready =		false;
		Radio_command_received =	false;
		
		switch(radio.rx_data_destination)	// where is it going?
		{
		case VCP_POWER:
			VCP_DMA_transmit(&radio, &power);
			PWR_WDOG_Seconds_counter = 0;								// Reset watchdog counter
			break;
		#ifdef STAR_UART
		case VCP_STAR_TRACKER:
			memcpy(star.tx_data, radio.rx_data, radio.rx_byte_count);	// copy fc rx buffer to star tx buffer
			star.tx_byte_count = radio.rx_byte_count;					// set block size
			DMA_transmit(&star);										// DMA
			break;										
		#endif
		#ifdef SUN_UART
		case VCP_SUN_SENSOR:
			memcpy(sun.tx_data, radio.rx_data, radio.rx_byte_count);	// copy fc rx buffer to star tx buffer
			sun.tx_byte_count = radio.rx_byte_count;					// set block size
			DMA_transmit(&sun);											// DMA
			break;
		#endif	
		case VCP_FC:
			Queue_RingBuffer_Insert(&fc_queue_ringbuff, VCP_RADIO);		// Insert to fc transmit queue	
			break;
		case VCP_CDHIB:
			memcpy(&Radio_Command_packet, radio.rx_data, CDHIB_COMMAND_PACKET_SIZE);
			Radio_command_received = true;								// Destination is this MCU	
			break;
		default:
			// Unknown address.	
			break;
		}
	}	
	
	// Check transmit queue and transmit to Radio 
	if (!Queue_RingBuffer_IsEmpty(&radio_queue_ringbuff))			// There's something in the queue
	{

		uint8 source_vcp_address = Queue_RingBuffer_Remove(&radio_queue_ringbuff); // what's the source for this data?

		if (source_vcp_address == VCP_FC)		
		{
			// source is fc buffer
			VCP_DMA_transmit(&fc, &radio);	// build VCP frame and transmit with DMA
		}			
		else if (source_vcp_address == VCP_CDHIB)
		{
			// source is THS buffer
			cdhib.rx_data =			(uint8ptr)&THS_Beacon;
			cdhib.rx_byte_count =	sizeof(THS_Beacon);
			VCP_DMA_transmit(&cdhib, &radio);	// build VCP frame and transmit with DMA
			
		}			
		else if (source_vcp_address == VCP_BROKEN)
		{
			radio.tx_data[0] = FEND;
			radio.tx_data[1] = VCP_FC;
			radio.tx_data[2] = 0x01;
			radio.tx_data[3] = 0x02;
			radio.tx_data[4] = 0x40;
			radio.tx_data[5] = 0x80;
			radio.tx_data[6] = FEND;
			radio.tx_byte_count = 7;
			DMA_transmit(&radio);
		}
		
		// transmit to radio here...
	}	
	
}


/**
 * Name         : ths_task
 *
 * Synopsis     : void ths_task	(void)
 *
 * Description  : THS Task
 * *			Collect and transmit THS beacon
 * 
 */
void ths_task	(void)
{
	// THS broadcast is triggered from timer interrupt or from external trigger (FC or Radio)
	
	#ifdef MCU_CDH_1	
	
		if ((THS_Seconds_counter >= THS_interval_seconds) || External_THS_trigger )
		{
			THS_Seconds_counter =	0;										// Reset the seconds counter
			THS_interval_seconds =	Commanded_THS_interval_seconds;			// Reload the interval
			External_THS_trigger =	false;									// Turn off the trigger
			
			Collect_THS_data();												// collect THS data into THS_Beacon
			Queue_RingBuffer_Insert(&radio_queue_ringbuff,VCP_CDHIB);		// Insert to radio transmit queue
		}	
													
	#else // MCU_CDH_2	
	
		if ((THS_Seconds_counter >= THS_interval_seconds) || External_THS_trigger )
		{
			THS_Seconds_counter =	0;										// Reset the seconds counter
			
			if (External_THS_trigger)										// In MCU2, the first interval is divided by 2
			{																// to create a half-interval phase shift
				THS_interval_seconds =	Commanded_THS_interval_seconds/2;	// between the two beacons
				External_THS_trigger =	false;								// Turn off the trigger
			}
			else
			{
				THS_interval_seconds =	Commanded_THS_interval_seconds;		// Reload the interval
				
				Collect_THS_data();											// collect THS data into THS_Beacon
				Queue_RingBuffer_Insert(&radio_queue_ringbuff,VCP_CDHIB);	// Insert to radio transmit queue
			}
		}
				
	#endif
}

#ifdef STAR_UART
/**
 * Name         : star_task
 *
 * Synopsis     : void star_task	(void)
 *
 * Description  : Star Tracker Task
 * *			Read the Star Tracker USART receive buffer
 * 
 */
void star_task	(void)
{
	// check if the buffer is free before writing to it
	//if (star.rx_byte_count == 0)
	read_Non_VCP_receive_buff(&star);
}	
#endif

#ifdef SUN_UART
/**
 * Name         : sun_task
 *
 * Synopsis     : void sun_task	(void)
 *
 * Description  : Sun Sensor Task
 * *			Read the Sun Sensor USART receive buffer 
 * 
 */
void sun_task	(void)
{
	// check if the buffer is free before writing to it
	//if (sun.rx_byte_count == 0)
		read_Non_VCP_receive_buff(&sun);
		
}
#endif

/**
 * Name         : tcap_task
 *
 * Synopsis     : void tcap_task	(void)
 *
 * Description  : TCAP Task
 * 
 */
void tcap_task	(void){}
