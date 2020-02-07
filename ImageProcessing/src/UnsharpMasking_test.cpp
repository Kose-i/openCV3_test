#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("dst");

  cv::Mat src = cv::imread("../test.jpg");

  cv::Mat filter = cv::Mat::zeros(3, 3, CV_64F);

  filter.at<double>(0, 0) = -0.125;filter.at<double>(0, 1) = -0.125;filter.at<double>(0, 2) = -0.125;
  filter.at<double>(1, 0) = -0.125;filter.at<double>(1, 1) =  2    ;filter.at<double>(1, 2) = -0.125;
  filter.at<double>(2, 0) = -0.125;filter.at<double>(2, 1) = -0.125;filter.at<double>(2, 2) = -0.125;

  std::cout << filter << '\n';

  cv::Mat dst = src.clone();

  cv::filter2D(src, dst, src.type(), filter);

  cv::imshow("src", src);
  cv::imshow("dst", dst);

  while (cv::waitKey(0) != 'q') {}
}
