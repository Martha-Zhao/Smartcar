
"""
@array test
@aim to access pic certain bit data
@ZZY   20180314
"""

import cv2 as cv
import numpy as np
import sys

def main(argv):
    
    #Load Image in form of Grayscale
    filename = argv[0] if len(argv) > 0 else "../data/dig.jpg"
    print ("filename is ",filename)

    Img_gray = cv.imread(filename,cv.IMREAD_GRAYSCALE)

    if Img_gray is None :
        print("Error opening image!")
        return -1
    
    cv.imshow("Lena",Img_gray)

    ## [Change color]
    




if __name__ == "__main__":
    main(sys.argv[1:])

