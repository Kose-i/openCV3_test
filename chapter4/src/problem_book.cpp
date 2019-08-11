#include <opencv2/opencv.hpp>

#include <iostream>

void problem4_1() {
  cv::Mat temp = cv::Mat::zeros(500, 500, CV_8UC1);
  cv::namedWindow("temp", cv::WINDOW_NORMAL);
  while (true) {
    cv::imshow("temp", temp);
    auto key = cv::waitKey(1);

    if (key == 48) { // Number 0 push
    } else if (key == 49) { // Number 1 push
    } else if (key == 50) { // Number 2 push
    } else if (key == 51) { // Number 3 push
    } else if (key == 52) { // Number 4 push
    } else if (key == 53) { // Number 5 push
    } else if (key == 54) { // Number 6 push
    } else if (key == 55) { // Number 7 push
    } else if (key == 56) { // Number 8 push
    } else if (key == 57) { // Number 9 push
    } else if (key == 8) {          // BackSpace
    } else if (key == 13) {  // Enter Key
    } else if (key == 81) {  // Left Key
    } else if (key == 82) {  // Up key
    } else if (key == 83) {  // Right Key
    } else if (key == 84) {  // Down Key
    } else if (key == 'q') {
      break;
    }
  }
}

void problem4_2() {}

int main(int argc, char** argv) {
  problem4_1();
  problem4_2();
}
