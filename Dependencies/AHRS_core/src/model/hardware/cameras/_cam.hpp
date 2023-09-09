#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <regex>
#include <execution>
#include <vector>
#include <thread>
#include <mutex> 
#include <chrono>
#include <opencv2/opencv.hpp>
#pragma once
#include <opencv2/videoio/videoio_c.h>
#include "./../../../threadweaver/threadweaver.hpp"

using namespace std;
using namespace cv;

std::vector<std::string> listCameras();

class camera{
    public:
    uint path;
    VideoCapture* source;
    int Yindex = 0; //index for the stitcher
};

class stubCamera : public camera{
    public:
    stubCamera() {
        path = 255;
        source = nullptr;
        source = new cv::VideoCapture("./Ressources/Textures/noi.jpeg");
    }
};

class cameraManager{
    protected:
    UMat stubImage = cv::imread("./Ressources/Textures/noi2.png").getUMat( ACCESS_READ );;

    public:
    std::vector<camera*> videoSources;
    std::vector<UMat> captures;
    std::vector<std::mutex*> accessLocks;
    bool runCaptureThread;
    cameraManager();
    void runCapture();
    void stopCapture();
    private:
    void runCaptureForCamera(camera* c, uint index);
};