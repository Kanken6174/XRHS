#include "_cam.hpp"
#include <signal.h>
#include <unordered_set>

std::string pipeline = "v4l2src device=/dev/video0 ! "
                        "image/jpeg,width=1920,height=1080,framerate=30/1 ! "
                        "jpegdec ! videoconvert ! appsink";

void cameraManager::runCaptureForCamera(camera* c, uint index){
    if(!c->source->isOpened()){
        cout << "camera " << c->path << " is closed, opening..." << endl;
        if(!c->source->open(pipeline)){
            cout << "couldn't open camera with index " << c->path << endl;
        }else{
            std::cout << "camera re-opened\n";
        }
    }

    while(runCaptureThread){
        if(!c->source->isOpened()){
            cout << "camera " << c->path << " is closed, opening..." << endl;
            if(!c->source->open(pipeline)){
                cout << "couldn't open camera with index " << c->path << endl;
            }else{
                std::cout << "camera re-opened\n";
            }
        }

        if(c->source->grab()){
            UMat surface;
            c->source->retrieve(surface);
            accessLocks[index]->lock();
            captures[index] = surface;
            accessLocks[index]->unlock();
        } else {
            cout << "read error grabbing from camera " << c->path << endl;
        }
    }
}

cameraManager::cameraManager() {
    std::cout << "init camera manager" << std::endl;
    std::vector<std::string> cameras = listCameras();
    std::unordered_set<int> invalid_cameras;

    // Parse invalid camera indices
    for(const auto& camIdx : cameras) {
        if(camIdx.find("dec") != std::string::npos || camIdx.find("enc") != std::string::npos) {
            std::string index_str = camIdx.substr(camIdx.find_last_of("-") + 1);
            invalid_cameras.insert(std::stoi(index_str));
        }
    }

    std::cout << "found " << cameras.size() << " cameras" << std::endl;

    for(std::string camIdx : cameras) {
        std::string index_str = camIdx.substr(camIdx.find_last_of("o") + 1);
        int camID = std::stoi(index_str);
        // If the camera index is invalid, skip it
        if(invalid_cameras.count(camID)) continue;

        try {
            
            if(camID == 0) {
                camera* cam = new camera();
                cam->source = new cv::VideoCapture(pipeline, cv::CAP_GSTREAMER);
                /*bool success = cam->source->set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
                if (!success) {
                    std::cerr << "Failed to set MJPEG FOURCC" << std::endl;
                }
                cam->source->set(CV_CAP_PROP_FPS , 60);
                cam->source->set(cv::CAP_PROP_FRAME_WIDTH, 1920);
                cam->source->set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
                */
                cam->path = camID;
                videoSources.push_back(cam);    //valid camera added
                std::cout << "\033[32m" << "added camera with path /dev/video" << cam->path << "\033[0m" << std::endl;
                cv::UMat m;
                captures.push_back(std::move(m));
            }
        } catch(std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "found " << std::to_string(videoSources.size()) << " valid cameras" << std::endl;
}


void cameraManager::runCapture(){
    cout << "cameraManager::runCapture------------------------------------------------\n" << "enabling capture thread for " << videoSources.size() << " cameras" << endl;
    uint i = 0;
    runCaptureThread = true;
    for(camera* c : videoSources){
        mutex* mlock = new mutex();
        mlock->unlock();
        accessLocks.push_back(mlock);
        cout << "enabling camera " << i << endl;
        c->source->release();
        std::thread* t = new std::thread(&cameraManager::runCaptureForCamera,this,c,i);   //TODO fix thread handling
        i++;
        cout << "moving thread" << endl;
        Threadweaver::stick_this_thread_to_core(t,CAMCORE);
        //Threadweaver::captureThreads.push_back(t);
        cout << "done" << endl;
    }
    cout << "done enabling threads" << endl;
}

void cameraManager::stopCapture(){
    runCaptureThread = false;
    /*for(std::thread* t : Threadweaver::captureThreads){
        t->join();
        delete t;
    }*/
    //Threadweaver::captureThreads.clear();
    for(std::mutex* mlock : accessLocks){
        mlock->unlock();
        delete mlock;
    }
    accessLocks.clear();
}