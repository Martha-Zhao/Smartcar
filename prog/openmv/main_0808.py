import sensor,time,image
from image import SEARCH_EX, SEARCH_DS
from pyb import UART
from pyb import Pin
def filt (img,w,h,w_m,h_m):
    l1 = img.get_pixel(4,2)
    c =  img.get_pixel(w_m,h_m + 3)
    l2 = img.get_pixel(4,h-2)
    r2 = img.get_pixel(w-1,h-1)
    l3 = img.get_pixel(2,10)
    r3 = img.get_pixel(w-2,10)
    l4 = img.get_pixel(2,h-10)
    r4 = img.get_pixel(w-2,h_m+1)
    if (w > 16):
        temp = img.get_pixel(w - 13,11)
        r5 = img.get_pixel(w_m+5,h_m)
    else:
        r5 = 0
        temp = 0
    l5 = img.get_pixel(3,h-10)
    u2 = img.get_pixel(w - 1,1)
    n2 = img.get_pixel(w-4,h-5)
    return ([l1,c,l2,r2,l3,r3,l4,r4,r5,l5,u2,n2,temp])

def mac (para):
    if para[0] < 20 and para[1] - para[0] >= 15:
       return (1)
    elif para[3] == para[5] == 0 and para[7:14] == [255,255,255,0,255,0,255]:
        return (0)
    elif para[5:10] == [0,0,0,255,255] and para[11:14] == [255,0,255]:
        return (9)
    elif para[2] == 0 and para[6:11] == [0,0,0,0,0]:
        return (7)
    elif para[7:12] == [0,0,255,0,0]:
        return (5)
    elif para[2] == 0 and para[4:13] == [255,0,255,255,0,255,0,0,0]:
        return (5)
    elif para[3:] == [255,255,0,255,0,0,255,255,0,0,255,0]:
        return (5)
    elif para[2:8] == [255,0,255,0,0,0] and para[9:12] == [0,0,255]:
        return (2)
    elif para[2:14] == [255,0,0,0,0,0,0,0,0,0,0,255]:
        return (2)
    elif para[2:] == [0,0,255,0,0,0,255,0,0,255,255,255,0]:
        return (2)
    elif para[5:] == [0,255,0,0,0,0,255,0,255,0] or para[5:13] == [0,255,0,0,0,0,0,0]:
        return (3)
    elif para[9:12] == [0,0,255]:
        if para[14] == 0:
            return (3)
        else:
            return (2)
    elif para[2] == [0] and para[4:8] == [255,0,255,255] and para[9:11] == [0,255] and para[12:13] == [0,0]:
        return (4)
    elif para[3] == 255 and para[5:9] == [0,255,255,0] and para[11] == 0 and para[13] == 0:
        return (6)
    elif para[2] == 0 and para[4:8] == [255,0,0,255] and para[9:11] == [0,255] and para[12:14] == [0,0]:
        return (4)
    elif para[2:6] == [0,0,0,0] and para[7:11] == [255,0,0,255] and para[12:13] == [0,0]:
        return (4)
    elif para[5] == 0 and para[7:12] == [255,255,0,255,255]: #and (para[2] or para[3]) != 0:
        return (8)
    elif para[4:12] == [255,0,255,255,255,255,255,255]:
        return (8)
    elif para[3:14] == [255,0,0,255,255,0,0,255,255,0,255]:
        return (8)
    elif para[2:] == [255,255,0,0,255,255,255,255,255,255,0,255]:
        return (8)
    else :
        return (4)

uart = UART(3, 115200,timeout=50,read_buf_len = 64)
pin0 = Pin('P6', Pin.IN, Pin.PULL_NONE)
sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)
sensor.set_auto_whitebal(False)
clock = time.clock()
the = 84

clock.tick()
img = sensor.snapshot()
b = img.find_blobs([(the,255)],area_threshold = 150)
uart.writechar(254)
R_piece = (0,0,0,0)
while(True):
    error_piece_y = 0
    error_piece_x = 0
    error_roll = 0
    error_error = 0
    error_x = 0
    error_y = 0
    cun = 0
    a = 0
    b_pin = pin0.value()
    clock.tick()
    img = sensor.snapshot()
    img.binary([(the,255)],invert = False)
    b = img.find_blobs([(the,255)],area_threshold = 150)
    piece_flag = 0
    find_piece = 0
    for blob in b:
        if blob[4] > 800 and blob[4] < 3000 and blob[0] > 25 and blob[0] < 130 and blob[1] > 5 and blob[1] < 72 and blob[2] < 100 and blob[3] < 60 and find_piece != 1:
            R_piece = (blob.x(),blob.y(),blob.w(),blob.h())
            #img.draw_rectangle(R_piece)
            find_piece = 1
        elif blob[4] < 700 and blob[0] > 25 and blob[0] < 130 and blob[1] > 10 and blob[1] < 60 and blob[3] > 25:
            cun = cun + 1
            R = (blob.x(),blob.y(),blob.w(),blob.h())
            #img.draw_rectangle(R)
            if cun == 1:
                cut_1 = img.copy(roi = R)
                a_1 = blob.x()
                a_2 = blob.y()
                a_3 = blob.h()
                a_4 = blob.w()
            elif cun == 2:
                cut_2 = img.copy(roi = R)
                b_1 = blob.x()
                b_2 = blob.y()
                b_3 = blob.h()
                b_4 = blob.w()
            elif cun == 3:
                c_1 = blob.x()

    if find_piece == 1:
        error_piece_y = -30
        error_piece_x = 30
        for i_piece in range (R_piece[2]/2):
            if (piece_flag == 1):
                break
            for j_piece in range (R_piece[3]/2):
                temp_piece = img.get_statistics(roi = (R_piece[0]+i_piece * 2,R_piece[1]+j_piece * 2,28,25))
                if (temp_piece[4] == 255):
                    piece_flag = 1
                    error_piece_x = int(R_piece[0]+i_piece *2 - 65)
                    error_piece_y = int(R_piece[1]+j_piece *2 - 41)
                    break
        #print("error_piece_x = ",error_piece_x)
        #print("error_piece_y = ",error_piece_y)

    elif cun == 1:
        error_x = int((a_1 + a_4)/2  - 50)
        error_y = (a_2 - 45)
        #print ("error_x = ",error_x)
        #print ("error_y = ",error_y)

    elif cun == 2:
        if a_1 < b_1:
            error_roll = a_2 - b_2
            error_x = int((a_1 + a_4 + b_1)/2 - 89) + 4 * error_roll
            error_y = b_2 - 39 + error_roll
            error_error = b_1 - a_1 - a_4
            error_error_l = a_1
            error_error_r = 160 - b_1 - b_4
        else :
            error_roll = b_2 - a_2
            error_x = int((b_1 + b_4 + a_1)/2 - 89) + 4 * error_roll
            error_y = a_2 - 39 + error_roll
            error_error = a_1 - b_1 - b_4
            error_error_l = b_1
            error_error_r = 160 - a_1 - a_4
        #print("error_x = ",error_x)
        #print("error_y = ",error_y)
        #print("error_roll = ",error_roll)
        #print("error_error = ",error_error)
    if  b_pin == 1:
        if error_roll < -9:
            error_roll = -9
        elif error_roll > 9:
            error_roll = 9
        uart.writechar(150 + error_roll)
        #uart.writechar(150 + error_x)
        #uart.writechar(150 + error_y)
    else:
        a = uart.read()
        #a = b'B'
        if a == b'A':
            if find_piece == 1:
                if error_piece_y < -1:
                    uart.writechar(71)
                    uart.writechar(-error_piece_y + 100)
                elif error_piece_y > 20:
                    uart.writechar(72)
                    uart.writechar(error_piece_y + 100)
                elif error_piece_x < -21:
                    uart.writechar(73)
                    uart.writechar(-error_piece_x + 100)
                elif error_piece_x > 12:
                    uart.writechar(74)
                    uart.writechar(error_piece_x + 100)
                else:
                    uart.writechar(190 + error_piece_x)
                    uart.writechar(230 + error_piece_y)
            elif cun == 2:
                if error_error > 20:
                    if error_error_l - error_error_r > 0:
                        uart.writechar(73)
                        uart.writechar(140)
                    else:
                        uart.writechar(74)
                        uart.writechar(140)
                elif error_roll > 1:
                    uart.writechar(75)
                    uart.writechar(error_roll + 100)
                elif error_roll < -1:
                    uart.writechar(76)
                    uart.writechar(-error_roll + 100)
                elif error_y < -10:
                    uart.writechar(71)
                    uart.writechar(-error_y + 100)
                elif error_y > 10:
                    uart.writechar(72)
                    uart.writechar(error_y  + 100)
                elif error_x < -12:
                    uart.writechar(73)
                    uart.writechar(-error_x + 100)
                elif error_x > 12:
                    uart.writechar(74)
                    uart.writechar(error_x + 100)
                else:
                    w_1 = a_4 - 1
                    h_1 = a_3 - 1
                    w_2 = b_4 - 1
                    h_2 = b_3 - 1
                    para_1 = [w_1,h_1] + filt(cut_1,w_1,h_1,int(w_1/2),int(h_1/2))
                    para_2 = [w_2,h_2] + filt(cut_2,w_2,h_2,int(w_2/2),int(h_2/2))
                    num_1 = mac(para_1)
                    num_2 = mac(para_2)
                    if a_1 < b_1:
                        num = num_2 * 10 + num_1
                    else :
                        num = num_1 * 10 + num_2
                    uart.writechar(num)
            elif cun == 1:
                if error_x < -6:
                    uart.writechar(73)
                    uart.writechar(-error_x + 103)
                elif error_x > 6:
                    uart.writechar(74)
                    uart.writechar(error_x + 103)
                elif error_y < -11:
                    uart.writechar(71)
                    uart.writechar (-error_y + 100)
                elif error_y > 10:
                    uart.writechar(72)
                    uart.writechar(error_y + 100)
                else:
                    for i_single_right in range (27,50):
                        single_right = a_1 + a_4+ i_single_right + 2
                        temp_right = img.get_statistics(roi = (single_right,a_3 + a_2,2,2))
                        if (temp_right[5] > 200):
                            break
                    for i_single_left in range (27,50):
                        single_left = a_1- i_single_left - 7
                        temp_left = img.get_statistics(roi = (single_left,a_3 + a_2,2,2))
                        if (temp_left[5] > 200):
                            break
                    error_single = int((i_single_left - i_single_right)/3)
                    if error_single > -1 and error_single < 1:
                        for i_single_right in range (27,50):
                            single_right = a_1 + a_4+ i_single_right
                            temp_right = img.get_statistics(roi = (single_right,a_2,2,2))
                            if (temp_right[5] > 200):
                                break
                        for i_single_left in range (27,50):
                            single_left = a_1- i_single_left
                            temp_left = img.get_statistics(roi = (single_left,a_2,2,2))#(single_left,a_3 + a_2,5,2)
                            if (temp_left[5] > 200):
                                break
                        error_single = int((i_single_right - i_single_left)/2)
                    if error_single > 1:
                        uart.writechar(76)
                        uart.writechar(error_single + 100)
                    elif error_single < -1:
                        uart.writechar(75)
                        uart.writechar(-error_single + 100)
                    else:
                        w_1 = a_4 - 1
                        h_1 = a_3 - 1
                        para_1 = [w_1,h_1] + filt(cut_1,w_1,h_1,int(w_1/2),int(h_1/2))
                        num = mac(para_1)
                        uart.writechar(num)

            elif cun == 3:
                if c_1 - b_1 > b_1 - a_1:
                    uart.writechar(73)
                    uart.writechar(140)
                else :
                    uart.writechar(74)
                    uart.writechar(140)

        elif a == b'B':
            cun_block = 0
            R_block = (65,40,50,50)
            b = img.find_blobs([(the,255)],roi = R_block,area_threshold = 150)
            for blob in b:
                if blob[2] > 45:
                    cun_block = cun_block + 1
                    R = (blob.x()-1,blob.y(),blob.w()+2,blob.h())
                    x_l = blob[0] - 2
                    x_r = blob[0] + blob[2]
                    y_0 = blob[1]
            if cun_block == 1:
                error_block_x = R[0] + R[2] / 2 - 89.5
                error_block_y = R[1] + R[3] / 2 - 63.5
                stic_l = img.get_statistics(roi = (x_l,y_0,6,blob [3]))
                stic_r = img.get_statistics(roi = (x_r-6,y_0,6,blob [3]))
                error_l = (img.get_pixel(R[ 0],R[1]+R[3]) +img.get_pixel(R[0],R[1]+R[3] -1) +img.get_pixel(R[0] + 1,R[1]+R[3]) +img.get_pixel(R[0] + 1,R[1]+R[3] -1))/4
                error_r = (img.get_pixel(R[0] + R[2] - 1,R[1]+R[3]) +img.get_pixel(R[0] + R[2] - 1,R[1]+R[3] -1) +img.get_pixel(R[0] + R[2],R[1]+R[3]) +img.get_pixel(R[0] + R[2],R[1]+R[3] -1))/4
                if R[3] > 30:
                    if stic_l[0] <  stic_r[0]:
                        uart.writechar(75)
                    else :
                        uart.writechar(76)
                    uart.writechar(101)
                elif R[3] > 14:
                    if error_l > 200 and error_r < 200:
                        uart.writechar(75)
                    else:
                        uart.writechar(76)
                    uart.writechar(101)
                elif error_block_y < -10:
                    uart.writechar(71)
                    uart.writechar(108)
                elif error_block_y < -2:
                    uart.writechar(71)
                    uart.writechar(101)
                elif error_block_y > 15:
                    uart.writechar(72)
                    uart.writechar(108)
                elif error_block_y > 2:
                    uart.writechar(72)
                    uart.writechar(101)
                else:
                    uart.writechar(253)

