import plotly
import serial
import time
import datetime
import plotly.plotly as py
from plotly.graph_objs import Scatter, Layout, Figure
import time
from math import log10

username = 'openplantscience'
api_key = 'NKnew0HFk61TBOdLZGfg'
stream_token1 = '0gjylwkcfn'
stream_token2 = '92dhemrhv0'

py.sign_in(username, api_key)

trace1 = Scatter(
    x=[],
    y=[],
    stream=dict(
        token=stream_token1,
        maxpoints=200
    ),
    name = 'Cell 1'
)
trace2 = Scatter(
    x=[],
    y=[],
    stream=dict(
        token=stream_token2,
        maxpoints=200
    ),
    name = 'Cell 2'
)


layout = Layout(
    title='Raspberry Pi Streaming OD'
)

fig = Figure(data=[trace1, trace2], layout=layout)

print py.plot(fig, filename='Raspberry Pi Streaming OD')

index = 0
stream1 = py.Stream(stream_token1)
stream2 = py.Stream(stream_token2)
stream1.open()
stream2.open()

s = serial.Serial('/dev/ttyACM0', 9600)
s.isOpen()
time.sleep(5)

s.write("test")
file = open("ecoli_growth_3.csv", "a+")

try:
	while True:
		response = s.readline()
		timestamp = '{:%Y-%m-%d %H:%M:%S}'.format(datetime.datetime.now())
		file.write(timestamp + "," + response)
		print(response)
		values = response.split(',')
		values = [float(i) for i in values]
		ref_dark, c1_dark, c2_dark, ref_light, c1_light, c2_light = values
		OD_c1 = -log10((c1_light - c1_dark)/(ref_light - ref_dark))
		OD_c2 = -log10((c2_light - c2_dark)/(ref_light - ref_dark)) 

		stream1.write({'x': timestamp, 'y': OD_c1}, reconnect_on=(200,'',408))
		time.sleep(1)
                stream2.write({'x': timestamp, 'y': OD_c2}, reconnect_on=(200,'',408))
		index = index + 1
		for i in range(33):
			time.sleep(1)
			stream1.heartbeat()
			time.sleep(1)
			stream2.heartbeat()
			time.sleep(28)

except KeyboardInterrupt:
	file.close()
	s.close()
