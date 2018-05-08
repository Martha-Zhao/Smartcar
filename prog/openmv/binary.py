# Untitled - By: ZZY - 周二 5月 8 2018

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()
th = (245,255)
while(True):
    clock.tick()
    img = sensor.snapshot()
    img.binary([th],invert = False)
    print(clock.fps())
