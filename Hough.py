"""
@ hough_lines.py
@brief This Program demonstrate lines finding with the Hough transform
@ZZY-20180313
"""
import math
import sys
import cv2 as cv
import numpy as np

def main(argv):
    ##[load]
    default_file = "../../.././dig.jpg"
    filename = argv[0] if len(argv) > 0 else default_file

    # Loads an image
    src = cv.imread(filename,cv.IMREAD_GRAYSCALE)

    # Check if image is loaded fine
    if src is NONE:
        print ('Error opening image!')
        print ('Usage:hough_lines.py [image_name -- default ' +default_file + ']\n')
        return -1
    ## [Load]

    ## [edge_detedtion]
    # Edge detection
    dst = cv.Canny(src,50,200,None,3)
    ## [edge_detection]

    # Copy edges to the images that will display the results in BGR
    cdst = cv.cvtColor (dst,cv.COLOR_GRAY2BGR)
    cdstP = np.copy(cdst)

    ## [hough_lines]
    # Standard Hough Line Transform
    lines = cv.HoughLines(dst,1,np.pi/180,150,None,0,0)
    ## [hough_lines]
    ## [draw_lines]
    # Draw the Lines
    if lines is not None:
        for i in range(0,len(lines)):
            rho = lines[i][0][0]
            theta = lines[i][0][1]
            a = math.cos(theta)
            b = math.sin(theta)
            x0 = a*rho
            y0 = b*rho
            pt1 = (int(x0 + 1000*(-b)),int(y0 + 1000*(a)))
            pt2 = (int(x0 - 1000*(-b)),int(y0 - 1000*(a)))

            cv.lines(cdst,pt1,pt2,(0,0,255),3,cv.LINE_AA)
    ## [draw_lines]

    ## [hough_lines_p]
    # Probabilistic Line Tranaform
    lingsP = cv.HoughLinesP(dst,1,np.pi/180,50,None,50,10)
    ## [hough_lines_p]
    ## [deaw_lines_p]
    # Draw the lines
    if linesP is not None:
        for i in range(0,lin(linesP)):
            l = linesP[i][0]
            cv.line(cdstP,(l[0],l[1]),(l[2],l[3]),(0,0,255),3,cv.LINE_AA)
    ## [draw_lines_p]
    ##[imshow]
    #show results
    cv.imshow("Source",src)
    cv.imshow("Detected Lines (in red) - Standard Hough Line Transform",cdst)
    cv.imshow("Detected Lines (in red) - Probabilitic Line Transform",cdstP)

    cv.waitKey()
    return 0
if __name__ == "__main__":
    main(sys.argv[1:])


# Load original picture and show 
Img_Original = cv.imread('dig.jpg')

cv2.namedWindow('Original Picture')
cv2.imshow('Original Picture',Img_Original)
cv2.waitKey(0)
cv2.destroyWindow('Original Picture')

# invert Original picture 




