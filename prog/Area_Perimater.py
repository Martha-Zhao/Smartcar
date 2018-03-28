
"""
@Area_Perimater
@calculate the area and permater
@ZZY 20180328
"""

import cv2
import numpy as np
import glob as gb
import sys
import pdb

##def main(argv):
##    [Load Images]
##filename = gb.glob('../data/New_correct//*')
path = '../data/New_correct/8.png'
##for path in filename:
img = cv2.imread(path,cv2.IMREAD_GRAYSCALE)

if img is None:
    print ('Error in loading images!')
##        return -1
##[cut]
img_cut = img[20:-10,10:-10]

##[contours]
ret,contours,hie = cv2.findContours(img_cut,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
print (path[17:],'len(con ) is ',len(contours))
##[draw contours]
img_color = cv2.cvtColor(img_cut,cv2.COLOR_GRAY2BGR)
cv2.drawContours(img_color,contours,1,(0,0,255),3)
cv2.imshow('img_color',img_color)

##[calculate area]
area = cv2.contourArea(contours[1])
print ('Area is' ,area)

##[calculate perimeter]
perimeter = cv2.arcLength(contours[1],True)
print ('Perimeter is ',perimeter)
    




##if __name__ == 'main':
##    main(sys.argv[1:])
