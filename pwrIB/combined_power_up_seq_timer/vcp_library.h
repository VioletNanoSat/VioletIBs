/*
 * vcp_library.h
 *
 * Created: 3/8/2012 2:37:47 PM
 *  Author: Liran
 */ 


#ifndef VCP_LIBRARY_H_
#define VCP_LIBRARY_H_

#include "common.h"

// KISS Frame
#define FEND  0xC0
#define FESC  0xDB
#define TFEND 0xDC
#define TFESC 0xDD

// VCP Flags and State machine States
#define VCP_OVR_ERR		0x03	// buffer overflow error
#define VCP_CRC_ERR		0x04	// calculated crc does not match received crc
#define VCP_NULL_ERR	0x05	// buffer is null
#define VCP_ADDR_ERR	0x06	// address field error
#define VCP_ESC_ERR		0x07	// Escaping error - no TFESC or TFEND after FESC

#define VCP_TERM		0x01	// frame terminated
#define VCP_ESC			0x02	// escaping
#define VCP_IDLE		0x00	// Waiting for beginning of frame	
#define VCP_ADDRESS		0x10	// Address is first byte in frame 
#define VCP_RECEIVING	0x20	// ongoing 

// VCP Sensor Addresses - according to Intrasatellite Communication ICD
#define VCP_POWER			0x01
#define VCP_RADIO_1			0x02
#define VCP_GPS_1			0x03
#define VCP_STAR_TRACKER	0x04
#define VCP_RADIO_2			0x05
#define VCP_GPS_2			0x06
#define VCP_SPECTROMETER	0x07
#define VCP_CDHIB_1			0x09
#define VCP_CDHIB_2			0x0A
#define	VCP_FC				0x0B 
#define VCP_SUN_SENSOR		0x38



// VCP Pointer Buffer
// This structure MUST be initialized with vcpptr_init(...)

typedef struct
{
	uint8		address;	// saves the VCP address
	uint8ptr	message;	// pointer to the data buffer
	uint16_t		crc;		// saves the crc 
	uint16		size;		// message buffer size		
	uint16		index;		// saves current place in the buffer
	uint8		status;		// Receive state machine or flags
} vcp_ptrbuffer;


void	vcpptr_init			(vcp_ptrbuffer *buff, uint8 *message_buffer, uint16 message_buffer_size);
uint8_t	Create_VCP_frame	(uint8ptr dst, uint16_t* dst_size, uint8 addr, uint8ptr src, uint16 src_size);
uint8_t	Receive_VCP_byte	(vcp_ptrbuffer *buff, uint8 byte);

#endif /* VCP_LIBRARY_H_ */
