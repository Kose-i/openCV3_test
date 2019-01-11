#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cout << "argc need 2 argments";
    return -1;
  }
  std::string movie_name{"movie_name"};

  cv::namedWindow(movie_name);
  cv::VideoCapture cap;

  cap.open(std::string(argv[1]));

  cv::Mat frame;
  for (;;) {
    cap >> frame;
    if (frame.empty()) {
      break;
    }
    cv::imshow(movie_name, frame);
    if ((char)cv::waitKey(33) >= 0) {//ESCキーを押したとき
      break;
    }
  }
  cv::destroyWindow(movie_name);
}
