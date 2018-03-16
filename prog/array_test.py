
"""
@array test
@aim to access pic certain bit data
@ZZY   20180314
"""

import cv2 
import numpy as np
import sys
import pdb

def main(argv):
    
    #Load Image in form of Grayscale
    filename = argv[0] if len(argv) > 0 else "../data/dig.jpg" #Load Image
    print ("filename is ",filename)

    Img_gray = cv2.imread(filename,cv2.IMREAD_GRAYSCALE) #read img in grayscale

    if Img_gray is None : #error in Load Image wrong
        print("Error opening image!")
        return -1
    
    #cv2.imshow("dig",Img_gray) #Show Image

    img_collon ,img_row = Img_gray.shape  #Get Image shape(collon and row)

    ## [binary]
    #img_bin is the result of Binarization 
    ret,img_bin = cv2.threshold(Img_gray,127,255,0)
    #cv2.imshow("img_bin",img_bin)
    ## [find contours]
    #change to color img
    img_color = cv2.cvtColor(Img_gray,cv2.COLOR_GRAY2BGR)

    #cv2.RETR_APPROX_SAMPLE 仅保存轮廓拐点信息
    #cv2.RETR_EXTERNAL 只检测最外层轮廓 保存轮廓上的所有点
    img_ext,contours_external,hie_external = cv2.findContours(img_bin,
        cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
    img_external = cv2.drawContours(img_color,contours_external,-1,(255,0,0),2)
    #cv2.imshow('contours',img_external)
    print("contours_external is ",contours_external[0])
    print ("the number of all contours_externalis ", len(contours_external))

    ##[break point]
    pdb.set_trace()


    #cv2.RETR_LIST 检测所有轮廓，但是不建立等级
    img_lis,contours_list,hie_list = cv2.findContours(img_bin,
        cv2.RETR_LIST,cv2.CHAIN_APPROX_SIMPLE)
    img_list = cv2.drawContours(img_color,contours_list,-1,(255,0,0),2)
    #cv2.imshow("list",img_list)
    print("contours_list is ",contours_list[0])
    print ("the number of all contours_list is ",len(contours_list))

    
    #cv2.RETR_TREE 检测所有轮廓，所有轮廓建立等级树
    img_tre,contours_tree,his_tree = cv2.findContours(img_bin,
        cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    img_tree = cv2.drawContours(img_color,contours_tree,-1,(255,0,0),2)
    #cv2.imshow("img_tree",img_tree)
    print("contours_tree is ", contours_tree[0])
    print("the number of all contours_tree is ",len(contours_tree))
    
    #cv2.RETR_CCOMP 检测所有轮廓 但是只建立两个等级关系
    img_ccomp, contours_ccomp,his_ccomp = cv2.findContours(img_bin,
        cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
    img_ccomp = cv2.drawContours(img_color,contours_ccomp,-1,(255,0,0),2)
    #cv2.imshow("img_ccomp",img_ccomp)
    print ("contours_ccomp is ",contours_ccomp[0])
    print ("the number of all contours_ccomps is ",len(contours_ccomp))



    ##[test]
    [tem_a,tem_b] = contours_external[0][1][0]
    img_copy = Img_gray[tem_a:tem_b,tem_a:tem_b]
    print("The shape of the part is ",img_copy.shape)
    cv2.imshow("img_copy",img_copy)



if __name__ == "__main__":
    main(sys.argv[1:])

