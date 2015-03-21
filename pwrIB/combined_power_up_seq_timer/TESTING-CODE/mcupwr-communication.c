#ifndef MCUPWR_COMMUNICATION_C
#define MCUPWR_COMMUNICATION_C

#include "mcupwr-Defs.h"
#include "vcp_library.h"
#include "crclib.h"
#include "uart.h"

ISR(TIMER0_COMP_vect)
{
  if ( timer0_counter[0] > 0 )
    --timer0_counter[0];
  if ( timer0_counter[1] > 0 )
    --timer0_counter[1];
}

/* Timer 1(A) routine */
ISR(TIMER1_COMPA_vect)		//Handle Radio & Torquer 30 min delays here
{
	SVIT_t *component;
	
    //if ( receive_flag == 1){		//If message is received, reset timer1_counter[0] to CYCLE_COUNTER
	if (timer1_counter[0] <= 0	  &&     rad_torq_flag){	//provides 30 minute delay			
	    timer1_counter[0] = CYCLE_COUNTER;
		
		//Turn on radios				
		component = &svit[RADIO_1];
		switch_on( component->switch_num );
		component->switch_state = SW_ON;
		component = &svit[RADIO_2];
		switch_on( component->switch_num );
		component->switch_state = SW_ON;
		
		//Turn on torque coils			
		component = &svit[TORQUER_1];
		switch_on( component->switch_num );
		component->switch_state = SW_ON;
		component = &svit[TORQUER_2];
		switch_on( component->switch_num );
		component->switch_state = SW_ON;
		component = &svit[TORQUER_3];
		switch_on( component->switch_num );
		component->switch_state = SW_ON;
		torquer_on(TORQUER_1);
		torquer_on(TORQUER_2);
		torquer_on(TORQUER_3);
		
		//PORTC ^= 0x02;	//LED for STK testing
		//PORTC ^= 0x01;
		
		//Don't reexecute this code
		rad_torq_flag = 0;

	}
	else{
		//PORTC ^= 0x01;		//LED for STK testing at PORTC0
		//_delay_ms(500);
		--timer1_counter[0];
	}
}

ISR(USART1_TX_vect)
{
  tx_put_byte( 1 );
}

ISR(USART1_RX_vect)
{
  if( Receive_VCP_byte( uart_vcp_buff[1], UDR1 ) == VCP_TERM )
  {
    rx_flag[1]++;
  }
}

ISR ( ADC_vect )
{
  ADC_low = ADCL;	// Left adjusted; read 2 LSB then 8 MSB
  ADC_high = ADCH;
  adc_flag = 1;
}

ISR( USART0_TX_vect )
{
  tx_put_byte( 0 );
}

ISR( USART0_RX_vect )
{
  if( Receive_VCP_byte( uart_vcp_buff[0], UDR0 ) == VCP_TERM )
  {
    rx_flag[0]++;
  }
}

void tx_put_byte( uint8_t uart )
{
  if ( uart != 0 && uart != 1 )
    return;
  if( tel_packet_index[uart] < tel_packet_size[uart] )
  {
      if ( uart == 0 )
      UDR0 = tel_packet[uart][tel_packet_index[uart]++];
    else if ( uart == 1 )
      UDR1 = tel_packet[uart][tel_packet_index[uart]++];
  }
}


void construct_telemetry_packet( uint8_t* packet_payload )
{
  packet_payload[0] = VCP_POWER_TELEMETRY;

  // switch on/off states
  uint8_t on_off_state0;
  uint8_t on_off_state1;
  uint8_t on_off_state2;
  uint8_t on_off_state3;
  uint8_t on_off_state4;

  on_off_state0 = ( svit[SPECTROMETER].switch_state << 0 ) |
                  ( svit[STAR_TRACKER].switch_state << 1 ) |
                  ( svit[FC_5V].switch_state << 2 )        |
                  ( svit[GPS_1].switch_state << 3 )        |
                  ( svit[GPS_2].switch_state << 4 )        |
                  ( svit[CDH_IB].switch_state << 5 )       |
                  ( svit[HEATER_1].switch_state << 6 )     |
                  ( svit[HEATER_2].switch_state << 7 )     ;

  on_off_state1 = ( svit[CMG].switch_state << 0 )        |
                  ( svit[SUN_SENSOR].switch_state << 1 ) |
                  ( svit[RADIO_1].switch_state << 2 )    |
                  ( svit[RADIO_2].switch_state << 3 )    |
                  ( svit[FOG_15V].switch_state << 4 )    |
                  ( svit[FOG_5V].switch_state << 5  )    ;

  on_off_state2 = ( svit[TORQUER_1].switch_state << 0 )  |
                  ( svit[TORQUER_2].switch_state << 1 ) |
                  ( svit[TORQUER_3].switch_state << 2 ) |
                  ( svit[MAESTRO].switch_state << 3 );

  packet_payload[1] = on_off_state0;
  packet_payload[2] = on_off_state1;
  packet_payload[3] = on_off_state2;
  packet_payload[4] = 0x99;
  packet_payload[5] = svit[MAESTRO].switch_state;

  // voltage values (raw ADC output)
  packet_payload[6]  = SVIT_check_V_critical( svit[SPECTROMETER].name );
  packet_payload[7]  = SVIT_check_V_critical( svit[STAR_TRACKER].name );
  packet_payload[8]  = SVIT_check_V_critical( svit[FC_5V].name );
  packet_payload[9]  = SVIT_check_V_critical( svit[FC_3_3V].name );
  packet_payload[10] = SVIT_check_V_critical( svit[GPS_1].name );
  packet_payload[11] = SVIT_check_V_critical( svit[CDH_IB].name );
  packet_payload[12] = SVIT_check_V_critical( svit[HEATER_1].name );
  packet_payload[13] = SVIT_check_V_critical( svit[HEATER_2].name );
  packet_payload[14] = SVIT_check_V_critical( svit[CMG].name );
  packet_payload[15] = SVIT_check_V_critical( svit[SUN_SENSOR].name );
  packet_payload[16] = SVIT_check_V_critical( svit[RADIO_1].name );
  packet_payload[17] = SVIT_check_V_critical( svit[RADIO_2].name );
  packet_payload[18] = SVIT_check_V_critical( svit[FOG_15V].name );
  packet_payload[19] = SVIT_check_V_critical( svit[FOG_5V].name );
  packet_payload[20] = SVIT_check_V_critical( svit[TORQUER_1].name );
  packet_payload[21] = SVIT_check_V_critical( svit[TORQUER_2].name );
  packet_payload[22] = SVIT_check_V_critical( svit[TORQUER_3].name );
  packet_payload[23] = SVIT_check_V_critical( svit[BATTERY_1].name );
  packet_payload[24] = SVIT_check_V_critical( svit[BATTERY_2].name );
  packet_payload[25] = SVIT_check_V_critical( svit[SOLAR_FULL].name );
  packet_payload[26] = SVIT_check_V_critical( svit[SOLAR_1].name );
  packet_payload[27] = SVIT_check_V_critical( svit[SOLAR_2].name );
  packet_payload[28] = SVIT_check_V_critical( svit[SOLAR_3].name );
  packet_payload[29] = SVIT_check_V_critical( svit[SOLAR_4].name );
  packet_payload[30] = SVIT_check_V_critical( svit[SOLAR_5].name );
  packet_payload[31] = SVIT_check_V_critical( svit[SOLAR_6].name );
  packet_payload[32] = SVIT_check_V_critical( svit[SOLAR_7].name );
  packet_payload[33] = SVIT_check_V_critical( svit[SOLAR_8].name );
  packet_payload[34] = SVIT_check_V_critical( svit[SOLAR_9].name );
  packet_payload[35] = SVIT_check_V_critical( svit[SOLAR_10].name );
  packet_payload[36] = SVIT_check_V_critical( svit[SOLAR_11].name );
  packet_payload[37] = SVIT_check_V_critical( svit[SOLAR_12].name );
  packet_payload[38] = SVIT_check_V_critical( svit[POWER_BOARD].name );

  // voltage error
  
  //uint8_t voltage_error0;
  //uint8_t voltage_error1;
  //uint8_t voltage_error2;
  //uint8_t voltage_error3;
  //uint8_t voltage_error4;
 
  packet_payload[39] = 0;
  packet_payload[40] = 0;
  packet_payload[41] = 0;
  packet_payload[42] = 0;
  packet_payload[43] = 0;

  // current values (raw ADC output)
  packet_payload[44] = SVIT_check_I_critical( svit[SPECTROMETER].name );
  packet_payload[45] = SVIT_check_I_critical( svit[STAR_TRACKER].name );
  packet_payload[46] = SVIT_check_I_critical( svit[FC_5V].name );
  packet_payload[47] = SVIT_check_I_critical( svit[FC_3_3V].name );
  packet_payload[48] = SVIT_check_I_critical( svit[GPS_1].name );
  packet_payload[49] = SVIT_check_I_critical( svit[CDH_IB].name );
  packet_payload[50] = SVIT_check_I_critical( svit[HEATER_1].name );
  packet_payload[51] = SVIT_check_I_critical( svit[HEATER_2].name );
  packet_payload[52] = SVIT_check_I_critical( svit[CMG].name );
  packet_payload[53] = SVIT_check_I_critical( svit[SUN_SENSOR].name );
  packet_payload[54] = SVIT_check_I_critical( svit[RADIO_1].name );
  packet_payload[55] = SVIT_check_I_critical( svit[RADIO_2].name );
  packet_payload[56] = SVIT_check_I_critical( svit[FOG_15V].name );
  packet_payload[57] = SVIT_check_I_critical( svit[FOG_5V].name );
  packet_payload[58] = SVIT_check_I_critical( svit[TORQUER_1].name );
  packet_payload[59] = SVIT_check_I_critical( svit[TORQUER_2].name );
  packet_payload[60] = SVIT_check_I_critical( svit[TORQUER_3].name );
  packet_payload[61] = SVIT_check_I_critical( svit[BATTERY_1].name );
  packet_payload[62] = SVIT_check_I_critical( svit[BATTERY_2].name );
  packet_payload[63] = SVIT_check_I_critical( svit[SOLAR_FULL].name );
  packet_payload[64] = SVIT_check_I_critical( svit[SOLAR_1].name );
  packet_payload[65] = SVIT_check_I_critical( svit[SOLAR_2].name );
  packet_payload[66] = SVIT_check_I_critical( svit[SOLAR_3].name );
  packet_payload[67] = SVIT_check_I_critical( svit[SOLAR_4].name );
  packet_payload[68] = SVIT_check_I_critical( svit[SOLAR_5].name );
  packet_payload[69] = SVIT_check_I_critical( svit[SOLAR_6].name );
  packet_payload[70] = SVIT_check_I_critical( svit[SOLAR_7].name );
  packet_payload[71] = SVIT_check_I_critical( svit[SOLAR_8].name );
  packet_payload[72] = SVIT_check_I_critical( svit[SOLAR_9].name );
  packet_payload[73] = SVIT_check_I_critical( svit[SOLAR_10].name );
  packet_payload[74] = SVIT_check_I_critical( svit[SOLAR_11].name );
  packet_payload[75] = SVIT_check_I_critical( svit[SOLAR_12].name );
  packet_payload[76] = 0xFF;//SVIT_check_I_critical( svit[POWER_BOARD].name );

  // current error
  
  //uint8_t current_error0;
  //uint8_t current_error1;
  //uint8_t current_error2;
  //uint8_t current_error3;
  //uint8_t current_error4;

  packet_payload[77] = batt1_voltage;//V_ack_change();
  packet_payload[78] = soc;//soc;// I_ack_change();
  packet_payload[79] = 0x00;//low >> 6;//safe_mode;
  packet_payload[80] = 0x00;//charging;
  packet_payload[81] = 0x00;//chargeforward;

  // temperature values (raw ADC output)
  packet_payload[82] = debug;//average_samples( svit[STAR_TRACKER].T_samples );
  packet_payload[83] = 0xFF;//average_samples( svit[BATTERY_1].T_samples );
  packet_payload[84] = average_samples( svit[BATTERY_2].T_samples );
  packet_payload[85] = average_samples( svit[SOLAR_1].T_samples );
  packet_payload[86] = average_samples( svit[SOLAR_2].T_samples );
  packet_payload[87] = average_samples( svit[SOLAR_3].T_samples );
  packet_payload[88] = average_samples( svit[SOLAR_4].T_samples );
  packet_payload[89] = average_samples( svit[SOLAR_5].T_samples );
  packet_payload[90] = average_samples( svit[SOLAR_9].T_samples );
  packet_payload[91] = average_samples( svit[POWER_BOARD].T_samples );

  // temperature error
  
  //uint8_t temperature_error0;
  //uint8_t temperature_error1;
  //uint8_t temperature_error2;
  //uint8_t temperature_error3;
  //uint8_t temperature_error4;
  
  packet_payload[92] = V_ack_change();
  packet_payload[93] = I_ack_change();
}

void transmit_packet( uint8_t uart, uint8_t packet_type, uint8_t ack_command )
{
  uint8_t VCP_tx_status;

  switch( packet_type )
  {
    case VCP_POWER_TELEMETRY:
      construct_telemetry_packet( tel_packet_payload[uart] );
      tel_packet_payload_size[uart] = 96;
      break;
    case VCP_INVALID_COMMAND:
      tel_packet_payload[uart][0] = VCP_INVALID_COMMAND;
      tel_packet_payload_size[uart] = 1;
      break;
    case VCP_ACK:
      tel_packet_payload[uart][0] = VCP_ACK;
      tel_packet_payload[uart][1] = ack_command;
      tel_packet_payload_size[uart] = 2;
      break;
    default:
      return;
  }

  // create VCP frame in the peripheral transmit buffer
  VCP_tx_status = Create_VCP_frame( dest_data[uart],
                                    &dest_size[uart],
                                    VCP_PWR_BOARD_ADDR,
                                    tel_packet_payload[uart],
                                    tel_packet_payload_size[uart]
                  );

  // VCP frame creation was successful
  if ( VCP_tx_status == VCP_TERM )
  {
    tel_packet_size[uart] = dest_size[uart];
    memcpy( tel_packet[uart], dest_data[uart], tel_packet_size[uart] );
    tel_packet_index[uart] = 0;
    // transmit first byte
    if ( uart == 1  && UCSR1A && ( 1 << UDRE ) )
      tx_put_byte( uart );
    else if ( uart == 0  && UCSR0A && ( 1 << UDRE ) )
      tx_put_byte( uart );
  }
}

uint8_t V_ack_change( void )
{
  uint8_t temp;

  temp = V_upper_val_change;
  V_upper_val_change = 0;
  return temp;
}

uint8_t I_ack_change( void )
{
  uint8_t temp;

  temp = I_upper_val_change;
  I_upper_val_change = 0;
  return temp;
}

#endif
