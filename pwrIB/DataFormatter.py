print 'Starting Format'

inputfile = open('DSCHG2.txt')
outputfile = open('CHARGEFIX2.txt','w')

print 'Opened Files'

my_text = inputfile.readlines()
floatings = []

numbers = my_text[0].split()
for s in numbers:
	floatings.append(float(s))
#for str in my_text:
#	numbers = str.split()
#	for s in numbers:
#		floatings.append(float(s))
	


txt = 'VIOLET' 

print 'Data Formatted'

for jabar in range(len(floatings)-1):
	outputfile.writelines(`854+jabar` + ' ' + `floatings[jabar]` + '\n')

#outputfile.writelines(`floatings`)

print len(floatings)
print 'Data Written'

inputfile.close()
outputfile.close()

print 'Format Complete'