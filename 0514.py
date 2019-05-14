import sensor,time,image
from image import SEARCH_EX, SEARCH_DS
from pyb import UART
from pyb import Pin, LED

uart = UART(4, 115200,timeout=50,read_buf_len = 64)
#pin0 = Pin('P6', Pin.IN, Pin.PULL_NONE)
tag_families = image.TAG25H9
blue_led  = LED(3)
green_led = LED(2)
red_led   = LED(1)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA) # we run out of memory if the resolution is much bigger...
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)  # must turn this off to prevent image washout...
sensor.set_auto_whitebal(False)  # must turn this off to prevent image washout...
clock = time.clock()
time.sleep(200)
uart.writechar(254)
count = 0
num = 0

while(1):
    a = 0
    clock.tick()
    img = sensor.snapshot()
    blue_led.off()
    green_led.off()
    red_led.off()
    x_error = 0
    y_error = 0
    flag = 0
    for tag in img.find_apriltags(families=tag_families):
        count = count + 1
        x = tag.cx()
        if ((abs((80-tag.cx()))<20 and (tag.cy()<98))or (tag.cx()<55 and tag.cy()<25)) :
            img.draw_rectangle(tag.rect(), color = (255, 0, 0))
            img.draw_cross(tag.cx(), tag.cy(), color = (0, 255, 0))
            #print(tag.cx())
            #print(tag.cy())
            #print('Done')
            #break
            if tag.cy() < 60:
                num = 100 + tag.id()
                flag = 1
                x_error = 72 - tag.cx()
                y_error = 20 - tag.cy()
            else:
                num = 200 + tag.id()
                flag = 2
                x_error = 72 - tag.cx()
                y_error = 74 - tag.cy()
            break
            #green_led.on()
            #time.sleep(50)
    count = 0
    print('flag = ', flag)
    print('x_error = ', x_error)
    print('y_error = ', y_error)
    a = uart.read()
    ##a = b'B'
    if a == b'A':
        green_led.off()
        red_led.on()
        if x_error > 4:
            print('right')
            uart.writechar(14)
        elif x_error < -10:
            print('left')
            uart.writechar(13)
        elif flag == 1:
            if y_error > 4:
                print('down')
                uart.writechar(12)
            elif y_error < -4:
                print('up')
                uart.writechar(11)
            else:
                print(num)
                uart.writechar(num)
        elif flag == 2:
            if y_error > 4 or y_error < -10:
                print('down')
                uart.writechar(12)
            elif y_error < -4:
                print('up')
                uart.writechar(11)
            else:
                print(num)
                uart.writechar(num)



