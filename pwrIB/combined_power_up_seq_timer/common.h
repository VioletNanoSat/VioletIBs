/*
 * common.h
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#ifndef common_h
#define common_h

// Defined for the CRC functions
//#define MCU_PLATFORM
#define COMP_PLATFORM

// for debugging purposes
#include <stdio.h>
#include <string.h>

// Define common types for portability reasons
typedef unsigned char		uint8;
typedef unsigned char*		uint8ptr;
typedef unsigned char**		uint8hdl;
typedef signed char			sint8;
typedef signed char*		sint8ptr;
typedef signed char**		sint8hdl;
typedef unsigned short		uint16;
typedef unsigned short*		uint16ptr;
typedef unsigned short**	uint16hdl;
typedef signed short		sint16;
typedef signed short*		sint16ptr;
typedef signed short**		sint16hdl;
typedef unsigned int		uint32;
typedef unsigned int*		uint32ptr;
typedef unsigned int**		uint32hdl;
typedef signed int			sint32;
typedef signed int*			sint32ptr;
typedef signed int**		sint32hdl;
typedef unsigned long long	uint64;
typedef unsigned long long* uint64ptr;
typedef unsigned long long**uint64hdl;
typedef signed long long	sint64;
typedef signed long long*	sint64ptr;
typedef signed long long**	sint64hdl;

typedef float		float32;
typedef float*		float32ptr;
typedef float**		float32hdl;
typedef double		float64;
typedef double*		float64ptr;
typedef double**	float64hdl;

#define true	1
#define false	0

// look in common.c for documentation on these functions
uint8 getbit(uint8 flag, uint8 bit);
uint32 insert_str(uint8 *output, uint32 output_size, uint32 start_index, uint8 *input, uint32 input_size);

#endif
