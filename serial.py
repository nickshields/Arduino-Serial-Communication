import time
from serial import serial
arduino = serial.Serial('/dev/cu.usbmodem1421', 115200, timeout=.1)
time.sleep(3) #give the connection a second to settle

command = {'Power': '1637937167\n',
        'Input': '1637922887\n',
        'Volume_Up': '1637888207\n',
        'Volume_Down': '1637920847\n',
        }

while True:
        data = arduino.readline()
        if data:
                print(data) #strip out the new lines for now
                # (better to do .read() in the long run for this reason
