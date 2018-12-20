#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cout << "argc != 2";
    return -1;
  }
  cv::Mat input_img = cv::imread(argv[1]);
  const std::string frame_in_name{"frame_in"};
  const std::string frame_out_name{"frame_out"};

  cv::namedWindow(frame_in_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(frame_out_name, cv::WINDOW_AUTOSIZE);

  cv::imshow(frame_in_name, input_img);

  cv::Mat output_img;

  /*
  *GaussianBlur()
  *blur()
  *medianBlur()
  *bilateralFilter()
  */

  GaussianBlur(input_img, output_img, cv::Size(5,5), 3, 3);
  GaussianBlur(output_img, output_img, cv::Size(5,5), 3, 3);

  cv::imshow(frame_out_name, output_img);

  cv::waitKey(0);

  cv::destroyWindow(frame_in_name);
  cv::destroyWindow(frame_out_name);
}
