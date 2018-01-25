#ifndef _PREDEP_H_
#define _PREDEP_H_

#pragma once

#include <opencv2/opencv.hpp>

#define CV_VERSION_ID \
CVAUX_STR(CV_MAJOR_VERSION) \
CVAUX_STR(CV_MINOR_VERSION) \
CVAUX_STR(CV_SUBMINOR_VERSION) \

#ifdef _DEBUG
#define cvLIB(name) "opencv_" name CV_VERSION_ID "d"
#else
#define cvLIB(name) "opencv_" name CV_VERSION_ID
#endif

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")
#pragma comment(lib, cvLIB("core"))
#pragma comment(lib, cvLIB("highgui"))
#pragma comment(lib, cvLIB("imgproc"))

#endif

IplImage* doCanny(IplImage  *in,
                  double    lowThresh,
                  double    highThresh,
                  int       aperture ) {
    if (in->nChannels != 1)
        return 0; // Canny only handles gray scale images

    IplImage *out = cvCreateImage(cvGetSize(in),
                                  IPL_DEPTH_8U,
                                  1);
    cvCanny(in, out, lowThresh, highThresh, aperture);

    return out;
}

void main() {
    IplImage *in = cvLoadImage("C:\\Users\\user001\\Pictures\\Saved Pictures\\–°√€∑‰.jpg");
    IplImage *grayIn = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCvtColor(in, grayIn, CV_BGR2GRAY);
    IplImage *out = doCanny(grayIn, 10, 300, 3);

    cvShowImage("win-in", in);
    cvShowImage("win-out", out);

    cvWaitKey(0);

    cvReleaseImage(&in);
    cvReleaseImage(&grayIn);
    cvReleaseImage(&out);

    cvDestroyWindow("win-in");
    cvDestroyWindow("win-out");
}