#include "game_manager.hpp"
#include "../components/renderer.hpp"
#include "../objects/object.hpp"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_scancode.h>
#include <cassert>
#include <iostream>

namespace BE {
namespace Managers {

static GameManager *smp_instance;

GameManager::GameManager() {}

GameManager::~GameManager() {
  std::cout << "GameManager destructor" << std::endl;
}

void GameManager::init() { std::cout << "GameManager init" << std::endl; }

void GameManager::run() {}

void GameManager::stop() {}

void GameManager::cleanup() {
  std::cout << "GameManager cleanup" << std::endl;
  delete smp_instance;
  smp_instance = nullptr;
}

GameManager *GameManager::getInstance() {
  // check if instance exists
  assert(!smp_instance);
  return smp_instance;
}

void GameManager::initInstance() {
  // check if instance exists
  if (smp_instance == nullptr) {
    smp_instance = new GameManager;
  } else {
    // log error
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "GameManager instance already exists");
    return;
  }
}

void GameManager::cleanupInstance() { smp_instance->cleanup(); }

Ptr<Objects::Object> GameManager::addObject(const Objects::Object &object) {
  // create a new object from the copied data
  Ptr<Objects::Object> newObject = MakePtr<Objects::Object>(object);

  std::cout << "Object Created\n";

  Ptr<Components::Renderer> renderer =
      newObject->addComponent<Components::Renderer>(newObject);

  std::cout << "Component Added\n";

  renderer->init();

  std::cout << "Component init\n";

  // add the new object to the list
  m_objects.push_back(newObject);

  return newObject;
}

} // namespace Managers
} // namespace BE