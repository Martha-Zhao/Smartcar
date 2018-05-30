# Untitled - By: ZZY - 周三 5月 30 2018

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()
cun_num = 0
the = 170  #二值化阈值

while(True):
    clock.tick()
    img = sensor.snapshot()

    i = 0
    cun = 0

    if cun_num < 40:
        cun_num = cun_num + 1
    else:
        img.binary([(the,255)],invert = False)
        b = img.find_blobs([(the,255)],area_threshold = 150)
        for blob in b:
            #if (blob.pixels() < 2000) and (blob.y() > 10):
            if (blob.y() > 10):
                if (blob.y() < 100) and (blob.x() < 200) and (blob.x() > 100):
                    cun = cun + 1
                    R = (blob.x(),blob.y(),blob.w(),blob.h())
                    img.draw_rectangle(R)
                    print (blob)
                    if blob.pixels() > 1060:
                        the = the + 5
                    elif blob.pixels() < 1000:
                        the = the - 5
                    else:
                        print ("the = ",the)
                    time.sleep(40)
        #print ("cun = ",cun)
        print (the)
