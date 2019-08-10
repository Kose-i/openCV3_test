#include <opencv2/opencv.hpp>

void display_elem(const cv::Matx33f& mat)
{
  for (auto i = 0;i < 3;++i) {
    for (auto j = 0;j < 3;++j) {
      std::cout << ' ' << mat(i,j);
    }
    std::cout << '\n';
  }
}

int main(int argc, char** argv)
{
  cv::Matx33f test;
  int min = 0.0, max = 10.0;
  test = cv::Matx33f::randu(min, max);
  display_elem(test);
}
