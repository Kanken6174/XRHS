#include "_cam.hpp"

//hidden to the rest of the program
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

//enumerates the cameras in the system, sends back the camera number for opencv
std::vector<std::string> listCameras() {
    std::cout << "listing cameras" << std::endl;
    std::vector<std::string> toreturn;
    std::string to,result = exec("ls /dev/video*");
    std::cout << "executed list command " << std::endl;
    
    std::stringstream ss(result);
    std::cout << "created stringstream" << std::endl;
    if (result != "") {
        while(std::getline(ss,to,'\n')){
            std::cout << "testing interface : " << to << std::endl;
            if (to.find("dec") == std::string::npos && to.find("enc") == std::string::npos) {
                to = std::regex_replace(to, std::regex(R"([\D])"), "");
                std::cout << "found valid camera " << to << std::endl;
                toreturn.push_back(to);
            }else {
                std::cout << "found invalid camera name match " << to << std::endl;
            }
        }
    }
    return toreturn;
}