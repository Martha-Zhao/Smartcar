
"""
@harris conner
@detect conner with Harris 
@ZZY 20180322
"""

import cv2
import numpy as np
import sys
import pdb

def main(argv):
    ##[Load Image]
    filename = argv[0] if len(argv) >0 else "../data/digital/0.bmp"
    print (filename)

    img_src = cv2.imread(filename,cv2.IMREAD_GRAYSCALE)
    if img_src is None :
        print ("Error in loading Image!")
        return (-1)
    cv2.imshow("img_src",img_src)
    col,row = img_src.shape

    ##[Binarize]
    ret,img_bin = cv2.threshold(img_src,115,255,0)
    

    ##[Correct the trapzitium distortion]
    src_dis = np.array([[0,0],[0,0],[0,0],[0,0]],dtype = np.float32)
    des_dis = np.array([[0,0],[0,0],[0,0],[0,0]],dtype = np.float32)
    src_dis[1,0] = row-1
    src_dis[2,1] = col-1
    src_dis[3,0] = row-1
    src_dis[3,1] = col-1

    des_dis[1,0] = row*0.9
    des_dis[2,0] = row*0.21
    des_dis[2,1] = col
    des_dis[3,0] = row*0.71
    des_dis[3,1] = col

    warp_dis = cv2.getPerspectiveTransform(src_dis,des_dis)
    img_des = cv2.warpPerspective(img_bin,warp_dis,(col*2,col))
    cv2.imshow("img_des",img_des)
    img_cut = img_des[:,25:175]

    ##[Dilating]
    cover = np.ones((5,5),dtype = np.uint8)
    img_dil = cv2.dilate(img_cut,cover,iterations = 1)
    cv2.imshow("img_dil",img_dil)

    ##[Harries Corner]
    img_dil_float = np.float32(img_dil)
    dst = cv2.cornerHarris(img_dil_float,3,23,0.04)
    img_dil_color = cv2.cvtColor(img_dil,cv2.COLOR_GRAY2BGR)
    img_dil_color[dst>0.01 * dst.max()] = [0,0,255]
    cv2.imshow("img_Harry",img_dil_color)

    #pdb.set_trace()




if __name__ == "__main__":
    main(sys.argv[1:])
    
