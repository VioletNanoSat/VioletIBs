/**
 * \file init.c
 * \brief Initialization source file
 *
 *  Author: Liran
 */

#include <asf.h>
#include "../src/config/conf_board.h"
#include "../src/memory/memory.h"

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
	memory_init		();
	dma_init		();
	usart_init		();
	timers_init		();
	io_init			();
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
	
	serial_options.baudrate =		RADIO_UART_BAUDRATE;
	usart_serial_init				(radio.USART, &serial_options);
	usart_set_rx_interrupt_level	(radio.USART,USART_RXCINTLVL_LO_gc);


	serial_options.baudrate =		CDHIB_UART_BAUDRATE;
	usart_serial_init				(cdhib.USART, &serial_options);
	usart_set_rx_interrupt_level	(cdhib.USART,USART_RXCINTLVL_LO_gc);
	cdhib.USART->BAUDCTRLA = 0x02;
	cdhib.USART->BAUDCTRLB = 0x96;
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
		PORTA.DIRSET =	PIN0_bm;		// LED0 - 1Hz "running" toggle
		PORTA.DIRSET =	PIN1_bm;		// LED1 
		PORTA.DIRSET =	PIN2_bm;		// LED2 
		PORTA.DIRSET =	PIN3_bm;		// LED3 
		PORTA.DIRSET =	PIN4_bm;		// LED4 
		PORTA.DIRSET =	PIN5_bm;		// LED5
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

		// peripheral structure LED pin assignment
		cdhib.tx_LED_pin =		PIN3_bm; 
		cdhib.rx_LED_pin =		PIN4_bm; 


		PORTD.DIRSET = PIN7_bm;		// Clock out
		PORTCFG.CLKEVOUT = 0x02;
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
	TCC0.PER = 125;

	// Pre-scale the 32MHz clock by 256
	TCC0.CTRLA = (TCC0.CTRLA & ~ TC0_CLKSEL_gm) | TC_CLKSEL_DIV256_gc;

	// 32000000 / 125 / 256 = 1000	=> 1KHz Interrupt.
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