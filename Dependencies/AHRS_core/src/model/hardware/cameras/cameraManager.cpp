#include "_cam.hpp"
#include <signal.h>
#include <unordered_set>

void cameraManager::runCaptureForCamera(camera* c, uint index){
    while(runCaptureThread){
        if(!c->source->isOpened()){
            cout << "camera " << c->path << " is closed, opening..." << endl;
            if(!c->source->open(c->path)){
                cout << "couldn't open camera with index " << c->path << endl;
            }else{
                c->source->set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
                c->source->set(CV_CAP_PROP_FPS , FPS_LIMIT_PSEYE);
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
            cv::VideoCapture vs(camID);
            if(!vs.isOpened() || !vs.open(camID)) {
                std::cout << "\x1B[31mopening camera " << camIdx << " failed\033[0m" << std::endl;
                vs.release();
            } else {
                vs.release();
                camera* cam = new camera();
                cam->source = new cv::VideoCapture(camID, cv::CAP_FFMPEG);
                cam->source->set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
                cam->source->set(CV_CAP_PROP_FPS , FPS_LIMIT_PSEYE);
                cam->source->set(cv::CAP_PROP_FRAME_WIDTH, 1920);
                cam->source->set(cv::CAP_PROP_FRAME_HEIGHT, 1080);

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