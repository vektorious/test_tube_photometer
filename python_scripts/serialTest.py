import serial
import time
import datetime

s = serial.Serial('/dev/ttyACM0', 9600)
s.isOpen()
time.sleep(5)

s.write("test")
file = open("first_data.csv", "a+")
try:
	while True:
		response = s.readline()
		timestamp = '{:%Y-%m-%d_%H:%M:%S}'.format(datetime.datetime.now())
		print(timestamp)
		file.write("Reference," + response)
		print(response)

except KeyboardInterrupt:
	file.close()
	s.close()
