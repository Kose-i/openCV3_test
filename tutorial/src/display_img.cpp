#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cout << "error: argc need 2\n";
    return -1;
  }

  cv::Mat img_data = cv::imread(argv[1]);

  if (img_data.empty()) {
    std::cout << "can't open img" << argv[1] << '\n';
    return -1;
  }

  const std::string img_name=argv[1];

  cv::namedWindow(img_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(img_name, img_data);

  cv::waitKey(0);
}
