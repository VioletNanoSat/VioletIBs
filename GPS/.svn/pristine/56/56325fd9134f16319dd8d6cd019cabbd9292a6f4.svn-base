#include <mega128.h>

#ifndef UBRR0L_VAL
#define UBRR0L_VAL 7
#endif

/* ----------------------- *
 *    STATE DEFINITIONS    *
 * ----------------------- */
#define MSG_EBSRIE				1
#define MSG_NOT_DONE			2
#define MSG_READ				3

#define NET_STATE_WAIT				0
#define NET_STATE_GET_CMD			1
#define NET_STATE_GET_SIZE			2
#define NET_STATE_GET_PAYLOAD		3
#define NET_STATE_GET_CRC			4
#define NET_STATE_SEND_RESPONSE		5
#define NET_STATE_SEND_CRC			6

#define INTERRUPT_RXC 0x20
#define INTERRUPT_DRE 0x40
#define INTERRUPT_TXC 0x80

#ifndef NET_TX_BUFFER_SIZE
	#define NET_TX_BUFFER_SIZE 1024
#endif

#define NET_STATE_WAIT_RXC				(NET_STATE_WAIT | INTERRUPT_RXC)
#define NET_STATE_GET_CMD_RXC			(NET_STATE_GET_CMD | INTERRUPT_RXC)
#define NET_STATE_GET_SIZE_RXC			(NET_STATE_GET_SIZE | INTERRUPT_RXC)
#define NET_STATE_GET_PAYLOAD_RXC		(NET_STATE_GET_PAYLOAD | INTERRUPT_RXC)
#define NET_STATE_GET_CRC_RXC			(NET_STATE_GET_CRC | INTERRUPT_RXC)
#define NET_STATE_SEND_RESPONSE_RXC		(NET_STATE_SEND_RESPONSE | INTERRUPT_RXC)
#define NET_STATE_SEND_CRC_RXC			(NET_STATE_SEND_CRC | INTERRUPT_RXC)

#define NET_STATE_WAIT_DRE				(NET_STATE_WAIT | INTERRUPT_DRE)
#define NET_STATE_GET_CMD_DRE			(NET_STATE_GET_CMD | INTERRUPT_DRE)
#define NET_STATE_GET_SIZE_DRE			(NET_STATE_GET_SIZE | INTERRUPT_DRE)
#define NET_STATE_GET_PAYLOAD_DRE		(NET_STATE_GET_PAYLOAD | INTERRUPT_DRE)
#define NET_STATE_GET_CRC_DRE			(NET_STATE_GET_CRC | INTERRUPT_DRE)
#define NET_STATE_SEND_RESPONSE_DRE		(NET_STATE_SEND_RESPONSE | INTERRUPT_DRE)
#define NET_STATE_SEND_CRC_DRE			(NET_STATE_SEND_CRC | INTERRUPT_DRE)

#define NET_STATE_WAIT_TXC				(NET_STATE_WAIT | INTERRUPT_TXC)
#define NET_STATE_GET_CMD_TXC			(NET_STATE_GET_CMD | INTERRUPT_TXC)
#define NET_STATE_GET_SIZE_TXC			(NET_STATE_GET_SIZE | INTERRUPT_TXC)
#define NET_STATE_GET_PAYLOAD_TXC		(NET_STATE_GET_PAYLOAD | INTERRUPT_TXC)
#define NET_STATE_GET_CRC_TXC			(NET_STATE_GET_CRC | INTERRUPT_TXC)
#define NET_STATE_SEND_RESPONSE_TXC		(NET_STATE_SEND_RESPONSE | INTERRUPT_TXC)
#define NET_STATE_SEND_CRC_TXC			(NET_STATE_SEND_CRC | INTERRUPT_TXC)

/* ----------------------- *
 *     TYPE DEFINITIONS    *
 * ----------------------- */
typedef unsigned char       BYTE;
typedef unsigned int        UINT;
typedef unsigned long	    ULONG;


/* ---------------------- *
 *        VARIABLES       *
 * ---------------------- */
BYTE Net_Msg_Status;
BYTE Net_State;
BYTE Net_Cmd;
BYTE Net_Reset_CUCP;
ULONG Net_My_CRC;
BYTE Net_Cmd_Has_Response;

BYTE Net_Payload_Length_Offset;
ULONG Net_Payload_Length;

BYTE* Net_Rx_Buffer;
ULONG Net_Rx_Buffer_Offset;

ULONG Net_Rx_CRC;
BYTE Net_Rx_CRC_Offset;

BYTE Net_Tx_Local_Buffer[NET_TX_BUFFER_SIZE];
BYTE* Net_Tx_Buffer;
ULONG Net_Tx_Length;
ULONG Net_Tx_Buffer_Offset;
BYTE Net_Tx_CRC_Offset;

/* ----------------------- *
 *     USEFUL MACROS       *
 * ----------------------- */

#define RxAllFrames     UCSR0A.0 = 0
#define RxAddrOnly      UCSR0A.0 = 1
#define TX_ENABLE UCSR0B.3
#define RS485_ENABLE DRIVER_LOC
#define TXC_INT_ENABLE UCSR0B.6
#define DRE_INT_ENABLE UCSR0B.5
#define TXC_CLEAR UCSR0A.6=1

#define CRC32_Part(data, currCRC) (CU_crc_table[((int)currCRC ^ data) & 0xff] ^ (currCRC >> 8))

// CRC lookup table
flash const unsigned long CU_crc_table[256] =
{
0x00000000UL, 0x77073096UL, 0xee0e612cUL, 0x990951baUL,0x076dc419UL,0x706af48fUL,
0xe963a535UL, 0x9e6495a3UL, 0x0edb8832UL, 0x79dcb8a4UL,0xe0d5e91eUL,0x97d2d988UL,
0x09b64c2bUL, 0x7eb17cbdUL, 0xe7b82d07UL, 0x90bf1d91UL,0x1db71064UL,0x6ab020f2UL,
0xf3b97148UL, 0x84be41deUL, 0x1adad47dUL, 0x6ddde4ebUL,0xf4d4b551UL,0x83d385c7UL,
0x136c9856UL, 0x646ba8c0UL, 0xfd62f97aUL, 0x8a65c9ecUL,0x14015c4fUL,0x63066cd9UL,
0xfa0f3d63UL, 0x8d080df5UL, 0x3b6e20c8UL, 0x4c69105eUL,0xd56041e4UL,0xa2677172UL,
0x3c03e4d1UL, 0x4b04d447UL, 0xd20d85fdUL, 0xa50ab56bUL,0x35b5a8faUL,0x42b2986cUL,
0xdbbbc9d6UL, 0xacbcf940UL, 0x32d86ce3UL, 0x45df5c75UL,0xdcd60dcfUL,0xabd13d59UL,
0x26d930acUL, 0x51de003aUL, 0xc8d75180UL, 0xbfd06116UL,0x21b4f4b5UL,0x56b3c423UL,
0xcfba9599UL, 0xb8bda50fUL, 0x2802b89eUL, 0x5f058808UL,0xc60cd9b2UL,0xb10be924UL,
0x2f6f7c87UL, 0x58684c11UL, 0xc1611dabUL, 0xb6662d3dUL,0x76dc4190UL,0x01db7106UL,
0x98d220bcUL, 0xefd5102aUL, 0x71b18589UL, 0x06b6b51fUL,0x9fbfe4a5UL,0xe8b8d433UL,
0x7807c9a2UL, 0x0f00f934UL, 0x9609a88eUL, 0xe10e9818UL,0x7f6a0dbbUL,0x086d3d2dUL,
0x91646c97UL, 0xe6635c01UL, 0x6b6b51f4UL, 0x1c6c6162UL,0x856530d8UL,0xf262004eUL,
0x6c0695edUL, 0x1b01a57bUL, 0x8208f4c1UL, 0xf50fc457UL,0x65b0d9c6UL,0x12b7e950UL,
0x8bbeb8eaUL, 0xfcb9887cUL, 0x62dd1ddfUL, 0x15da2d49UL,0x8cd37cf3UL,0xfbd44c65UL,
0x4db26158UL, 0x3ab551ceUL, 0xa3bc0074UL, 0xd4bb30e2UL,0x4adfa541UL,0x3dd895d7UL,
0xa4d1c46dUL, 0xd3d6f4fbUL, 0x4369e96aUL, 0x346ed9fcUL,0xad678846UL,0xda60b8d0UL,
0x44042d73UL, 0x33031de5UL, 0xaa0a4c5fUL, 0xdd0d7cc9UL,0x5005713cUL,0x270241aaUL,
0xbe0b1010UL, 0xc90c2086UL, 0x5768b525UL, 0x206f85b3UL,0xb966d409UL,0xce61e49fUL,
0x5edef90eUL, 0x29d9c998UL, 0xb0d09822UL, 0xc7d7a8b4UL,0x59b33d17UL,0x2eb40d81UL,
0xb7bd5c3bUL, 0xc0ba6cadUL, 0xedb88320UL, 0x9abfb3b6UL,0x03b6e20cUL,0x74b1d29aUL,
0xead54739UL, 0x9dd277afUL, 0x04db2615UL, 0x73dc1683UL,0xe3630b12UL,0x94643b84UL,
0x0d6d6a3eUL, 0x7a6a5aa8UL, 0xe40ecf0bUL, 0x9309ff9dUL,0x0a00ae27UL,0x7d079eb1UL,
0xf00f9344UL, 0x8708a3d2UL, 0x1e01f268UL, 0x6906c2feUL,0xf762575dUL,0x806567cbUL,
0x196c3671UL, 0x6e6b06e7UL, 0xfed41b76UL, 0x89d32be0UL,0x10da7a5aUL,0x67dd4accUL,
0xf9b9df6fUL, 0x8ebeeff9UL, 0x17b7be43UL, 0x60b08ed5UL,0xd6d6a3e8UL,0xa1d1937eUL,
0x38d8c2c4UL, 0x4fdff252UL, 0xd1bb67f1UL, 0xa6bc5767UL,0x3fb506ddUL,0x48b2364bUL,
0xd80d2bdaUL, 0xaf0a1b4cUL, 0x36034af6UL, 0x41047a60UL,0xdf60efc3UL,0xa867df55UL,
0x316e8eefUL, 0x4669be79UL, 0xcb61b38cUL, 0xbc66831aUL,0x256fd2a0UL,0x5268e236UL,
0xcc0c7795UL, 0xbb0b4703UL, 0x220216b9UL, 0x5505262fUL,0xc5ba3bbeUL,0xb2bd0b28UL,
0x2bb45a92UL, 0x5cb36a04UL, 0xc2d7ffa7UL, 0xb5d0cf31UL,0x2cd99e8bUL,0x5bdeae1dUL,
0x9b64c2b0UL, 0xec63f226UL, 0x756aa39cUL, 0x026d930aUL,0x9c0906a9UL,0xeb0e363fUL,
0x72076785UL, 0x05005713UL, 0x95bf4a82UL, 0xe2b87a14UL,0x7bb12baeUL,0x0cb61b38UL,
0x92d28e9bUL, 0xe5d5be0dUL, 0x7cdcefb7UL, 0x0bdbdf21UL,0x86d3d2d4UL,0xf1d4e242UL,
0x68ddb3f8UL, 0x1fda836eUL, 0x81be16cdUL, 0xf6b9265bUL,0x6fb077e1UL,0x18b74777UL,
0x88085ae6UL, 0xff0f6a70UL, 0x66063bcaUL, 0x11010b5cUL,0x8f659effUL,0xf862ae69UL,
0x616bffd3UL, 0x166ccf45UL, 0xa00ae278UL, 0xd70dd2eeUL,0x4e048354UL,0x3903b3c2UL,
0xa7672661UL, 0xd06016f7UL, 0x4969474dUL, 0x3e6e77dbUL,0xaed16a4aUL,0xd9d65adcUL,
0x40df0b66UL, 0x37d83bf0UL, 0xa9bcae53UL, 0xdebb9ec5UL,0x47b2cf7fUL,0x30b5ffe9UL,
0xbdbdf21cUL, 0xcabac28aUL, 0x53b39330UL, 0x24b4a3a6UL,0xbad03605UL,0xcdd70693UL,
0x54de5729UL, 0x23d967bfUL, 0xb3667a2eUL, 0xc4614ab8UL,0x5d681b02UL,0x2a6f2b94UL,
0xb40bbe37UL, 0xc30c8ea1UL, 0x5a05df1bUL, 0x2d02ef8dUL
};

/* ----------------------- *
 *        FUNCTIONS        *
 * ----------------------- */
void sendNoBuffer(BYTE*, UINT);
BYTE* get_receive_mem(BYTE, UINT*, BYTE*, BYTE*);
void CUCPInterrupt(char, char);

inline void ResetCUCP() {
	Net_State = NET_STATE_WAIT;
	RxAddrOnly;
	//Net_Msg_Status = MSG_READ;
	Net_Reset_CUCP = 0;
	TXC_CLEAR;
	TX_ENABLE = 0;
	TXC_INT_ENABLE = 0;
	DRE_INT_ENABLE = 0;
	RS485_ENABLE = 0;
}

void send(BYTE* data, UINT size) {
    register int i;
    if (size == 0) {
        ResetCUCP();
        return;
    }
    for (i = 0; i < size; i++)
        Net_Tx_Local_Buffer[i] = data[i];

	sendNoBuffer(Net_Tx_Local_Buffer, size);
}

void sendSingleByte(BYTE32 byte, USHORT32 numToSend) {
    memset(Net_Tx_Local_Buffer,byte,numToSend);
    sendNoBuffer(Net_Tx_Local_Buffer, numToSend);
}

void sendNoBuffer(BYTE* data, UINT size) {
	Net_Tx_Buffer = data;
	Net_My_CRC = CRC32_Part(*Net_Tx_Buffer, 0xffffffff);

	while (!UCSR0A.5) ; // wait for DRE flag before sending this byte

	// set global state vars
	Net_State = NET_STATE_SEND_RESPONSE;
	Net_Tx_Length = size;
	Net_Tx_Buffer_Offset = 1;

	TX_ENABLE = 1;  // enable transmitter (probably still enabled, so will have no effect)
	UDR0 = *Net_Tx_Buffer;   // send first byte of response
	DRE_INT_ENABLE = 1; // enable DRE interrupt
}

void CUCP_Init() {
    UBRR0H = 0;
    UBRR0L = UBRR0L_VAL; //7; // 47 is 38.4kbs on double speed at 14.74MHz, 51 for 16MHz
    UCSR0A = 0b00000011;    // dbl speed
    UCSR0B = 0b10010100;    // bit 2 = 9 bit mode (address bit for CUCP)
                            // bit 5 = Tx DRE interrupt
                            // bit 7 = Rx complete interrupt
    ResetCUCP();
    Net_Msg_Status = MSG_READ;
}

void CUCPInterrupt(char intrrpt, char recChar) {
    BYTE s;
    s = Net_State | intrrpt;

	switch (s) {
		case NET_STATE_GET_CMD_RXC:
			Net_Cmd = recChar;
			Net_Payload_Length = 0;
			Net_Payload_Length_Offset = 0;
			Net_State = NET_STATE_GET_SIZE;
			UDR0 = Net_Cmd;
			break;

		case NET_STATE_GET_SIZE_RXC:
			//Net_Payload_Length = (Net_Payload_Length<<8) | recChar; no idea why this doesn't work...probably CodeVision bug
			((unsigned char *) &Net_Payload_Length)[3-Net_Payload_Length_Offset] = recChar;
			if (++Net_Payload_Length_Offset < 4) {
				UDR0 = recChar;
			}
			else { // Net_Payload_Length filled, but still have to echo the last byte
				BYTE isValidCmd;
				UINT Net_wtfisthis;
				Net_Rx_Buffer = get_receive_mem(Net_Cmd, &Net_wtfisthis, &Net_Cmd_Has_Response, &isValidCmd);
				if (!isValidCmd) {
					TXC_CLEAR;
					TXC_INT_ENABLE = 1;
					Net_Reset_CUCP = 1;

				} else if (Net_Payload_Length > 0) {
					Net_Rx_Buffer_Offset = 0;
					Net_My_CRC = 0xffffffff;
					Net_State = NET_STATE_GET_PAYLOAD;

				} else if (Net_Cmd_Has_Response && Net_Payload_Length == 0) {
					Net_Msg_Status = MSG_EBSRIE; // be careful with user input here, the user code must wait until the ack is sent before transmitting. Or, can set EBSRIE in the DRE interrupt using a flag: Net_User_Input = 1

				} else { // !Net_Cmd_Has_Response && Net_Payload_Length == 0
					TXC_CLEAR;
					TXC_INT_ENABLE = 1;
					Net_Reset_CUCP = 1;
					Net_Msg_Status = MSG_EBSRIE; // be careful with user input here, the user code must wait until the ack is sent before transmitting. Or, can set EBSRIE in the DRE interrupt using a flag: Net_User_Input = 1

				}
				UDR0 = recChar;
			}
			break;
		case NET_STATE_GET_SIZE_TXC:
			if (Net_Reset_CUCP) {
				ResetCUCP();
			}
			break;

		case NET_STATE_GET_PAYLOAD_RXC:

			*(Net_Rx_Buffer + Net_Rx_Buffer_Offset++) = recChar;
			Net_My_CRC = CRC32_Part(recChar, Net_My_CRC);
			if (Net_Rx_Buffer_Offset == Net_Payload_Length) {
				Net_Rx_CRC = 0;
				Net_Rx_CRC_Offset = 0;
				Net_My_CRC = ~Net_My_CRC;
				Net_State = NET_STATE_GET_CRC;
			}
			break;

		case NET_STATE_GET_CRC_RXC:

			//Net_Rx_CRC = (Net_Rx_CRC<<8) | recChar; no idea why this doesn't work...probably CodeVision bug
			((unsigned char *) &Net_Rx_CRC)[3-Net_Rx_CRC_Offset] = recChar;
			Net_Rx_CRC_Offset++;
			if (Net_Rx_CRC_Offset == 4) {
				BYTE crcMatch;
				crcMatch = (Net_Rx_CRC == Net_My_CRC);
				if (crcMatch && Net_Cmd_Has_Response) {
					Net_Msg_Status = MSG_EBSRIE;
					UDR0 = CRC_ACK; // be careful with user input here, the user code must wait until the ack is sent before transmitting. Or, can set EBSRIE in the DRE interrupt using a flag: Net_User_Input = 1
				} else if (crcMatch && !Net_Cmd_Has_Response) {
					TXC_CLEAR;
					TXC_INT_ENABLE = 1;
					Net_Reset_CUCP = 1;
					Net_Msg_Status = MSG_EBSRIE; // must be careful with user input here
					UDR0 = CRC_ACK;
				} else { // crc mismatch
					TXC_CLEAR;
					TXC_INT_ENABLE = 1;
					Net_Reset_CUCP = 1;
					UDR0 = CRC_NACK;
				}
			}
			break;
		case NET_STATE_GET_CRC_TXC:
			if (Net_Reset_CUCP) {
				ResetCUCP();
			}
			break;

		case NET_STATE_SEND_RESPONSE_DRE:
			if (Net_Tx_Buffer_Offset == Net_Tx_Length) {
				Net_State = NET_STATE_SEND_CRC;
				Net_My_CRC = ~Net_My_CRC;
				Net_Tx_CRC_Offset = 1;
				UDR0 = (BYTE) (Net_My_CRC & 0xff);
			} else {
				BYTE currChar;
				currChar = *(Net_Tx_Buffer + Net_Tx_Buffer_Offset++);
				Net_My_CRC = CRC32_Part(currChar, Net_My_CRC);
				UDR0 = currChar;
			}
			break;

		case NET_STATE_SEND_CRC_DRE:
			if (Net_Tx_CRC_Offset == 3) {
				DRE_INT_ENABLE = 0;
				TXC_CLEAR;
				TXC_INT_ENABLE = 1;
				Net_Reset_CUCP = 1;
			}
			UDR0 = *(((BYTE *) &Net_My_CRC) + Net_Tx_CRC_Offset++);
			break;
		case NET_STATE_SEND_CRC_TXC:
			if (Net_Reset_CUCP) {
				ResetCUCP();
			}
			break;
	}
}

interrupt [USART0_RXC] void uart0_rec(void) {
	unsigned char recChar;
	BYTE ninthBit;
	ninthBit = UCSR0B.1;
	recChar = UDR0;
	if (Net_State == NET_STATE_WAIT && ninthBit && (recChar == NET_ADDR))  {
		RxAllFrames;                        // Accept frames w/o ninth bit high now
        RS485_ENABLE = 1;                   // Turn on rs485 driver, we'll turn it off
                                            // at the end of the comm event
		TX_ENABLE = 1;
		Net_Msg_Status = MSG_NOT_DONE;
		Net_State = NET_STATE_GET_CMD;
		UDR0 = recChar;
	} else if (Net_State != NET_STATE_WAIT && ninthBit) { // we're not in the wait state and receiving an address, jump to wait!
		ResetCUCP();
	} else {
		CUCPInterrupt(INTERRUPT_RXC, recChar);
	}
}

interrupt [USART0_DRE] void uart0_send(void) {
	CUCPInterrupt(INTERRUPT_DRE, 0);
}

interrupt [USART0_TXC] void uart0_txc(void) {
	CUCPInterrupt(INTERRUPT_TXC, 0);
}

//inline unsigned long cu_crc32_part(char data, unsigned long currCRC) {
//	return CU_crc_table[((int)currCRC ^ data) & 0xff] ^ (currCRC >> 8);
//}