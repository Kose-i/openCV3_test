#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("dst");

  cv::Mat src = cv::imread("../test.jpg");

  cv::Mat dst = src.clone();

  cv::Size kernel_size(3, 3);

  cv::medianBlur(src, dst, 3);

  cv::imshow("src", src);
  cv::imshow("dst", dst);

  while (cv::waitKey(0) != 'q') {}
}
