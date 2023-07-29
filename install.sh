#!/bin/bash
mkdir -p ~/code/auto_installed/
cd ~/code/auto_installed/

sudo apt update -y
sudo apt upgrade -y
sudo apt install -y git cmake g++ wget unzip build-essential ccache pkg-config
#-------------------------------------------------zbar
sudo apt-get install -y libzbar-dev
#-------------------------------------------------gl deps
PACKAGES="libglm-dev libfreetype6-dev libglew-dev libglfw3-dev libassimp-dev libx11-dev libgl1-mesa-dev freeglut3-dev libopencv-dev libtbb-dev libpthread-stubs0-dev pkg-config libhidapi-dev"
sudo apt-get install -y $PACKAGES
#------------------------------------------------------------------------------------Hidapi
sudo apt-get install -y libudev-dev libusb-1.0-0-dev
mkdir hid
cd hid
git clone https://github.com/libusb/hidapi
cd hidapi

cmake .
cmake --build . -j7
sudo make install
sudo ldconfig
#-------------------------------------------------------------------------------------Opencv
cd ~/code/auto_installed/

sudo apt-get install -y libtbb-dev ffmpeg freeglut3 freeglut3-dev binutils-gold libglew-dev mesa-common-dev libglm-dev libtbb-dev mesa-utils gtk2.0 libgtkglext1 libgtkglext1-dev libcanberra-gtk-module

sudo apt-get install -y ffmpeg libavcodec-dev libavformat-dev libavutil-dev libswscale-dev

sudo apt-get install -y libgtk2.0-dev libgl1-mesa-dev libglu1-mesa-dev

mkdir ocv
cd ocv

wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip -o opencv.zip
unzip -o opencv_contrib.zip

rm opencv.zip
rm opencv_contrib.zip

mkdir -p build && cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x -DWITH_FFMPEG=ON -DWITH_OPENGL=ON -DWITH_OPENCL=ON -DWITH_GTK=ON -DWITH_QT=OFF -DWITHTBB=ON
#-------------------------------------------------build project
# Get the number of cores
NUM_CORES=$(nproc)
# Add 1 to the number of cores
NUM_JOBS=$((NUM_CORES + 1))
# Build with cmake
cmake --build . -j$NUM_JOBS
sudo make install
sudo ldconfig
