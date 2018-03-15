
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
    filename = argv[0] if len(argv) > 0 else "../data/dig.jpg" #Load Image
    print ("filename is ",filename)

    Img_gray = cv2.imread(filename,cv2.IMREAD_GRAYSCALE) #read img in grayscale

    if Img_gray is None : #error in Load Image wrong
        print("Error opening image!")
        return -1
    
    cv2.imshow("dig",Img_gray) #Show Image

    img_collon ,img_row = Img_gray.shape  #Get Image shape(collon and row)

    ## [binary]
    #img_bin is the result of Binarization 
    ret,img_bin = cv2.threshold(Img_gray,127,255,0)
    cv2.imshow("img_bin",img_bin)
    
    image,contours,hierarchy = cv2.findContours(img_bin,
        cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)

    
    color = cv2.cvtColor(Img_gray,cv2.COLOR_GRAY2BGR)
    img = cv2.drawContours(color,contours,-1,(255,0,0),2)
    cv2.imshow('contours',color)
    
    




if __name__ == "__main__":
    main(sys.argv[1:])

