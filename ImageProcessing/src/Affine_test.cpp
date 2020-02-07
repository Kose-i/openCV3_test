#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("dst");

  cv::Mat src = cv::imread("../test.jpg");

  cv::Mat M = cv::Mat::zeros(2, 3, CV_64F);
  M.at<double>(0, 0) = 2;
  M.at<double>(0, 1) = 0;
  M.at<double>(0, 2) = 0;
  M.at<double>(1, 0) = 1;
  M.at<double>(1, 1) = 1;
  M.at<double>(1, 2) = 1;
  std::cout << M << '\n';

  cv::Mat dst = src.clone();

  cv::Size trans_size = dst.size();
  std::cout << "dst-size:" << trans_size << '\n';
  cv::warpAffine(src, dst, M, trans_size);

  cv::imshow("src", src);
  cv::imshow("dst", dst);

  while (cv::waitKey(0) != 'q') {}
}
