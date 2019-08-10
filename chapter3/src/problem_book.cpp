#include <opencv2/opencv.hpp>
#include <random>

void problem3_1() {
  std::cout << "\nproblem3-1\n";
  const float number{-3.141};
  std::cout << "cvCeil(" << number << "):" << cvCeil(number) << '\n';

  std::random_device rnd;
  for (auto i = 0;i < 10;++i) {
    std::cout << rnd() << ' ';
  }
  std::cout << '\n';

  cv::Point2f temp_float(2.3, 2.5);
  cv::Point temp_int = temp_float;
  std::cout << "temp_float:" << temp_float << '\n';
  std::cout << "temp_int:" << temp_int << '\n';
  temp_float = temp_int;
  std::cout << "temp_float:" << temp_float << '\n';
}

void problem3_2() {
  std::cout << "\nproblem3-2\n";
  cv::Matx33f tensor_t(1.2, 2.2, 3.1, 4.1, 5.1, 6.1, 7.2, 8.3, 9.1);
  cv::Vec3f vector_t(3.4, 2.3, 8.5);
  std::cout << "tensor_t:" << tensor_t << '\n';
  std::cout << "vector_t:" << vector_t << '\n';
}

void problem3_3() {
  std::cout << "\nproblem3-3\n";
  cv::Matx<float, 3, 3> tensor_t(1.2, 2.2, 3.1, 4.1, 5.1, 6.1, 7.2, 8.3, 9.1);
  cv::Vec<float, 3> vector_t(3.4, 2.3, 8.5);
  std::cout << "tensor_t:" << tensor_t << '\n';
  std::cout << "vector_t:" << vector_t << '\n';

//  cv::Matx<float, 3> vector_tensor_transform = tensor_t;
//  std::cout << "vector_tensor = tensor_t:" << vector_tensor_transform << '\n';
}

int main(int argc, char** argv) {
  problem3_1();
  problem3_2();
  problem3_3();
}
