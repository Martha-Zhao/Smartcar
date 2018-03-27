"""
@recognize.py
@according to the cut image without deliting recognize digitals
@ZZY  20180327
"""

import cv2
import numpy as np
import glob as gb
import sys
import pdb

def main(argv):
##    [Load original images]
    
    filename = gb.glob('../data/cut\/*')
##    print (len(filename))
    for path in filename:
##        print (path)
##        path = '../data/cut/7.jpg'
        img_src = cv2.imread(path,cv2.IMREAD_GRAYSCALE)
##        cv2.imshow('img_src',img_src)


##        [binarization]
        ret,img_bin = cv2.threshold(img_src,100,1,0)

        
##        [sum]
        sum_col = np.sum(img_bin,axis = 0)
        sum_row = np.sum(img_bin,axis = 1)


##        print (path,'len(sum_col) is ',len(sum_col))
##        print ('sum loc is ',sum_col)
##        print ('len(sum_row) is ',len(sum_row))
##        print ('sum_row is ',sum_row)

##        print (path,sum(sum_col),'\n\n')
##        [end sum]

##        [Focus]
        re_col = np.where (sum_col == max(sum_col))
        print (path,re_col,'len is ',len(sum_col))
        
##        re_row = np.where (sum_row == max(sum_row))
##        print (path,re_row,'len is ',len(sum_row))
        
    


if __name__ == '__main__':
    main(sys.argv[1:])
