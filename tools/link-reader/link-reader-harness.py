'''
Tester for SerialReader.

This module implements the test case for serially reading data during
Violet's Simulated Communications test. We spoof a defined packet
(constructed via the field message) and send it into the serial port
to which the reader is connected. We then verify the functionality
of the SerialReader.

@author Akshay Dongaonkar
@email akd54@cornell.edu

'''



from serial import *
from binascii import unhexlify
from time import sleep

import sys

class LinkReaderTester:
	'''
	Creates a new Serial Reader tester given a serial port and message.

	The user can then manually or periodically send the message over
	the serial port.
	'''
	def __init__(self,port,message='c005180304050607c0'):
		self.server = Serial(
			port=port,
			baudrate=9600,
			parity=PARITY_NONE,
			bytesize=EIGHTBITS,
			timeout=1)
		if len(message) % 2 != 0:
			print 'Invalid Message'
			raise ValueError
		self.message = unhexlify(message)
		print 'Sending chunks of size {}'.format(len(self.message))
		print 'Make sure Link Reader has proper chunk value.'

	def send_individually(self):
		try:
			while 1:
				raw_input('Press enter to send message')
				self.server.write(self.message)
		except KeyboardInterrupt:
			pass

	def send_periodically(self,period):
		try:
			while 1:
				self.server.write(self.message)
				sleep(period)
		except KeyboardInterrupt:
			pass

	def send_variable_length_packets(self,packet_type):
		if 'vcp' in packet_type:
			pass
		elif 'lithium' in packet_type:
			pass
		else:
			print 'Unknown packet type to send. Returning.'


if __name__ == '__main__':
	print 'Link Reader Testing Module'

	# DEFAULT INITIALIZERS
	port = '/dev/pts/13'
	message = 'c005180304050607c0'

	if len(sys.argv) > 1:
		for i in range(1,len(sys.argv)):
			split = sys.argv[i].split('=')
			if len(split) > 1:
				if 'port' in split[0]:
					port = split[1]
				elif 'message' in split[0]:
					message = split[1]
				else:
					print 'Unknown arg'
					raise ValueError
			else:
				print 'Unformatted Argument'
				raise ValueError

	tester = LinkReaderTester(port,message)
	tester.send_individually()
	print 'End Link Reader Testing Module'