//=======================================================================
// Voltage, current, temperature measurements
//=======================================================================

#ifndef MCUPWR_SENSING_C
#define MCUPWR_SENSING_C

#include "mcupwr-Defs.h"


void set_mux_sel( uint8_t mux_num, uint8_t mux_sel )
{
  switch( mux_num )
  {
    case MUX0:
      READ( mux_sel, 4 ) ? SET( PORTA, 7 ) : CLR( PORTA, 7 );
      READ( mux_sel, 3 ) ? SET( PORTA, 6 ) : CLR( PORTA, 6 );
      READ( mux_sel, 2 ) ? SET( PORTA, 5 ) : CLR( PORTA, 5 );
      READ( mux_sel, 1 ) ? SET( PORTA, 4 ) : CLR( PORTA, 4 );
      READ( mux_sel, 0 ) ? SET( PORTA, 3 ) : CLR( PORTA, 3 );

      break;

    case MUX1:
      READ( mux_sel, 4 ) ? SET( PORTB, 0 ) : CLR( PORTB, 0 );
      READ( mux_sel, 3 ) ? SET( PORTB, 1 ) : CLR( PORTB, 1 );
      READ( mux_sel, 2 ) ? SET( PORTB, 2 ) : CLR( PORTB, 2 );
      READ( mux_sel, 1 ) ? SET( PORTB, 3 ) : CLR( PORTB, 3 );
      READ( mux_sel, 0 ) ? SET( PORTB, 4 ) : CLR( PORTB, 4 );

      break;

    case MUX2:
      READ( mux_sel, 4 ) ? SET( PORTE, 3 ) : CLR( PORTE, 3 );
      READ( mux_sel, 3 ) ? SET( PORTE, 4 ) : CLR( PORTE, 4 );
      READ( mux_sel, 2 ) ? SET( PORTE, 5 ) : CLR( PORTE, 5 );
      READ( mux_sel, 1 ) ? SET( PORTE, 6 ) : CLR( PORTE, 6 );
      READ( mux_sel, 0 ) ? SET( PORTE, 7 ) : CLR( PORTE, 7 );

      break;

    default:
      break;
  }
}

void torquer_off( uint8_t torquer_num )
{
  switch( torquer_num )
  {
    case TORQUER_1:
      CLR( PORTC, 0 );
	  CLR( PORTG, 1 );
      break;

    case TORQUER_2:
      CLR( PORTG, 0 );
	  CLR( PORTD, 0 );
      break;

    case TORQUER_3:
      CLR( PORTG, 3 );
	  CLR( PORTG, 4 );
      break;

    default:
      break;
  }  
}

void torquer_on( uint8_t torquer_num )
{
  switch( torquer_num )
  {
    case TORQUER_1:
      SET( PORTC, 0 );
	  SET( PORTG, 1 );
      break;

    case TORQUER_2:
      SET( PORTG, 0 );
	  SET( PORTD, 0 );
      break;

    case TORQUER_3:
      SET( PORTG, 3 );
	  SET( PORTG, 4 );
      break;


    default:
      break;
  }
}

void switch_on( uint8_t switch_num )
{
  switch ( switch_num )
  {
    case 1:
      SET( PORTA, 0 );
      break;

    case 2:
      SET( PORTA, 1 );
      break;

    case 3:
      SET( PORTA, 2 );
      break;

    case 4:
      SET( PORTB, 5 );
      break;

    case 5:
      SET( PORTB, 6 );
      break;

    case 6:
      SET( PORTB, 7 );
      break;

    case 7:
      SET( PORTD, 4 );
      break;

    case 8:
      SET( PORTD, 5 );
      break;

    case 9:
      SET( PORTG, 2 );
      break;

    case 10: 
      SET( PORTC, 7 );
      break;

    case 11:
      SET( PORTC, 6 );
      break;

    case 12:
      SET( PORTC, 5 );
      break;

    case 13:
      SET( PORTC, 4 );
      break;

    case 14:
      SET( PORTC, 3 );
      break;

    case 15:
      SET( PORTC, 2 );
      break;

    case 16:
      SET( PORTC, 1 );
      break;

    default:
      break;
  }
}

void switch_off( uint8_t switch_num )
{
  switch ( switch_num )
  {
    case 1:
      CLR( PORTA, 0 );
      break;

    case 2:
      CLR( PORTA, 1 );
      break;

    case 3:
      CLR( PORTA, 2 );
      break;

    case 4:
      CLR( PORTB, 5 );
      break;

    case 5:
      CLR( PORTB, 6 );
      break;

    case 6:
      CLR( PORTB, 7 );
      break;

    case 7:
      CLR( PORTD, 4 );
      break;

    case 8:
      CLR( PORTD, 5 );
      break;

    case 9:
      CLR( PORTG, 2 );
      break;

    case 10: 
      CLR( PORTC, 7 );
      break;

    case 11:
      CLR( PORTC, 6 );
      break;

    case 12:
      CLR( PORTC, 5 );
      break;

    case 13:
      CLR( PORTC, 4 );
      break;

    case 14:
      CLR( PORTC, 3 );
      break;

    case 15:
      CLR( PORTC, 2 );
      break;

    case 16:
      CLR( PORTC, 1 );
      break;

    default:
      break;
  }
}

uint8_t SVIT_check_V_critical( uint8_t name )
{
  uint8_t temp;
  SVIT_t* component= &svit[name];
  if ( component->V_critical_value != 0 )
  {
    temp= component->V_critical_value;
    component->V_critical_value = 0;
    return temp;
  }
  else
  {
    return  average_samples( component->V_samples );
  }
}

uint8_t SVIT_check_I_critical( uint8_t name )
{
  uint8_t temp;
  SVIT_t* component= &svit[name];
  if ( component->I_critical_value != 0 )
  {
    temp= component->I_critical_value;
    component->I_critical_value = 0;
    return temp;
  }
  else
  {
    return  average_samples( component->I_samples );
  }
}

uint8_t average_samples( uint8_t samples[NUM_SAMPLES] )
{
  uint8_t average = 0;
  uint16_t sum = 0;

  for(uint8_t avg_index = 0; avg_index < NUM_SAMPLES; avg_index++)
    sum += samples[avg_index];

  average = sum / NUM_SAMPLES;

  return average;
}

void perform_ADC( uint8_t mux_num )
{
  // set Vref to AVCC and set the ADC channel to the correct pin ( mux_num )
  ADMUX = (1 << ADLAR) | ( 1 << REFS0 );
  ADMUX &= ~0x3;
  ADMUX |= mux_num;

  // signal ADC to start a new conversion
  ADCSRA |= ( 1 << ADSC );

  // when the conversion finishes, the result is stored in ADCL and ADCH
}

void read_VIT( void )
{
  uint8_t mux_num;
  uint8_t mux_sel;
  SVIT_t* component;
  uint8_t sample_index;
  //analyze completed ADC conversion 
  
  switch ( adc_sensor_type ){
		case ADC_VOLTAGE:
			component = &svit[adc_component];
			sample_index = component->V_sample_index;
			component->V_sample_index = ( sample_index + 1 ) % NUM_SAMPLES;

			// SoC: If component is a battery, store in different global variable
			if (component->name == BATTERY_1) {
				batt1_voltage = ADC_high;
				batt1_voltageLow = ADC_low;
				high = ADC_high;
				low = ADC_low;
				//debug = adc_component;
			}
			else if (component->name == BATTERY_2) {
				batt2_voltage = ADC_high;
			}
			component->V_samples[sample_index] = ADC_high;
            
			//OverVoltage
	  		if ( ( ADC_high > component->V_upper_limit ) && ( component->force_on != 1 ) ){
				if ( component->switch_num != SW_NULL ){
					switch_off( component->switch_num );
				}else {
					switch ( component->name ){
						case TORQUER_1:
				  			torquer_off( TORQUER_1 );
				  			break;
						case TORQUER_2:
	  			  			torquer_off( TORQUER_2 );
		  		  			break;
			  			case TORQUER_3:
				    		torquer_off( TORQUER_3 );
				    		break;
						default:
				  			break;
					}
  				}
				component->switch_state = SW_OFF;
				component->V_critical_value = ADC_high;
			}
			//UnderVoltage
			else if((ADC_high < component->V_lower_limit) && component->switch_state){
				if ( component->switch_num != SW_NULL ){
					switch_off( component->switch_num );
				}else {
					switch ( component->name ){
						case TORQUER_1:
							torquer_off( TORQUER_1 );
							break;
						case TORQUER_2:
							torquer_off( TORQUER_2 );
							break;
						case TORQUER_3:
							torquer_off( TORQUER_3 );
							break;
						default:
							break;
					}
				}
				component->switch_state = SW_OFF;
				component->V_critical_value = ADC_high;
			}
			adc_sensor_type = ADC_CURRENT;

		    //perform next ADC conversion
		    mux_num = component->I_mux_num;
		    mux_sel = component->I_mux_sel;
		    set_mux_sel( mux_num, mux_sel );
		    //_delay_us(1);
		    //_delay_us(6000);
		    _delay_ms(ADC_DELAY_MS);
		    perform_ADC( mux_num );
		    break;
	
    //-------------------------------------------------------------------
    // Measure current
    //-------------------------------------------------------------------
	  case ADC_CURRENT:
     
	    component = &svit[adc_component];
	  	sample_index = component->I_sample_index;
	  	component->I_sample_index = ( sample_index + 1 ) % NUM_SAMPLES;

		// SoC hardcode backward current
		//if (adc_component == BATTERY_1) {
	//		debug = 2;
//		}

		// SoC hardcode backward current
//		if (adc_component == BATTERY_1_b) {
			//debug = 5;
		//}
		
		if(component->name == SOLAR_1){
			solar1_current = ADC_high;
			hasCheckedCurr = 1;
		}

	  	component->I_samples[sample_index] = ADC_high;
    
	    if ( ( ADC_high > component->I_upper_limit ) && ( component->force_on != 1 ) )
	  	{
	  		if ( component->switch_num != SW_NULL )
	  		{
	  		  switch_off( component->switch_num );
	  		}
	  		else
	  		{
	  		  switch ( component->name )
		  	  {
  		  		case TORQUER_1:
	  	  		  torquer_off( TORQUER_1 );
		    		  break;
			    	case TORQUER_2:
			  	    torquer_off( TORQUER_2 );
			  	    break;
  		  		case TORQUER_3:
	  	  		  torquer_off( TORQUER_3 );
		    		  break;
			     	default:
				      break;
			    }
			  }
			  component->switch_state = 0;
        component->I_critical_value = ADC_high;
		  }
      //perform next ADC conversion
      mux_num = component->T_mux_num;
      if( mux_num != MUX_NULL )
      {
		    adc_sensor_type = ADC_TEMPERATURE;
        mux_sel = component->T_mux_sel;        
		  }
      else
      {
        adc_sensor_type = ADC_VOLTAGE;
		    adc_component = ( adc_component + 1 ) % SVIT_SZ;
        component = &svit[adc_component];
        mux_num = component->V_mux_num;
        mux_sel = component->V_mux_sel;
      }
      set_mux_sel( mux_num, mux_sel );
      //_delay_us(1);
      //_delay_us(6000);
	  _delay_ms(ADC_DELAY_MS);
      perform_ADC( mux_num );
      break;
    //-------------------------------------------------------------------
    // Measure temperature
    //-------------------------------------------------------------------
	  case ADC_TEMPERATURE:
		  component = &svit[adc_component];
		  sample_index = component->T_sample_index;
		  component->T_sample_index = ( sample_index + 1 ) % NUM_SAMPLES;
		  component->T_samples[sample_index] = ADC_high;
      //perform next ADC conversion
  	  adc_sensor_type = ADC_VOLTAGE;
		  adc_component = ( adc_component + 1 ) % SVIT_SZ;
      component = &svit[adc_component];
      mux_num = component->V_mux_num;
      mux_sel = component->V_mux_sel;
      set_mux_sel( mux_num, mux_sel );
      //_delay_us(1);
      //_delay_us(6000);
	  _delay_ms(ADC_DELAY_MS);
      perform_ADC( mux_num );
		  break;
    case ADC_INIT:
      //perform next ADC conversion
		  adc_sensor_type = ADC_VOLTAGE;
      component = &svit[adc_component];
      mux_num = component->V_mux_num;
      mux_sel = component->V_mux_sel;
      set_mux_sel( mux_num, mux_sel );
      //_delay_us(1);
	  //_delay_us(6000);
	  _delay_ms(ADC_DELAY_MS);
      perform_ADC( mux_num );
      break;
	  default:
      //perform next ADC conversion
		  adc_sensor_type = ADC_VOLTAGE;
      component = &svit[adc_component];
      mux_num = component->V_mux_num;
      mux_sel = component->V_mux_sel;
      set_mux_sel( mux_num, mux_sel );
      //_delay_us(1);
      //_delay_us(6000);
	  _delay_ms(ADC_DELAY_MS);
	  perform_ADC( mux_num );
      break;
  } 
}

#endif
