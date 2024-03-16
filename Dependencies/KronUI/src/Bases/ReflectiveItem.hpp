#ifndef Guard_ReflectiveItem
#define Guard_ReflectiveItem
#include <string>
#include <sstream>

class ReflectiveItem{
private:
    std::string _name = "";
    const void * address = static_cast<const void*>(this);
public:
    ReflectiveItem(std::string name){
        std::stringstream ss;
        ss << "ReflectiveItem" << ":" << address;
        _name = ss.str(); 
    }
    std::string getName() {return _name;}
    ReflectiveItem* getAddress() {return this;}
};

#endif