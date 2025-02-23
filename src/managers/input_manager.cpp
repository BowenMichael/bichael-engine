

#include "input_manager.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_mouse.h>
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
  // get the current state of the keyboard
  mp_keyborad_state = SDL_GetKeyboardState(NULL);
}

void InputManager::run() {}

bool InputManager::getKeyState(SDL_Scancode key) {

  if (mp_keyborad_state[key]) {
    m_last_key_pressed = key;
  }

  return (bool)mp_keyborad_state[key];
}

bool InputManager::getKeyStateDown(SDL_Scancode key) {
  if (m_last_key_pressed == key) {
    return true;
  }
  return false;
}

bool InputManager::getMouseState(int button) const {
  return SDL_BUTTON_MASK(button) & SDL_GetMouseState(NULL, NULL);
}

std::array<float, 2> InputManager::getMousePosition() {
  SDL_GetMouseState(&m_mouse_pos[0], &m_mouse_pos[1]);
  return m_mouse_pos;
}

} // namespace BE::Managers
