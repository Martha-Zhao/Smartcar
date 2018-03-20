
"""
@ Trapezium
@ aim to Correction the  trapezitium distortion
@ ZZY 20180320

"""
import cv2
import numpy as np
import sys
import os
import pdb


def main (argv):
    #Load Image in form of Grayscale
    filename = argv[0] if len(argv) > 0 else "../data/digital/0.bmp"
    print (filename)

    #pdb.set_trace()

    Img_gray = cv2.imread(filename,cv2.IMREAD_GRAYSCALE)

    if Img_gray is None :
        print("There is an error in Loading files!")
        return -1
    cv2.imshow("Img_gray",Img_gray)

    #base paraments of original picure
    img_collon,img_row = Img_gray.shape

    #Binarize the picture
    img_bin = cv2.threshold(Img_gray,115,255,0)  #threshold is uncertained

    #Correct the trapezitium distortion
    src_dis = np.array( [ [0,0],[0,0],[0,0],[0,0] ],dtype = np.float32)
    des_dis = np.array( [ [0,0],[0,0],[0,0],[0,0] ],dtype = np.float32)
    src_dis[1,0] = img_row-1
    src_dis[2,1] = img_collon-1
    src_dis[3,0] = img_row-1
    src_dis[3,1] = img_collon-1

    des_dis[1,0] = img_row*0.9
    des_dis[2,0] = img_row*0.21
    des_dis[2,1] = img_collon
    des_dis[3,0] = img_row*0.71
    des_dis[3,1] = img_collon

    warp_mat = cv2.getPerspectiveTransform(src_dis,des_dis)

    #pdb.set_trace()

    img_des = cv2.warpPerspective(Img_gray,warp_mat,(img_collon*2,img_collon))

    #show results
    cv2.imshow("img_des",img_des)
    




if __name__ == "__main__":
    main(sys.argv[1:])
