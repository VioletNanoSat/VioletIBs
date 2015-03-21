//========================================================================
// ATMega128 MCU Powerboard Definitions Header File
//========================================================================
// Authors: Adam Wrobel, John Fu, Matheus Ogleari, and Sean Clark

#ifndef MCUPWR_DEFS_H
#define MCUPWR_DEFS_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <util/delay.h>
#include "vcp_library.h"
#include "uart.h"

#ifndef MCU_PLATFORM
#define MCU_PLATFORM
#endif

#define READ( U, N ) ( ( U ) >> ( N ) & 1u )
#define SET( U, N ) ( ( void )( ( U ) |= 1u << ( N ) ) )
#define CLR( U, N ) ( ( void )( ( U ) &= ~( 1u << ( N ) ) ) )

// VCP commands
#define VCP_COMPONENT_ON  0x00
#define VCP_COMPONENT_OFF 0x01
#define VCP_POWER_CYCLE   0x02
#define VCP_TORQ_CTRL     0x03
#define VCP_GET_TELEMETRY 0x04
#define VCP_FORCE_ON      0x05
#define VCP_CRIT_V_CHANGE 0x06
#define VCP_CRIT_I_CHANGE 0x07

// VCP packet fields
#define VCP_COMMAND_FIELD 0x00
#define VCP_PAYLOAD_FIELD 0x01

// VCP headers
#define VCP_POWER_TELEMETRY 0x00
#define VCP_INVALID_COMMAND 0x01
#define VCP_ACK             0x02

#define VCP_PWR_BOARD_ADDR 0x01

// component names
#define SPECTROMETER 0x00
#define STAR_TRACKER 0x01
#define FC_5V        0x02
#define FC_3_3V      0x03
#define GPS_1        0x04
#define GPS_2        0x05
#define CDH_IB       0x06
#define HEATER_1     0x07
#define HEATER_2     0x08
#define CMG          0x09
#define SUN_SENSOR   0x0a
#define RADIO_1      0x0b
#define RADIO_2      0x0c
#define MAESTRO      0x0d
#define MAGNETOM     0x0e
#define FOG_15V      0x0f
#define FOG_5V       0x10
#define TORQUER_1    0x11
#define TORQUER_2    0x12
#define TORQUER_3    0x13
#define BATTERY_1    0x14
//#define BATTERY_1_b   0x15
#define BATTERY_2    0x15
#define SOLAR_FULL   0x16
#define SOLAR_1      0x17
#define SOLAR_2      0x18
#define SOLAR_3      0x19
#define SOLAR_4      0x1a
#define SOLAR_5      0x1b
#define SOLAR_6      0x1c
#define SOLAR_7      0x1d
#define SOLAR_8      0x1e
#define SOLAR_9      0x1f
#define SOLAR_10     0x20
#define SOLAR_11     0x21
#define SOLAR_12     0x22
#define POWER_BOARD  0x23

// switch enables
#define SW_EN1  0x01
#define SW_EN2  0x02
#define SW_EN3  0x03
#define SW_EN4  0x04
#define SW_EN5  0x05
#define SW_EN6  0x06
#define SW_EN7  0x07
#define SW_EN8  0x08
#define SW_EN9  0x09
#define SW_EN10 0x0a
#define SW_EN11 0x0b
#define SW_EN12 0x0c
#define SW_EN13 0x0d
#define SW_EN14 0x0e
#define SW_EN15 0x0f
#define SW_EN16 0x10
#define SW_NULL 0xff

#define SW_OFF 0
#define SW_ON  1

// SVIT definitions
#define SVIT_SZ  36
#define NAME_SZ  8
#define MUX0     0
#define MUX1     1
#define MUX2     2
#define MUX_NULL 3

#define ADC_VOLTAGE     1
#define ADC_CURRENT     2
#define ADC_TEMPERATURE 3
#define ADC_INIT        4

#define V_THRESHOLD_VALUE 225
#define I_THRESHOLD_VALUE 225

#define NUM_SAMPLES 3

#define BUFFER_SIZE 255

// SoC Defs used to determine when to enter safe mode or shunt 
// the maestro

// Timer Stuff
#define CYCLE_COUNTER 900 //for 30 min!

//GLITCHY UDRE code, NEEDED ON AVR6 - apparently not in toolchain, 
//YET seems not to cause problems when run on AVR 4 (which uses the SAME toolchain!)
//#define UDRE 5

#define SAFE_MODE 9 // 9% charged 11.788122 V (ADC_val = 440, percent = 0x09)
#define SHUNT_MODE 90 // 90% charged 12.846085 (ADC_val = 479, percent = 0x5A)
#define ADC_DELAY_MS 8

//------------------------------------------------------------------------
// Defines Some Enums and Structs
//------------------------------------------------------------------------

// 10-byte Packet type used for communication between MCU and FC
typedef struct Packet
{
  uint8_t   Fend0;
  uint8_t   Source_Dest;
  uint8_t   Data;
  uint16_t  crc;
  uint8_t   Fend1;
} Packet_t;

typedef struct SVIT
{
  uint8_t  name;

  uint8_t  switch_num;
  uint8_t  switch_state; // is the switch on or off?

  uint8_t  force_on;

  uint8_t  V_mux_num;              // which analog mux does this component belong to?
  uint8_t  V_mux_sel;              // mux select bits for choosing this component
  uint8_t  V_upper_limit;
  uint8_t  V_samples[NUM_SAMPLES]; // previous 4 samples used to construct median value
  uint8_t  V_sample_index;
  uint8_t  V_critical_value;

  uint8_t  I_mux_num;
  uint8_t  I_mux_sel;
  uint8_t  I_upper_limit;
  uint8_t  I_samples[NUM_SAMPLES];
  uint8_t  I_sample_index;
  uint8_t  I_critical_value;

  uint8_t  T_mux_num;
  uint8_t  T_mux_sel;
  uint8_t  T_samples[NUM_SAMPLES];
  uint8_t  T_sample_index;

} SVIT_t;

SVIT_t svit[SVIT_SZ];

volatile uint8_t adc_flag;
uint8_t adc_component;
uint8_t adc_sensor_type;
volatile uint8_t ADC_high;
volatile uint8_t ADC_low;

uint8_t V_upper_val_change;
uint8_t I_upper_val_change;

// Timers and Counters
volatile uint8_t timer0_counter[2];
volatile uint8_t timer1_counter[1];

vcp_ptrbuffer* uart_vcp_buff[2];

uint8_t uart_message_buff[2][BUFFER_SIZE];

uint8_t tel_packet[2][BUFFER_SIZE];
volatile uint16_t tel_packet_size[2];
volatile uint8_t tel_packet_index[2];

uint8_t tel_packet_payload[2][BUFFER_SIZE];
uint8_t dest_data[2][BUFFER_SIZE];
uint16_t dest_size[2];
uint16_t tel_packet_payload_size[2];

volatile uint8_t rx_flag[2];
uint8_t rad_torq_flag;	//For 30 min rad and torque coil turn-on delay

/* State of Charge variables */
// Polynomial coefficients for the charge curve
float p1, p2, p3, p4;
float q1, q2, q3, q4;

// Fourier coefficients for the discharge curve
int f0, f1, f2, f3, f4, f5;
int b1, b2, b3, b4, b5;
int32_t h0, h1, h2, h3, h4;
int32_t g1, g2, g3, g4;
float w, w2;

// Time and voltage values (between 0 and 255)
float batt_time;
uint8_t batt1_voltage;
uint8_t batt2_voltage;
uint8_t high;
uint8_t low;

// Transmit Flags
uint8_t safe_mode;
uint8_t been_to_safe;
uint8_t been_to_shunt;
uint8_t transmit_safe;
uint8_t transmit_shunt;
uint8_t limit_check_overriden;

// Used to determine if battery is charging or not
uint8_t charging;
uint8_t chargeforward;
uint8_t chargebackward;
// Array of components with switch enables 
uint8_t components[16];

//DEBUGGING
uint8_t debug;
uint8_t debug2;	//Used to display if percent is being rounded to 0 (0xA0), 100 (0xB0) or in between (0xC0)
float real;
float discharge_max_time;
float charge_max_time;
float percent;
uint8_t soc;

ISR(TIMER0_COMP_vect);
ISR(TIMER1_COMPA_vect);
ISR(USART1_TX_vect);
ISR(USART1_RX_vect);
ISR ( ADC_vect );
ISR( USART0_TX_vect );
ISR( USART0_RX_vect );

void initialize( void );
void initialize_svit( void );
void receive_message( uint8_t uart, uint8_t* message, uint8_t message_size );
void set_component( uint8_t svit_index, uint8_t name, uint8_t switch_num, uint8_t switch_state, uint8_t V_mux_num, uint8_t V_mux_sel, uint8_t V_upper_limit, uint8_t I_mux_num, uint8_t I_mux_sel, uint8_t I_upper_limit, uint8_t T_mux_num, uint8_t T_mux_sel );
void read_VIT( void );
void switch_on( uint8_t switch_num );
void switch_off( uint8_t switch_num );
void torquer_on( uint8_t torquer_num );
void torquer_off( uint8_t torquer_num );
void set_mux_sel( uint8_t mux_num, uint8_t mux_sel );
void perform_ADC( uint8_t mux_num );
void tx_put_byte( uint8_t uart );
void construct_telemetry_packet( uint8_t* packet_payload );
void transmit_packet( uint8_t uart, uint8_t packet_type, uint8_t ack_command );

uint8_t average_samples( uint8_t samples[NUM_SAMPLES] );
uint8_t SVIT_check_V_critical( uint8_t name );
uint8_t SVIT_check_I_critical( uint8_t name );
uint8_t V_ack_change( void );
uint8_t I_ack_change( void );

// State of charge
void assign_discharge_fit( void );
void assign_charge_fit( void );
void soc_time( void );
void soc_voltage( void );
void compareVoltage( void );
void limit_check( void );
void calcSOC( void );

#endif
