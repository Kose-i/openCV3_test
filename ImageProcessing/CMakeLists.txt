cmake_minimum_required(VERSION 3.0.0)
project(jouhousyorisystemII)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Affine_test src/Affine_test.cpp)
target_link_libraries(Affine_test ${OpenCV_LIBS})

add_executable(UnsharpMasking_test src/UnsharpMasking_test.cpp)
target_link_libraries(UnsharpMasking_test ${OpenCV_LIBS})

add_executable(SharpMasking_test src/SharpMasking_test.cpp)
target_link_libraries(SharpMasking_test ${OpenCV_LIBS})

add_executable(MedianFilter_test src/MedianFilter_test.cpp)
target_link_libraries(MedianFilter_test ${OpenCV_LIBS})

add_executable(SobelFilter_test src/SobelFilter_test.cpp)
target_link_libraries(SobelFilter_test ${OpenCV_LIBS})

add_executable(LaplacianFilter_test src/LaplacianFilter_test.cpp)
target_link_libraries(LaplacianFilter_test ${OpenCV_LIBS})

add_executable(LaplacianOfGaussianFilter_test src/LaplacianOfGaussianFilter_test.cpp)
target_link_libraries(LaplacianOfGaussianFilter_test ${OpenCV_LIBS})

add_executable(DifferenceOfGaussianFilter_test src/DifferenceOfGaussianFilter_test.cpp)
target_link_libraries(DifferenceOfGaussianFilter_test ${OpenCV_LIBS})

add_executable(CannyEdgeDetection_test src/CannyEdgeDetection_test.cpp)
target_link_libraries(CannyEdgeDetection_test ${OpenCV_LIBS})
