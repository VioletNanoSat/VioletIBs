/** \file
 * vcp_library.h
 * \brief VCP Library header file
 *
 * Created: 3/8/2012
 *
 * Author: Liran
 */ 


#ifndef VCP_LIBRARY_H_
#define VCP_LIBRARY_H_

#include "common.h"

// KISS Frame
#define FEND  0xC0	///< KISS frame FEND			
#define FESC  0xDB	///< KISS frame FESC
#define TFEND 0xDC	///< KISS frame TFEND
#define TFESC 0xDD	///< KISS frame TFESC

// VCP Flags and State machine States
#define VCP_OVR_ERR		0x03	///< VCP Flag: buffer overflow error
#define VCP_CRC_ERR		0x04	///< VCP Flag: calculated crc does not match received crc
#define VCP_NULL_ERR	0x05	///< VCP Flag: buffer is null
#define VCP_ADDR_ERR	0x06	///< VCP Flag: address field error
#define VCP_ESC_ERR		0x07	///< VCP Flag: Escaping error - no TFESC or TFEND after FESC

#define VCP_TERM		0x01	///< State machine: frame terminated
#define VCP_ESC			0x02	///< State machine: escaping
#define VCP_IDLE		0x00	///< State machine: Waiting for beginning of frame	
#define VCP_ADDRESS		0x10	///< State machine: Address is first byte in frame 
#define VCP_RECEIVING	0x20	///< State machine: ongoing 

// VCP Sensor Addresses - according to Intrasatellite Communication ICD
#define VCP_POWER			0x01	///< VCP Address of Power Board
#define VCP_RADIO_1			0x02	///< VCP Address of Radio 1
#define VCP_GPS_1			0x03	///< VCP Address of GPS 1
#define VCP_STAR_TRACKER	0x04	///< VCP Address of Star Tracker
#define VCP_RADIO_2			0x05	///< VCP Address of Radio 2
#define VCP_GPS_2			0x06	///< VCP Address of GPS 2
#define VCP_SPECTROMETER	0x07	///< VCP Address of Spectrometer
#define VCP_CDHIB_1			0x09	///< VCP Address of CDH IB MCU 1
#define VCP_CDHIB_2			0x0A	///< VCP Address of CDH IB MCU 2
#define	VCP_FC				0x0B 	///< VCP Address of Flight Computer
#define VCP_SUN_SENSOR		0x38	///< VCP Address of Sun Sensor



/**
 *
 *	VCP Pointer Buffer.
 *	This structure MUST be initialized with vcpptr_init(...)
 */
typedef struct
{
	uint8		address;	// saves the VCP address
	uint8ptr	message;	// pointer to the data buffer
	uint16		crc;		// saves the crc 
	uint16		size;		// message buffer size		
	uint16		index;		// saves current place in the buffer
	uint8		status;		// Receive state machine or flags
} vcp_ptrbuffer;	

void	vcpptr_init			(vcp_ptrbuffer *buff, uint8 *message_buffer, uint16 message_buffer_size);		///< See vcp_library.c
uint8_t	Create_VCP_frame	(uint8ptr dst, uint16ptr dst_size, uint8 addr, uint8ptr src, uint16 src_size);	///< See vcp_library.c
uint8_t	Receive_VCP_byte	(vcp_ptrbuffer *buff, uint8 byte);												///< See vcp_library.c

#endif /* VCP_LIBRARY_H_ */