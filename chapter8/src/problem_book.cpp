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

    cv::Mat edges;
    constexpr double under_lim { 10};
    constexpr double top_lim   {100};
    cv::Canny(gray_frame, edges, under_lim, top_lim);

    cv::imshow("frame", frame);
    cv::imshow("gray_frame", gray_frame);
    cv::imshow("edges", edges);

    char key = cv::waitKey(1);
    if (key == 'q') {
      break;
    }
  }
}

int main(int argc, char** argv) {
  problem8_1();
  //problem8_2();
  //problem8_3();
  //problem8_4();
}
