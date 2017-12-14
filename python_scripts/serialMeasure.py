import serial
import time
import datetime


s = serial.Serial('/dev/ttyACM0', 9600)
s.isOpen()
time.sleep(5)

s.write("test")
file = open("ecoli_growth.csv", "a+")
try:
	while True:
		response = s.readline()
		timestamp = '{:%Y-%m-%d_%H:%M:%S}'.format(datetime.datetime.now())
		file.write(timestamp + "," + response)
		print(response)

except KeyboardInterrupt:
	file.close()
	s.close()
