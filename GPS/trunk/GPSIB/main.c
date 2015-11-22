#include "main.h"
#include "uart.h"
#include "gps.h"
#include "gps_packet.h"
#include "adc.h"
#include "vcplib.h"

// Internal Infrastructure Variables
#define usart0_buffer_size 500
#define usart1_buffer_size 1000

uint8 usart0_buffer[usart0_buffer_size];
volatile uint16 usart0_index;
volatile uint16 usart0_complete;
volatile uint8 usart0_flags;

uint8 usart1_buffer[usart1_buffer_size];
volatile uint16 usart1_index;
volatile uint16 usart1_complete;
volatile uint8 usart1_flags;

uint16 usart0_snapshot = 0;
uint16 usart1_snapshot = 0;

// GPS Specific Variables
gps_telem 		telem;
gps_f00	  		f00;
gps_f03	  		f03;
gps_f18	  		f18;
gps_f22	  		f22;
gps_f23	  		f23;
gps_packet 		tx_packet;
//gps_timestamp 	myTime;

uint32			count;
uint8			order = 0x00;		// this stores which sentence was last retrieved
uint8			error;				// status reg
uint8			gpsi_ready;			// this flag signifies that all of the gps data for this second has been received and is ready to be sent
uint8			f00_ready;			// this flag signifies that f00 has been received and is ready to be sent
volatile uint8	sample_ADC;			// trigger ADC sampling
volatile uint16	deadSecs;			// counts seconds between time syncs.	
volatile uint8	watchdog_transmit;	// trigger transmit when no data from receiver in IB_TRANSMIT_TRIGGER_TIME seconds	


uint8			rx_id[3];			// Used to hole identifiers for the GPS sentences
uint8			checksum[2];		// Hold the calculated checksum
uint8			rec_checksum[2];	// Hold the received checksum



void initialize()
{

	//STK500
	#ifdef STK500					// init STK500 debug LEDs pins here 
		DDRC |= (1<<DDC0);
		DDRC |= (1<<DDC1);
		DDRC |= (1<<DDC2);
		PORTC = 0x07;				// LEDs start OFF
	#endif

	// Init output I/Os
	DDRA |= (1<<DDA4);				// DISCP	on Pin PA4 as output ???
	DDRA &= ~(1<<DDA3);	
	
	// UART TX Pins should be automatically configured as outputs when the UART is enabled
	// regardless of the following DDRx setting
	DDRD |= (1<<DDD3);	// GPS_TX	on Pin PD3 as output
	DDRE |= (1<<DDE1);	// COMM_TX	on Pin PE1 as output 
	
	
		
	// set up the UART lines
	usart0_initialize(get_ubrr(CDHIB_BAUD_RATE));		// UART0 is the interface to the CDH IB
	usart1_initialize(get_ubrr(RECEIVER_BAUD_RATE));	// UART1 is the interface to the GPS receiver

	usart0_index		= 0;
	usart0_complete		= 0;
	usart0_flags		= 0;

	usart1_index		= 0;
	usart1_complete		= 0;
	usart1_flags		= 0;

	gpsi_ready			= 0;
	f00_ready			= 0;
	watchdog_transmit	= 0;
	deadSecs			= 0;


	// Init ADC
    ADMUX	|=  ( (1<<REFS0) | (1<<ADLAR) );				// External AVcc as Ref, Left adjusted result
	ADCSRA	|= 	( (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0) );	// Prescaler 128, conversion clock = CLOCK_SPEED/prescaler
	Clear_ADC_MUX();										// Clear the MUX
	Enable_ADC();											// Enable ADC
	Start_ADC_Conversion();									// Do first dummy conversion on Channel 0


	// Init watchdog (use Timer 1 in CTC mode to create 1Hz interrupts)
	TCCR1A 	= 	0; 							// no I/O connected
	OCR1A	=	((CLOCK_SPEED / 1024) - 1);	// 1 Hz interrupt	  
	TIMSK 	|=	( (1<< OCIE1A));			// enable interrupt on compare
	TCCR1B 	|= 	( (1<<WGM12));				// CTC mode, OCR1A is top
	TCCR1B	|=	( (1<<CS10)  | (1<<CS12)); 	// prescale clock by 1024 and start the timer		
	
	
	// TX_EN High - enable transmit on 422 driver in Rev 2. Not connected in Rev 3.
	#ifdef GPSIB_REV_2
		DDRA	|= (1<<DDA1);		// TX_EN	on Pin PA1 as output
		PORTA	|= (1<<PA1);
	#endif		


	// enable interrupts
	sei();
}


/* How this function works:
 * It's a state machine:
 * - GPSI_UNKNOWN: 		General state where the code isn't actively receiving data,
 * 						and/or has no idea what's going on.
 * 
 * - GPSI_PRELIM1,2,3:	Grabs preliminary information like the last command received
 * 
 * - GPSI_ID1,2,3:		Grabs successive bytes of the sentence ID variable that identifies
 * 						the sentence and stores them in the rx_id[] variable.
 * 
 * - GPSI_S1,2,3,4,5:	Loops through the length of the sentence and grabs each
 * 						successive byte.
 * 
 * - GPSI_CHKSA,B:		For checking that the data wasn't corrupted during the transfer (Checksum)
 * 
 * - GPSI_DONE:			When the sentence is fully downloaded, checks for the end byte as
 * 						confirmation then does a bit of cleanup.
 * 
 * If it gets unexpected data at any stage (except in the GPSI_S1,2,3,4,5 stages), it'll
 * throw a general error and go into GPSI_UNKNOWN. If it recognizes a start byte and starts
 * ID'ing the sentence, it'll clear the general error.
 */ 
void retrieve_gps_data()
{
	// The buffer is circular, so when the loop gets to the end, it just
	// sets back to index 0 and continues until it reaches usart1_snapshot
	// This helps to prevent unwanted loss of data
	for (; usart1_index != usart1_snapshot; usart1_index = (usart1_index+1 < usart1_buffer_size ? usart1_index+1 : 0))
	{
		switch (get_usart_state(usart1_flags))
		{
			case  GPSI_UNKNOWN:
				if (usart1_buffer[usart1_index] == GPSI_START)
				{
					gpsi_ready = 0;
					set_usart_state(usart1_flags, GPSI_ID1);
					rem_gen_state(error, GPSI_ERR_GEN);
				}
				else
				{
					set_gen_state(error, GPSI_ERR_GEN);
				}
				break;


			case GPSI_PRELIM1:
				telem.last_command = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_PRELIM2);
				break;


			case GPSI_PRELIM2:
				telem.command_success = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_PRELIM3);
				break;


			case GPSI_PRELIM3:
				telem.last_satellite = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_ID1:
				if (usart1_buffer[usart1_index] == 'F')
				{
					set_usart_state(usart1_flags, GPSI_ID2);
					rx_id[0] = 'F';
					rem_gen_state(error, GPSI_ERR_GEN);
				}
				else
				{
					set_usart_state(usart1_flags, GPSI_UNKNOWN);
					set_gen_state(error, GPSI_ERR_GEN);
				}
				break;


			case  GPSI_ID2:
				switch(usart1_buffer[usart1_index])
				{
					// Four possible valid options here
					case '0':
					case '1':
					case '2':
					case '9':
						set_usart_state(usart1_flags, GPSI_ID3);
						rx_id[1] = usart1_buffer[usart1_index];
						rem_gen_state(error, GPSI_ERR_GEN);
						break;
					default:
						set_usart_state(usart1_flags, GPSI_UNKNOWN);
						set_gen_state(error, GPSI_ERR_GEN);
						break;
				}
				break;


			case  GPSI_ID3:
				rx_id[2] = usart1_buffer[usart1_index];
				rem_gen_state(error, GPSI_ERR_GEN);
				if (rx_id[1] == '0' && rx_id[2] == '0')			// F00
					set_usart_state(usart1_flags, GPSI_S1);
				else if (rx_id[2] == '3' && rx_id[1] == '0')	// F03
					set_usart_state(usart1_flags, GPSI_S2);
				else if (rx_id[1] == '1' && rx_id[2] == '8')	// F18
					set_usart_state(usart1_flags, GPSI_S3);
				else if (rx_id[1] == '2' && rx_id[2] == '2')	// F22
					set_usart_state(usart1_flags, GPSI_S4);
				else if (rx_id[2] == '3' && rx_id[1] == '2')	// F23
					set_usart_state(usart1_flags, GPSI_S5);
				else if (rx_id[1] == '9' && rx_id[2] == '9')	// f99
					set_usart_state(usart1_flags, GPSI_PRELIM1);
				else
				{
					set_usart_state(usart1_flags, GPSI_UNKNOWN);
					set_gen_state(error, GPSI_ERR_GEN);
				}

				count = 0;
				break;


			case  GPSI_S1: // F00
				if (count == 0)
				{
					checksum[0] = 0;
					checksum[1] = 0;
				}

				((uint8ptr)&f00)[count] = usart1_buffer[usart1_index];
				checksum[count%2] = checksum[count%2]^usart1_buffer[usart1_index];
				count++;

				if (count == sizeof(gps_f00))
				{
					count = 0;
					set_usart_state(usart1_flags, GPSI_CHKS1A);
				}
				break;


			case  GPSI_S2: // F03
				if (count == 0)
				{
					checksum[0] = 0;
					checksum[1] = 0;
				}

				((uint8ptr)&f03)[count] = usart1_buffer[usart1_index];
				checksum[count%2] = checksum[count%2]^usart1_buffer[usart1_index];
				count++;

				if (count == sizeof(gps_f03))
				{
					count = 0;
					set_usart_state(usart1_flags, GPSI_CHKS2A);
				}
				break;


			case  GPSI_S3: // F18
				if (count == 0)
				{
					checksum[0] = 0;
					checksum[1] = 0;
				}

				((uint8ptr)&f18)[count] = usart1_buffer[usart1_index];
				checksum[count%2] = checksum[count%2]^usart1_buffer[usart1_index];
				count++;

				if (count == sizeof(gps_f18))
				{
					count = 0;
					set_usart_state(usart1_flags, GPSI_CHKS3A);
				}
				break;


			case  GPSI_S4: // F22
				if (count == 0)
				{
					checksum[0] = 0;
					checksum[1] = 0;
				}

				((uint8ptr)&f22)[count] = usart1_buffer[usart1_index];
				checksum[count%2] = checksum[count%2]^usart1_buffer[usart1_index];
				count++;

				if (count == sizeof(gps_f22))
				{
					count = 0;
					set_usart_state(usart1_flags, GPSI_CHKS4A);
				}
				break;


			case  GPSI_S5: // F23
				if (count == 0)
				{
					checksum[0] = 0;
					checksum[1] = 0;
				}

				((uint8ptr)&f23)[count] = usart1_buffer[usart1_index];
				checksum[count%2] = checksum[count%2]^usart1_buffer[usart1_index];
				count++;

				if (count == sizeof(gps_f23))
				{
					count = 0;
					set_usart_state(usart1_flags, GPSI_CHKS5A);
				}
				break;


			case  GPSI_CHKS1A: // F00 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS1B);
				break;


			case  GPSI_CHKS1B: // F00 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f00, 0x00, sizeof(gps_f00));	// Checksum failed - Write zeros to F00

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS2A: // F03 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS2B);
				break;


			case  GPSI_CHKS2B: // F03 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f03, 0x00, sizeof(gps_f03));	// Checksum failed - Write zeros to F03

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS3A: // F18 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS3B);
				break;


			case  GPSI_CHKS3B: // F18 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];
				
				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f18, 0x00, sizeof(gps_f18));	// Checksum failed - Write zeros to F18

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS4A: // F22 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS4B);
				break;


			case  GPSI_CHKS4B: // F22 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f22, 0x00, sizeof(gps_f22));	// Checksum failed - Write zeros to F22

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS5A: // F23 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS5B);
				break;


			case  GPSI_CHKS5B: // F23 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f23, 0x00, sizeof(gps_f23));	// Checksum failed - Write zeros to F23

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_DONE:
				if (usart1_buffer[usart1_index] == GPSI_END)
				{
					

					
					if (rx_id[1] == '0' && rx_id[2] == '0')
					{
						order = GPSI_ORDER_F00;

						rem_gen_state(error, GPSI_ERR_1); // F00 received ok
						f00_ready = 1;
						#ifdef STK500
							PORTC ^= (1<<PC2);		// toggle led 2
						#endif


					}

					else if (rx_id[2] == '3' && rx_id[1] == '0')
					{
						if (order == GPSI_ORDER_F00)
							order = GPSI_ORDER_F03;

						rem_gen_state(error, GPSI_ERR_2); // F03 received ok
					}
					
					else if (rx_id[1] == '1' && rx_id[2] == '8')
					{
						if (order == GPSI_ORDER_F03)
							order = GPSI_ORDER_F18;

						rem_gen_state(error, GPSI_ERR_3); // F18 received ok
					}
					
					else if (rx_id[1] == '2' && rx_id[2] == '2')
					{
						if (order == GPSI_ORDER_F18)
							order = GPSI_ORDER_F22;

						rem_gen_state(error, GPSI_ERR_4); // F22 received ok
					}
					
					else if (rx_id[2] == '3' && rx_id[1] == '2')
					{
						if (order == GPSI_ORDER_F22)
							order = GPSI_ORDER_F23;

						rem_gen_state(error, GPSI_ERR_5); // F23 received ok
						gpsi_ready = 1;		

					}
					
					
					else if (rx_id[1] == '9' && rx_id[2] == '9') {} // preliminary sentence
					else
					{
						set_usart_state(usart1_flags, GPSI_UNKNOWN);
						set_gen_state(error, GPSI_ERR_GEN);
						break;
					}

					set_usart_state(usart1_flags, GPSI_UNKNOWN);
					rem_gen_state(error, GPSI_ERR_GEN);
				}
				else
				{
					set_usart_state(usart1_flags, GPSI_UNKNOWN);
					set_gen_state(error, GPSI_ERR_GEN);
				}
				break;


			default:
				set_usart_state(usart1_flags, GPSI_UNKNOWN);
				set_gen_state(error, GPSI_ERR_GEN);
				break;
		}

		if (order == GPSI_ORDER_F23)	// All sentences received successfully
		{
			
			deadSecs		= 0;	// It's alive
			rem_gen_state(error, GPSI_ERR_DEAD);
			
		}
	}
}

// PGOOD is an input from the receiver on pin PA3
void check_pgood()
{

	if (getbit(PINA, PINA3)) // PGOOD pin HIGH
		rem_gen_state(error, GPSI_ERR_PGOOD);
	else
		set_gen_state(error, GPSI_ERR_PGOOD);

}

// Check time since last sync with receiver 
void check_time()
{
	if (deadSecs >= RECEIVER_DEAD_TIME) 	// Receiver is dead after DEAD_TIME seconds
	{
		deadSecs = 100*RECEIVER_DEAD_TIME;		// avoid overflow on deadSecs
		set_gen_state(error, GPSI_ERR_DEAD);
	}
	else
		rem_gen_state(error, GPSI_ERR_DEAD);
}


void send_VCP_data()	// VCP
{
	uint32 size = usart0_buffer_size;
	
	// create VCP frame in the transmit buffer
	uint8_t VCP_tx_status = Create_VCP_frame(	usart0_buffer, 
												(uint16ptr)&size, 
												VCP_GPS_1, 
												(uint8ptr)&tx_packet, 
												sizeof(gps_packet));

	if (VCP_tx_status == VCP_OVR_ERR)	{}
	if (VCP_tx_status == VCP_NULL_ERR)	{}
	if (VCP_tx_status == VCP_ADDR_ERR)	{}
	if (VCP_tx_status == VCP_TERM)			// Done with no errors
	{
		usart0_index = 0;				// reset index
		usart0_complete = size;			// packet length
		usart0_tx_interrupt_enable();	// enable interrupt to start transmission
	}			
}


void send(char *str, int len)	// No VCP
{
	memcpy(usart0_buffer, str, len);	// copy packet to transmit buffer
	usart0_index = 0;					// reset index
	usart0_complete = len;				// packet length
	usart0_tx_interrupt_enable();		// enable interrupt to start transmission
}


// Main
int main()
{
	initialize();

	usart1_rx_interrupt_enable();

	set_usart_state(usart1_flags, GPSI_UNKNOWN);

	for (;;)	// Loooooop
	{
		if (usart0_flags & USART_TX_COMPLETE)
		{
			usart0_flags ^= USART_TX_COMPLETE;
		}
		
		if (f00_ready || watchdog_transmit)
		{
			
			check_pgood();
			check_time();
			

			// pack
			tx_packet.packet_status = error;
			tx_packet.packet_telem = telem;
			if (watchdog_transmit)	// No sync with receiver - Write zeros to F00
				memset(&tx_packet.packet_f00, 0x00, sizeof(gps_f00));	
			else
				tx_packet.packet_f00 = f00;

			// reset all the triggers
			f00_ready = 0;
			watchdog_transmit = 0;
					
			// Transmit data
			#ifdef COMM_DEBUG
				tx_packet.packet_status = 0xFF;						// start comm byte for debug
				((uint8ptr)&tx_packet.packet_f00)[71] = 0xFF;		// end comm byte for debug
				send( (char*)&tx_packet, sizeof(tx_packet) );		// Transmit without VCP frame
				//send( (char*)&telem, sizeof(telem) );				// Debug - transmit only telem
				//send( (char*)&tx_packet.packet_f00, sizeof(f00) );	// Debug - transmit only f00
			#else
				send_VCP_data();								// Transmit with VCP frame
			#endif

			// set all sentence receive errors for next receive cycle
			set_gen_state(error, GPSI_ERR_1);
			set_gen_state(error, GPSI_ERR_2);
			set_gen_state(error, GPSI_ERR_3);
			set_gen_state(error, GPSI_ERR_4);
			set_gen_state(error, GPSI_ERR_5);
			
			// trigger ADC sampling
			sample_ADC = 1;				

		}
		
		
		if (usart1_flags & USART_RX_READY)
		{
			usart1_flags ^= USART_RX_READY;		// signal received
			usart1_snapshot = usart1_complete;	// grab a snapshot of the current usart state in case it changes
			
			// extract the data from the buffer
			retrieve_gps_data();
		}
		
		if (sample_ADC)
		{
			sample_ADC			= 0;
			telem.gps_temp		= Get_ADC_Result(ADC_THERM_GPS_CHANNEL);
			telem.gpsib_temp	= Get_ADC_Result(ADC_THERM_GPSIB_CHANNEL);
			telem.radio_temp	= Get_ADC_Result(ADC_THERM_RADIO_CHANNEL);
		}

	}
}

// Catch interrupts without ISR - should never happen 
ISR(BADISR_vect)
{
    // user code here
}

// Timer1 compare interrupt service routine
ISR(TIMER1_COMPA_vect)
{
	deadSecs++;					// count seconds between time syncs
	
	if (deadSecs % IB_TRANSMIT_TRIGGER_TIME == 2)	// trigger transmit every <IB_TRANSMIT_TRIGGER_TIME> seconds
		watchdog_transmit = 1;
			
	#ifdef STK500			
		PORTC ^= (1<<PC0);			// toggle led 0
		if (watchdog_transmit)	
			PORTC &= ~(1<<PC1);		// led 1 ON
		else
			PORTC |= (1<<PC1);		// led 1 OFF
	#endif
}

// uart0 transmit interrupt service routine
ISR (USART0_UDRE_vect)
{		
	if (usart0_index != usart0_complete)
	{
		UDR0 = usart0_buffer[usart0_index++];
	}
	else
	{
		usart0_tx_interrupt_disable();
		usart0_flags |= USART_TX_COMPLETE;
	}
}

// uart1 receive interrupt service routine
ISR (USART1_RX_vect)
{
	usart1_buffer[usart1_complete] = UDR1;
	usart1_complete = ((usart1_complete+1) < usart1_buffer_size ? (usart1_complete+1) : 0);
	
	usart1_flags |= USART_RX_READY;
}
