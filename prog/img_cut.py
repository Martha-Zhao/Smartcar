
"""
@img_cut.py
@Cut Image
@ZZY 20180326
"""
import cv2
import numpy as np
import sys
import pdb


def main(argv):
    
    img_src = cv2.imread('../data/des/0.bmp',cv2.IMREAD_GRAYSCALE)
    cv2.imshow('img_src',img_src)
    ret,img_bin = cv2.threshold (img_src,100,1,0)
    sum_col = sum(img_bin)
    sum_row = np.sum(img_bin,axis = 1)
    print (sum_row)
    loc_left = 0
    loc_right = 0
    loc_top = 0
    loc_buttom = 0

    for i in range(len(sum_col)-1):
        if sum_col[i] < 60 and sum_col[i-1] > 80:
            loc_left = i
        if sum_col[i] < 60 and sum_col[i+1] > 80:
            loc_right = i

    print ('loc_left is ',loc_left)
    print ('loc_right is ', loc_right)

    for i in range(len(sum_row)-1):
        if sum_row[i] < 100 and sum_row[i-1] > 100 and i<60:
            loc_top = i
        if sum_row[i] < 100 and sum_row[i+1] > 100:
            loc_bottom = i

    print ('loc_top is ',loc_top)
    print ('loc_bottom is ',loc_bottom)

    

    img_cut = img_src[loc_top+5:loc_bottom-5,loc_left+5:loc_right-5]
    cv2.imshow('img_cut',img_cut)





if __name__ == "__main__":
    main(sys.argv[1:])
