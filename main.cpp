#include <SDL3/SDL_init.h>
#include <iostream>

#include "build/version.h" // Ensure this file exists and is in the correct include path
#include "src/engine.hpp"

int main(int argc, char *argv[]) {
  std::cout << "Hello World\n";
  // report project name
  std::cout << "Project: " << PROJECT_NAME << std::endl;

  // report version
  std::cout << argv[0] << " Version " << VERSION << std::endl;

  // report compiler
  std::cout << "Compiler: " << COMPILER_NAME << " " << COMPILER_VERSION
            << std::endl;

  // report build type
  std::cout << "Build type: " << BUILD_TYPE << std::endl;

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
  }

  // init game manager
  BE::Engine engine;

  // init game manager
  engine.init();

  // run game manager
  while (engine.isRunning()) {
    engine.run();
  }

  engine.cleanup();

  return 0;
}
