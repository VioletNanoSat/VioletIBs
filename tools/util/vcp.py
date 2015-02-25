'''@package VCP
This module contains VCP constants and VCP functions

Functions include checksum generation and verification.

'''

VCP_ESCAPE 			= chr(0xC0)
VCP_FEND 			= VCP_ESCAPE

VCP_ADDR_POWER		= chr(0x01)
VCP_STAR_TRACKER	= chr(0x04)
VCP_SPECTROMETER	= chr(0x07)
VCP_FC				= chr(0x0B)
VCP_SUN_SENSOR		= chr(0x38)

VCP_CDH_MCU_1		= chr(0x09)
VCP_CDH_MCU_2		= chr(0x0A)

VCP_ADDR_RADIO_1	= chr(0x02)
VCP_ADDR_RADIO_2	= chr(0x05)

VCP_CDH				= VCP_CDH_MCU_2
VCP_RADIO			= VCP_ADDR_RADIO_2


if __name__ == '__main__':
	print 'VCP Library'