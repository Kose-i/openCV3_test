#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::namedWindow("src");
  cv::namedWindow("Gaussian-dst");
  cv::namedWindow("LaplacianOfGaussian-dst");

  cv::Mat src = cv::imread("../test.jpg");
  cv::cvtColor(src, src, cv::COLOR_RGB2GRAY);

  cv::Mat dst1 = src.clone();
  cv::Mat dst2 = src.clone();

  double sigmaX {1.0};
  double sigmaY {1.0};

  cv::GaussianBlur(src, dst1, cv::Size(3, 3), sigmaX, sigmaY);
  cv::Laplacian(dst1, dst2, dst1.type());

  cv::imshow("src", src);
  cv::imshow("Gaussian-dst", dst1);
  cv::imshow("LaplacianOfGaussian-dst", dst2);

  while (cv::waitKey(0) != 'q') {}
}
