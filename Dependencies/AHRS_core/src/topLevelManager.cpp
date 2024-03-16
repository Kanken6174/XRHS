#include "topLevelManager.hpp"

using namespace psvr;

topLevelManager::topLevelManager()
{
    try
    {
        detectHWAndConfig();
        setupThreads();
        std::cout << "Config finished, main thread now sleeping" << endl;
        /*while (true)
        {
            sleep(1);
        }*/
    }
    catch (...)
    {
        cerr << "caught main thread exception" << endl;
        exit(1);
    }

    DEBUG_LOG("Exitted sleep while")
    //Threadweaver::gfxPipelineThread->join();
}

void topLevelManager::detectHWAndConfig(){
    char tmp[256];
    getcwd(tmp, 256);
    std::cout << "Current working directory: " << tmp << std::endl;

    unsigned num_cpus = std::thread::hardware_concurrency();
    cout << num_cpus << " cores detected" << endl;
    std::cout << cv::getBuildInformation() << std::endl;
}

void topLevelManager::setupThreads(){
    localPipeline = new Pipeline();
}