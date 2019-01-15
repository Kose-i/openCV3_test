cmake_minimum_required(VERSION 2.8)
project(tutorial)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Display_elem src/display_elem.cpp)
target_link_libraries(Display_elem ${OpenCV_LIBS})
