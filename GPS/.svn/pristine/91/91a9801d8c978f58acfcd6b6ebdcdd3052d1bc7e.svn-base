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

/*
 * int_to_char
 *
 * This stores the string representation of an int into 
 * a char array
 */
uint32 int_to_char(uint32 number, uint32 base, uint8 *str, uint32 str_size)
{
	if (str == NULL || str_size == 0)
		return 0;

	uint32 pos = 0;
	uint32 num;
	uint32 temp;
	uint32 div = 1;
	uint32 levels = 0;

	if (number > 0)
		num = number;
	else if (number == 0)
	{
		str[0] = '0';
		return 1;
	}
	else
	{
		str[pos++] = '-';
		num = (uint32)-number;
	}

	while (num/div > 0)
	{
		div *= base;
		levels++;
	}

	div /= base;

	while (div >= 1)
	{
		temp = num/div;
		num = num - temp*div;
		if (pos < str_size)
		{
			if (temp < 10)
				str[pos++] = temp+48;
			else
				str[pos++] = temp+55;
		}
		else
			break;

		div /= base;
	}

	return pos;
}
