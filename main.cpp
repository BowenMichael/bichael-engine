#include <iostream>

#include "version.h" // Ensure this file exists and is in the correct include path

int main(int argc, char const *argv[]) {
  std::cout << "Hello World\n";
  // report project name
  std::cout << "Project: " << PROJECT_NAME << std::endl;

  // report version
  std::cout << argv[0] << " Version " << VERSION_MAJOR << "."
            << VERSION_MINOR << "." << VERSION_PATCH << std::endl;

  // report compiler
  std::cout << "Compiler: " << COMPILER_NAME << " " << COMPILER_VERSION << std::endl;

  // report build type
  std::cout << "Build type: " << BUILD_TYPE << std::endl;

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;


  }
  return 0;

}
