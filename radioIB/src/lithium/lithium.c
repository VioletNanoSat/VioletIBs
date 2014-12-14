/*
 * lithium.c
 *
 * Created: 4/18/2014 2:36:25 AM
 *  Author: akd54_admin
 */ 

#include "lithium.h"

void calculate_header_chksum(uint8ptr hdr) 
{
	uint8_t first = 0;
	uint8_t second = 0;
	uint8_t i = 0;
	
	while(i < LI_HDR - 2)
	{
		first = first + hdr[i];
		second = second + first;
	}
	
	hdr[6] = first;
	hdr[7] = second;	
}