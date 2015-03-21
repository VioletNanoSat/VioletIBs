'''@package VCP
This module contains VCP constants and VCP functions

Functions include checksum generation and verification.
Uses cristianav's PyCRC library for CRC16 checksum generation
Usage covered under GPLv3 license
'''

from binascii import hexlify,unhexlify
from CRC16 import CRC16


VCP_FEND 			= 0xC0

VCP_POWER			= 0x01
VCP_STAR_TRACKER	= 0x04
VCP_SPECTROMETER	= 0x07
VCP_FC				= 0x0B
VCP_SUN_SENSOR		= 0x38

VCP_CDH_MCU_1		= 0x09
VCP_CDH_MCU_2		= 0x0A

VCP_ADDR_RADIO_1	= 0x02
VCP_ADDR_RADIO_2	= 0x05

VCP_CDH				= VCP_CDH_MCU_2
VCP_RADIO			= VCP_ADDR_RADIO_2

crc_calculator		= CRC16() 

def wrap_vcp(hex_str,address):
	binaries = [ord(unit) for unit in unhexlify(hex_str)]

	if 'pwb' in address:
		binaries.insert(0,VCP_POWER)
	elif 'star' in address:
		binaries.insert(0,VCP_STAR_TRACKER)
	elif 'spec' in address:
		binaries.insert(0,VCP_SPECTROMETER)
	elif 'fc' in address:
		binaries.insert(0,VCP_FC)
	elif 'sun' in address:
		binaries.insert(0,VCP_SUN_SENSOR)
	elif 'cdh' in address:
		binaries.insert(0,VCP_CDH)
	elif 'radio' in address:
		binaries.insert(0,VCP_RADIO)
	else:
		print 'Unknown VCP Address'
		return []

	chk_a,chk_b = get_checksum(binaries)

	binaries.append(chk_a)
	binaries.append(chk_b)
	binaries.append(VCP_FEND)
	binaries.insert(0,VCP_FEND)

	return hexlify(''.join(map(chr,binaries)))


def get_checksum(binary):
	crc = crc_calculator.calculate(''.join([chr(x) for x in binary]))
	return ((crc >> 8) & 0xff,crc & 0xff)
    

if __name__ == '__main__':
	print 'VCP Library'