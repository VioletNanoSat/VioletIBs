import sys
from subprocess import check_output

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

	RS-232 Spare Layout:
	RX	..	TX
	CTS	..	RTS
	'''
	def __init__(self,serial):
		self.test_port = serial

	def test_to_fc(self):
		pass

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
