#include "rendering_manager.hpp"
#include "../components/renderer.hpp"

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cassert>
#include <iostream>

namespace BE {
namespace Managers {
static RenderingManager *smp_instance;

RenderingManager *RenderingManager::getInstance() {
  assert(smp_instance);
  return smp_instance;
}

void RenderingManager::initInstance() {
  assert(!smp_instance);
  smp_instance = new RenderingManager;
}

void RenderingManager::cleanupInstance() { smp_instance->cleanup(); }

RenderingManager::RenderingManager()
    : mp_window(nullptr), mp_renderer(nullptr), m_window_size({0, 0}) {}

RenderingManager::~RenderingManager() {}

void RenderingManager::init(int width, int height) {
  m_window_size[0] = width;
  m_window_size[1] = height;

  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "Error initializing SDL" << std::endl;

    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION,
                 "SDL could not initialize! SDL_Error: %s", SDL_GetError());
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  } else {
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "SDL initialized");

    // create window
    mp_window = SDL_CreateWindow("TurboHybrid Engine", width, height,
                                 SDL_WINDOW_OPENGL);

    if (mp_window == NULL) {
      std::cerr << "Error creating window" << std::endl;
    } else {
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Window created");
    }

    // create a renderer
    mp_renderer = SDL_CreateRenderer(mp_window, NULL);

    // check if the renderer was created
    if (mp_renderer == NULL) {
      std::cerr << "Error creating renderer" << std::endl;
    } else {
      SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Renderer created");
    }
  }
}

void RenderingManager::cleanup() {
  // clean up sdl window and renderer
  SDL_DestroyRenderer(mp_renderer);
  SDL_DestroyWindow(mp_window);

  delete smp_instance;
  smp_instance = nullptr;
}

void RenderingManager::render() {
  // check if the renderer was cleared
  if (!SDL_RenderClear(mp_renderer)) {
    std::cerr << "Error clearing renderer" << std::endl;
  } else {
    SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Renderer cleared");
  }

  // set the draw color
  SDL_SetRenderDrawColor(mp_renderer, 255, 0, 0, 255);

  //   // draw a rectangle
  SDL_FRect rect = {0, 0, (float)m_window_size[0], (float)m_window_size[1]};
  SDL_RenderFillRect(mp_renderer, &rect);

  // draw the background using sdl

  // render all render components
  for (Ptr<Components::Renderer> &renderComponent : m_renderer_components) {
    renderComponent.get()->render(mp_renderer);
  }

  SDL_RenderPresent(mp_renderer);

  // print done rendering
  SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, "Done rendering");
}

void RenderingManager::addComponent(
    Ptr<Components::Renderer> renderer_component) {
  m_renderer_components.push_back(renderer_component);
}

} // namespace Managers
} // namespace BE