#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

#include <iostream>

int main(int argc, char *argv[]) {

  constexpr auto wait_time = std::chrono::seconds(2);
  constexpr auto wait_small_time = std::chrono::milliseconds(20);
  constexpr auto timer_count = wait_time/wait_small_time;
  std::cout << timer_count <<  '\n';

  cv::VideoCapture cap(0);
  if(!cap.isOpened()){
    return -1;
  }
  //std::this_thread::sleep_for(wait_time);
  cv::namedWindow("row_img", cv::WINDOW_NORMAL);

  cv::Mat row_img;
  for(auto i = 0;i < timer_count;++i){
    cap>>row_img;
    cv::imshow("row_img", row_img);
    auto key = cv::waitKey(1);// ? ms 誤差大
    if (key == 'q') {
      break;
    }
    //std::this_thread::sleep_for(wait_small_time);
  }
  cv::imwrite("camera.png",row_img);
  cv::destroyAllWindows();
}
