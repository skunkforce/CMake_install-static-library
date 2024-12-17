#include "StaticLib.h"
#include <iostream>

void StaticLib::sayHello() const {
    std::cout << "Hello from Static Library!" << std::endl;
}