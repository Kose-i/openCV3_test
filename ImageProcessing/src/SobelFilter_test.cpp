#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("x-dst");
  cv::namedWindow("y-dst");

  cv::Mat src = cv::imread("../test.jpg");
  cv::cvtColor(src, src, cv::COLOR_RGB2GRAY);

  cv::Mat x_dst = src.clone();
  cv::Mat y_dst = src.clone();

  cv::Sobel(src, x_dst, src.type(), 1, 0);
  cv::Sobel(src, y_dst, src.type(), 0, 1);

  cv::imshow("src", src);
  cv::imshow("x-dst", x_dst);
  cv::imshow("y-dst", y_dst);

  while (cv::waitKey(0) != 'q') {}
}
