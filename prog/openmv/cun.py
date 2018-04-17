# Untitled - By: ZZY - 周六 4月 14 2018

import sensor, image, time

sensor.reset()
sensor.set_framesize(sensor.QVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.skip_frames(10)
sensor.set_auto_whitebal(False)
#img = sensor.snapshot()

R = (101,18,130,94)
thre = (46, 81, -44, 20, -83, 21)
th = (58, 215)

while(True):
    time.clock()
    cun = 0
    img = sensor.snapshot()
    b = img.find_blobs([th],roi = R, invert = True)
    for blob in b:
        img.draw_rectangle(blob.rect())
        for i in range (blob[0],(blob[0]+blob[2])):
            for j in range (blob[1],(blob[1]+blob[3])):
                t = img.get_pixel(i,j)
                #print(t)
                #print('\n')
                if t > 100:
                    cun = cun+1

    print(cun)
    print('\n')
