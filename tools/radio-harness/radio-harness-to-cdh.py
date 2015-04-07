import sys
import serial
from subprocess import check_output
from binascii import unhexlify

sys.path.append('../util/')
from vcp import *
from lithium import *

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

	def populate_fc_packets(self):
		packets = [[0x18,0xff,0x01,0x05]]
		return packets,[wrap_lithium(hexlify(''.join([chr(x) for x in entry])),True) for entry in packets]

	def verify_fc_packets(self,packets):
		return [wrap_vcp(hexlify(''.join([chr(x) for x in entry])),VCP_FC) for entry in packets]

	def send_packets_to_fc(self,radio_uart,cdh_uart):
		print 'The Radio UART is located at {r}. The CDH UART is located at {c}.'.format(r=radio_uart,c=cdh_uart)
		print 'Connect the RX pin of the RS-232 spare to the RX of the Radio UART.'
		print 'Connect the TX pin of the RS-232 Spare to the TX of the CDH UART.'

		bare_packets,test_packets = self.populate_fc_packets()
		verification_packets = self.verify_fc_packets(bare_packets)
		correct_packets = 0
		for pair in zip(test_packets,verification_packets):
			send,recv = pair
			self.test_port.write(unhexlify(send))
			actual = self.test_port.read(len(recv)/2)
			if unhexlify(recv) == actual:
				correct_packets += 1
				print 'Received Correct Packet {}'.format(correct_packets)
			else:
				print 'Sent Packet:'
				print '0x'+' 0x'.join(a+b for a,b in zip(send[::2],send[1::2]))
				print 'Received: '
				print '0x'+' 0x'.join(a+b for a,b in zip(hexlify(actual)[::2],hexlify(actual)[1::2]))
				print 'Expected: '
				print '0x'+' 0x'.join(a+b for a,b in zip(recv[::2],recv[1::2]))

		print 'FC Packets Complete'


	def run_full_test(self):
		print 'We will test the path from RadioIB to the CDHIB.'
		print 'There are only 2 type of packet that comes in.'
		print 'One packet is [LI | AX-25 | CCSDS | AX-25 Footer | LI Footer] and'
		print 'The other packet is [LI | AX-25 | CCSDS Command | AX-25 Footer | LI-Footer]'
		print 'We will test both types of packets.\n\n'

		# Make sure version you are running is latest commit.
		latest_commit = check_output(['git','log','--pretty=format:"%h"']).split('\n')[0]
		with open('../../radioIB/src/config/conf_usart_serial.h','r') as f:
			uarts = (''.join(f.readlines()).split('BEGIN UARTS')[1]).split('END_UARTS')[0].split('\n')

		print 'Latest commit is {}. Make sure the code being tested is ON THIS COMMIT!!!'.format(latest_commit)

		radio_uart 	= ''
		cdh_uart 	= ''

		for uart in uarts:
			if 'RADIO_UART' in uart and radio_uart == '':
				radio_uart = uart.split('\t')[-1]
			elif 'CDHIB_UART' in uart and cdh_uart == '':
				cdh_uart = uart.split('\t')[-1]

		print 'Testing First Type of Packets'
		self.send_packets_to_fc(radio_uart,cdh_uart)




if __name__ == '__main__':
	print 'Radio IB to CDH Test Path'
	tester = RadioPathTester(serial.Serial(port='/dev/ttyUSB0',baudrate=9600,
		timeout=10))
	tester.run_full_test()

