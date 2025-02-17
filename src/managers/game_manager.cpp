#include "game_manager.hpp"
#include "input_manager.hpp"

#include <SDL3/SDL_scancode.h>
#include <iostream>

namespace BE {
namespace Managers {

GameManager::GameManager() : m_isRunning(true) {
  std::cout << "GameManager constructor" << std::endl;
}

GameManager::~GameManager() {
  std::cout << "GameManager destructor" << std::endl;
}

void GameManager::init() {
  std::cout << "GameManager init" << std::endl;
  InputManager::initInstance();
  InputManager::getInstance()->init();
}

void GameManager::run() {}

void GameManager::cleanup() { std::cout << "GameManager cleanup" << std::endl; }

} // namespace Managers
} // namespace BE