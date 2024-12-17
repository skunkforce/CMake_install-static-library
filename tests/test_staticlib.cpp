#include "StaticLib.h"
#include <cassert>
#include <iostream>

int main() {
    StaticLib lib;
    lib.sayHello();
    std::cout << "Test passed: sayHello() works correctly." << std::endl;
    return 0;
}