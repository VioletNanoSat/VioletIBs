import sys

port 		= None
baudrate 	= None
timeout 	= None

def test_fc_path():
	pass

def test_radio_path():
	pass

def test_power_board_path():
	pass

def test_gps_path():
	pass

def test_sun_sensor_path():
	pass

def test_star_tracker_path():
	pass

'''
Sys.argv follows the same patterns as the serial reader.

port		= the port we will use to test specific pathways of the CDHIB
baudrate	= the baudrate being used 
path 		= the path being tested
MCU 		= Which MCU path it is
'''
if __name__ == '__main__':
	print "CDH IB Tester"

	# Default Values

	port 		= '/dev/pts/14'
	baudrate 	= 9600
	timeout 	= 1
	path 		= 'fc'

	for sys_arg in sys.argv[1:]:
		split = sys_arg.split('=')
		if len(split) > 1:
			argument = split[0].lower()
			value = split[1].lower()
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

	if 'fc' in path:
		test_fc_path()
	elif 'radio' in path:
		test_radio_path()
	elif 'power' in path:
		test_power_board_path()
	elif 'gps' in path:
		test_gps_path()
	elif 'sun' in path:
		test_sun_sensor_path()
	elif 'star' in path:
		test_star_tracker_path()
	else:
		sys.exit('Unknown test path: {}'.format(path))
	print 'Test Complete'