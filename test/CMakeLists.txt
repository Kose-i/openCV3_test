cmake_minimum_required(VERSION 2.8)
project(tutorial)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(TestCamera src/camera.cpp)
target_link_libraries(TestCamera ${OpenCV_LIBS})

add_executable(one_color src/one_temp_color_img.cpp)
target_link_libraries(one_color ${OpenCV_LIBS})
