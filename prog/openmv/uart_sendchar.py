# UART Control
#
# This example shows how to use the serial port on your OpenMV Cam. Attach pin
# P4 to the serial input of a serial LCD screen to see "Hello World!" printed
# on the serial LCD display.

import time
from pyb import UART

# Always pass UART 3 for the UART number for your OpenMV Cam.
# The second argument is the UART baud rate. For a more advanced UART control
# example see the BLE-Shield driver.
uart = UART(3, 115200)
uart.init (115200,bits = 8,parity = None, stop = 1)

while(True):
    for i in range (10):
        uart.writechar(i)
        #uart.write("\r")
    #uart.write("Hello World!\r")
        print (i,"\r")
    time.sleep(1000)
