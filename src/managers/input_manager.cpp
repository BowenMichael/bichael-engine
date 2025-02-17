

#include "input_manager.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_scancode.h>
#include <cstdio>

namespace BE::Managers {
InputManager::InputManager() {}

InputManager::~InputManager() {}

static InputManager *smp_instance;

InputManager *InputManager::getInstance() {
  assert(smp_instance);
  return smp_instance;
}

void InputManager::initInstance() {
  assert(!smp_instance);
  smp_instance = new InputManager;
}

void InputManager::cleanupInstance() {
  delete smp_instance;
  smp_instance = nullptr;
}

void InputManager::init() {
  //
}

void InputManager::run() {
  // call get key state for the escape key
  if (getKeyState(SDL_SCANCODE_W)) {
    // call stop on the game manager
    // stop();
  }
}

bool InputManager::getKeyState(SDL_Scancode key) const {

  // print the key
  printf("Key: %d\n", key);

  // Get the state of the key using sdl3

  int *length;

  const bool *state = SDL_GetKeyboardState(length);

  // print the length of the state
  printf("Length: %d\n", *length);

  // loop over state for length if state at index is true print the index
  for (int i = 0; i < *length; i++) {
    if (state[i]) {
      printf("Key: %d\n", i);
    }
  }

  printf(state[key] ? "true" : "false");
  printf("\n");
  return state[key];
}

bool InputManager::getKeyState(SDL_Scancode key, int state) const {}

bool InputManager::getMouseState(int button) const {}

bool InputManager::getMouseState(int button, int state) const {}
} // namespace BE::Managers
