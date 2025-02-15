#include <iostream>

#include "TutorialConfig.h"

int main(int argc, char const *argv[]) {
  std::cout << "Hello World\n";

  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
              << Tutorial_VERSION_MINOR << Tutorial_BUILD_TYPE <<  std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;

    return 0;
  }
}
