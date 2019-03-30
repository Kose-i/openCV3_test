cmake_minimum_required(VERSION 2.8)
project(tutorial)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(TestCamera src/camera.cpp)
target_link_libraries(TestCamera ${OpenCV_LIBS})
