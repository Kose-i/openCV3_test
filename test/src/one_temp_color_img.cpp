#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  auto rowsize=50;
  auto colsize=50;
  cv::Scalar color(255,255,255);

  cv::Mat one_tone_color = cv::Mat(rowsize, colsize, CV_8UC3, color);
  cv::imshow("one_tone_color", one_tone_color);
  cv::waitKey(1);
}
