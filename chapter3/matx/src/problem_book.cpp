#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  const float define_floot{-3.141};

  std::cout << "cvCeil(" << define_floot << "):" << cvCeil(define_floot) << '\n';
}
