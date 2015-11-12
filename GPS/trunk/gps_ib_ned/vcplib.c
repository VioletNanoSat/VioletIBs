/*
 * vcplib.c
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#include "vcplib.h"
#include "common.h"
#include "crclib.h"

/*
 * vcp_get_error
 *
 * This parses the flags of a vcp_buffer into a
 * readable string for debugging purposes.
 */
void vcp_get_error(uint8 flags, uint8 *message_buffer, uint32 message_buffer_size)
{
	uint32 index = 0;
	if ((flags & VCP_TERM) == VCP_TERM)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Buffer is Terminated | ", 23);

	if ((flags & VCP_ESC) == VCP_ESC)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Buffer is Escaped | ", 20);

	if ((flags & VCP_FULL_ERR) == VCP_FULL_ERR)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Buffer is Full | ", 17);

	if ((flags & VCP_OVR_ERR) == VCP_OVR_ERR)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Buffer has Overflowed | ", 24);

	if ((flags & VCP_CRC_ERR) == VCP_CRC_ERR)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"CRC does not match | ", 21);

	if ((flags & VCP_NULL_ERR) == VCP_NULL_ERR)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Buffer is NULL | ", 17);

	if ((flags & VCP_ADDR_ERR) == VCP_ADDR_ERR)
		index = insert_str(message_buffer, message_buffer_size, index, (uint8*)"Address is NULL | ", 18);

	message_buffer[index] = '\0';
}

/*
 * vcp_clear
 *
 * This clears a vcp buffer so it can be reused.
 */
void vcp_clear(vcp_buffer *buff)
{
	buff->address = 0;
	buff->index	= 0;
	buff->crc	= CRC16_INIT_VALUE;
	buff->flags	= 0;
}

/*
 * vcp_rx
 *
 * Removes VCP Wrapper
 *
 * returns an 8 bit vcp flag
 * this same flag is stored in buff->flags
 *
 * This function takes in one character at a time,
 * removing kiss frames and calculating the crc.
 */
uint8 vcp_rx(vcp_buffer *buff, uint8 character)
{

	uint32 start_index = buff->index;

	// Check to see if the buffer is already full
	if ((buff->flags & VCP_TERM) == VCP_TERM)
	{
		buff->flags |= VCP_FULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer will overflow
	if (buff->index >= VCP_MAX-1)
	{
		buff->flags |= VCP_OVR_ERR;
		return buff->flags;
	}

	// Check to see if character is the end of the packet
	if (character == FEND)
	{
		if (buff->index != 0)
		{
			buff->flags |= VCP_TERM;
			if (buff->crc != *(uint16*)(&buff->message[buff->index-2]))
				buff->flags |= VCP_CRC_ERR;

			buff->message[--buff->index] = 0;
			buff->message[--buff->index] = 0;

			return buff->flags;
		}
	}
	// Check for an escaped character
	else if (character == FESC)
		buff->flags |= VCP_ESC;
	else if (character == TFEND && (buff->flags & VCP_ESC) == VCP_ESC)
	{
		buff->message[buff->index++] = FEND;
		buff->flags ^= VCP_ESC;
	}
	else if (character == TFESC && (buff->flags & VCP_ESC) == VCP_ESC)
	{
		buff->message[buff->index++] = FESC;
		buff->flags ^= VCP_ESC;
	}
	// Just add a character to the buffer
	else
		buff->message[buff->index++] = character;

	// Calculate the 16 bit crc if the index has changed
	if (buff->index > 2 && buff->index != start_index)
		append_crc16(buff->message[buff->index - 3], &buff->crc);

	// If this is the first byte of the data, then it is the sensor address
	if (buff->index == 1 && buff->address == 0)
		buff->address = buff->message[--buff->index];

	return buff->flags;
}

/*
 * vcp_tx
 *
 * Adds VCP Wrapper
 *
 * returns an 8 bit vcp flag
 * this same flag is stored in buff->flags
 *
 * This function takes in one character at a time,
 * adding kiss frames and calculating the crc.
 *
 * Don't forget to set the address byte in the buff
 * structure before you call this function!!!!!!
 */
uint8 vcp_tx(vcp_buffer *buff, uint8 character, uint8 flags)
{
	// Check to see if the buffer is already full
	if ((buff->flags & VCP_TERM) == VCP_TERM)
	{
		buff->flags |= VCP_FULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer will overflow
	if (buff->index >= VCP_MAX-3)
	{
		buff->flags |= VCP_OVR_ERR;
		return buff->flags;
	}

	// Check to see if this is the end of the packet
	if ((flags & VCP_TERM) == VCP_TERM)
	{
		buff->message[buff->index++] = ((uint8*)&buff->crc)[0];
		buff->message[buff->index++] = ((uint8*)&buff->crc)[1];
		buff->message[buff->index++] = FEND;
		buff->flags |= VCP_TERM;
		return buff->flags;
	}

	// Check to see if this is the beginning of the packet
	if (buff->index == 0)
	{
		// start the frame
		buff->message[buff->index++] = FEND;

		// Check for NULL address
		if (buff->address == 0)
		{
			buff->flags |= VCP_ADDR_ERR;
			return buff->flags;
		}

		// Insert the address field
		// The value for the address should never be anywhere near FEND or FESC, but its always good to check
		if (buff->address == FEND)
		{
			buff->message[buff->index++] = FESC;
			buff->message[buff->index++] = TFEND;
		}
		else if (buff->address == FESC)
		{
			buff->message[buff->index++] = FESC;
			buff->message[buff->index++] = TFESC;
		}
		else
			buff->message[buff->index++] = buff->address;
	}


	// Check for FEND
	if (character == FEND)
	{
		buff->message[buff->index++] = FESC;
		buff->message[buff->index++] = TFEND;
	}
	// Check for FESC
	else if (character == FESC)
	{
		buff->message[buff->index++] = FESC;
		buff->message[buff->index++] = TFESC;
	}
	// Add the character to the buffer
	else
		buff->message[buff->index++] = character;

	// Calculate the crc
	append_crc16(character, &buff->crc);

	return buff->flags;
}

/*
 * vcpptr_init
 *
 * This initializes a vcp ptrbuffer to be used.
 */
void vcpptr_init(vcp_ptrbuffer *buff, uint8 *message_buffer, uint32 message_buffer_size)
{
	buff->address = 0;
	buff->message = message_buffer;
	buff->size = message_buffer_size;
	buff->index	= 0;
	buff->crc	= CRC16_INIT_VALUE;
	buff->flags	= 0;
}

/*
 * vcpptr_clear
 *
 * This clears a vcp ptrbuffer so it can be reused.
 */
void vcpptr_clear(vcp_ptrbuffer *buff)
{
	buff->address = 0;
	buff->index	= 0;
	buff->crc	= CRC16_INIT_VALUE;
	buff->flags	= 0;
}

/*
 * vcpptr_rx
 *
 * Removes VCP Wrapper
 *
 * returns an 8 bit vcp flag
 * this same flag is stored in buff->flags
 *
 * This function takes in one character at a time,
 * removing kiss frames and calculating the crc.
 */
uint8 vcpptr_rx(vcp_ptrbuffer *buff, uint8 character)
{
	uint32 start_index = buff->index;

	// Check for null buffer
	if (buff->message == 0)
	{
		buff->flags |= VCP_NULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer is already full
	if ((buff->flags & VCP_TERM) == VCP_TERM)
	{
		buff->flags |= VCP_FULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer will overflow
	if (buff->index >= buff->size-1)
	{
		buff->flags |= VCP_OVR_ERR;
		return buff->flags;
	}

	// Check to see if character is the end of the packet
	if (character == FEND)
	{
		if (buff->index != 0)
		{
			buff->flags |= VCP_TERM;
			if (buff->crc != *(uint16*)(&buff->message[buff->index-2]))
				buff->flags |= VCP_CRC_ERR;

			buff->message[--buff->index] = 0;
			buff->message[--buff->index] = 0;

			return buff->flags;
		}
	}
	// Check for an escaped character
	else if (character == FESC)
		buff->flags |= VCP_ESC;
	else if (character == TFEND && (buff->flags & VCP_ESC) == VCP_ESC)
	{
		buff->message[buff->index++] = FEND;
		buff->flags ^= VCP_ESC;
	}
	else if (character == TFESC && (buff->flags & VCP_ESC) == VCP_ESC)
	{
		buff->message[buff->index++] = FESC;
		buff->flags ^= VCP_ESC;
	}
	// Just add a character to the buffer
	else
		buff->message[buff->index++] = character;

	// Calculate the 16 bit crc if the index has changed
	if (buff->index > 2 && buff->index != start_index)
		append_crc16(buff->message[buff->index - 3], &buff->crc);

	// If this is the first byte of the data, then it is the sensor address
	if (buff->index == 1 && buff->address == 0)
		buff->address = buff->message[--buff->index];

	return buff->flags;
}

/*
 * vcpptr_tx
 *
 * Adds VCP Wrapper
 *
 * returns an 8 bit vcp flag
 * this same flag is stored in buff->flags
 *
 * This function takes in one character at a time,
 * adding kiss frames and calculating the crc.
 *
 * Don't forget to set the address byte in the buff
 * structure before you call this function!!!!!!
 */
uint8 vcpptr_tx(vcp_ptrbuffer *buff, uint8 character, uint8 flags)
{
	// Check for null buffer
	if (buff->message == 0)
	{
		buff->flags |= VCP_NULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer is already full
	if ((buff->flags & VCP_TERM) == VCP_TERM)
	{
		buff->flags |= VCP_FULL_ERR;
		return buff->flags;
	}

	// Check to see if the buffer will overflow
	if (buff->index >= buff->size-3)
	{
		buff->flags |= VCP_OVR_ERR;
		return buff->flags;
	}

	// Check to see if this is the end of the packet
	if ((flags & VCP_TERM) == VCP_TERM)
	{
		buff->message[buff->index++] = ((uint8*)&buff->crc)[0];
		buff->message[buff->index++] = ((uint8*)&buff->crc)[1];
		buff->message[buff->index++] = FEND;
		buff->flags |= VCP_TERM;
		return buff->flags;
	}

	// Check to see if this is the beginning of the packet
	if (buff->index == 0)
	{
		// start the frame
		buff->message[buff->index++] = FEND;

		// Check for NULL address
		if (buff->address == 0)
		{
			buff->flags |= VCP_ADDR_ERR;
			return buff->flags;
		}
		// Insert the address field
		// The value for the address should never be anywhere near FEND or FESC, but its always good to check
		if (buff->address == FEND)
		{
			buff->message[buff->index++] = FESC;
			buff->message[buff->index++] = TFEND;
		}
		else if (buff->address == FESC)
		{
			buff->message[buff->index++] = FESC;
			buff->message[buff->index++] = TFESC;
		}
		else
			buff->message[buff->index++] = buff->address;
	}

	// Check for FEND
	if (character == FEND)
	{
		buff->message[buff->index++] = FESC;
		buff->message[buff->index++] = TFEND;
	}
	// Check for FESC
	else if (character == FESC)
	{
		buff->message[buff->index++] = FESC;
		buff->message[buff->index++] = TFESC;
	}
	// Add the character to the buffer
	else
		buff->message[buff->index++] = character;

	// Calculate the crc
	append_crc16(character, &buff->crc);

	return buff->flags;
}

/*
 * vcp_unpackage
 *
 * Unpackages an entire packet into dst,
 * returning the buffer's flags.
 */
uint8 vcp_unpackage(uint8ptr dst, uint32ptr dst_size, uint8ptr src, uint32 src_size)
{
	vcp_ptrbuffer buff;
	vcpptr_init(&buff, dst, *dst_size);
	uint32 x = 0;

	for (x = 0; x < src_size; x++)
	{
		vcpptr_rx(&buff, src[x]);
		if (buff.flags != 0 && buff.flags != VCP_ESC)
		{
			*dst_size = buff.index;
			return buff.flags;
		}
	}

	*dst_size = buff.index;

	return buff.flags;
}

/*
 * vcp_package
 *
 * Packages an entire packet into dst,
 * returning the buffer's flags.
 */
uint8 vcp_package(uint8ptr dst, uint32ptr dst_size, uint8 addr, uint8ptr src, uint32 src_size)
{
	vcp_ptrbuffer buff;
	vcpptr_init(&buff, dst, *dst_size);
	buff.address = addr;
	uint32 x = 0;

	for (x = 0; x < src_size; x++)
	{
		vcpptr_tx(&buff, src[x], 0);
		if (buff.flags != 0)
		{
			*dst_size = buff.index;
			return buff.flags;
		}
	}
	vcpptr_tx(&buff, 0, VCP_TERM);

	*dst_size = buff.index;

	return buff.flags;
}
