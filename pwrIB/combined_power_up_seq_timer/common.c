/*
 * common.c
 *
 *  Created on: Jun 14, 2010
 *      Author: Ned Bingham
 */

#include "common.h"

/*
 * getbit
 * this gets the value of a specific
 * bit in the flag byte
 *
 * returns 0 or 1
 */
uint8 getbit(uint8 flag, uint8 bit)
{
	return (flag & (0x01 << bit)) >> bit;
}

/*
 * insert_str
 *
 * this copies a string into another, starting
 * at a specific index
 */
uint32 insert_str(uint8 *output, uint32 output_size, uint32 start_index, uint8 *input, uint32 input_size)
{
	uint32 i = start_index;
	for (i = start_index; i < start_index + input_size && i < output_size-1; i++)
		output[i] = input[i - start_index];

	return i;
}
