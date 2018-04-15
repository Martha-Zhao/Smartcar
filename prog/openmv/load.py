# Untitled - By: ZZY - 周六 4月 14 2018

import sensor, image, time

def rgb2gray (rgbFram):
    #grayFram = rgbFram
    #sensor.set_pixformat(sensor.GRAYSCALE)
    img_gray = sensor.snapshot()
    for x in range (0,rgbFram.width()):
        for y in range (0,rgbFram.height()):
            rgb = rgbFram.get_pixel(x,y)
            gray = image.rgb_to_grayscale(rgb)
            img_gray.set_pixel(x,y,gray)
            #grayFram[x,y] = gray
    a = img_gray.get_pixel(10,10)
    print(a)
    return img_gray
            



path = "0.bmp"
img = image.Image(path,copy_to_fb = True)

sensor.reset()
sensor.set_framesize(sensor.QVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.skip_frames(10)
img_gray = sensor.snapshot()

#sensor.flush()

#time.sleep(100)

#roi = (10,10,10,10)
#thres = (49,174)
while(True):

    #clock.tick()
    
    #img_gray = sensor.snapshot()
    #a = img.get_pixel(10,10)
    #i = rgb2gray(img)
    #time.sleep(100)
    #img.draw_rectangle(roi)
    #img = image.Image(path,copy_to_fb = True)
    #a = img.get_pixel(10,10)
    #b = image.rgb_to_grayscale(a)
    #bloc = img.find_blobs(thres)
    #roi = blob.rect()
    #img.draw_rectangle(roi)
    #a = img.width()
    
    for i in range(0,img.width()):
        for j in range(0,img.height()):
           a = img.get_pixel(i,j) 
           g = image.rgb_to_grayscale(a)
           img_gray.set_pixel(i,j,g)
    
    iii = image.copy(img_gray)
    b = img_gray.get_pixel(10,10)
    print(b)
