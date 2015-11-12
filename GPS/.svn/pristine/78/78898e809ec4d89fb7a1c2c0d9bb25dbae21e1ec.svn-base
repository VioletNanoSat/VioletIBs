#include "uart.h"
#include "main.h"
#include "gps.h"
#include "gps_packet.h"

// Internal Infrastructure Variables
#define usart0_buffer_size 1000
#define usart1_buffer_size 1000

volatile uint8 usart0_buffer[usart0_buffer_size];
volatile uint16 usart0_index;
volatile uint16 usart0_complete;
volatile uint8 usart0_flags;

volatile uint8 usart1_buffer[usart1_buffer_size];
volatile uint16 usart1_index;
volatile uint16 usart1_complete;
volatile uint8 usart1_flags;

uint16 usart0_snapshot = 0;
uint16 usart1_snapshot = 0;

// general state variables
// bytes 0 and 1 are reserved for uart maintenance
// bytes 2 through 7 can be used by other entities though
#define USART_RX_READY    0x01
#define USART_TX_COMPLETE 0x02

#define set_usart_state(a, b) (a = (a^(a&0xFC))|b) // remove the current state and set the new one
#define get_usart_state(a)	 (a&0xFC)			  // get the current state

#define set_gen_state(a, b) (a |= b)
#define rem_gen_state(a, b) (a &= ~b)
#define get_gen_state(a, b)	((a & b) != 0)

// GPS Specific Variables
gps_telem telem;
gps_f00	  f00;
gps_f03	  f03;
gps_f18	  f18;
gps_f22	  f22;
gps_f23	  f23;

uint32	  count;
uint8	  order; // this stores which sentence was last retrieved
uint8	  error;
uint8	  gpsi_ready; // this flag signifies that all of the gps data for this second has been received and is ready to be sent
uint8	  send_on_command; // this flag determines whether to wait for a command to send the data or to just send it on an interval

uint8	  rx_id[3];
uint8	  checksum[2];
uint8	  rec_checksum[2];

void send(char *str, int len)
{
	int i = 0, count = usart0_complete;
	for (i = 0; i < len; i++)
	{
		usart0_buffer[count] = str[i];
		count = (count+1 < usart0_buffer_size ? count+1 : 0);
	}

	usart0_complete = count;
	usart0_txen_int();
}

void initialize()
{
	// set up the uart lines
	usart0_initialize(get_ubrr(57600));
	usart1_initialize(get_ubrr(76800));

	usart0_index = 0;
	usart0_complete = 0;
	usart0_flags = 0;

	usart1_index = 0;
	usart1_complete = 0;
	usart1_flags = 0;

	gpsi_ready = 0;
	send_on_command = 0;

	// turn on the led's
	//DDRB = 0xFF;
	
	// For some reason, this does not need to be done
	// Set Up the GPS
	//PORTA = most significant <--[discp][pgood][mem][tx][rx]
	//DDRA = 0x17;  // 0b00010111
	//PORTA = 0x04; // 0b00000100

	//set_usart_state(usart1_flags, GPSI_UNKNOWN);

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
	// sets back to index 0 and continutes until it reaches usart1_snapshot
	// This helps to prevent unwanted loss of data
	for (; usart1_index != usart1_snapshot; usart1_index = (usart1_index+1 < usart1_buffer_size ? usart1_index+1 : 0))
	{
		switch (get_usart_state(usart1_flags))
		{
			case  GPSI_UNKNOWN:
				if (usart1_buffer[usart1_index] == GPSI_START)
				{
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
				if (rx_id[1] == '0' && rx_id[2] == '0')
					set_usart_state(usart1_flags, GPSI_S1);
				else if (rx_id[1] == '0' && rx_id[2] == '3')
					set_usart_state(usart1_flags, GPSI_S2);
				else if (rx_id[1] == '1' && rx_id[2] == '8')
					set_usart_state(usart1_flags, GPSI_S3);
				else if (rx_id[1] == '2' && rx_id[2] == '2')
					set_usart_state(usart1_flags, GPSI_S4);
				else if (rx_id[1] == '2' && rx_id[2] == '3')
					set_usart_state(usart1_flags, GPSI_S5);
				else if (rx_id[1] == '9' && rx_id[2] == '9')
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
					memset(&f00, 0x00, sizeof(gps_f00));

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS2A: // F03 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS2B);
				break;


			case  GPSI_CHKS2B: // F03 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f03, 0x00, sizeof(gps_f03));

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS3A: // F18 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS3B);
				break;


			case  GPSI_CHKS3B: // F18 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];
				
				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f18, 0x00, sizeof(gps_f18));

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS4A: // F22 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS4B);
				break;


			case  GPSI_CHKS4B: // F22 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f22, 0x00, sizeof(gps_f22));

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_CHKS5A: // F23 Checksum Byte 0
				rec_checksum[0] = usart1_buffer[usart1_index];
				set_usart_state(usart1_flags, GPSI_CHKS5B);
				break;


			case  GPSI_CHKS5B: // F23 Checksum Byte 1
				rec_checksum[1] = usart1_buffer[usart1_index];

				if (rec_checksum[0] != checksum[0] || rec_checksum[1] != checksum[1])
					memset(&f23, 0x00, sizeof(gps_f23));

				set_usart_state(usart1_flags, GPSI_DONE);
				break;


			case  GPSI_DONE:
				if (usart1_buffer[usart1_index] == GPSI_END)
				{
					if (rx_id[1] == '0' && rx_id[2] == '0')
					{
						order = GPSI_ORDER_F00;

						// status... error 1?
					}
					else if (rx_id[1] == '0' && rx_id[2] == '3')
					{
						if (order == GPSI_ORDER_F00)
							order = GPSI_ORDER_F03;

						// status... error 2?
					}
					else if (rx_id[1] == '1' && rx_id[2] == '8')
					{
						if (order == GPSI_ORDER_F03)
							order = GPSI_ORDER_F18;

						// status... error 3?
					}
					else if (rx_id[1] == '2' && rx_id[2] == '2')
					{
						if (order == GPSI_ORDER_F18)
							order = GPSI_ORDER_F22;

						// status... error 4?
					}
					else if (rx_id[1] == '2' && rx_id[2] == '3')
					{
						if (order == GPSI_ORDER_F22)
							order = GPSI_ORDER_F23;

						gpsi_ready = 1;
						// status... error 5?
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

		if (order == GPSI_ORDER_F23)
		{
			// TODO sync up the time stamp

			error = 0x00; // remove all error messages
		}
	}
}


void retrieve_command()
{
}

void send_data()
{
	usart0_rxdis_int();
	usart0_txdis_int();

	uint32 size = 1000;
	vcp_package(usart0_buffer, &size, VCP_GPS_1, (uint8ptr)&f00, sizeof(gps_f00));
	
	usart0_index = 0;
	usart0_complete = size;

	usart0_txen_int();
	gpsi_ready = 0;
}

int main()
{
	initialize();

	usart0_rxen_int();
	usart0_txdis_int();
	usart1_rxen_int();
	usart1_txdis_int();

	//PORTB = 0xFF;

	set_usart_state(usart1_flags, GPSI_UNKNOWN);

	while (1)
	{
		if (usart0_flags & USART_TX_COMPLETE)
		{
			usart0_flags ^= USART_TX_COMPLETE;
		}
		if (usart1_flags & USART_TX_COMPLETE)
		{
			usart1_flags ^= USART_TX_COMPLETE;
		}

		if (gpsi_ready && !send_on_command)
			send_data();

		if (usart0_flags & USART_RX_READY)
		{
			usart0_flags ^= USART_RX_READY;		// signal received
			usart0_snapshot = usart0_complete;	// grab a snapshot of the current usart state in case it changes
			//PORTB ^= 0x02;

			// extract the commands from the buffer
			retrieve_command();
		}

		if (usart1_flags & USART_RX_READY)
		{
			usart1_flags ^= USART_RX_READY;		// signal received
			usart1_snapshot = usart1_complete;	// grab a snapshot of the current usart state in case it changes
			//PORTB ^= 0x01;
			
			// extract the data from the buffer
			retrieve_gps_data();
		}
	}

	return 0;
}

ISR(BADISR_vect)
{
    // user code here
}

// uart0 receive interrupt service routine
ISR (USART0_RX_vect)
{
	usart0_buffer[usart0_complete] = usart0_rx_int();
	usart0_complete = (usart0_complete+1 < usart0_buffer_size ? usart0_complete+1 : 0);

	usart0_flags |= USART_RX_READY;
}

// uart0 transmit interrupt service routine
ISR (USART0_UDRE_vect)
{		
	// loop through the received bytes and loop around if the end of the buffer is reached
	if (usart0_index != usart0_complete)
	{
		//PORTB = usart0_buffer[usart0_index] ^ 0xFF;
		UDR0 = usart0_buffer[usart0_index];
		usart0_index = (usart0_index+1 < usart0_buffer_size ? usart0_index+1 : 0);
	}
	else
	{
		usart0_txdis_int();
		usart0_flags |= USART_TX_COMPLETE;
	}
}

// uart1 receive interrupt service routine
ISR (USART1_RX_vect)
{
	usart1_buffer[usart1_complete] = usart1_rx_int();
	usart1_complete = (usart1_complete+1 < usart1_buffer_size ? usart1_complete+1 : 0);

	usart1_flags |= USART_RX_READY;
	gpsi_ready = 0;
}

// uart1 transmit interrupt service routine
ISR (USART1_UDRE_vect)
{
	// loop through the received bytes and loop around if the end of the buffer is reached
	if (usart1_index != usart1_complete)
	{
		//PORTB = usart1_buffer[usart1_index] ^ 0xFF;
		UDR1 = usart1_buffer[usart1_index];
		usart1_index = (usart1_index+1 < usart1_buffer_size ? usart1_index+1 : 0);
	}
	else
	{
		usart1_txdis_int();
		usart1_flags |= USART_TX_COMPLETE;
	}
}
