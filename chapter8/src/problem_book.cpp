#include <opencv2/opencv.hpp>

#include <vector>
#include <iostream>

void problem8_1() {
  cv::VideoCapture cap(0);
  if (!cap.isOpened()) {
    std::cerr << "!cap.isOpened\n";
  }
  while (true) {
    cv::Mat frame;
    cap >> frame;
    cv::Mat gray_frame;
    cv::cvtColor(frame , gray_frame , cv::COLOR_BGR2GRAY);

    cv::Mat edges_frame;
    constexpr double under_lim { 10};
    constexpr double top_lim   {100};
    cv::Canny(gray_frame, edges_frame, under_lim, top_lim);

    //cv::imshow("frame", frame);
    //cv::imshow("gray_frame", gray_frame);
    //cv::imshow("edges_frame", edges_frame);

    cv::Mat matrix(frame.rows, frame.cols*3, frame.type());
    cv::Mat roi1(matrix, cv::Rect(0,0,frame.cols, frame.rows));
    cv::Mat roi2(matrix, cv::Rect(frame.cols, 0, frame.cols, frame.rows));
    cv::Mat roi3(matrix, cv::Rect(frame.cols*2, 0, frame.cols, frame.rows));

    frame.copyTo(roi1);
    gray_frame.copyTo(roi2);
    edges_frame.copyTo(roi3);

    cv::imshow("matrix", matrix);

    char key = cv::waitKey(1);
    if (key == 'q') {
      break;
    }
  }
}

int x_point, y_point;
void on_mouse_call_back(int event, int x, int y, int flags) {
  if (flags == cv::EVENT_LBUTTONDOWN) {
    x_point = x;
    y_point = y;
  }
}

void problem8_2() {
  cv::Mat matrix = cv::imread("../../lenna.png");
  std::string str_pix_color;
  cv::namedWindow("matrix", matrix);
  cv::setMouseCallback("matrix", on_mouse_call_back);
  while (true) {
    cv::putText(str_pix_color);
    char key = cv::waitKey(1);
    if (key == 'q') {
      break;
    }
  }
}

int main(int argc, char** argv) {
  //problem8_1();
  problem8_2();
  //problem8_3();
  //problem8_4();
}
