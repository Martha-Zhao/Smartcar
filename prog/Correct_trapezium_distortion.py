
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

    #膨胀
    

    #base paraments of original picure
    img_collon,img_row = Img_gray.shape


    ##[binarize should be after correction]
    #Binarize the picture
    ret,img_bin = cv2.threshold(Img_gray,100,255,0)  #threshold is uncertained
    ##[binarize is done!]



    #Correct the trapezitium distortion
    src_dis = np.array( [ [0,0],[0,0],[0,0],[0,0] ],dtype = np.float32)
    des_dis = np.array( [ [0,0],[0,0],[0,0],[0,0] ],dtype = np.float32)
    src_dis[1,0] = img_collon-1   #img_row-1
    src_dis[2,1] = img_row-1   #img_collon-1
    src_dis[3,0] = img_collon-1   #img_row-1
    src_dis[3,1] = img_row-1   #img_collon-1

    des_dis[1,0] = img_collon * 0.9 #img_row*0.9
    des_dis[2,0] = img_collon * 0.21 #img_row*0.21
    des_dis[2,1] = img_row  #img_collon
    des_dis[3,0] = img_collon * 0.71 #img_row*0.71
    des_dis[3,1] = img_row  #img_collon

    warp_mat = cv2.getPerspectiveTransform(src_dis,des_dis)

    #pdb.set_trace()

    img_des = cv2.warpPerspective(img_bin,warp_mat,(img_collon*2,img_collon))

    #show results
    cv2.imshow("img_des",img_des)

    ##[cut]
    img_cut = img_des[:,25:175]
    cv2.imshow("img_cut",img_cut)
    ##膨胀
    cover = np.ones((5,5),dtype = np.uint8)
    img_dila = cv2.dilate(img_cut,cover,iterations = 1)

    ##[Canny]
    #img_canny = cv2.Canny(img_cut,50,80)
    #cv2.imshow("Canny",img_canny)

    img_contours,contours,hierarchy = cv2.findContours(img_dila,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    #x,y,w,h = cv2.boundingRect(contours[4])

    img_color = cv2.cvtColor(img_dila,cv2.COLOR_GRAY2BGR)
    cv2.drawContours(img_color,contours,2,(0,0,255),3)
    cv2.imshow("img_color",img_color)
    
    #cv2.imshow("img_add",img_cut[x:x+w,y:y+h])
    


if __name__ == "__main__":
    main(sys.argv[1:])
