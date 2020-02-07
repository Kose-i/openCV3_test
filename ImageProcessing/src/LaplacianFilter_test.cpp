#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("dst");

  cv::Mat src = cv::imread("../test.jpg");
  cv::cvtColor(src, src, cv::COLOR_RGB2GRAY);

  cv::Mat dst = src.clone();

  cv::Laplacian(src, dst, src.type());

  cv::imshow("src", src);
  cv::imshow("dst", dst);

  while (cv::waitKey(0) != 'q') {}
}
