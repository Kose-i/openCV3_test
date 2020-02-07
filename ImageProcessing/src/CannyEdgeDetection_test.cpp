#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("dst");

  cv::Mat src = cv::imread("../test.jpg");

  cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);

  cv::Mat dst = src.clone();

  double threshold1 {50};
  double threshold2 {100};

  cv::Canny(src, dst, threshold1, threshold2);

  cv::imshow("src", src);
  cv::imshow("dst", dst);

  while (cv::waitKey(0) != 'q') {}
}
