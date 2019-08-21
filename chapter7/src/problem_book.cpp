#include <opencv2/opencv.hpp>

#include <vector>
#include <iostream>

void problem7_1() {
  cv::RNG rng_eng(cv::theRNG());

  for (auto i = 0;i < 3;++i) {
    std::cout << rng_eng.uniform(0.0, 1.0) << ' ';
  }
  std::cout << '\n';

  for (auto i = 0;i < 3;++i) {
    std::cout << rng_eng.gaussian(1.0) << ' ';
  }
  std::cout << '\n';

  for (auto i = 0;i < 3;++i) {
    std::cout << rng_eng.uniform(0,255) << ' ';
  }
  std::cout << '\n';
}

void problem7_2() {
  cv::Mat matrix_a(20, 1, CV_32FC1);
  cv::RNG rng_eng(cv::theRNG());
  rng_eng.fill(matrix_a, cv::RNG::UNIFORM, 0.0, 1.0);
  for (auto i = 0;i < 20;++i) {
    std::cout << matrix_a.at<float>(i,0) << ' ';
  }
  std::cout << '\n';

  cv::Mat matrix_b(20, 1, CV_32FC1);
  rng_eng.fill(matrix_b, cv::RNG::NORMAL, 0.0, 1.0);
  for (auto i = 0;i < 20;++i) {
    std::cout << matrix_b.at<float>(i,0) << ' ';
  }
  std::cout << '\n';

  cv::Mat matrix_c(20, 1, CV_8UC1);
  rng_eng.fill(matrix_c, cv::RNG::UNIFORM, 0, 255);
  for (auto i = 0;i < 20;++i) {
    std::cout << matrix_c.at<int>(i,0) << ' ';
  }
  std::cout << '\n';

  cv::Mat matrix_d(20, 1, CV_8UC3);
  std::vector<int> max_iter{255,255,255};
  std::vector<int> min_iter{  0,  0,  0};
  rng_eng.fill(matrix_d, cv::RNG::UNIFORM, min_iter, max_iter);
  for (auto i = 0;i < 20;++i) {
    cv::Vec3b temp = matrix_d.at<cv::Vec3b>(i,0);
    std::cout << '(';
    //std::cout << matrix_d.at<int>(i,0) << ',';
  }
  std::cout << '\n';
}

void problem7_3() {

  cv::Mat matrix(3, 100, CV_8UC1);
  cv::RNG rng_eng(cv::theRNG());
  cv::Mat roi1(matrix, cv::Rect(0,0,100,1));
  rng_eng.fill(roi1, cv::RNG::NORMAL, 64, 10);

  cv::Mat roi2(matrix, cv::Rect(0,1,100,1));
  rng_eng.fill(roi1, cv::RNG::NORMAL, 128, 2);

  cv::Mat roi3(matrix, cv::Rect(0,2,100,1));
  rng_eng.fill(roi1, cv::RNG::NORMAL, 192, 10);

  //TODO cv::PCA
  
  //std::vector<std::vector<int>> mean_matrix{{64,}, {128,}, {192,}};

  //cv::PCA tmp(matrix,mean_matrix, cv::PCA::DATA_AS_COL, 3);

  //cv::Mat projection_matrix = tmp.project(matrix);
}

void problem7_4() {
  std::vector<std::vector<double>> matrix_A{{1,1},{0,1},{-1,1}};
  cv::SVD tmp;
  std::vector<std::vector<double>> matrix_W;
  std::vector<std::vector<double>> matrix_U;
  std::vector<std::vector<double>> matrix_Vt;
  //tmp.compute(matrix_A, matrix_W, matrix_U, matrix_Vt);
}

int main(int argc, char** argv) {
  //problem7_1();
  //problem7_2();
  problem7_3();
  //problem7_4();
}
