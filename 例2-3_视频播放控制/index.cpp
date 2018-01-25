#include <opencv2/opencv.hpp>

#pragma comment(lib, "opencv_imgproc231d")

int         g_slider_position   = 0;
CvCapture   *g_capture          = NULL;

void onTrackbarSlide(int pos) {
    cvSetCaptureProperty(g_capture, CV_CAP_PROP_POS_FRAMES, pos);
}

IplImage* doCanny(IplImage *in) {
    IplImage *gray = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCvtColor(in, gray, CV_BGR2GRAY);

    IplImage *out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);
    cvCanny(gray, out, 10, 200, 3);

    cvReleaseImage(&gray);
    return out;
}

int main(int argc, char **argv) {
    cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Example3_canny", CV_WINDOW_AUTOSIZE);
    g_capture = cvCreateFileCapture("C:\\Users\\user001\\Pictures\\Saved Pictures\\金字塔造假之谜大揭密_标清.avi");
    int frames = (int) cvGetCaptureProperty(g_capture, CV_CAP_PROP_FRAME_COUNT);
    if (frames != 0) {
        cvCreateTrackbar(
            "Position",
            "Example3",
            &g_slider_position,
            frames,
            onTrackbarSlide);
    }
    IplImage *frame = NULL;
    IplImage *cannyImg = NULL;
    while (1) {
        frame = cvQueryFrame(g_capture);
        if (!frame) break;
        cannyImg = doCanny(frame);
        cvShowImage("Example3", frame);
        cvShowImage("Example3_canny", cannyImg);
        cvReleaseImage(&cannyImg);
        char c = cvWaitKey(41);
        if (c == 27) break;
    }
    cvReleaseCapture(&g_capture);
    cvDestroyWindow("Example3");
    cvDestroyWindow("Example3_canny");
    return 0;
}
