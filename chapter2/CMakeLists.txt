cmake_minimum_required(VERSION 2.8)
project(tutorial)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(Display_img src/display_img.cpp)
target_link_libraries(Display_img ${OpenCV_LIBS})

add_executable(Display_movie src/display_movie.cpp)
target_link_libraries(Display_movie ${OpenCV_LIBS})

add_executable(Display_movie_re src/display_movie_re.cpp)
target_link_libraries(Display_movie_re ${OpenCV_LIBS})

add_executable(Gaussian_blur src/gaussianblur.cpp)
target_link_libraries(Gaussian_blur ${OpenCV_LIBS})

add_executable(PyrDown src/pyrDown.cpp)
target_link_libraries(PyrDown ${OpenCV_LIBS})

add_executable(Canny src/canny.cpp)
target_link_libraries(Canny ${OpenCV_LIBS})

add_executable(VideoWriter src/videowriter.cpp)
target_link_libraries(VideoWriter ${OpenCV_LIBS})
