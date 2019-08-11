cmake_minimum_required(VERSION 2.8)
project(tutorial)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Problem src/problem_book.cpp)
target_link_libraries(Problem ${OpenCV_LIBS})
