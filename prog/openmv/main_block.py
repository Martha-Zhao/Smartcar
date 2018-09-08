import sensor,time,image
from image import SEARCH_EX, SEARCH_DS
from pyb import UART
from pyb import LED

uart = UART(3, 115200)
uart.init (115200,bits = 8,parity = None, stop = 1)

red_led   = LED(1)

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_whitebal(False)

clock = time.clock()
cun_num = 0
cun = 0
the = 146
flag = 1
a = 0
te = 1

while(True):
    i = 0
    cun = 0
    if (a == 0):
        clock.tick()
        img = sensor.snapshot()
        img.binary([(the,255)],invert = False)
        #img.draw_rectangle(R_block)
        R_block = (65,40,50,50)
        b = img.find_blobs([(the,255)],roi = R_block,area_threshold = 150)
        for blob in b:
            if blob[2] > 45:
                cun = cun + 1
                R = (blob.x()-2,blob.y()-2,blob.w()+4,blob.h()+4)
                x_l = blob[0] - 2
                x_r = blob[0] + blob[2]
                y_0 = blob[1]
                img.draw_rectangle(R)
        print("cun == ",cun)
        if cun == 1:
            error_block_x = R[0] + R[2] / 2 - 89.5
            error_block_y = R[1] + R[3] / 2 - 63.5
            print("error_block_x = ",error_block_x)
            print("error_block_y = ",error_block_y)
            stic_l = img.get_statistics(roi = (x_l,y_0,6,blob [3]))
            stic_r = img.get_statistics(roi = (x_r-6,y_0,6,blob [3]))
            error_l = (img.get_pixel(R[0],R[1]+R[3]) +img.get_pixel(R[0],R[1]+R[3] -1) +img.get_pixel(R[0] + 1,R[1]+R[3]) +img.get_pixel(R[0] + 1,R[1]+R[3] -1))/4
            error_r = (img.get_pixel(R[0] + R[2] - 1,R[1]+R[3]) +img.get_pixel(R[0] + R[2] - 1,R[1]+R[3] -1) +img.get_pixel(R[0] + R[2],R[1]+R[3]) +img.get_pixel(R[0] + R[2],R[1]+R[3] -1))/4
            if R[3] > 30:
                if stic_l[0] < stic_r[0]:
                    uart.writechar(75)
                    print("TL")
                else :
                    uart.writechar(76)
                    print("TR")
                uart.writechar(101)
            elif R[3] > 14:
                if error_l > 200 and error_r < 200:
                    uart.writechar(75)
                    print("TL")
                else:
                    uart.writechar(76)
                    print("TR")
                uart.writechar(101)
            elif error_block_y < -1:
                print("forard")
                uart.writechar(71)
                uart.writechar(101)
            elif error_block_y > 15:
                print("backward 108")
                uart.writechar(72)
                uart.writechar(108)
            elif error_block_y > 1:
                print("backward")
                uart.writechar(72)
                uart.writechar(101)
            else:
                print("block")
                uart.writechar(253)

