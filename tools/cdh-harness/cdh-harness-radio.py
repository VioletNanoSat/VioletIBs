import sys
import serial
from subprocess import check_output
from binascii import unhexlify
import re

sys.path.append('../util/')
from vcp import *

class RadioPathTester():
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

	def populate_radio_packets(self,path):
		if 'fc' in path:
			ret = [[0x18,0xff,0xde,0xad]]
		elif 'pwb' in path:
			pass
		elif 'cdh' in path:
			pass
		else:
			Sys.exit('Path is invalid: ' + path)

		return [wrap_vcp(hexlify(''.join([chr(x) for x in entry])),path) for entry in ret]

	def verify_radio_packets(self,path):
		if 'fc' in path:
			ret = []
			ret.append([0x18,0xff,0xde,0xad])
		elif 'pwb' in path:
			pass
		elif 'cdh' in path:
			pass
		else:
			Sys.exit('Path is invalid: ' + path)

		return [wrap_vcp(hexlify(''.join([chr(x) for x in entry])),'radio') for entry in ret]


	def test_to_dest(self,dest,radio_uart,fc_uart,pwb_uart):
		switch(dest) {
		  case 'fc':
		  	location = 'FC';
		  	l='fc_uart';
		    break;
		  case 'pwb':
		  	location = 'PWB';
		  	l='power_uart';
		  	break;
		  case 'cdh':
		  	location = 'CDH';
		  	printf("NOT YET IMPLEMENTED");
		  	pass;
		  	#break;
		  default:
		    printf("Erroneous destination.");
		    pass;

		print 'The Radio UART is located at {r}. The ' + location + ' UART is located at {l}'.format(r=radio_uart,l=l)
		print 'Connect the RX pin of the RS-232 spare to the RX of the Radio UART.'
		print 'Connect the TX pin of the RS-232 spare to the TX of the ' + location + ' UART'
		print ''
		raw_input('Press Enter to begin ' +  + ' Test')
		radio_packets				= self.populate_radio_packets(dest)
		verification_packets		= self.verify_radio_packets(dest)
		correct_packets = 0
		for pair in zip(radio_packets,verification_packets):
			send, recv = pair
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
		print location + ' Test Path Complete'


	# def test_to_fc(self,radio_uart,fc_uart):
	# 	print 'The Radio UART is located at {r}. The FC UART is located at {f}'.format(r=radio_uart,f=fc_uart)
	# 	print 'Connect the RX pin of the RS-232 spare to the RX of the Radio UART.'
	# 	print 'Connect the TX pin of the RS-232 spare to the TX of the FC UART'
	# 	print ''
	# 	raw_input('Press Enter to begin FC Test')
	# 	radio_packets				= self.populate_radio_packets('fc')
	# 	verification_packets		= self.verify_radio_packets('fc')
	# 	correct_packets = 0
	# 	for pair in zip(radio_packets,verification_packets):
	# 		send, recv = pair
	# 		self.test_port.write(unhexlify(send))
	# 		actual = self.test_port.read(len(recv)/2)
	# 		if unhexlify(recv) == actual:
	# 			correct_packets += 1
	# 			print 'Received Correct Packet {}'.format(correct_packets)
	# 		else:
	# 			print 'Sent Packet:'
	# 			print '0x'+' 0x'.join(a+b for a,b in zip(send[::2],send[1::2]))
	# 			print 'Received: '
	# 			print '0x'+' 0x'.join(a+b for a,b in zip(hexlify(actual)[::2],hexlify(actual)[1::2]))
	# 			print 'Expected: '
	# 			print '0x'+' 0x'.join(a+b for a,b in zip(recv[::2],recv[1::2]))
	# 	print 'FC Test Path Complete'

	# def test_to_pwb(self):
	# 	print 'The Radio UART is located at {r}. The PWB UART is located at {p}.'.format(r=radio_uart,p='power_uart')
	# 	print 'Connect the RX pin of the RS-232 spare to the RX of the Radio UART.'
	# 	print 'Connect the TX pin of the RS-232 spare to the TX of the Power UART.'
	# 	print ''
	# 	raw_input('Press Enter to begin PWB Test')
	# 	radio_packets				= self.populate_radio_packets('pwb')
	# 	verification_packets		= self.verify_radio_packets('pwb')
	# 	correct_packets = 0
	# 	for pair in zip(radio_packets,verification_packets):
	# 		send, recv = pair
	# 		self.test_port.write(unhexlify(send))
	# 		actual = self.test_port.read(len(recv)/2)
	# 		if unhexlify(recv) == actual:
	# 			correct_packets += 1
	# 			print 'Received Correct Packet {}'.format(correct_packets)
	# 		else:
	# 			print 'Sent Packet:'

	# 			print '0x'+' 0x'.join(a+b for a,b in zip(send[::2],send[1::2]))
	# 			print 'Received: '
	# 			print '0x'+' 0x'.join(a+b for a,b in zip(hexlify(actual)[::2],hexlify(actual)[1::2]))
	# 			print 'Expected: '
	# 			print '0x'+' 0x'.join(a+b for a,b in zip(recv[::2],recv[1::2]))
	# 	print 'Power Board Test Path Complete'

	# def test_to_cdh(self):
	# 	pass


	def run_full_test(self):
		print 'The Radio IB talks to only three devices: CDHIB, Power Board, and FC.'
		print 'We will be running 3 separate tests from Radio To {CDHIB,FC,PWB}'

		# Make sure Version of CDH IB on git is the version you are running!!
		latest_commit = check_output(['git','log','--pretty=format:"%h"']).split('\n')[0]
		print 'Latest commit is {}. Make sure the code being tested is ON THIS COMMIT!!!'.format(latest_commit)

		with open('../../cdhIB/src/config/conf_usart_serial.h','r') as f:
			test_cdh = (''.join(f.readlines()).split('MCU_CDH_2')[1]).split('#else')[0].split('\n')

		radio_uart	= ''
		fc_uart	= ''
		pwb_uart	= ''
		for config in test_cdh:
			if 'RADIO_UART' in config and radio_uart == '':
				radio_uart = config.split('\t')[-1]
			if 'FC_UART' in config and fc_uart == '':
				fc_uart = config.split('\t')[-1]
			if 'POWER_UART' in config and power_uart == '':
				pwb_uart = config.split('\t')[-1]

		print ''
		print 'Testing RADIO IB to FC'
		#self.test_to_fc(radio_uart,fc_uart)
		self.test_to_dest('fc',radio_uart,fc_uart,pwb_uart)

if __name__ == '__main__':
	print 'RadioPathTester Tester:\n'
	tester = RadioPathTester(serial.Serial(port='/dev/ttyUSB0',baudrate=9600,
		timeout=10))
	tester.run_full_test()
