#include <iostream>
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"

void DetectFace(cv::Mat img);

int main(int argc, char** argv) {
     cv::Mat img;
     cv::VideoCapture vid(0);

     /*Checks if default camera is opened*/
     if (!vid.isOpened()) {
          std::cerr << "Camera is Not Connected\n";
          return -1;
     }

     /*Loop converts images, detects face, and shows gui of video*/
     while (true) {
          vid.read(img);
          cv::namedWindow("Window", cv::WINDOW_AUTOSIZE);
          DetectFace(img);
          cv::imshow("Window", img);
          cv::waitKey(24);
     }
     return 0;
}

void DetectFace(cv::Mat img) {
     cv::CascadeClassifier face_cascade;
     cv::Mat img_gray;
     /*Cascade of Faces*/
     std::string face_cascade_name = "/home/kryptic/opencv/data/lbpcascades/lbpcascade_frontalface_improved.xml";
     std::vector<cv::Rect> face;

     /*Converts image to grayscale then equalizes color for easier cascading*/
     cv::cvtColor(img, img_gray,cv::COLOR_RGB2GRAY);
     cv::equalizeHist(img_gray, img_gray);
     face_cascade.load(face_cascade_name);

     face_cascade.detectMultiScale(img_gray, face, 1.1, 2, cv::CASCADE_SCALE_IMAGE, cv::Size(30,30));

     /*Places an ellipses around detected item*/
     for (size_t i=0; i < face.size(); i++) {
          cv::Point center(face[i].x + face[i].width/2, face[i].y + face[i].height/2);
          ellipse( img, center, cv::Size(face[i].width/2, face[i].height/2), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
     }
}
