# math_temp - By: ZZY - 周五 5月 4 2018
import sensor,time,image
from image import SEARCH_EX, SEARCH_DS
#0-w 1-h 2-l1-左上 3-r1-右上 4-c-中心 5-l2-左中  6-r2-右中 7-r3-右下 8-l-(x+4 y+18) 9-r-(w-4 y+10)
def mid (w,h):
    if w%2 == 1:
        w_m = int ((w + 1 )/2)
    else:
        w_m = int(w/2)
    if h%2 == 1:
        h_m = int ((h + 1)/2)
    else:
        h_m = int (h/2)
    return (w_m,h_m)

def filt (img,w,h,w_m,h_m):
    ##l1 左上   r1 右上 c 中心 l2 左中  r2  右中  r3 右下 l (x+4 y+18) r (w-4 y+10)

    l1 = (img.get_pixel(0,2) + img.get_pixel(0,3) + img.get_pixel(1,2) + img.get_pixel(1,3))/4
    r1 = (img.get_pixel(w-2,0) + img.get_pixel(w-2,1) + img.get_pixel(w-1,0) + img.get_pixel(w-1,1))/4
    c =  (img.get_pixel(w_m,h_m) + img.get_pixel(w_m,h_m+1) + img.get_pixel(w_m+1,h_m) + img.get_pixel(w_m+1,h_m+1))/4
    l2 = (img.get_pixel(1,h_m_1) + img.get_pixel(1,h_m) + img.get_pixel(2,h_m-1) + img.get_pixel(2,h_m))/4
    r2 = (img.get_pixel(w,h_m) + img.get_pixel(w-1,h_m-1) + img.get_pixel(w,h_m) + img.get_pixel(w,h_m-1))/4
    r3 = (img.get_pixel(w-3,h-3) + img.get_pixel(w-3,h-2) + img.get_pixel(w-2,h-3) + img.get_pixel(w-2,h-2))/4
    l =  (img.get_pixel(4,15) + img.get_pixel(4,16) + img.get_pixel(5,15) + img.get_pixel(5,16))/4
    r =  (img.get_pixel(w-4,10) + img.get_pixel(w-4,9) + img.get_pixel(w-3,10) + img.get_pixel(w-4,9))/4
    return ([l1,r1,c,l2,r2,r3,l,r])

def mac (para):
    if para[1]- para[0] > 10:
        return (1)
    elif para[2] > 200:
        return (7)
    elif para[3] > 200:
        return (5)
    elif para[7] > 200:
        return (2)
    elif para[6] > 200:
        return (0)
    elif para[5] > 200:
        return (9)
    elif para[8] > 200:
        return (8)
    elif para[9] > 200:
        return (3)
    elif para[4] > 200:
        return (6)
    else:
        return (4)

sensor.reset()
sensor.set_contrast(1)
sensor.set_gainceiling(16)
sensor.set_framesize(sensor.QVGA)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_auto_whitebal(False)

clock = time.clock()
cun_num = 0

while(True):
    clock.tick()
    img = sensor.snapshot()
    img.binary([(205,255)],invert = False)
    b = img.find_blobs([(205,255)],area_threshold = 150)
    i = 0
    cun = 0

    if cun_num < 40:
        cun_num = cun_num + 1
    else:
        for blob in b:
            if (blob.pixels() < 2000) and (blob.y() > 10):
                if (blob.y() < 100) and (blob.x() < 200) and (blob.x() > 100):
                    cun = cun + 1
                    R = (blob.x(),blob.y(),blob.w(),blob.h())
                    #img.draw_rectangle(R)
                    #print (blob)
                    if cun == 1:
                        #loc = "./" + str(4) + ".pgm"
                        a_1 = blob.x()
                    else :
                        #loc = "./" + str(3) + ".pgm"
                        a_2 = blob.x()
                        #print (blob)
                        #img.draw_rectangle(R)

                    loc = "./" + str(cun) + ".pgm"
                    cut = img.save(loc,roi = R)
                    time.sleep(40)
        print ("cun = ",cun)

    if cun_num > 30:
        src_1 = image.Image("/1.pgm")
        src_2 = image.Image("/2.pgm")

        w_1 = src_1.width()-1
        h_1 = src_1.height()-1

        w_2 = src_2.width()-1
        h_2 = src_2.height()-1
        [w_m_1,h_m_1] = mid(w_1,h_1)
        [w_m_2,h_m_2] = mid(w_2,h_2)

        para_1 = [w_m_1,h_m_1] + filt(src_1,w_1,h_1,w_m_1,h_m_1)
        para_2 = [w_m_2,h_m_2] + filt(src_2,w_2,h_2,w_m_2,h_m_2)

        ##l1 = src_1.get_pixel(0,0)
        ##r1 = src_1.get_pixel(w_1 - 1,0)
        ##c = src_1.get_pixel(w_m_1,h_m_1)
        ##l2 = src_1.get_pixel(0,h_m_1)
        ##r2 = src_1.get_pixel(w_1 - 1,h_m_1)
        ##r3 = src_1.get_pixel(w_1 - 1,h_1 - 1)
        ##l = src_1.get_pixel(4,18)
        ##r = src_1.get_pixel(w_1-4,10)
        #para = [w_1,h_1,l1,r1,c,l2,r2,r3,l,r]
        #print (para_2)

        num_1 = mac(para_1)
        #print("num_1 = ",num_1)
        num_2 = mac(para_2)
        #print("num_2 = ",num_2)

        if cun == 2:
            if a_1 < a_2:
                num = num_1 * 10 + num_2
            else :
                num = num_2 * 10 + num_1
        else:
            num = num_1
        print ("The num is ",num)





