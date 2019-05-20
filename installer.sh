#!/bin/bash

# apt リポジトリ最新化
sudo apt update
sudo apt upgrade
sudo apt dist-upgrade
sudo apt autoremove

# Install build tool
sudo apt install build-essential cmake

# Install GUI using Qt
sudo apt install qt5-default libvtk6-dev

# Install MediaI/O
sudo apt install zlib1g-dev libjpeg-dev libwebp-dev libpng-dev libtiff5-dev libjasper-dev libopenexr-dev libgdal-dev

# Install VideoI/O
sudo apt install libdc1394-22-dev libavcodec-dev libavformat-dev libswscale-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev yasm libopencore-amrnb-dev libopencore-amrwb-dev libv4l-dev libxine2-dev

# Install 並列化と線形代数関係
sudo apt install libtbb-dev libeigen3-dev

# Install for python
sudo apt install python-dev python-tk python-numpy python3-dev python3-tk python3-numpy

# Install for Java
sudo apt install ant default-jdk

# Install compile documentation
sudo apt install doxygen graphviz

# Install OpenCL
sudo apt install ocl-icd-libopencl1

# Install OpenCV
sudo apt install libopencv-dev python-opencv

# Install Shared library
sudo ldconfig
