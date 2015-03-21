// Package a packet from a source buffer to a destination buffer into a VCP frame 

	// Reset transmit data count to full buffer size
	dest_byte_count = dest_data_buffer_size;
	// create VCP frame in the peripheral transmit buffer
	VCP_tx_status = Create_VCP_frame(dest_data, 
									(uint16ptr)dest_byte_count, 
									source_VCP_address, 
									source_data, 
									source_byte_count);

	if (VCP_tx_status == VCP_OVR_ERR)	{}	// Overflow error
	if (VCP_tx_status == VCP_NULL_ERR)	{}	// Null buffer error
	if (VCP_tx_status == VCP_ADDR_ERR)	{}	// Address error 
	if (VCP_tx_status == VCP_TERM)			// Done with no errors
	{

		// Transmit with UART interrupt
		
	}		

	

// This loop reads a VCP peripheral ring buffer into a linear non-VCP buffer
	while(!RingBuffer_IsEmpty(&rx_ringbuff))
	{
		//if there's no vcp buffer, initialize it
		if (vcp_rx_msg.message == NULL)
		{
			vcpptr_init(&(vcp_rx_msg), rx_data, rx_data_buffer_size);
			rx_byte_count = 0;
		}
		
		// Get byte from receive ring buffer
		uint8_t rx_byte = RingBuffer_Remove(&rx_ringbuff);
		// decode VCP
		VCP_rx_status = Receive_VCP_byte(&(vcp_rx_msg), rx_byte);

		if (VCP_rx_status & VCP_OVR_ERR)	{}	// Overflow error
		if (VCP_rx_status & VCP_CRC_ERR)	{}	// CRC error
		if (VCP_rx_status & VCP_NULL_ERR)	{}	// Null buffer error
		if (VCP_rx_status & VCP_ADDR_ERR)	{}	// Address error
		if (VCP_rx_status & VCP_ESC_ERR)	{}	// Escaping error
		if (VCP_rx_status == VCP_TERM) 			// Done with no errors
		{
			// save received byte count
			rx_byte_count = vcp_rx_msg.index;
			
			// Received data ready - do something with it here !	
			
			// Kill the buffer
			vcp_rx_msg.message = NULL;
			// Exit the while loop
			break;
		}	
	}		
