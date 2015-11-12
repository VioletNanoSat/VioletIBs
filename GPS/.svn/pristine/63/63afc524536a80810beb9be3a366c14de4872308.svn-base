#include "adc.h"


// This function collects 4 samples for a moving average filter of length 4, returns the average result
// (channel) is the ADC Mux channel, range 0-8.
uint8 Get_ADC_Result (uint8 channel)
{
	
	uint32  ADC_Temp = 0;

    ADC_samples [channel][ADC_samples_index[channel]++] = Sample_ADC_Channel(channel);		// read ADC result and change the index
    if(ADC_samples_index[channel] >= 4)	
		ADC_samples_index[channel] = 0;							// length-4 filter
    
	ADC_Temp = (		(uint32)ADC_samples [channel][0] +
                		(uint32)ADC_samples [channel][1] +
                		(uint32)ADC_samples [channel][2] +
                		(uint32)ADC_samples [channel][3] );		// add up last 4
	return				(uint8)	(ADC_Temp >> 2);    			// divide by 4 and return the result
	
}


// This function starts a conversion on (channel), waits for conversion to complete and returns the result
// (channel) is the ADC Mux channel, range 0-7.
uint8 Sample_ADC_Channel (uint8 channel)
{
	
	Select_ADC_channel(channel); 			// Channel
    Start_ADC_Conversion();   				// start conversion
	while ( !ADC_Conversion_Finished() );   // wait for conversion to end

    return ADCH; 							// read ADC result and change the index
}