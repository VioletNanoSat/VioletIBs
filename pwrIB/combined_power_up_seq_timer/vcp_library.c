/*
 * vcp_library.c
 *
 * Created: 3/8/2012 2:37:15 PM
 *  Author: Liran
 */ 

#include "vcp_library.h"
#include "crclib.h"
#include "mcupwr-Defs.h"

// This function initializes a VCP ptrbuffer to be used.
// Must call before calling Receive_VCP_byte() 
// Parameters: 
// vcp_ptrbuffer	*buff -					Pointer to the vcp buffer structure
// uint8			*message_buffer -		Pointer to the allocated data buffer
// uint16			message_buffer_size -	Size of the allocated data buffer
void vcpptr_init(vcp_ptrbuffer *buff, uint8 *message_buffer, uint16 message_buffer_size)
{
	buff->address =	0;
	buff->message =	message_buffer;
	buff->size =	message_buffer_size;
	buff->index	=	0;
	buff->crc =		CRC16_INIT_VALUE;
	buff->status =	VCP_IDLE;
}

// This function takes a full packet and packages it into a VCP frame,
// including VCP address, CRC calculation and KISS escaping
// and return VCP status.
// Parameters:
// uint8ptr		dst -		Pointer to the destination buffer
// uint16ptr	dst_size -	Pointer to the destination size. This will contain the frame size after the function exits.
// uint8		addr -		Source peripheral VCP address 
// uint8ptr		src -		Pointer to the source buffer
// uint16		src_size -	Source size
uint8_t Create_VCP_frame(uint8ptr dst, uint16_t* dst_size, uint8 addr, uint8ptr src, uint16 src_size)
{
	uint16_t crc = CRC16_INIT_VALUE;
	uint16_t src_index = 0;
	uint16_t dst_index = 0;
	uint16_t payload_size;
	
	// Check for invalid buffers
	if (dst == NULL || src == NULL)
		return VCP_NULL_ERR;

	// Check for invalid VCP address	
	if (addr > VCP_FC && addr != VCP_SUN_SENSOR)
		return VCP_ADDR_ERR;
		
	// Calculate CRC:
	append_crc16(addr, &crc);

	for (src_index = 0; src_index < src_size; src_index++)
	  append_crc16(src[src_index], &crc);
	
	// Add CRC to the end of the source buffer
	src[src_index++] = ((crc >> 8) & 0xFF);
	src[src_index++] = (crc & 0xFF);
	
	// Size including the 2 CRC bytes
	payload_size = src_index;
	
	// Build KISS Frame:
	
	// Start the frame with FEND
	dst[dst_index++] =					FEND;
	// then insert VCP address
	dst[dst_index++] =					addr;
	
	// Copy src to dst and Escape when necessary
	for (src_index = 0; src_index < payload_size; src_index++ )
	{
		if (src[src_index] == FEND)
		{
			dst[dst_index++] =			FESC;
			dst[dst_index++] =			TFEND;
		}
		else if (src[src_index] == FESC)
		{
			dst[dst_index++] =			FESC;
			dst[dst_index++] =			TFESC;
		}
		else
		{
			dst[dst_index++] =			src[src_index];
		}
		
		// Check if the frame fits in the dst buffer 
		//if (dst_index >= *dst_size - 1)
			//return VCP_OVR_ERR;
	}
	
	// End the frame with FEND
	dst[dst_index++] =					FEND;
	
	// Save the frame size
	*dst_size = dst_index;
	
	// All good
	return VCP_TERM;
}

// This function takes one byte at a time from a VCP frame,
// removing KISS escaping, checking CRC when the frame is done,
// and return VCP status.
// Parameters:
// vcp_ptrbuffer	*buff -	Pointer to the vcp buffer structure
// uint8			byte -	received byte
uint8_t Receive_VCP_byte(vcp_ptrbuffer *buff, uint8 byte)
{
	uint16_t payload_index;
	uint16_t message_crc;
	
	// Check for invalid buffer
	if (buff->message == NULL)
		return VCP_NULL_ERR;
	
	// Check if the buffer will overflow
	if (buff->index >= buff->size-1)
		return VCP_OVR_ERR;
	
	// State Machine
	switch (buff->status)
	{
		case VCP_IDLE:										
			if (byte == FEND)
				buff->status = VCP_ADDRESS;	
			break;
		case VCP_ADDRESS:
			// Check for invalid VCP address
			if (byte > VCP_FC && byte != VCP_SUN_SENSOR)
				return VCP_ADDR_ERR;
			else
			{
				buff->address = byte;
				buff->status = VCP_RECEIVING;
			}	
			break;
		case VCP_RECEIVING:
			if (byte == FEND)
			{
				if (buff->index > 0)
					// Done
					buff->status = VCP_TERM;
				else
					// No data between FENDs - assume lost sync and start over
					buff->status = VCP_ADDRESS;
			}
			else if (byte == FESC)
				buff->status = VCP_ESC;
			else
			{
				buff->message[(buff->index)++] = byte;	
			}						
			break;
		case VCP_ESC:
			if (byte == TFEND)
			{
				buff->message[(buff->index)++] = FEND;
				buff->status = VCP_RECEIVING;
			}
			else if (byte == TFESC)
			{
				buff->message[(buff->index)++] = FESC;
				buff->status = VCP_RECEIVING;
			}
			else
				return VCP_ESC_ERR;	
			break;
		default:
			buff->status = VCP_IDLE;
			break; 
	}
	
	// End of frame
	if (buff->status == VCP_TERM)
	{
		// Message CRC is last 2 bytes 
		message_crc = (buff->message[buff->index-2] << 8 ) + buff->message[buff->index-1];
		// Remove CRC bytes from the message
		buff->index -= 2;
		// Calculate CRC on received message (including address)
		append_crc16(buff->address, &(buff->crc));
		for (payload_index = 0; payload_index < buff->index; payload_index++)
		{
			append_crc16(buff->message[payload_index], &buff->crc);
		}
		// Check Calculated CRC against Received CRC
		if (buff->crc != message_crc)
			return VCP_CRC_ERR;
	}

	return buff->status;
}
