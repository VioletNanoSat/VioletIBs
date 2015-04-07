import sys
import serial

class RadioToCDHTester():
	'''
	STK600 Layout:
	Port A:
	A0:	..
	 RX	..	TX <- For Port A0
	A1:	..	
	 RX	..	TX <- For Port A1
	GND	..	VTG

	Same pattern holds for all Ports on the STK600

	RS-232 Spare Layout:
	RX	..	TX
	CTS	..	RTS
	'''
	def __init__(self,serial):
		self.test_port = serial

	def send_packets_to_fc(self):
		pass


	def run_full_test(self):
		print 'We will test the path from RadioIB to the CDHIB.'
		print 'There are only 2 type of packet that comes in.'
		print 'One packet is [LI | AX-25 | CCSDS | AX-25 Footer | LI Footer] and'
		print 'The other packet is [LI | AX-25 | CCSDS Command | AX-25 Footer | LI-Footer]'
		print 'We will test both types of packets.'

		# Make sure version you are running is latest commit.
		latest_commit = check_output(['git','log','--pretty=format:"%h"']).split('\n')[0]
		self.send_packets_to_fc()


if __name__ == '__main__':
	print 'Radio IB to CDH Test Path'
	tester = RadioPathTester(serial.Serial(port='/dev/ttyUSB0',baudrate=9600,
		timeout=10))
	tester.run_full_test()

