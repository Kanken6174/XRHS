#!/bin/bash
mkdir -p ~/code/auto_installed/
cd ~/code/auto_installed/

# Update system and install base dependencies
sudo pacman -Syu --noconfirm
sudo pacman -S --noconfirm git cmake gcc wget unzip base-devel ccache pkg-config

#-------------------------------------------------zbar
sudo pacman -S --noconfirm zbar

#-------------------------------------------------gl deps
PACKAGES="glm freetype2 glew glfw-assimp xorg-server libglvnd freeglut opencv tbb pthread-stubs pkg-config hidapi"
sudo pacman -S --noconfirm $PACKAGES

#------------------------------------------------------------------------------------Hidapi
mkdir hid
cd hid
git clone https://github.com/libusb/hidapi
cd hidapi

cmake .
cmake --build . -j7
sudo make install
sudo ldconfig
#------------------------------------------------------------------------------------LinuxSerial
git clone https://github.com/gbmhunter/CppLinuxSerial

cd CppLinuxSerial
mkdir build
cd build

cmake ..
make
sudo make install

cd ..

#-------------------------------------------------------------------------------------Opencv
cd ~/code/auto_installed/

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/include/libpng

# Install necessary dependencies for OpenCV
sudo pacman -S --noconfirm ffmpeg glew mesa glm gtk2 opencl-headers

# Create OpenCV directory and download OpenCV and contrib modules
rm -rf ./ocv/
mkdir ocv
cd ocv

wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip -o opencv.zip
unzip -o opencv_contrib.zip

rm opencv.zip
rm opencv_contrib.zip

sudo ldconfig

# Build OpenCV
mkdir -p build && cd build
cmake -DOPENCV_EXTRA_MODULES_PATH=../opencv_contrib-4.x/modules ../opencv-4.x \
 -DWITH_FFMPEG=ON -DWITH_OPENGL=ON -DWITH_OPENCL=ON -DWITH_GTK=ON -DWITH_GTK_2_X=ON -DWITH_QT=OFF -DWITHTBB=ON \
 -DWITH_CUDA=OFF -DBUILD_TESTS=OFF -DBUILD_PERF_TESTS=OFF -DBUILD_PNG=ON

#-------------------------------------------------build project
# Get the number of cores
NUM_CORES=$(nproc)
# Add 1 to the number of cores
NUM_JOBS=$((NUM_CORES + 1))
# Build with cmake
cmake --build . -j$NUM_JOBS
sudo make install
sudo ldconfig