#include <opencv2/opencv.hpp>

#include <vector>
#include <string>

void problem6_1() {
  cv::Mat matrix = cv::Mat::zeros(100, 100, CV_8UC3);

  {
    cv::Point circle_point(20, 20);
    int radius = 10;
    cv::Scalar color(200, 0, 0);
    cv::circle(matrix, circle_point, radius, color); //BGR
  }
  cv::ellipse(matrix, cv::Point(10, 50), cv::Size(20, 80), 45, 10, 300, cv::Scalar(0, 200, 0));

  {
    cv::Point npts[3];
    npts[0] = cv::Point(20, 10);
    npts[1] = cv::Point(30, 40);
    npts[2] = cv::Point(50, 60);

    cv::fillConvexPoly(matrix, npts, 3, cv::Scalar(0, 0, 200));
  }
  {
    cv::Point start_point(0, 10);
    cv::Point end_point(10, 20);
    cv::Scalar color(20, 20, 20);
    cv::line(matrix, start_point, end_point, color);
  }
  {
    cv::Point lt_point(30, 10);
    cv::Point rb_point(30, 10);
    cv::Scalar color(40, 40, 50);
    cv::rectangle(matrix, lt_point, rb_point, color);
  }
  {
    //https://book.mynavi.jp/support/pc/opencv2/c3/opencv_drawing.html
  
    cv::RNG gen(0xffffffff);
    int npt[] = {4, 4};
    cv::Point pt1[2][4];
    const cv::Point *ppt[2] = {pt1[0], pt1[1]};
  
    // Red
    for(int i=0; i<2; i++)
      for(int j=0; j<4; j++)
        pt1[i][j] = cv::Point(gen.uniform(0, matrix.size().width), gen.uniform(0, matrix.size().height));
    // 画像，折れ線頂点の配列の配列，頂点数の配列，折れ線数，線が閉じているか？，色，線太さ，種類
    cv::polylines(matrix, ppt, npt, 2, true, cv::Scalar(0,0,200), 3, 4);
    // Green
    for(int i=0; i<2; i++)
      for(int j=0; j<4; j++)
        pt1[i][j] = cv::Point(gen.uniform(0, matrix.size().width), gen.uniform(0, matrix.size().height));
    cv::polylines(matrix, ppt, npt, 2, true, cv::Scalar(0,200,0), 3, 8);
    // Blue
    for(int i=0; i<2; i++)
      for(int j=0; j<4; j++)
        pt1[i][j] = cv::Point(gen.uniform(0, matrix.size().width), gen.uniform(0, matrix.size().height));
    cv::polylines(matrix, ppt, npt, 2, false, cv::Scalar(200,0,0), 10, cv::LINE_AA);
  
  }

  cv::imshow("problem6-1", matrix);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem6_2() {
  cv::Mat matrix = cv::imread("../../lenna.png");
  cv::imshow("problem6-2", matrix);

  cv::Mat gray_matrix ;
  cv::imshow("problem6-2 gray", gray_matrix);

  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem6_3() {
  cv::VideoCapture cap(0);

  if (!cap.isOpened()) {
    std::cerr << "!cap.isOpened\n";
  }

  cv::Mat frame;
  cv::namedWindow("camera", cv::WINDOW_NORMAL);

  while (true) {
    cap>>frame;
    unsigned temp = cap.get(cv::CAP_PROP_FPS);
    std::string str_fps = std::to_string(temp);
    cv::putText(frame, str_fps, cv::Point(100,100), cv::FONT_HERSHEY_SIMPLEX, 4, cv::Scalar(255, 0, 0));
    cv::imshow("camera", frame);
    int key = cv::waitKey(1);
    if (key == 'q') {
      break;
    }
  }
  cv::destroyAllWindows();
}

void DrawFace(cv::Mat& image, const cv::Point& center, const int& radius) {
  cv::Scalar color(255, 255, 0);
  cv::circle(image, center, radius, color);
}

void problem6_4() {
  cv::VideoCapture cap(0);

  if (!cap.isOpened()) {
    std::cerr << "!cap.isOpened\n";
  }

  cv::Mat frame;
  cap>>frame;

  DrawFace(frame, cv::Point(100, 100), 80);
  cv::imshow("camera", frame);
  while (true) {
    if (cv::waitKey(0) == 'q') {
      break;
    }
  }
}

void problem6_5() {
}

int main(int argc, char** argv) {
  //problem6_1();
  //problem6_2();
  //problem6_3();
  problem6_4();
  //problem6_5();
}
