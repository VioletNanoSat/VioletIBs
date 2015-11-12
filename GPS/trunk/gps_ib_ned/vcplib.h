/*
 * vcplib.h
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#include "common.h"

#ifndef vcplib_h
#define vcplib_h

/*
 * VCP In a nutshell
 * [Field Size(bytes)]
 * { KISS Escaped Data Goes inside curly brackets }
 *
 * [FEND 1]{[address 1][data n][crc 2]}[FEND 1]
 */

// KISS Frame
#define FEND  0xC0
#define FESC  0xDB
#define TFEND 0xDC
#define TFESC 0xDD

// VCP Flags
#define VCP_TERM		0x01	// terminated
#define VCP_ESC			0x02	// escaped
#define VCP_FULL_ERR	0x04	// structure not empty error
#define VCP_OVR_ERR		0x08	// buffer overflow error
#define VCP_CRC_ERR		0x10	// calculated crc does not match sent crc
#define VCP_NULL_ERR	0x20	// message is null, only happens in vcp_ptrbuffer
#define VCP_ADDR_ERR	0x40	// The address field wasn't set before the transmit function was called

// VCP Sensor Addresses
#define VCP_POWER			0x01
#define VCP_RADIO_1			0x02
#define VCP_RADIO_2			0x03
#define VCP_GPS_1			0x04
#define VCP_GPS_2			0x05
#define VCP_SUN_SENSOR		0x06
#define VCP_STAR_TRACKER	0x07
#define VCP_MAGNETOMETER	0x08
#define VCP_SPECTROMETER	0x09
#define VCP_MAESTRO			0x0A

// VCP Buffer Defines
#define VCP_MAX 4096

// Look at vcplib.c for documentation on these functions
void vcp_get_error(uint8 flags, uint8 *message_buffer, uint32 message_buffer_size);

/*
 * VCP Buffer
 * All interpreted data goes to an
 * internal buffer.
 */
typedef struct
{
	// resulting data
	uint8		address;
	uint8		message[VCP_MAX];
	uint16		crc;

	// helper variables
	uint32		index;
	uint8		flags;
} vcp_buffer;

// Look at vcplib.c for documentation on these functions
void		vcp_clear(vcp_buffer *buff);

uint8		vcp_rx(vcp_buffer *buff, uint8 character);
uint8		vcp_tx(vcp_buffer *buff, uint8 character, uint8 flags);

/*
 * VCP Pointer Buffer
 * This structure MUST be initialized
 * All interpreted output goes to an
 * external buffer at the address pointed
 * to by message.
 */
typedef struct
{
	// resulting data
	uint8		address;
	uint8ptr	message;
	uint16		crc;

	// helper variables
	uint32		size;
	uint32		index;
	uint8		flags;
} vcp_ptrbuffer;

// Look at vcplib.c for documentation on these functions
void		vcpptr_init(vcp_ptrbuffer *buff, uint8 *message_buffer, uint32 message_buffer_size);
void		vcpptr_clear(vcp_ptrbuffer *buff);

uint8		vcpptr_rx(vcp_ptrbuffer *buff, uint8 character);
uint8		vcpptr_tx(vcp_ptrbuffer *buff, uint8 character, uint8 flags);

uint8		vcp_unpackage(uint8ptr dst, uint32ptr dst_size, uint8ptr src, uint32 src_size);
uint8		vcp_package(uint8ptr dst, uint32ptr dst_size, uint8 addr, uint8ptr src, uint32 src_size);

#endif
