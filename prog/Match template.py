
"""
@Matching template
@ZZY 20180325

"""

import cv2
import numpy as np
import sys
import pdb

def main (argv):
            img_src = cv2.imread("../data/digital/3.bmp",cv2.IMREAD_GRAYSCALE)
            img_tem = cv2.imread("../data/temp/3.jpg",cv2.IMREAD_GRAYSCALE)

            w,h = img_tem.shape

            res = cv2.matchTemplate(img_src,img_tem,cv2.TM_CCOEFF)
            min_val,max_val,min_loc,max_loc = cv2.minMaxLoc(res)
            top_left = max_loc
            botton_right = (max_loc[0]+w,max_loc[1]+h)
            cv2.rectangle(img_src,top_left,botton_right,255,2)
            #pdb.set_trace()
            cv2.imshow('img',img_src)




if __name__ == "__main__":
            main(sys.argv[1:])

            
