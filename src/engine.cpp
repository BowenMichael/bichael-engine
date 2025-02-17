
#include "engine.hpp"
#include "managers/input_manager.hpp"
#include "version.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_scancode.h>

#include <chrono>
#include <iostream>
#include <thread>

namespace BE {
Engine::Engine() : m_isRunning(true) {}

Engine::~Engine() {}

void Engine::init() {
  // init SDL

  SDL_SetAppMetadata(std::string(PROJECT_NAME).c_str(),
                     std::string(VERSION).c_str(), "bichael");

  if (SDL_Init(SDL_INIT_EVENTS) < 0) {
    std::cerr << "Error initializing SDL" << std::endl;
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }
  else {
    
  }

  // init input manager
  Managers::InputManager::initInstance();
  Managers::InputManager::getInstance()->init();
}

void Engine::run() {
  // start loop timer
  startLoopTimer();

  // print handle loop timing
  // std::cout << "Handle loop timing" << std::endl;

  // check if the escape key is pressed
  //   if
  //   (Managers::InputManager::getInstance()->getKeyState(SDL_SCANCODE_ESCAPE))
  //   {
  //     // stop the game manager
  //     stop();
  //   }

  // handle loop timing
  handleLoopTiming();
}

void Engine::stop() {
  std::cout << "GameManager stop" << std::endl;
  m_isRunning = false;
}

void Engine::cleanup() {}

bool Engine::isRunning() const { return m_isRunning; }

void Engine::startLoopTimer() {
  // start a chrono timer
  start = std::chrono::high_resolution_clock::now();
}

void Engine::handleLoopTiming() {
  // sleep for 10 ms
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  // compute the time difference from start to now
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
      end.time_since_epoch() - start.time_since_epoch());

  // print the elapsed time
  // std::cout << "Elapsed time: " << elapsed.count() / 1000000.0 << "ms\n";

  // create duration in seconds
  auto frameDuration = std::chrono::duration<double>(INV_FRAME_RATE);

  // calculate the remaining frame time by casting frame duration to
  // microseconds
  auto remainingFrameTime = frameDuration - elapsed;

  // sleep for the remaining frame time
  std::this_thread::sleep_for(remainingFrameTime);

  // print time slept for
  //   std::cout << "Slept for: "
  //             << std::chrono::duration_cast<std::chrono::nanoseconds>(
  //                    remainingFrameTime)
  //                        .count() /
  //                    1000000.0

  //             << "ms\n";
}
} // namespace BE