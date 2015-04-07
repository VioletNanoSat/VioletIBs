import sys
import serial

def test_cdh_path(radioIB):
	pass

def test_radio_path(radioIB):
	pass
	
if __name__ == '__main__':
	print "Radio IB Testing Module"
	sys.path.append('../util/')

	# Default Values
	port		= '/dev/pts/25'
	baudrate	= 9600
	timeout		= 1
	path		= 'to_cdh'
	
	for sys_arg in sys.argv[1:]:
		split = sys_arg.split('=')
		if len(split) > 1:
			argument	= split[0].lower()
			value 		= split[1].upper()
			if 'port' in argument:
				port = split[1]
			elif 'baudrate' in argument:
				baudrate = int(value)
			elif 'path' in argument:
				path = value
			elif 'timeout' in argument:
				timeout = int(value)
			else:
				sys.exit('Unknown argument: {}'.format(argument))
		else:
			sys.exit('Incorrectly formatted system argument: {}'.format(sys_arg))

	radioIB = serial.Serial(port		= port,
							baudrate 	= baudrate,
							timeout 	= timeout,
							parity 		= serial.PARITY_NONE,
							bytesize 	= serial.EIGHTBITS)

	if 'cdh' in path:
		test_cdh_path(radioIB)
	elif 'radio' in path:
		test_radio_path(radioIB)
	else:
		sys.exit('Path not defined. Either <cdh> or <radio>')

	print "Full Radio Test Complete"
	
