
"""
@array test
@aim to access pic certain bit data
@ZZY   20180314
"""

import cv2 
import numpy as np
import sys

def main(argv):
    
    #Load Image in form of Grayscale
    filename = argv[0] if len(argv) > 0 else "../data/dig.jpg"
    print ("filename is ",filename)

    Img_gray = cv2.imread(filename,cv2.IMREAD_GRAYSCALE)

    if Img_gray is None :
        print("Error opening image!")
        return -1
    
    cv2.imshow("dig",Img_gray) #显示图像

    ## [Change color]
    img_collon ,img_row = Img_gray.shape  #找到图像大小


    ##[findContours]
    ret,thresh = cv2.threshold(Img_gray,127,255,0)
    image,contours,hierarchy = cv2.findContours(thresh,
        cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    color = cv2.cvtColor(Img_gray,cv2.COLOR_GRAY2BGR)
    img = cv2.drawContours(color,contours,-1,(255,0,0),2)
    cv2.imshow('contours',color)
    
    




if __name__ == "__main__":
    main(sys.argv[1:])

