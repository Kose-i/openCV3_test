#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
  cv::Mat input_img, gray_img, canny_img;

  const std::string input_img_name{"input_img_name"};
  const std::string gray_img_name{"gray_img_name"};
  const std::string canny_img_name{"canny_img_name"};

  if (argc != 2) {
    std::cout << "argc != 2\n";
    return -1;
  }
  input_img = cv::imread(argv[1]);
  if (input_img.empty()) {
    std::cout << "cant open img\n";
    return -1;
  }

  cv::cvtColor(input_img, gray_img, cv::COLOR_BGR2GRAY);
  cv::Canny(gray_img, canny_img, 10, 100, 3, true);

  cv::namedWindow(input_img_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(gray_img_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(canny_img_name, cv::WINDOW_AUTOSIZE);

  cv::imshow(input_img_name, input_img);
  cv::imshow(gray_img_name, gray_img);
  cv::imshow(canny_img_name, canny_img);

  cv::waitKey(0);

  cv::destroyWindow(input_img_name);
  cv::destroyWindow(gray_img_name);
  cv::destroyWindow(canny_img_name);
  
}
