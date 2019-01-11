#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
  cv::Mat input_img, output_img;
  const std::string input_img_name{"input_img_name"};
  const std::string output_img_name{"output_img_name"};

  if (argc != 2) {
    std::cout << "argc != 2\n";
    return -1;
  }
  input_img = cv::imread(argv[1]);
  if (input_img.empty()) {
    std::cout << "cant open img\n";
    return -1;
  }

  cv::pyrDown(input_img, output_img);
  cv::imshow(input_img_name, input_img);
  cv::imshow(output_img_name, output_img);

  cv::waitKey(0);

  cv::namedWindow(input_img_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(output_img_name, cv::WINDOW_AUTOSIZE);

}
