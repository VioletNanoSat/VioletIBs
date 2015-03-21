import serial

radio_ib = serial.Serial(
	port='COM19',			
	baudrate=115200 , 
	timeout=1,
	parity=serial.PARITY_NONE,
	bytesize=serial.EIGHTBITS
	)
	
#Constants Needed
LI_SYNC_0 = 0x48
LI_SYNC_1 = 0x65
LI_CMD_0 = 0x10
LI_CMD_1 = 0x03

#AX.25 Constants- These constants all contain dummy values, because AX.25 is already taken care of by our radio
FLAG = 0x7E       			#Beginning and Ending AX.25 Flag
SOURCE_ADDR = "VIOLET"      #7 byte source addr NONREPEATER
DEST_ADDR = "CORNEL"        #7 byte destination addr NONREPEATER
SOURCE_SSID = 0x01    		#source station
DEST_SSID = 0x02      		#destination station
CONTROL = 0x13        		#Control Field: we assume bit 4 = 1 meaning that we expecct an acknowledgement
PID = 0xF0           		#PID Field: No layer 3 protocol implemented
FCS_byte0 = 0x55    		#FCS Field: we assume radio does check sum so this field is irrelevent
FCS_byte1 = 0xAA    		#FCS Field: 2nd byte of payload checksum
	
test_input_packets = []
expected_result = []

def checksum_calc(header):
    """Returns: a tuple containing the calculated checksums
    based on the 8-bit Fletcher Algorithm
    
    Precondition: header is a list of hex values"""
    i=0;
    CK_A = 0
    CK_B = 0 
    for i in range(len(header)):
        CK_A = CK_A + header[i]
        CK_B = CK_B + CK_A
    
    CK_A2 = CK_A & 0xFF
    CK_B2 = CK_B & 0xFF
    
    return (CK_A2,CK_B2)

def create_address():
    """Returns: A binary representation of the address field in AX.25.
    Converts the 7-bit source and destination addresses into binary
    and then adds the source and destination SSID."""
    address = []
    for x in range(0,len(DEST_ADDR)):
        h = hex(ord(DEST_ADDR[x]))
        address.append(int(h[2:], 16))
    address.append(DEST_SSID)
     
    for x in range(0,len(SOURCE_ADDR)):
        a = hex(ord(SOURCE_ADDR[x]))
        address.append(int(a[2:], 16))
    address.append(SOURCE_SSID)
    
    return address

def construct_ground_packet(offset):
	ret = bytearray()
	packet = test_input_packets[offset]
	#---------------- Lithium Header ----------------#
	ret.append(LI_SYNC_0)
	ret.append(LI_SYNC_1)
	ret.append(LI_CMD_0)
	ret.append(LI_CMD_1)
	ret.append(0x00) 		#Dummy Length
	ret.append(0x00) 		#Dummy Length
	ret.append(0x00)		#Dummy CHKSUM
	ret.append(0x00)		#Dummy CHKSUM
	
	address = create_address()
	for i in range(len(address)):
		ret.append(address[i])
	for i in range(len(packet)):
		ret.append(packet[i])
		
	ret.append(FCS_byte0)	#Dummy CHKSUM
	ret.append(FCS_byte1)	#Dummy CHKSUM
		
	#------AX-25 has been wrapped around packet------#
	length = len(ret[8:])
	ret[4] = length >> 8
	ret[5] = length
	
	#----------------Header checksums----------------#
	(chk_a,chk_b) = checksum_calc(ret[2:7])
	ret[6] = chk_a 			#Putting in correct CHKSUM
	ret[7] = chk_b			#Putting in correct CHKSUM
	

	#-----------------Data checksums-----------------#
	(chk_a,chk_b) = checksum_calc(ret[7:])
	
	ret.append(chk_a)		
	ret.append(chk_b)
	
	return ret
	
def check_packet_output(recv,expc):
	if len(recv) != len(expc):
		return False
	for i in range(len(recv)):
		if(not recv[i] == expc[i]):
			return False
	return True
	
def get_response():
	recv = bytearray()
	header = radio_ib.read(8)
	packet_length = header[4] << 8 + header[5]
	payload = []
	while(not len(payload) == packet_length):
		payload.append(radio_ib.read())
		
	recv.extend(header)
	recv.extend(payload)
	
	#-----------------Data checksums-----------------#
	recv.append(radio_ib.read())
	recv.append(radio_ib.read())
	
	return recv

def test():
	for entry in range(len(test_input_packets)):
		req = construct_ground_packet(entry)
		radio_ib.write(req) 
		resp = get_response()
		ex_resp = expected_result[entry]
		valid = check_packet_output(resp,ex_resp)
		if not valid:
			print "Test %d failed." %(entry)	

	
if __name__ == '__main__':
	print "Radio IB Testing Module"
	test()
	print "Finished Testing"
	radio_ib.close()
	
