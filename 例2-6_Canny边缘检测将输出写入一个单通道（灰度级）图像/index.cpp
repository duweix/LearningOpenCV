#include <opencv2/opencv.hpp>

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

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