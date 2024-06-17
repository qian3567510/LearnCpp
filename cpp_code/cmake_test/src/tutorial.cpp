// mkdir build
// cd build
// cmake -G "Ninja Multi-Config" -DUSE_MYMATH=ON ..
//OR cmake -G "Ninja Multi-Config" -DUSE_MYMATH=OFF ..
// cmake --build .

#include <cmath>
// #include <cstdlib>
#include <iostream>
#include <string>

#include "TutorialConfig.h"
//#include "MathFunctions.h"
#ifdef USE_MYMATH
    #include "MathFunctions.h"
#endif

int main(int argc, char *argv[])
{
    // report version
    std::cout << "Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << "." << Tutorial_VERSION_PATCH
              << " Build on " << TIMESTAMP << std::endl;

    if (argc < 2)
    {

        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    // convert input to double
    // const double inputValue = atof(argv[1]);
    const double inputValue = std::stod(argv[1]); // Support since C++ 11

    // calculate square root
    //const double outputValue = sqrt(inputValue);
    //const double outputValue = mathfunctions::sqrt(inputValue);
    #ifdef USE_MYMATH
        const double outputValue = mathfunctions::sqrt(inputValue);
    #else
        const double outputValue = sqrt(inputValue);
    #endif

    std::cout << "The square root of " << inputValue
              << " is " << outputValue
              << std::endl;
    return 0;
}