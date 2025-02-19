#include "engine.hpp"
#include "managers/game_manager.hpp"
#include "managers/input_manager.hpp"
#include "managers/rendering_manager.hpp"
#include "util/defs.hpp"
#include "version.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_video.h>

#include <SDL3/SDL_video.h>
#include <chrono>
#include <thread>

namespace BE {

#define WIDTH 800
#define HEIGHT 600
Engine::Engine() : m_isRunning(true), mp_rendering_manager(nullptr) {}

Engine::~Engine() {}

void Engine::init() {
  // init SDL

  SDL_SetAppMetadata(std::string(PROJECT_NAME).c_str(),
                     std::string(VERSION).c_str(), "bichael");

  // set log level to debug
  if (BUILD_TYPE == "Debug")
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_DEBUG);

  // init rendering manager
  mp_rendering_manager = MakePtr<Managers::RenderingManager>();
  mp_rendering_manager.get()->init(WIDTH, HEIGHT);

  // init input manager
  Managers::InputManager::initInstance();
  Managers::InputManager::getInstance()->init();

  // init game manager
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "GameManager init");
  Managers::GameManager::initInstance();
  Managers::GameManager::getInstance()->init();
}

void Engine::run() {
  // start loop timer
  startLoopTimer();

  SDL_Event event;
  while (SDL_PollEvent(&event)) {

    // check for mouse movement
    if (event.type == SDL_EVENT_MOUSE_MOTION) {
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Mouse moved");
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "We got a motion event.");
    }

    // check for input events
    if (event.type == SDL_EVENT_KEY_DOWN) {
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Key pressed");
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "We got a key press event.");
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
                   "The key pressed has a scancode of %u", event.key.scancode);
      SDL_Log("The key pressed has a scancode of %u", event.key.scancode);

      if (event.key.scancode == SDL_SCANCODE_ESCAPE) {
        // stop the game manager
        stop();
      }
    }

    // print event type
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Event type: %d", event.type);
  }

  // print mouse state of left button

  if (Managers::InputManager::getInstance()->getMouseState(SDL_BUTTON_LEFT)) {
    SDL_Log("Left mouse button pressed");

    // TODO: add object
    Managers::GameManager::getInstance()->addObject();
  }

  // print done polling events
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Done polling events");

  // print done getting key state
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Done getting key state");

  // render
  mp_rendering_manager->render();

  // handle loop timing
  handleLoopTiming();
}

void Engine::stop() {
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "GameManager stop");
  m_isRunning = false;

  // quit sdl
  SDL_Quit();
}

void Engine::cleanup() {
  // cleanup game manager
  Managers::GameManager::cleanupInstance();

  // cleanup input manager
  Managers::InputManager::cleanupInstance();

  // cleanup rendering manager
  mp_rendering_manager->cleanup();
}
bool Engine::isRunning() const { return m_isRunning; }

void Engine::startLoopTimer() {
  // start a chrono timer
  m_start = std::chrono::high_resolution_clock::now();
}

void Engine::handleLoopTiming() {
  // sleep for 10 ms
  // std::this_thread::sleep_for(std::chrono::milliseconds(10));

  // compute the time difference from start to now
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(
      end.time_since_epoch() - m_start.time_since_epoch());

  // print the elapsed time
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Elapsed time: %f ms",
               elapsed.count() / 1000000.0);

  // create duration in seconds
  auto frameDuration = std::chrono::duration<double>(INV_FRAME_RATE);

  // calculate the remaining frame time by casting frame duration to
  // microseconds
  auto remainingFrameTime = frameDuration - elapsed;

  // sleep for the remaining frame time
  std::this_thread::sleep_for(remainingFrameTime);
  frame++;

  // print frame
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Frame: %ld", frame);

  // print time slept for
  SDL_LogDebug(
      SDL_LOG_CATEGORY_APPLICATION, "Slept for: %f ms",
      std::chrono::duration_cast<std::chrono::nanoseconds>(remainingFrameTime)
              .count() /
          1000000.0);
}
} // namespace BE