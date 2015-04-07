from binascii import hexlify, unhexlify

LI_H 		= chr(0x48)
LI_e 		= chr(0x65)

SOURCE_SSID = 0x01 
DEST_SSID 	= 0x02

def checksum(binaries):
    CK_A = 0
    CK_B = 0 
    for byte in binaries:
        CK_A = CK_A + byte
        CK_B = CK_B + CK_A
    
    CK_A = CK_A & 0xFF
    CK_B = CK_B & 0xFF
    
    binaries.append(CK_A)
    binaries.append(CK_B)
    return binaries

def wrap_lithium(hex_str,is_command):
	if is_command:
		hex_str = wrap_ax_25(hex_str)

	length = len(hex_str)/2
	header = [ord(LI_H),ord(LI_e),0x10,0x03,length >> 8 & 0xff,length & 0xff]
	full_header = checksum(header)
	payload = [ord(x) for x in unhexlify(hex_str)]
	return hexlify(''.join([chr(x) for x in full_header + checksum(payload)]))


def wrap_ax_25(hex_str):
	source = 'CORNEL'
	dest = 'VIOLET'
	datum = dest + chr(DEST_SSID) + source + chr(SOURCE_SSID) +	 unhexlify(hex_str)
	binaries = [ord(x) for x in datum]
	return hexlify(''.join([chr(x) for x in checksum(binaries)]))

if __name__ == '__main__':
	print 'Lithium Library'
	test = '18ff'
	print wrap_lithium(test,True)
