import sys
import serial
from binascii import unhexlify,hexlify
from time import sleep

sys.path.append('../util/')
from vcp import *
from lithium import *

def send_to_radio(test_port,test_packet):
	full_packet = unhexlify(wrap_lithium(test_packet,True))
	print 'Sending ' + hexlify(full_packet)
	packets_read = 0
	try:
		while 1:
			test_port.write(full_packet)
			read = hexlify(test_port.read(2 + 10))
			if read != '':
				packets_read += 1
			print 'Packet {} Read:'.format(str(packets_read))
			print '0x' + ' 0x'.join(a+b for a,b in zip(read[::2],read[1::2]))
			print ''
			raw_input('Enter')
	except KeyboardInterrupt:
		pass


if __name__ == '__main__':
	print 'End to End tests on HW'
	test_port = serial.Serial(port='/dev/ttyUSB0',baudrate=9600,timeout=3)
	test_packet = '18ffdead'
	send_to_radio(test_port,test_packet)

