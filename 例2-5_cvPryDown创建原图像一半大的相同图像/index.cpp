#include <opencv2/opencv.hpp>

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

IplImage* doPyrDown(IplImage *in/*, int filter = IPL_GAUSSIAN_5x5*/) {
    // Best to make sure input image is divisible by two.
    assert(in->width % 2 == 0 && in->height % 2 == 0);

    IplImage *out = cvCreateImage(
                            cvSize(in->width / 2, in->height / 2),
                            in->depth,
                            in->nChannels);
    cvPyrDown(in, out);

    return out;
}

void main() {
    IplImage *img = cvLoadImage("C:\\Users\\user001\\Pictures\\Saved Pictures\\–°√€∑‰.jpg");
    IplImage *out = NULL;

    out = doPyrDown(img);

    cvShowImage("w-in", img);
    cvShowImage("w-out", out);

    cvWaitKey(0);

    cvReleaseImage(&img);
    cvReleaseImage(&out);

    cvDestroyWindow("w-in");
    cvDestroyWindow("w-out");
}