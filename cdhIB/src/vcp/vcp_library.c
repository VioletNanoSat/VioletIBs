/** \file
 * vcp_library.c
 * \brief VCP Library source file
 *
 * 
 *
 * Author: Liran, William Voge, Akshay
 */ 

#include "vcp_library.h"
#include "crclib.h"

/**
 * Name         : vcpptr_init
 *
 * Synopsis     : void vcpptr_init(vcp_ptrbuffer *buff, uint8 *message_buffer, uint16 message_buffer_size)
 *
 * \param	*buff					Pointer to the vcp buffer structure,
 * \param	*message_buffer			Pointer to the allocated data buffer,
 * \param	message_buffer_size		Size of the allocated data buffer.
 *
 * Description  : This function initializes a VCP ptrbuffer to be used.
 *				  Must call before calling Receive_VCP_byte().
 * 
 */
void vcpptr_init(vcp_ptrbuffer *buff, uint8 *message_buffer, uint16 message_buffer_size)
{
	buff->address =	0;
	buff->message =	message_buffer;
	buff->size =	message_buffer_size;
	buff->index	=	0;
	buff->crc =		CRC16_INIT_VALUE;
	buff->status =	VCP_IDLE;
}


/**
 * Name         : Create_VCP_frame
 *
 * Synopsis     : uint8_t Create_VCP_frame(uint8ptr dst, uint16ptr dst_size, uint8 addr, uint8ptr src, uint16 src_size)
 *
 * \param	dst  		Pointer to the destination buffer
 * \param	dst_size 	Pointer to the destination size. This will contain the frame size after the function exits
 * \param	addr  		Source peripheral VCP address
 * \param	src  		Pointer to the source buffer
 * \param	src_size  	Source buffer size
 *
 * Description  : This function takes a full packet and packages it into a VCP frame,
 *				  including VCP address, CRC calculation and KISS escaping
 * 
 * \return				VCP status flags
 */
uint8_t Create_VCP_frame(uint8ptr dst, uint16ptr dst_size, uint8 addr, uint8ptr src, uint16 src_size)
{
	uint16_t crc = CRC16_INIT_VALUE;
	uint16_t src_index = 0;
	uint16_t dst_index = 0;
	uint16_t payload_size;
	
	// Check for invalid buffers
	if (dst == NULL || src == NULL)
		//return VCP_NULL_ERR;
	// Check for invalid VCP address	
	if (addr > VCP_BROKEN && addr != VCP_SUN_SENSOR)
		return VCP_ADDR_ERR;		
		
	// Calculate CRC:
	append_crc16(addr, (uint16ptr)&crc);
	for (src_index = 0; src_index < src_size; src_index++)
	{
		append_crc16(src[src_index], (uint16ptr)&crc);
	}
	
	/*unsigned short crcSUN = 0xFFFF;
	uint8ptr srcSUN;
	srcSUN[0] = 0x39;
	for(int i = 0; i<src_size; i++){
		srcSUN[i+1] = src[i];
	}
	int src_size_sun = src_size +1;
	while(src_size_sun-- > 0){
		unsigned char ch = *srcSUN++;
		for(int i=0; i<8; i++){
			crcSUN = (crcSUN>>1)^(((ch^crcSUN) & 0x01)? 0x8408: 0);
			ch>>=1;
		}
	}*///FOR SUN SENSOR
	
	// Add CRC to the end of the source buffer
	src[src_index++] = ((crc >> 8) & 0xFF);//(crcSUN & 0xFF);
	src[src_index++] = (crc & 0xFF);//((crcSUN >> 8) & 0xFF);
	
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
		//if (dst_index >= *dst_size - 1){
			//return VCP_OVR_ERR;
		//}
	}
	if (dst_index >= *dst_size - 1){
		//return VCP_OVR_ERR;
		dst_index = *dst_size - 3;
	}
	// End the frame with FEND
	dst[dst_index++] =					FEND;
	
	// Save the frame size
	*dst_size = dst_index;
	
	// All good
	return VCP_TERM;

}

/**
 * Name         : Create_VCP_frame
 *
 * Synopsis     : uint8_t Create_VCP_frame(uint8ptr dst, uint16ptr dst_size, uint8 addr, uint8ptr src, uint16 src_size)
 *
 * \param	dst  		Pointer to the destination buffer
 * \param	dst_size 	Pointer to the destination size. This will contain the frame size after the function exits
 * \param	addr  		Source peripheral VCP address
 * \param	src  		Pointer to the source buffer
 * \param	src_size  	Source buffer size
 *
 * Description  : This function takes a full packet and packages it into a VCP frame,
 *				  including VCP address, CRC calculation and KISS escaping
 * 
 * \return				VCP status flags
 */
uint8_t Create_Sun_VCP_frame(uint8ptr dst, uint16ptr dst_size, uint8 addr, uint8ptr src, uint16 src_size)
{
	uint16_t crc = CRC16_INIT_VALUE;
	uint16_t src_index = 0;
	uint16_t dst_index = 0;
	uint16_t payload_size;
	
	// Check for invalid buffers
	if (dst == NULL || src == NULL)
		//return VCP_NULL_ERR;
	// Check for invalid VCP address	
	if (addr > VCP_BROKEN && addr != VCP_SUN_SENSOR)
		return VCP_ADDR_ERR;		
		
	// Calculate CRC:
	append_crc16(addr, (uint16ptr)&crc);
	for (src_index = 0; src_index < src_size; src_index++)
	{
		append_crc16(src[src_index], (uint16ptr)&crc);
	}
	
	unsigned short crcSUN = 0xFFFF;
	uint8ptr srcSUN;
	srcSUN[0] = 0x39;
	for(int i = 0; i<src_size; i++){
		srcSUN[i+1] = src[i];
	}
	int src_size_sun = src_size +1;
	while(src_size_sun-- > 0){
		unsigned char ch = *srcSUN++;
		for(int i=0; i<8; i++){
			crcSUN = (crcSUN>>1)^(((ch^crcSUN) & 0x01)? 0x8408: 0);
			ch>>=1;
		}
	}///FOR SUN SENSOR
	
	// Add CRC to the end of the source buffer
	src[src_index++] = /*((crc >> 8) & 0xFF);*/(crcSUN & 0xFF);
	src[src_index++] = /*(crc & 0xFF);*/((crcSUN >> 8) & 0xFF);
	
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
		//if (dst_index >= *dst_size - 1){
			//return VCP_OVR_ERR;
		//}
	}
	if (dst_index >= *dst_size - 1){
		//return VCP_OVR_ERR;
		dst_index = *dst_size - 3;
	}
	// End the frame with FEND
	dst[dst_index++] =					FEND;
	
	// Save the frame size
	*dst_size = dst_index;
	
	// All good
	return VCP_TERM;

}



/**
 * Name         : Receive_VCP_byte
 *
 * Synopsis     : uint8_t Receive_VCP_byte(vcp_ptrbuffer *buff, uint8 byte)
 *
 * \param	*buff	Pointer to the vcp buffer structure
 * \param	byte	Received byte
 *
 * Description  : This function takes one byte at a time from a VCP frame,
 *				  removing KISS escaping, checking CRC when the frame is done.
 * 
 * \return			VCP status flags
 */
uint16_t bitez = 0;
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
			if(byte == FEND){
				buff->status = VCP_ADDRESS;
			}else if (byte > VCP_FC && byte != VCP_SUN_SENSOR){
				if(byte != 0x11){
					return VCP_ADDR_ERR;
				}else{
					buff->address = byte;
					buff->status = VCP_RECEIVING;
				}
			}
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
				//bitez++;
			}			
			if(bitez>45){
				//bitez=0;
				//buff->status = VCP_TERM;
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
				//buff->status = VCP_RECEIVING;
			break;
		default:
			buff->status = VCP_IDLE;
			break; 
	}
	
	// End of frame
	if (buff->status == VCP_TERM)
	{
		//radio.tx_LED_pin == 0;
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
//		if (buff->crc != message_crc)
//			return VCP_CRC_ERR;
	}

	return buff->status;
}