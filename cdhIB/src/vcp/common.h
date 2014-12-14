/** \file
 * common.h
 * \brief Common header file
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#ifndef common_h
#define common_h

// Defined for the CRC functions
#define MCU_PLATFORM
//#define COMP_PLATFORM

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
typedef unsigned int		uint16;
typedef unsigned int*		uint16ptr;
typedef unsigned int**		uint16hdl;
typedef signed int			sint16;
typedef signed int*			sint16ptr;
typedef signed int**		sint16hdl;
typedef unsigned long		uint32;
typedef unsigned long*		uint32ptr;
typedef unsigned long**		uint32hdl;
typedef signed long			sint32;
typedef signed long*		sint32ptr;
typedef signed long**		sint32hdl;
typedef unsigned long long	uint64;
typedef unsigned long long* uint64ptr;
typedef unsigned long long**uint64hdl;
typedef signed long long	sint64;
typedef signed long long*	sint64ptr;
typedef signed long long**	sint64hdl;

typedef float		float32;
typedef float*		float32ptr;
typedef float**		float32hdl;
typedef struct
{
	double data[2];
} float64;
typedef float64*	float64ptr;
typedef float64**	float64hdl;

#define true	1
#define false	0

// look in common.c for documentation on these functions
uint8 getbit(uint8 flag, uint8 bit);
uint32 insert_str(uint8 *output, uint32 output_size, uint32 start_index, uint8 *input, uint32 input_size);
uint32 int_to_char(uint32 number, uint32 base, uint8 *str, uint32 str_size);

#endif
