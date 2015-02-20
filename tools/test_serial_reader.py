import serial
import binascii
import time

print 'Testing Module for Serial Reader'
client = serial.Serial(port='/dev/pts/13',baudrate=9600,parity=serial.PARITY_NONE)
to_send = 'c005180405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f2021222324c0'
ascii_str = binascii.unhexlify(to_send)
print 'Sending: ' + to_send + ' as: ' + ascii_str
print 'Chunk size should be: ' + str(len(ascii_str))
try:
	while 1:
		ret = client.write(ascii_str)
		raw_input('')
except KeyboardInterrupt:
	client.close()

print "Exiting"