#include <opencv2/opencv.hpp>

#include <iostream>

void problem5_1() {
  cv::Mat matrix = cv::Mat::zeros(100, 100, CV_8UC1);

  cv::Point center_circle;
  int radius_circle {100};
  cv::Scalar color_circle {255};
  int thickness_circle {1};
  int lineType_circle {8};
  int shift_circle {0};
  cv::circle(matrix, center_circle, radius_circle, color_circle, thickness_circle, lineType_circle, shift_circle);

  cv::imshow("problem5-1", matrix);
  while (cv::waitKey(0));
}

void problem5_2() {}

int main(int argc, char** argv) {
  problem5_1();
  problem5_2();
}
