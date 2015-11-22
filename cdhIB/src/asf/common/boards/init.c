/**
 * \file init.c
 * \brief Initialization source file
 *
 *  Author: Liran
 */

#include <asf.h>
#include "../src/config/conf_board.h"
#include "../src/memory/memory.h"
#include "adc_driver.h"
//#include "../tasks/ths.h"

//ADC Defines
#define ADCACAL0_offset 0x20
#define ADCACAL1_offset 0x21
#define ADCBCAL0_offset 0x24
#define ADCBCAL1_offset 0x25
#define ADC_ConvMode_and_Resolution_Config(_adc, _signedMode, _resolution) \
((_adc)->CTRLB = ((_adc)->CTRLB & (~(ADC_RESOLUTION_gm|ADC_CONMODE_bm)))| \
(_resolution| ( _signedMode? ADC_CONMODE_bm : 0)))

/**
 * Name         : board_init
 *
 * Synopsis     : void board_init(void)
 *
 * Description  : Call all the initialization functions
 * 
 */
void board_init(void)
{

	//clock_init		();
	
	interrupts_init	();
	adc_init		();
	memory_init		();
	dma_init		();
	usart_init		();
	timers_init		();
	io_init			();
	cdhib_init		();
}


/**
 * Name         : adc_init
 *
 * Synopsis     : void adc_init	(void)
 *
 * Description  : Initialize the main system clock
 * 
 */
void adc_init	(void)
{
	/////////////////FROM XPLAINED 1505////////////////////////////////
	// Variable for use when we read the result from an ADC channel
	//PORTQ.PIN2CTRL = (PORTQ.PIN2CTRL & ~PORT_OPC_gm) | PORT_OPC_PULLDOWN_gc; // This pin must be grounded to "enable" NTC-resistor
	/* Move stored calibration values to ADC B */
	ADC_CalibrationValues_Load(&ADCA);
	/* Set up ADC A to have signed conversion mode and 8 bit resolution. */
	ADC_ConvMode_and_Resolution_Config(&ADCA, true, ADC_RESOLUTION_12BIT_gc);
	// The ADC has different voltage reference options, controlled by the REFSEL bits in the
	// REFCTRL register. Here the internal reference is selected
	ADC_Reference_Config(&ADCA, ADC_REFSEL_VCC_gc);
	// The clock into the ADC decides the maximum sample rate and the conversion time, and
	// this is controlled by the PRESCALER bits in the PRESCALER register. Here, the
	// Peripheral Clock is divided by 8 ( gives 250 KSPS with 2Mhz clock )
	ADC_Prescaler_Config(&ADCA, ADC_PRESCALER_DIV8_gc);
	// The used Virtual Channel (CH0) must be set in the correct mode
	// In this task we will use single ended input, so this mode is selected
	/* Setup channel 0 to have single ended input. */
	ADC_Ch_InputMode_and_Gain_Config(&ADCA.CH0,
	ADC_CH_INPUTMODE_SINGLEENDED_gc,
	ADC_CH_GAIN_1X_gc);
	ADC_Ch_InputMode_and_Gain_Config(&ADCA.CH1,
	ADC_CH_INPUTMODE_SINGLEENDED_gc,
	ADC_CH_GAIN_1X_gc);
	ADC_Ch_InputMode_and_Gain_Config(&ADCA.CH2,
	ADC_CH_INPUTMODE_SINGLEENDED_gc,
	ADC_CH_GAIN_1X_gc);
	
	// Setting up the which pins to convert.
	// Note that the negative pin is internally connected to ground
	//ADC_Ch_InputMux_Config(&ADCB.CH0, ADC_CH_MUXPOS_PIN9_gc, ADC_CH_MUXNEG_PIN1_gc);
	ADCA.CH0.MUXCTRL |= ADC_CH_MUXPOS_PIN0_gc;
	ADCA.CH1.MUXCTRL |= ADC_CH_MUXPOS_PIN1_gc;
	ADCA.CH2.MUXCTRL |= ADC_CH_MUXPOS_PIN2_gc;
	
	// Before the ADC can be used it must be enabled
	ADC_Enable(&ADCA);
	
	// Wait until the ADC is ready
	ADC_Wait_8MHz(&ADCA);
	// In the while(1) loop, a conversion is started on CH0 and the 8 MSB of the result is
	// output on the LEDPORT when the conversion is done
	/* Get offset value for ADC B. */
	adcx.offset = ADC_Offset_Get_Signed(&ADCA, &(ADCA.CH0), true);
	adcy.offset = ADC_Offset_Get_Signed(&ADCA, &(ADCA.CH1), true);
	adcz.offset = ADC_Offset_Get_Signed(&ADCA, &(ADCA.CH2), true);
		
}


/**
 * Name         : clock_init
 *
 * Synopsis     : void clock_init	(void)
 *
 * Description  : Initialize the main system clock
 * 
 */
void clock_init	(void)
{
	
	xosc_recovey = true;
	
	// Set the source to be a 12-16Mhz crystal. Change this if using 8MHz crystal
	OSC.XOSCCTRL = OSC_FRQRANGE_12TO16_gc | OSC_XOSCSEL_EXTCLK_gc ;
	
	// Enable external oscillator and internal 32MHz oscillator
	OSC.CTRL |= OSC_XOSCEN_bm;
	OSC.CTRL |= OSC_RC32MEN_bm;
	
	while( !(OSC.STATUS & OSC_RC32MRDY_bm) )	// wait until internal 32MHz oscillator is stable
	
	// Switch clock source to the internal 32MHz oscillator
	ccp_write_io((uint8_t *)&CLK.CTRL, CLK_SCLKSEL_RC32M_gc);
		
	// Try to switch to external oscillator if ready	
	switch_to_ext_osc ();	

}

 /**
  * Name         : usart_init
  *
  * Synopsis     : void usart_init (void)
  *
  * Description  : Initialize the defined USARTs 
  * *	Set the Baud rate
  * *	8N1 (8 data bits, No Parity, 1 Stop bit)
  * *	Enable receive interrupt
  * 
  */
 void usart_init (void)
{
	
	usart_serial_options_t		serial_options;	

	// 8 data bits, No parity, 1 stop bit
	serial_options.charlength = USART_CHSIZE_8BIT_gc;
	serial_options.paritytype = USART_PMODE_DISABLED_gc;
	serial_options.stopbits =	false;
	
	// Set baudrate, initialize and enable receive interrupt
	serial_options.baudrate =		POWER_UART_BAUDRATE;
	usart_serial_init				(power.USART, &serial_options);
	usart_set_rx_interrupt_level	(power.USART,USART_RXCINTLVL_LO_gc);
	power.USART->BAUDCTRLA = 0x01;
	power.USART->BAUDCTRLB = 0xD0;
	
	serial_options.baudrate =		GPS_UART_BAUDRATE;
	usart_serial_init				(gps.USART,	&serial_options);
	usart_set_rx_interrupt_level	(gps.USART,USART_RXCINTLVL_LO_gc);
	
	serial_options.baudrate =		RADIO_UART_BAUDRATE;
	usart_serial_init				(radio.USART, &serial_options);
	usart_set_rx_interrupt_level	(radio.USART,USART_RXCINTLVL_LO_gc);
	radio.USART->BAUDCTRLA = 0x02;
	radio.USART->BAUDCTRLB = 0x96;

	serial_options.baudrate =		FC_UART_BAUDRATE;
	usart_serial_init				(fc.USART, &serial_options);
	usart_set_rx_interrupt_level	(fc.USART,USART_RXCINTLVL_LO_gc);
	fc.USART->BAUDCTRLA = 0x02;
	fc.USART->BAUDCTRLB = 0x96;
	//fc.USART->BAUDCTRLA = 0x96;
	//fc.USART->BAUDCTRLB = 0x90;
	
	#ifdef STAR_UART
	serial_options.baudrate =		STAR_UART_BAUDRATE;
	usart_serial_init				(star.USART, &serial_options);
	usart_set_rx_interrupt_level	(star.USART,USART_RXCINTLVL_LO_gc);
	star.USART->BAUDCTRLA = 0x01;
	star.USART->BAUDCTRLB = 0xD0;
	#endif
	
	#ifdef SUN_UART
	serial_options.baudrate =		SUN_UART_BAUDRATE;
	usart_serial_init				(sun.USART, &serial_options);
	usart_set_rx_interrupt_level	(sun.USART,USART_RXCINTLVL_LO_gc);
	sun.USART->BAUDCTRLA = 0x96;    //Sun Baud = 57600
	sun.USART->BAUDCTRLB = 0x90;
	#endif
	
}	

/**
 * Name         : interrupts_init
 *
 * Synopsis     : void interrupts_init (void)
 *
 * Description  : Initialize and enable global interrupts
 * 
 */
void interrupts_init (void)
{
	// Enable low level and medium level interrupts 
	PMIC.CTRL = PMIC_LVL_LOW | PMIC_LVL_MEDIUM;
	
	// Set priority of low level interrupts to Round Robin scheduling
	PMIC.CTRL |= PMIC_RREN_bm;
	
	// Enable global interrupts
	Enable_global_interrupt();
}

/**
 * Name         : io_init
 *
 * Synopsis     : void io_init (void)
 *
 * Description  : Initialize I/Os
 * 
 */
void io_init (void)
{

	PORTA.DIRCLR = PIN1_bm;
	PORTA.DIRCLR = PIN2_bm;
	PORTA.DIRCLR = PIN3_bm;
	PORTB.DIRCLR = PIN0_bm;
	// Power 422 driver TX_EN and RX_EN I/Os
	// In both MCUs:
	// Port C, Pin 4 = PWR_TX_EN
	// Port C, Pin 5 = PWR_RX_EN 
	PORTC.DIRSET = PIN4_bm | PIN5_bm;	// Both pins are outputs
	PORTC.OUTSET = PIN5_bm;				// TX_EN active low, RX_EN Active high	
	
	// Data sheet says -
	// No need to init the UART I/Os - when Tx/Rx are enabled it overrides normal port operation.
	// But doesn't work without this.
	PORTC.DIRSET = PIN3_bm;	// PC3 - USARTC0 
	PORTC.DIRSET = PIN7_bm;	// PC7 - USARTC1 
	PORTD.DIRSET = PIN3_bm;	// PD3 - USARTD0
	PORTD.DIRSET = PIN7_bm;	// PD7 - USARTD1
	PORTE.DIRSET = PIN3_bm;	// PE3 - USARTE0
	PORTE.DIRSET = PIN7_bm;	// PE7 - USARTE1
	
	#ifdef DEBUG
		// Debug STK600 LEDs, set pins to output
		/*PORTA.DIRCLR =	PIN0_bm;		// LED0 - 1Hz "running" toggle
		PORTA.DIRCLR =	PIN1_bm;		// LED1 
		PORTA.DIRCLR =	PIN2_bm;		// LED2 
		PORTA.DIRCLR =	PIN3_bm;		// LED3 
		PORTA.DIRCLR =	PIN4_bm;		// LED4 
		PORTA.DIRCLR =	PIN5_bm;		// LED5
		PORTA.DIRSET =	PIN6_bm;		// LED6
		PORTA.DIRSET =	PIN7_bm;		// LED7 - debug
		// Start Off
		PORTA.OUTSET =	PIN0_bm;		// LED0 
		PORTA.OUTSET =	PIN1_bm;		// LED1 
		PORTA.OUTSET =	PIN2_bm;		// LED2 
		PORTA.OUTSET =	PIN3_bm;		// LED3 
		PORTA.OUTSET =	PIN4_bm;		// LED4 
		PORTA.OUTSET =	PIN5_bm;		// LED5
		PORTA.OUTSET =	PIN6_bm;		// LED6
		PORTA.OUTSET =	PIN7_bm;		// LED7
        */
		// peripheral structure LED pin assignment
		/*power.tx_LED_pin =	PIN1_bm; 
		power.rx_LED_pin =	PIN2_bm; 
		fc.tx_LED_pin =		PIN3_bm; 
		fc.rx_LED_pin =		PIN4_bm; 
		gps.rx_LED_pin =	PIN5_bm; 
		#ifdef STAR_UART
		star.tx_LED_pin =	PIN6_bm; 
		star.rx_LED_pin =	PIN7_bm; 
		#endif
		#ifdef SUN_UART
		sun.tx_LED_pin =	PIN6_bm; 
		sun.rx_LED_pin =	PIN7_bm; 
		#endif

		PORTD.DIRSET = PIN7_bm;		// Clock out
		PORTCFG.CLKEVOUT = 0x02;
      */	
	#endif
	
}

/**
 * Name         : timers_init
 *
 * Synopsis     : void timers_init (void)
 *
 * Description  : Initialize Timers. 32000000 / 125 / 256 = 1000	=> 1KHz Interrupt.
 * 
 */
void timers_init (void)
{
	// Enable clock to the Timer
	sysclk_enable_peripheral_clock(&TCC0);

	// Enable overflow interrupt
	TCC0.INTCTRLA = (TCC0.INTCTRLA & ~TC0_OVFINTLVL_gm ) | TC_OVFINTLVL_LO_gc;

	// Set the period
	TCC0.PER = 125/16;

	// Pre-scale the 32MHz clock by 256
	TCC0.CTRLA = (TCC0.CTRLA & ~ TC0_CLKSEL_gm) | TC_CLKSEL_DIV256_gc;

	// 32000000 / 125 / 256 = 1000	=> 1KHz Interrupt.
}

/**
 * Name         : cdhib_init
 *
 * Synopsis     : void cdhib_init	(void)
 *
 * Description  : Initialize THS and CDHIB values
 * 
 */
void cdhib_init	(void)
{
	// THS
	//THS_interval_seconds =				DEFAULT_THS_INTERVAL_SECONDS;
	//Commanded_THS_interval_seconds =	DEFAULT_THS_INTERVAL_SECONDS;
	//External_THS_trigger =				true;	// set to true to trigger beacon on power up
	
	// ACK packet
	ACK[0] = 0x41;
	ACK[1] = 0x43;
	ACK[2] = 0x4B;
	
	// PWR_NOOP packet
	PWR_NOOP[0] = NOOP_COMMAND;
}

/**
 * Name         : switch_to_ext_osc
 *
 * Synopsis     : void switch_to_ext_osc (void)
 *
 * Description  : Check if external oscillator is present and stable and switch the system source to the external oscillator and PLL
 * 
 */
void switch_to_ext_osc (void)
{
	
	if (OSC.STATUS & OSC_XOSCRDY_bm) // External oscillator stable
	{
					
		// Configure the PLL to be external oscillator *2. Change to *4 if using 8MHz crystal
		OSC.PLLCTRL = OSC_PLLSRC_XOSC_gc | 2 ;
		
		// Enable the PLL
		OSC.CTRL |= OSC_PLLEN_bm ;
		// Wait until it's stable
		while( !(OSC.STATUS & OSC_PLLRDY_bm) ); 
		
		// Switch system clock source to the PLL output
		ccp_write_io((uint8_t *)&CLK.CTRL, CLK_SCLKSEL_PLL_gc);
	
		// Enable external oscillator fault detection
		ccp_write_io((uint8_t *)&OSC.XOSCFAIL, OSC_XOSCFDEN_bm);
		
		// Reset the flag
		xosc_recovey = false;
	}	
}