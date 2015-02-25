'''
Serial Reader for Violet for use during Simulated Communications

This module is aimed primarily for use as a debugging tool during Violet's
Simulated Communications Pre-integration Review (PIR) test. 

Usage:
	There are three links that we would like to read serial data from:
	RADIO <--> RADIOIB <--> CDHIB <--> FC

	We will use 3 instances of this program with some hardware to read data at each
	stage of the test. I imagine we will see all packets going either way in all 
	links, but I am not sure. 

	RADIO <--> RADIOIB:
	For the Radio to the Radio IB link, we will use a female-female socket stripped
	at one end, the STK600, and as RS-232 to USB cable to to read packets.
	The stripped end of the socket will connect to the RX coming out of the 
	Radio breakout board. The socket end will connect to the TX pin of the STK600.
	The STK600 will then be powered on and connected to the computer running this
	code. 

	Look at the device manager to see which port corresponds to the connected
	cable. On Unix-like systems, this can be achieved by running::
		$ dmesg | grep tty 
	in the terminal. This will be the port argument to the python
	program. 

	To then read from this link, simply run::

		$ cd /dir/to/serial_reader
		$ python serial_reader.py port=port_arg chunk_size=?? message=RADIO\ TO\ RADIOIB

	The chunk size will be determined based on the packet the GS sends to the Radio.
	Calculate accordingly for each link. Additional arguments such as baudrate, parity,
	and bytesize may also be provided to override default behavior.

	RADIOIB <--> CDHIB:
	For the Radio IB to the CDHIB link, we will need the Y-splitter that lies on a
	breadboard and a RS-422 to USB converter. Again, once plugged in, make sure
	you use a device manager to determine on which port the converter resides.
	This will be the port argument to the program that reads this link. Run the
	program as described above, simply changing the port_arg and chunk_size and
	updating the message to be message=RADIOIB\ TO\ CDHIB

	CDHIB <--> FC:
	For the CDHIB to FC link, connect a DB9 cable to another RS-422 to USB 
	converter. Connect the other end of the DB9 cable to the CDH2 to FC connection
	on the EGSE. Locate the port that maintains that connection. This will be the
	port argument to the program that reads this link. Run the program as 
	described above, simply changing the port_arg and chunk_size and
	updating the message to be message=CDHIB\ TO\ FC.

	This setup allows reading all packets as they route through the Violet Power's
	hardware. However, to test this code, another setup is required.

Testing:
	Testing on a Unix-like computer requires certain tools.
	setuptools	- on linux systems, install setuptools by running in a terminal:
		wget https://bootstrap.pypa.io/ez_setup.py -O | sudo python
				- on Mac systems, install setuptools by running in a terminal:
		curl https://bootstrap.pypa.io/ez_setup.py -o - | sudo python

		This is only required once. Once you have it installed, you should be able
		to run easy_install in your terminal. You might need sudo if you actually
		want to be able to install packages.

	termcolor	- with setuptools, run: easy_install termcolor. You might need to 
		run it as superuser, so if that doesn't work, 
		run: sudo easy_install termcolor.
		Once that's done, open up a python interpreter and make sure termcolor is
		installed by making sure 'import termcolor' throws no errors once evaluated
		in the interpreter. If there are any other modules missing, install them in
		a similar manner.

		This is only required once. If you have already installed termcolor, 
		just skip to running socat in its own terminal window.

	socat		- On *buntu computers run sudo apt-get install socat.
				- On Macs, follow the instructions on this website:
		http://www.xappsoftware.com/wordpress/2013/10/10/how-to-run-socat-on-mac-os-x/

		Once installed, run <socat -d -d pty,raw,echo=0 pty,raw,echo=0> in a terminal
		This creates a virtual serial port pair that we can test.
		socat will tell you the locations of both ports in a message 
		like <date> <time> socat[#####] N PTY is /dev/pts/xx. The /dev/pts/xx, where 
		the xx's are two numbers, is the port identifier, whichc we will call port_id.

		There will be two such messages, one for each end of the virtual
		serial port. You can then initialize the Serial Reader on one end
		of the virtual serial port. Pick the first serial port just to be consistent
		whenever you test.

		To initialize the serial reader, open a *new* terminal, <cd> to the directory
		which contains the python code, and run:
		python serial_reader.py port=port_id message=TESTING\ VIRTUAL\ PORTS
		where port_id is the first port identifier given by socat. 

		Then, open another terminal and run:
		python test_serial_reader port=port_id2
		where port_id2 is the second identifier given by socat
		Every time you want to send a packet, press enter at the prompt and a
		packet should appear in the serial_reader terminal. If not, debug baby.

		To experiment further, try changing the chunk_size for the readers and 
		testers to see which packets come in and out.

@author Akshay Dongaonkar
@email akd54@cornell.edu
'''


import sys
from binascii import hexlify
from time import sleep

import serial
from termcolor import colored

sys.path.append('../util/')
from vcp import *
from lithium import *

class LinkReader:
	'''
	SerialReader class that reads internal Violet packets.

	As described above, this class reads data from data links during the 
	Simulated Communications test and pretty prints them in the terminal
	for easy debugging.

	'''

	colors=['red','green','yellow','blue','magenta','cyan']




	def __init__(self,port,chunk_size,link_message,baudrate=9600,timeout=1,
			parity=serial.PARITY_NONE,bytesize=serial.EIGHTBITS):
		'''
		Initializer that creates and open a serial port with described arguments.

		Note:
			All arguments but the chunk_size argument are used to initialize the
			serial port reader.

		Args:
			port (str): Name of port to read
			chunk_size: The packet size coming in if constant
			link_message (string): Describes the link being read
			baudrate (int, optional): Passed to serial Initializer
			timeout (int, optional): Passed to serial Initializer
			parity (str,optional): Passed to serial Initializer
			bytesize (str,optional): Passed to serial Initializer
		'''
		self.chunk_size = chunk_size
		if port:
			self.reader = serial.Serial(port=port,
										baudrate=baudrate,
										timeout=timeout,
										parity=parity,
										bytesize=bytesize)
		else:
			self.reader = None

		self.link_message 	= link_message
		self.received 		= 0
		print colored('Connected to: ' + self.reader.portstr,'yellow')

	def pretty_print(self,datum):
		self.received = self.received + 1

		current_color 	= self.colors[self.received % len(self.colors)]
		prev_color 		= self.colors[(self.received - 1) % len(self.colors)]
		
		print colored('='*80,current_color)
		if self.link_message != '':
			print colored(self.link_message,current_color)

		msg_info = 'Message Size: ' + str(len(datum))+ '. Received: ' + str(self.received)
		print colored(msg_info,current_color)
		print ''

		hex_rep = hexlify(datum)
		hex_to_screen = '0x'+' 0x'.join(a+b for a,b in zip(hex_rep[::2],hex_rep[1::2]))
		print colored('Message:',current_color)
		byte_offset = 0
		for entry in [hex_to_screen[i:i+80] for i in range(0,len(hex_to_screen),80)]:
			byte_string = ''.join([' {}'.format(byte_offset+i)+' '*(5-len(' {}'.format(byte_offset+i))) for i in range(byte_offset,byte_offset+16)])
			print colored(byte_string,prev_color)
			print colored(entry,current_color)
			print ''
			byte_offset = byte_offset + 8 # literally no clue why this is 8 and not 16, but it works lol!!!!
		#End pretty print

		print colored('='*80,current_color)
		print '\n'


	def serial_read_fixed_packet_length(self):
		'''
		Read, format, and pretty-print all serial data read that is chunk_size long.

		To exit serial collection, press Ctrl+c to raise a 
		KeyboardInterrupt. 
		'''
		print colored('Enter Ctrl+c to exit collection','red')
		sleep(0.3)
		print colored('Reading','blue',attrs=['blink'])
		try:
			while 1:
				datum = self.reader.read(self.chunk_size)
				if len(datum) > 0:
					self.pretty_print(datum)
		except KeyboardInterrupt:
			pass

	def serial_read_variable_packet_length(self,packet_type):
		try:
			if 'vcp' in packet_type:
				while 1:
					escape = self.reader.read()
					if escape != VCP_ESCAPE:
						if escape != '':
							print colored('PACKET DOES NOT START WITH FEND','red')
						continue
					packet = [escape]
					next_byte = None
					while next_byte != VCP_ESCAPE:
						next_byte = self.reader.read()
						packet.append(next_byte)
					datum = ''.join(packet)
					self.pretty_print(datum)
			elif 'lithium' in packet_type:
				while 1:
					h = self.reader.read()
					if h != LI_H:
						print colored('Li SYNC H DOES NOT MATCH','red')
						continue
					packet = [h]

					e = self.reader.read()
					if e != LI_e:
						print colored('Li SYNC e DOES NOT MATCH','red')
						continue
					packet.append(e)

					li_type = self.reader.read(2)
					packet.append(li_type)

					size_1 	= self.reader.read()
					size_2 	= self.reader.read()
					packet.append(size_1)
					packet.append(size_2)

					size 	= (ord(size_1) << 8) + ord(size_2)

					chk_a 	= self.reader.read()
					chk_b 	= self.reader.read()
					packet.append(chk_a)
					packet.append(chk_b)

					payload = self.reader.read(size)
					packet.append(payload)

					payload_chk_a = self.reader.read()
					payload_chk_b = self.reader.read()
					packet.append(payload_chk_a)
					packet.append(payload_chk_b)

					datum = ''.join(packet)
					self.pretty_print(datum)

			else:
				print colored('Unknown packet type','red')
		except KeyboardInterrupt:
			pass

	def get_serial_object(self):
		''' Returns serial object in a closed state '''
		self.reader.close()
		return self.reader()


if __name__ == '__main__':
	print 'Link Reader Module'

	# DEFAULT INITIALIZERS
	port 			= '/dev/pts/14'
	baudrate 		= 9600
	timeout 		= 5
	parity 			= serial.PARITY_NONE
	bytesize 		= serial.EIGHTBITS
	chunk_size 		= 9
	link_message 	= 'No message supplied' 
	packet_type 	= ''
	windows			= False

	# Parse System Arguments
	if len(sys.argv) > 1:
		for i in range(1,len(sys.argv)):
			split = sys.argv[i].split("=")
			if len(split) > 1:
				serial_arg = split[0].lower()
				serial_val = split[1].lower()
				if serial_arg == 'port':
					port = split[1]
					print port
				elif serial_arg == 'baudrate':
					baudrate = int(serial_val)
				elif serial_arg == 'timeout':
					timeout = int(serial_val)
				elif serial_arg == 'parity':
					if 'none' in serial_val:
						parity = serial.PARITY_NONE
					elif 'even' in serial_val:
						parity = serial.PARITY_EVEN
					elif 'odd' in serial_val:
						parity = serial.PARITY_ODD
					elif 'mark' in serial_val:
						parity = serial.PARITY_MARK
					elif 'space' in serial_val:
						parity = serial.PARITY_SPACE
					else:
						print colored('Unknown Parity','red')
						raise ValueError
				elif serial_arg == 'bytesize':
					if 'five' in serial_val:
						bytesize = serial.FIVEBITS
					elif 'six' in serial_val:
						bytesize = serial.SIXBITS
					elif 'seven' in serial_val:
						bytesize = serial.SEVENBITS
					elif 'eight' in serial_val:
						bytesize = serial.EIGHTBITS
					else:
						print colored('Unknown Bytesize','red')
						raise ValueError
				elif serial_arg == 'chunk_size':
					if 'variable' in serial_val:
						chunk_size = None
					else:
						chunk_size = int(serial_val)
				elif serial_arg == 'message':
					link_message = split[1]
				elif serial_arg == 'packet_type':
					if 'vcp' in serial_val:
						packet_type = 'vcp'
					elif 'lithium' in serial_val:
						packet_type = 'lithium'
					else:
						print colored('Invalid Packet Type','red')
						raise ValueError
				elif serial_arg == 'windows':
					if 'true' in serial_val:
						windows = True 
					else:
						windows = False 
				else:
					print colored("Unknown arg",'red')
					raise ValueError
			else:
				print colored("Unformatted Arguments",'red')
				raise ValueError

	if windows:
		import colorama
		colorama.init()


	listener = LinkReader(port,chunk_size,link_message,
		baudrate,timeout,parity,bytesize)

	if chunk_size:
		listener.serial_read_fixed_packet_length()
	else:
		if packet_type != 'vcp' and packet_type != 'lithium':
			print colored('Packet Type not specified','red')
			print colored('If reading variable length packets, please specify packet type','red')
		else:
			listener.serial_read_variable_packet_length(packet_type)

	print 'End Link Reader Module'

