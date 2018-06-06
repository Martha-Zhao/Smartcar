# math_temp - By: ZZY - 周五 5月 4 2018
import sensor,time,image
from image import SEARCH_EX, SEARCH_DS
#from pyb import UART
#from pyb import LED

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_whitebal(False)

clock = time.clock()
cun_num = 0
the = 195

while(True):
    clock.tick()
    img = sensor.snapshot()
    img.binary([(the,255)],invert = False)
    b = img.find_blobs([(the,255)],area_threshold = 150)
    i = 0
    cun = 0

    for blob in b:
        if (blob.pixels() < 2000)and (blob.pixels() > 400)and (blob.y() > 10) and (blob.y() < 130) and (blob.x() < 200) and (blob.x() > 60):
            cun = cun + 1
            R = (blob.x(),blob.y(),blob.w(),blob.h())
            #img.draw_rectangle(R)
            if cun == 1:
                loc = "./" + "2-2" + ".pgm"
                a_1 = blob.x()
            else :
                loc = "./" + "7-2" + ".pgm"
                a_2 = blob.x()

            #loc = "./" + str(cun) + ".pgm"
            cut = img.save(loc,roi = R)
            #time.sleep(10)
    print ("cun = ",cun)
