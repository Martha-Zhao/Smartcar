# math_temp - By: ZZY - 周五 5月 4 2018
import sensor,time,image
from image import SEARCH_EX, SEARCH_DS

sensor.reset()
sensor.set_contrast(1)
sensor.set_gainceiling(16)
sensor.set_framesize(sensor.QQVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_auto_whitebal(False)

clock = time.clock()

#temp = image.Image("./1-11.pgm")
temp = image.Image("./temp.pgm")

while(True):
    clock.tick()
    img = sensor.snapshot()

    b = img.find_blobs([(233,255)],area_threshold = 150)
    i = 0
    for blob in b:
        if (blob.pixels() < 3000):
            img.draw_rectangle(blob.rect())
            i = i + 1
            #print ("i = ",i)
            #print (blob)
            R = (blob.x(),blob.y(),blob.w(),blob.h())
            loc = "./" + str(i) + ".pgm"
            #print(loc)
            cut = img.save(loc,roi = R)
            time.sleep(40)
    print ("i = ",i)
    time.sleep(1000)

    src = image.Image("./1.pgm")

    r = temp.find_template(src, 0.5, step=4, search=SEARCH_EX) #, roi=(10, 0, 60, 60))
    if r:
        img.draw_rectangle(r)
        print(r)
