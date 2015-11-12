/*
 * crclib.h
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#include "common.h"

#ifndef crclib_h
#define crclib_h

#define CRC16_INIT_VALUE	0x0000

// This will be defined in common.h
#ifdef COMP_PLATFORM

// look at crclib.c for documentation on these functions
uint16	crc16(uint8ptr message, uint32 size);
void	append_crc16(uint8 byte, uint16ptr crc);

#endif

// This will be defined in common.h
#ifdef MCU_PLATFORM

// look at crclib.c for documentation on these functions
uint16 crc16(uint8ptr message, uint32 size);
void append_crc16(uint8 character, uint16ptr crc);

#endif

#endif
