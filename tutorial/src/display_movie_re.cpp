#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <string>

int g_slider_position {};
int g_run {1};
int g_dontset {};
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void*)
{
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);

  if (! g_dontset) {
    g_run = 1;
    g_dontset = 0;
  }
}

int main(int argc, char** argv)
{
  const std::string frame_name{"movie_frame_name"};
  cv::namedWindow(frame_name, cv::WINDOW_AUTOSIZE);
  g_cap.open(argv[1]);
  int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
  int tmpw =   (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
  int tmph =   (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
  std::cout << "video has " << frames << "frames of dimensions(" << tmpw << ',' << tmph << ").\n";
  cv::createTrackbar("Position", frame_name, &g_slider_position, frames, onTrackbarSlide);

  cv::Mat frame;
  for (;;) {
    if (g_run != 0) {
      g_cap >> frame;
      if (frame.empty()) {
        break;
      }
      int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
      g_dontset = 1;

      cv::setTrackbarPos("Position", frame_name, current_pos);
      cv::imshow(frame_name, frame);

      g_run = 1;

    }
    char c = (char)cv::waitKey(10);
    if (c == 's') {
      g_run = 1;
      std::cout << "Single step ,run = " << g_run << '\n';
    } else if (c == 'r') {
      g_run = -1;
      std::cout << "Run mode ,run = " << g_run << '\n';
    } else if (c == 29) { //ESC キー
      break;
    }
  }
  cv::destroyWindow(frame_name);
}
