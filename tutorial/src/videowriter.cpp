#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 3) {
    std::cout << "argc != 2\n";
    return -1;
  }

  //カメラIDを与えることでカメラを起動できる
  cv::VideoCapture cap(argv[1]);
  if (!cap.isOpened()) {
    std::cout << "cant open img\n";
    return -1;
  }

  double fps = cap.get(cv::CAP_PROP_FPS);
  cv::Size size(
    (int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
    (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT)
  );

  cv::VideoWriter videowriter;
  videowriter.open(argv[2], CV_FOURCC('M','J','P','G'), fps, size);

  cv::Mat input_img, logpolar_img;
  const std::string input_img_name{"input_img_name"};
  const std::string logpolar_img_name{"logpolar_img_name"};

  cv::namedWindow(input_img_name, cv::WINDOW_AUTOSIZE);
  cv::namedWindow(logpolar_img_name, cv::WINDOW_AUTOSIZE);

  for (;;) {
    cap >> input_img;
    if (input_img.empty()) {
      break;
    }
    cv::logPolar(
      input_img,
      logpolar_img,
      cv::Point2f(
        input_img.cols/2,
        input_img.rows/2
      ),
      40,
      CV_WARP_FILL_OUTLIERS
    );

    cv::imshow(input_img_name, input_img);
    videowriter << logpolar_img;

    char c = (char) cv::waitKey(33);
    if (c == 'q') {
      break;
    }
  }
  cap.release();
  videowriter.release();

  cv::destroyWindow(input_img_name);
  cv::destroyWindow(logpolar_img_name);
}
