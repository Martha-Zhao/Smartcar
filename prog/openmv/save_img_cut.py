# Save_Image - By: ZZY - 周四 5月 3 2018

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    cut = img.save("/t.pgm",roi = (5,5,10,10),quality = 50)
    time.sleep(100)

    temp = image.Image("/t.pgm")
    print (temp.size())
