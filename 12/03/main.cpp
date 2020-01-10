#include <iostream>
#define CATCH_CONFIG_RUNNER
#include "catch.h"

int main(int argc, char** argv) {
    int r = Catch::Session().run(argc, argv);
    std::cout << "Resultatwert: " << r << std::endl;
    return r;
}
