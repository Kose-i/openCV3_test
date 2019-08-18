#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>

void problem5_1() {
  cv::Mat matrix = cv::Mat::zeros(100, 100, CV_8UC1);

  cv::Point center_circle(30, 30);
  int radius_circle {50};
  cv::Scalar color_circle {255};
  int thickness_circle {1};
  int lineType_circle {8};
  int shift_circle {0};
  cv::circle(matrix, center_circle, radius_circle, color_circle, thickness_circle, lineType_circle, shift_circle);

  cv::imshow("problem5-1", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem5_2() {
  cv::Mat matrix = cv::Mat::zeros(100, 100, CV_8UC1);
  //(20, 5) , (40, 20)

  for (auto i = 20;i <= 40;++i) {
    for (auto j = 5;j <= 20;++j) {
      matrix.at<uchar>(i,j) = 255;
    }
  }

  cv::imshow("problem5-2", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem5_3() {
  cv::Mat matrix = cv::Mat::zeros(100, 100, CV_8UC3);
  //(20, 5) , (40, 20)

  for (auto i = 20;i <= 40;++i) {
    for (auto j = 5;j <= 20;++j) {
      matrix.at<cv::Vec3b>(i,j) = cv::Vec3b(0, 255, 0); //BGR
    }
  }

  cv::imshow("problem5-3", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem5_4() {
  cv::Mat matrix = cv::Mat::zeros(210, 210, CV_8UC1);

  for (auto i = 0;i <= 10;++i) {
    auto x = 10*i;
    auto width = 210 - 2*x;
    cv::Mat roi(matrix, cv::Rect(x,x,width,width));
    roi.setTo(x);
  }

  cv::imshow("problem5-4", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem5_5() {
  cv::Mat matrix = cv::imread("../../lenna.png");

  cv::Point start_point1( 5, 10);
  cv::Point start_point2(50, 60);

  auto width=20, height = 30;

  cv::Mat roi1(matrix, cv::Rect(start_point1.x, start_point1.y, width, height));
  cv::Mat roi2(matrix, cv::Rect(start_point2.x, start_point2.y, width, height));

  cv::bitwise_not(roi1, roi2);

  cv::imshow("problem5-5", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem5_6() {
  cv::Mat matrix = cv::imread("../../lenna.png");

  std::vector<cv::Mat> color_matrix(3);
  cv::split(matrix, color_matrix);

  //cv::imshow("problem5-6", matrix);
  //cv::imshow("problem5-6-b", color_matrix[0]);
  //cv::imshow("problem5-6-g", color_matrix[1]);
  //cv::imshow("problem5-6-r", color_matrix[2]);

  cv::Mat green_image = color_matrix[1];
  cv::Mat clone1 = green_image.clone();
  cv::Mat clone2 = green_image.clone();

  double maximum {}; double minimum {};
  cv::minMaxIdx(green_image, &minimum, &maximum);

  unsigned thresh = (maximum - minimum)/2.0;

  clone1 = cv::Mat::ones(clone1.size(), clone1.type())*thresh;
  clone2 = cv::Mat::zeros(clone2.size(), clone2.type());

  //cv::imshow("clone1", clone1);
  //cv::imshow("green_image", green_image);
  //cv::imshow("clone2", clone2);

  cv::compare(green_image, clone1, clone2, cv::CMP_GE);

  //cv::imshow("clone1-compare", clone1);
  //cv::imshow("green_image-compare", green_image);
  //cv::imshow("clone2-compare", clone2);

  cv::subtract(green_image, thresh/2, green_image, clone2);

  cv::imshow("subtract clone2", clone2);

  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

int main(int argc, char** argv) {
  //problem5_1();
  //problem5_2();
  //problem5_3();
  //problem5_4();
  //problem5_5();
  problem5_6();
}
