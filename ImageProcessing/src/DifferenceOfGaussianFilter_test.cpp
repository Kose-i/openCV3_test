#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("Gaussian-dst(sigma=1)");
  cv::namedWindow("Gaussian-dst(sigma=1.6)");
  cv::namedWindow("DifferenceOfGaussian-dst");

  cv::Mat src = cv::imread("../test.jpg");
  cv::cvtColor(src, src, cv::COLOR_RGB2GRAY);

  cv::Mat dst1 = src.clone();
  cv::Mat dst2 = src.clone();

  double sigmaX {1.0};
  double sigmaY {1.0};

  cv::GaussianBlur(src, dst1, cv::Size(3, 3), sigmaX, sigmaY);

  sigmaX = 1.6;
  sigmaY = 1.6;

  cv::GaussianBlur(src, dst2, cv::Size(3, 3), sigmaX, sigmaY);

  cv::imshow("src", src);
  cv::imshow("Gaussian-dst(sigma=1)",   dst1);
  cv::imshow("Gaussian-dst(sigma=1.6)", dst2);
  cv::imshow("DifferenceOfGaussian-dst",dst2 - dst1);

  while (cv::waitKey(0) != 'q') {}
}
