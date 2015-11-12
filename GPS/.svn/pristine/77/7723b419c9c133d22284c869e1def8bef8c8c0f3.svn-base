#define NET_ADDR NETWORK_ADDRESS_GPS1
#define UBRR0L_VAL 7 // for 38.4k doublespeed // 7 for 230.4k doublespeed
// define DRIVER_LOC to be the pin used for DE (Tx enable) on the MAX3083
// make sure this pin is set to be an output !
#define DRIVER_LOC      PORTA.1

// we want to cut down on the buffer size to save space
#define TRANSMIT_BUFFER_SIZE TIMESTAMP_SIZE

//***** INCLUDES *****//
#include <MEGA128.h>

#include "gps_include.h"

//***** DEFINES *****//

#define RX_EN    PORTA.0
#define TX_EN    PORTA.1
#define MEM_EN   PORTA.2

// shortcuts to the errorStatus parts
/* errors that GPS can throw (from Comm ICD)
    0b00000001: dead
    0b00000010: power to board is down
    0b00000100: general error
*/
#define ERR_DEAD    0b00000001
#define ERR_PGOOD   0b00000010
#define ERR_GEN     0b00000100
#define ERR_1       0b00001000
#define ERR_2       0b00010000
#define ERR_3       0b00100000
#define ERR_4       0b01000000
#define ERR_5       0b10000000

//states for receiving data
#define START_BYTE    ((BYTE32)0x02)
#define END_BYTE      ((BYTE32)0x03)
#define STATE_PRELIM1 ((BYTE32)0xE0)    // last command
#define STATE_PRELIM2 ((BYTE32)0xE1)	// command success
#define STATE_PRELIM3 ((BYTE32)0xE2)    // last satellite
#define STATE_S1      ((BYTE32)0xC1)    // 0xF00
#define STATE_S2      ((BYTE32)0xC2)    // 0xF03
#define STATE_S3      ((BYTE32)0xC3)    // 0xF18
#define STATE_S4      ((BYTE32)0xC4)    // 0xF22
#define STATE_S5      ((BYTE32)0xC5)    // 0xF23
#define STATE_HUH     ((BYTE32)0xA1)    //not sure where we are
#define STATE_ID1     ((BYTE32)0xB1)    // id stages
#define STATE_ID2     ((BYTE32)0xB2)
#define STATE_ID3     ((BYTE32)0xB3)
#define STATE_CHKS1A  ((BYTE32)0xD1)    // first chksum byte of F00
#define STATE_CHKS1B  ((BYTE32)0xD2)    // second chksum byte of F00
#define STATE_CHKS2A  ((BYTE32)0xD3)    // first ... F03
#define STATE_CHKS2B  ((BYTE32)0xD4)    // second ... F03
#define STATE_CHKS3A  ((BYTE32)0xD5)    // first ... F18
#define STATE_CHKS3B  ((BYTE32)0xD6)    // second ... F18
#define STATE_CHKS4A  ((BYTE32)0xD7)    // first ... F22
#define STATE_CHKS4B  ((BYTE32)0xD8)    // second ... F22
#define STATE_CHKS5A  ((BYTE32)0xD9)    // first ... F23
#define STATE_CHKS5B  ((BYTE32)0xDA)    // second ... F23
#define STATE_DONE    ((BYTE32)0xFF)

// for checking the order that we get the data from the GPS board
#define ORDER_READY_1   ((BYTE32)0x11)
#define ORDER_READY_2   ((BYTE32)0x22)
#define ORDER_READY_3   ((BYTE32)0x33)
#define ORDER_READY_4   ((BYTE32)0x44)
#define ORDER_READY_5   ((BYTE32)0x55)

#define DEAD_TIME   5   //minutes before the gps board is declared 'dead'

// ADC Register Definitions
#define ADEN ADCSRA.7   //  enable ADC
#define ADSC ADCSRA.6   //  start conversion
#define ADIF ADCSRA.4   //  conversion done

char* version = "$Rev::       $"; // 14 bytes

//***** FUNCTIONS *****//
void init(void);

// Variables that we need
RESP_STATUS     errorStatus;                    // for reporting back to CDH board
BYTE32   		gpsStatus[RESP_GPS_DATA_SIZE]; 	// keep track of GPS data
BYTE32          chk00[2];                       // two bytes of checksum for F00
BYTE32          chk03[2];                       // checksum for F03
BYTE32          chk18[2];                       // checksum for F18
BYTE32          chk22[2];                       // checksum for F22
BYTE32          chk23[2];                       // checksum for F23
BYTE32          needsSet00;                     // stores whether we need to memset sentenceF00
BYTE32          needsSet03;                     // ... sentenceF03
BYTE32          needsSet18;                     // ... sentenceF18
BYTE32          needsSet22;                     // ... sentenceF22
BYTE32          needsSet23;                     // ... sentenceF23
BYTE32          cchkF00[2];                     // stores calculated checksum for F00
BYTE32          cchkF03[2];                     // ... F03
BYTE32          cchkF18[2];                     // ... F18
BYTE32          cchkF22[2];                     // ... F22
BYTE32          cchkF23[2];                     // ... F23
BYTE32          finishedSentences = 0;          // stores whether we finished sentences and can send them out (without checksum validity)
RESP_GPS_TELEM  telemStatus;                    // for keeping track of vitals: current, vcc, etc.
TIMESTAMP       myTime;                         // keep track of time ourselves, and have a dummy var for the SET_TIME command
BYTE32			specCMD[SENTENCEF22_SIZE+20];

INT32 timeTemp;

BYTE32   rxState, rxID[3];               // for keeping track of which data we're receiving
BYTE32   rxOrder;                        // make sure we receive the sentences in the right order
USHORT32 rxCount;
BYTE32   txDone;
BYTE32   txCount;

USHORT32 deadMins;                       // how many minutes passed since last sync

BYTE32  sample_flag;
BYTE32  myPGood;

BYTE32  canModifySentences = 1;
USHORT32 checksumCounter = 0;

// define some commonly used size additions
const USHORT32 F0003 = SENTENCEF00_SIZE+SENTENCEF03_SIZE;
const USHORT32 F000318 = SENTENCEF00_SIZE+SENTENCEF03_SIZE+SENTENCEF18_SIZE;
const USHORT32 F00031822 = SENTENCEF00_SIZE+SENTENCEF03_SIZE+SENTENCEF18_SIZE+SENTENCEF22_SIZE;

// dev's version of the filter
typedef struct {
    BYTE32      data[4];    // hold four previous values
    SHORT32     index;      // index of current value
} MA4;
MA4     telemCurrent;
MA4     telemVoltage3;
MA4     telemVoltage35;
MA4     telemTemp;
INT32   maTemp;         // for big addition

void init(){

    // sets RX_EN, TX_EN, MEM_EN, DISCP to outputs, PGOOD to input
    DDRA = 0b00010111;

    // Enable UART1
    // baud rates: for 76800 bps use 11, for 19200 bps use 47 for 14.7456 MHz oscillator
    UBRR1L = 11;//47;
    UCSR1B = 0b11011000;

    // Enable TX, RX and MEM
    RX_EN = 0;
    TX_EN = 0;
    MEM_EN = 1;

    // set up timer 0 to generate compare interrupts @ 400Hz
    // formula: targetHz = clkfreq/(TIMSK*prescale[low three bits used of TCCR0,page103 Mega128 doc reference]*(1+OCR0))
    TIMSK=2;
    OCR0 = 143; // this makes it 400Hz
    //OCR0 = 49999;
    TCCR0 = 0b00001110;

    // set up ADC
    ADMUX = 0b11100100;  // select channel 4 to set up state machine
    ADCSRA = 0b11000111; //ADC enable, start conversion, prescaler 128

    // turns on the watchdog with resets @ 1.8s (longest duration possible)
    //WDTCR = 0x0F;

    // initialize variables

    RESP_GPS_TELEM_Current(telemCurrent) =		(BYTE32)0;
    RESP_GPS_TELEM_Voltage_35(telemVoltage35) =		(BYTE32)0;
    RESP_GPS_TELEM_Voltage_3(telemVoltage3) =		(BYTE32)0;
    RESP_GPS_TELEM_Temp(telemTemp) =			(BYTE32)0;
    myPGood = 1;
    RESP_STATUS_myStatus(errorStatus) = 0;

    // receiving vars
    rxState = STATE_HUH;
    rxCount = 0;

    //Init Data
    TIMESTAMP_day(myTime) = 0;
    TIMESTAMP_hour(myTime) = 0;
    TIMESTAMP_minute(myTime) = 0;
    TIMESTAMP_seconds(myTime) = 0;
    TIMESTAMP_hundredMicroSeconds(myTime) = 0;

    deadMins = 0; // assume GPS board operational

}

// timer interrupt
interrupt [TIM0_COMP] void timer0_compare(void) {


    // add 0.0025 seconds and instruct main function to sample
    TIMESTAMP_hundredMicroSeconds(myTime) = TIMESTAMP_hundredMicroSeconds(myTime)+25;
    sample_flag = 1;
}

// rx interrupt for GPS Board connection
interrupt [USART1_RXC] void uart1_rec(void){
    /* How this function works:
        It's a state machine:
            - STATE_HUH: general state where the code isn't actively receiving data,
                            and/or has no idea what's going on.
        	- STATE_PRELIM1,2,3: grabs preliminary information like the last command received
            - STATE_ID1,2,3: grabs successive bytes of the sentID[] variable that identifies
                                the sentence and stores them in the rxID[] variable.
            - STATE_S1,2,3,4,5: loops through the length of the sentence and grabs each
                                successive byte.
            - STATE_CHKSA,B: for checking that the data wasn't corrupted during the transfer
            - STATE_DONE: when the sentence is fully downloaded, checks for the end bit as
                            confirmation then does a bit of cleanup.
        If it gets unexpected data at any stage (except in the STATE_S1,2,3,4,5 stages), it'll
        throw a general error and go into STATE_HUH. If it recognizes a start byte and starts
        ID'ing the sentence, it'll clear the general error.

        When a sentence is received, it sets a flag for the main function to check the checksum
        at its leisure.
    */
    BYTE incData;

	incData = UDR1;                 //grab received data
    if(!canModifySentences) return; // CUCP is trying to transmit, writing now would result in undefined behavior
    finishedSentences = 0;


    // let's begin
    switch(rxState)
    {
    case STATE_PRELIM1: // note: this is for f99 preliminary data, just like a sentence but no checksum
    	RESP_GPS_TELEM_lastCommand(telemStatus) = incData;
    	rxState = STATE_PRELIM2;
    	break;
    case STATE_PRELIM2:
    	RESP_GPS_TELEM_commandSuccess(telemStatus) = incData;
    	rxState = STATE_PRELIM3;
    	break;
    case STATE_PRELIM3:
    	RESP_GPS_TELEM_lastSat(telemStatus) = incData;
    	rxState = STATE_DONE;
    	break;
    case STATE_HUH:                         //means we probably need to start receiving data
        if( incData == START_BYTE )
        {
            rxCount = 0;
            // begin id'ing the sentence
            // and clear bit 2(general) (11111011)
            rxState = STATE_ID1;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_GEN;
        }
        else
        {
            rxState = STATE_HUH;                // this is not a good state to be in
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;      // throw a general error
        }
        break;
    case STATE_ID1:
        if( incData == 'F' )
        {
            rxState = STATE_ID2;
            rxID[0] = 'F';
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_GEN;
        }
        else
        {
            rxState = STATE_HUH;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;
        }
        break;
    case STATE_ID2:
        switch( incData )
        {
        case '0':  /* all these cases are good */
        case '1':
        case '2':
        case '9':
            rxState = STATE_ID3;
            rxID[1] = incData;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_GEN;
            break;
        default:    /* but this case is bad */
            rxState = STATE_HUH;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;
        }
        break;
    case STATE_ID3:
        /* walk through all cases */
        RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_GEN;
        if( rxID[1]=='0' && incData=='0' )
            rxState = STATE_S1;
        else if( rxID[1]=='0' && incData=='3' )
            rxState = STATE_S2;
        else if( rxID[1]=='1' && incData=='8' )
            rxState = STATE_S3;
        else if( rxID[1]=='2' && incData=='2' )
            rxState = STATE_S4;
        else if( rxID[1]=='2' && incData=='3' )
            rxState = STATE_S5;
        else if( rxID[1]=='9' && incData=='9' )
        	rxState = STATE_PRELIM1;
        else
        {
            rxState = STATE_HUH;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;   //error in communication
        }
        rxID[2] = incData;
        rxCount = 0;
        break;
    case STATE_S1:
        if(rxCount == 0){
            cchkF00[0] = 0;
            cchkF00[1] = 0;
            cchkF03[0] = 0;
            cchkF03[1] = 0;
            cchkF18[0] = 0;
            cchkF18[1] = 0;
            cchkF22[0] = 0;
            cchkF22[1] = 0;
            cchkF23[0] = 0;
            cchkF23[1] = 0;
        }
        gpsStatus[rxCount++] = incData;         //grab the byte & point to the next byte
        cchkF00[checksumCounter%2] = cchkF00[checksumCounter%2]^incData;
        checksumCounter++;
        if( rxCount == SENTENCEF00_SIZE ){       //if we've filled the buffer...
            checksumCounter = 0;
            rxState = STATE_CHKS1A;               //...go to the verify state
        }
        break;
    case STATE_S2:
        gpsStatus[SENTENCEF00_SIZE + rxCount++] = incData;
        cchkF03[checksumCounter%2] = cchkF03[checksumCounter%2]^incData;
        checksumCounter++;
        if( rxCount == SENTENCEF03_SIZE ){
            checksumCounter = 0;
            rxState = STATE_CHKS2A;
        }
        break;
    case STATE_S3:
        gpsStatus[F0003 + rxCount++] = incData;
        cchkF18[checksumCounter%2] = cchkF18[checksumCounter%2]^incData;
        checksumCounter++;
        if( rxCount == SENTENCEF18_SIZE ){
            checksumCounter = 0;
            rxState = STATE_CHKS3A;
        }
        break;
    case STATE_S4:
        gpsStatus[F000318 + rxCount++] = incData;
        cchkF22[checksumCounter%2] = cchkF22[checksumCounter%2]^incData;
        checksumCounter++;
        if( rxCount == SENTENCEF22_SIZE ){
            checksumCounter = 0;
            rxState = STATE_CHKS4A;
        }
        break;
    case STATE_S5:
        gpsStatus[F00031822 + rxCount++] = incData;
        cchkF23[checksumCounter%2] = cchkF23[checksumCounter%2]^incData;
        checksumCounter++;
        if( rxCount == SENTENCEF23_SIZE ){
            checksumCounter = 0;
            rxState = STATE_CHKS5A;
        }
        break;
    case STATE_CHKS1A:
        chk00[0] = incData;
        rxState = STATE_CHKS1B;
        break;
    case STATE_CHKS2A:
        chk03[0] = incData;
        rxState = STATE_CHKS2B;
        break;
    case STATE_CHKS3A:
        chk18[0] = incData;
        rxState = STATE_CHKS3B;
        break;
    case STATE_CHKS4A:
        chk22[0] = incData;
        rxState = STATE_CHKS4B;
        break;
    case STATE_CHKS5A:
        chk23[0] = incData;
        rxState = STATE_CHKS5B;
        break;
    case STATE_CHKS1B:
        chk00[1] = incData;
        if(cchkF00[0] != chk00[0] || cchkF00[1] != chk00[1]){
                needsSet00 = 1;
        }
        rxState = STATE_DONE;
        break;
    case STATE_CHKS2B:
        chk03[1] = incData;
        if(cchkF03[0] != chk03[0] || cchkF03[1] != chk03[1]){
                needsSet03 = 1;
        }
        rxState = STATE_DONE;
        break;
    case STATE_CHKS3B:
        chk18[1] = incData;
        if(cchkF18[0] != chk18[0] || cchkF18[1] != chk18[1]){
                needsSet18 = 1;
        }
        rxState = STATE_DONE;
        break;
    case STATE_CHKS4B:
        chk22[1] = incData;
        if(cchkF22[0] != chk22[0] || cchkF22[1] != chk22[1]){
                needsSet22 = 1;
        }
        rxState = STATE_DONE;
        break;
    case STATE_CHKS5B:
        chk23[1] = incData;
        if(cchkF23[0] != chk23[0] || cchkF23[1] != chk23[1]){
                needsSet23 = 1;
        }
        rxState = STATE_DONE;
        break;
    case STATE_DONE:
        if( incData == END_BYTE )   // means we successfully got everything
        {
            /* check which sentence we just finished */
            if( rxID[1]=='0' && rxID[2]=='0' )      // sentence 1
            {
                // make sure that we're receiving in the right order
                rxOrder = ORDER_READY_1;
            	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_1;
            }
            else if( rxID[1]=='0' && rxID[2]=='3' ) // sentence 2
            {
                // makes sure that we're receiving the data in the right order
                if( rxOrder == ORDER_READY_1 ) rxOrder = ORDER_READY_2;
            	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_2;
            }
            else if( rxID[1]=='1' && rxID[2]=='8' ) // sentence 3
            {
                if( rxOrder == ORDER_READY_2 ) rxOrder = ORDER_READY_3;
            	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_3;
            }
            else if( rxID[1]=='2' && rxID[2]=='2' ) // sentence 4
            {
                if( rxOrder == ORDER_READY_3 ) rxOrder = ORDER_READY_4;
            	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_4;
            }
            else if( rxID[1]=='2' && rxID[2]=='3' ) // sentence 5
            {
                if( rxOrder == ORDER_READY_4 ) rxOrder = ORDER_READY_5;
            	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_5;
            	finishedSentences = 1;
            }
            else if( rxID[1]=='9' && rxID[2]=='9' ){} // preliminary sentence
            else // double-plus-ungood
            {
                rxState = STATE_HUH;
                RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;
                break;
            }

            rxState = STATE_HUH;                // be ready again
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_GEN; // and clear bit 2(general) (11111011)
        }
        else
        {
            rxState = STATE_HUH;
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;   // set bit 2(general) = 1 (00000100)
        }
        break;
    default:
        rxState = STATE_HUH;   // if we ever get here, cry.
        RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_GEN;         // set bit 2(general) = 1 (00000100)
    }

    if( rxOrder == ORDER_READY_5 )
    {
        // sync the time up; sentenceF00 is the first entry in gpsStatus so a cast retrieves it
        TIMESTAMP_day(myTime) = sentenceF00_day(*(sentenceF00*)gpsStatus);
        TIMESTAMP_hour(myTime) = sentenceF00_hour(*(sentenceF00*)gpsStatus);
	TIMESTAMP_minute(myTime) = sentenceF00_minute(*(sentenceF00*)gpsStatus);
	TIMESTAMP_seconds(myTime) = sentenceF00_Second2(*(sentenceF00*)gpsStatus);
	TIMESTAMP_hundredMicroSeconds(myTime) = sentenceF00_DeSecond(*(sentenceF00*)gpsStatus);

        deadMins = 0; // got a sync

        // turn off state machine errors
	RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_DEAD & ~ERR_1 & ~ERR_2 & ~ERR_3 & ~ERR_4 & ~ERR_5;
    }
}

// tx interrupt
interrupt [USART1_TXC] void uart1_xmit(void){
    txDone = 1;
}

// rolls over the time variables if needed, ie, new minute, day, etc.
void rollTime(){
        timeTemp = TIMESTAMP_hundredMicroSeconds(myTime);
        if (timeTemp >= 10000) {
                TIMESTAMP_hundredMicroSeconds(myTime) = timeTemp-10000;
                timeTemp = TIMESTAMP_seconds(myTime);
                TIMESTAMP_seconds(myTime) = ++timeTemp;
                if (timeTemp >= 60) {
                        TIMESTAMP_seconds(myTime) = timeTemp-60;
                        timeTemp = TIMESTAMP_minute(myTime);
                        TIMESTAMP_minute(myTime) = ++timeTemp;
                	deadMins++;
                        if (timeTemp >= 60) {
        	                TIMESTAMP_minute(myTime) = timeTemp-60;
                                timeTemp = TIMESTAMP_hour(myTime);
                                TIMESTAMP_hour(myTime) = ++timeTemp;
                                if (timeTemp >= 24) {
                                        TIMESTAMP_hour(myTime) = timeTemp-24;
                                        timeTemp = TIMESTAMP_day(myTime);
                                        TIMESTAMP_day(myTime) = timeTemp+1;
        	                }
        	        }
                }
        }

        if( deadMins > DEAD_TIME )
            RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_DEAD; // gps be dead - set bit 0(dead) to 1 (00000001)

}

// samples ADCs and populates values if sample_flag == 1 and sets sample_flag to 0
void sampleLines(){
        if (sample_flag == 1){  // it samples
            // Current sense
            ADMUX = 0b11100000; //Channel 0
            ADSC = 1;           // start conversion
            while (!ADIF);      // chill out

            /* current filter */
            telemCurrent.data[telemCurrent.index++] = ADCH; //grab the adc and inc the index
            if(telemCurrent.index >= 4)
                telemCurrent.index = 0;                     // length-4 filter
            maTemp = (  (INT32)telemCurrent.data[3] +
                        (INT32)telemCurrent.data[2] +
                        (INT32)telemCurrent.data[1] +
                        (INT32)telemCurrent.data[0]    );   //add up...
            RESP_GPS_TELEM_Current(telemStatus) = (BYTE32)(maTemp >> 2);    //and divide

            // VCC Sense
            ADMUX = 0b11100001; //Channel 1
            ADSC = 1;           // start conversion
            while (!ADIF);        // chill out

            /* vcc filter */
            telemVoltage35.data[telemVoltage35.index++] = ADCH;     //grab the adc and inc the index
            if( telemVoltage35.index >= 4 )
                telemVoltage35.index = 0;                           // length-4 filter
            maTemp = (  (INT32)telemVoltage35.data[3] +
                        (INT32)telemVoltage35.data[2] +
                        (INT32)telemVoltage35.data[1] +
                        (INT32)telemVoltage35.data[0]    );         //add up...
            RESP_GPS_TELEM_Voltage_35(telemStatus) = (BYTE32)(maTemp >> 2);         //and divide

            // Memory Voltage sense
            ADMUX = 0b11100010; //Channel 2
            ADSC = 1;           // start conversion
            while (!ADIF);        // chill out

            /* vmem filter */
            telemVoltage3.data[telemVoltage3.index++] = ADCH;       //grab the adc and inc the index
            if( telemVoltage3.index >= 4 )
                telemVoltage3.index = 0;                            // length-4 filter
            maTemp = (  (INT32)telemVoltage3.data[3] +
                        (INT32)telemVoltage3.data[2] +
                        (INT32)telemVoltage3.data[1] +
                        (INT32)telemVoltage3.data[0]    );          //add up...
            RESP_GPS_TELEM_Voltage_3(telemStatus) = (BYTE32)(maTemp >> 2);          //and divide

            // Thermistor sense
            ADMUX = 0b11100011; //Channel 3
            ADSC = 1;           // start conversion
            while (!ADIF);        // chill out

            /* temp filter */
            telemTemp.data[telemTemp.index++] = ADCH;   //grab the adc and inc the index
            if( telemTemp.index >= 4 )
                telemTemp.index = 0;                    // length-4 filter
            maTemp = (  (INT32)telemTemp.data[3] +
                        (INT32)telemTemp.data[2] +
                        (INT32)telemTemp.data[1] +
                        (INT32)telemTemp.data[0]    );  //add up...
            RESP_GPS_TELEM_Temp(telemStatus) = (BYTE32)(maTemp >> 2);   //and divide

            // Check PGOOD
            myPGood = PORTA.3;
            if( myPGood )
                RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) & ~ERR_PGOOD;   // sets bit 1(pgood) = 0 (11111101)
            else
                RESP_STATUS_myStatus(errorStatus) = RESP_STATUS_myStatus(errorStatus) | ERR_PGOOD;    // sets bit 1(pgood) = 1 (00000010)

            sample_flag = 0;
        }
}

void main() {
    init();
    CUCP_Init();

    #asm("sei");

    while(1) {
       // #asm("wdr");    //resets the watchdog timer

        // memset vars if necessary
        if(needsSet00){
                memset(gpsStatus,0xAA,SENTENCEF00_SIZE);
                needsSet00 = 0;
        }
        if(needsSet03){
                memset(&gpsStatus[SENTENCEF00_SIZE],0xBB,SENTENCEF03_SIZE);
                needsSet03 = 0;
        }
        if(needsSet18){
                memset(&gpsStatus[F0003],0xCC,SENTENCEF18_SIZE);
                needsSet18 = 0;
        }
        if(needsSet22){
                memset(&gpsStatus[F000318],0xDD,SENTENCEF22_SIZE);
                needsSet22 = 0;
        }
        if(needsSet23){
                memset(&gpsStatus[F00031822],0xEE,SENTENCEF23_SIZE);
                needsSet23 = 0;
        }

        // roll over time vars if needed
        rollTime();

        // sample values
        sampleLines();

        if (Net_Msg_Status == MSG_EBSRIE) { // Command and payload have been received
            switch (Net_Cmd) {

                case NET_CMD_GPS_GET_TIME:
                    send((BYTE*)&myTime, TIMESTAMP_SIZE);
                    break;

                case NET_CMD_GPS_GET_DATA:
                    // if we aren't finished getting a sentence, delay until we have gotten one, or
                    // 500 ms has passed.  CUCP will timeout gracefully.
                    //send((BYTE*)gpsStatus, RESP_GPS_DATA_SIZE);

                    timeTemp = TIMESTAMP_hundredMicroSeconds(myTime);
                    while(needsSet23 || !finishedSentences){ // wait until we are in a good state
                        if((timeTemp + 5000) <= TIMESTAMP_hundredMicroSeconds(myTime)) break;
                        // memset vars if necessary
                        if(needsSet00){
                                memset(gpsStatus,0xAA,SENTENCEF00_SIZE);
                                needsSet00 = 0;
                        }
                        if(needsSet03){
                                memset(&gpsStatus[SENTENCEF00_SIZE],0xBB,SENTENCEF03_SIZE);
                                needsSet03 = 0;
                        }
                        if(needsSet18){
                                memset(&gpsStatus[F0003],0xCC,SENTENCEF18_SIZE);
                                needsSet18 = 0;
                        }
                        if(needsSet22){
                                memset(&gpsStatus[F000318],0xDD,SENTENCEF22_SIZE);
                                needsSet22 = 0;
                        }
                        if(needsSet23){
                                memset(&gpsStatus[F00031822],0xEE,SENTENCEF23_SIZE);
                                needsSet23 = 0;
                        }
                    }

                    if(finishedSentences){
                        canModifySentences = 0;
                        send((BYTE*)gpsStatus, RESP_GPS_DATA_SIZE);
                        canModifySentences = 1;
                    }
                    else{
                        sendSingleByte(0,RESP_GPS_DATA_SIZE);
                    }
                    break;

                case NET_CMD_GPS_GET_TELEM:
                    send((BYTE*)&telemStatus, RESP_GPS_TELEM_SIZE);
                    break;

                case NET_CMD_GPS_SPEC_CMD:

                    txCount = 0;
                    txDone = 1;
                    while(txCount < Net_Payload_Length){
                        while(!txDone);             // wait while still transmitting stuff

                        txDone = 0;
                        UDR1 = specCMD[txCount++];  // write data out
                    }

                    break;

                case NET_CMD_PING:
                    break;

                case NET_CMD_GET_STATUS:
                    send((BYTE*)errorStatus, RESP_STATUS_SIZE);
                    break;

                case NET_CMD_SILENCE:
                    break;

                case NET_CMD_SET_TIME:
                    //don't need this since we provide the time
                    break;
                case NET_CMD_REPROGRAM:
                    #asm("jmp 0xfc00");
                    break;

                case NET_CMD_VERSION:
                	send(version,RESP_VERSION_SIZE);

                default:
                    break;
            }
 	    Net_Msg_Status = MSG_READ;
        }
    }
}

BYTE* get_receive_mem(BYTE Net_Cmd, UINT* memBufferSize, BYTE* hasResponse, BYTE* isValidCmd) {
        *isValidCmd = 1;

        switch (Net_Cmd)
        {
        case NET_CMD_GPS_GET_TIME:
            *memBufferSize = 0;
            *hasResponse = 1;
            return NULL;

        case NET_CMD_GPS_GET_DATA:
            *memBufferSize = 0;
            *hasResponse = 1;
            return NULL;

        case NET_CMD_GPS_GET_TELEM:
            *memBufferSize = 0;
            *hasResponse = 1;
            return NULL;

        case NET_CMD_GPS_SPEC_CMD:
            *memBufferSize = Net_Payload_Length;
            *hasResponse = 0;
            return (BYTE *)specCMD;   /* if it works */
            break;

        case NET_CMD_PING:
        case NET_CMD_SILENCE:
            *memBufferSize = 0;
            *hasResponse = 0;
            return NULL;

        case NET_CMD_SET_TIME:
            *memBufferSize = 0;
            *hasResponse = 0;
            return NULL;

        case NET_CMD_GET_STATUS:
            *memBufferSize = 0;
            *hasResponse = 1;
            return NULL;

		case NET_CMD_VERSION:
            *memBufferSize = 0;
            *hasResponse = 1;
            return NULL;

        case NET_CMD_REPROGRAM:
            *memBufferSize = 0;
            *hasResponse = 0;
            return NULL;
        default:
            *isValidCmd = 0;
            return NULL;
        }
}
