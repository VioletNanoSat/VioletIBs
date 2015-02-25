import sys
from subprocess import check_output
from binascii import unhexlify

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
			ret = []
			ret.append('18ffdead')
		elif 'pwb' in path:
			pass
		elif 'cdh' in path:
			pass
		else:
			Sys.exit('Path is invalid: ' + path)

		return map(unhexlify,[wrap_vcp(entry,path) for entry in ret])

	def test_to_fc(self,radio_uart,fc_uart):
		print 'The Radio UART is located at {r}. The FC UART is located at {f}'.format(r=radio_uart,f=fc_uart)
		print 'Connect the RX pin of the RS-232 spare to the RX of the Radio UART.'
		print 'Connect the TX pin of the RS-232 spare to the TX of the FC UART'
		raw_input('Press Enter to continue')
		radio_packets = self.populate_radio_packets('fc')
		print radio_packets

	def test_to_pwb(self):
		pass

	def test_to_cdh(self):
		pass

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
		power_uart	= ''
		for config in test_cdh:
			if 'RADIO_UART' in config and radio_uart == '':
				radio_uart = config.split('\t')[-1]
			if 'FC_UART' in config and fc_uart == '':
				fc_uart = config.split('\t')[-1]
			if 'POWER_UART' in config and power_uart == '':
				power_uart = config.split('\t')[-1]

		print ''
		print 'Testing RADIO IB to FC'
		self.test_to_fc(radio_uart,fc_uart)

if __name__ == '__main__':
	print 'RadioPathTester Tester:\n'
	tester = RadioPathTester(None)
	tester.run_full_test()
