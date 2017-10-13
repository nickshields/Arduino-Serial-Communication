import serial, time
arduino = serial.Serial('/dev/cu.usbmodem1421', 115200, timeout=.1)
time.sleep(1) #give the connection a second to settle

while True:
        data = arduino.readline()
        if data:
                print data.split() #strip out the new lines for now
                # (better to do .read() in the long run for this reason
