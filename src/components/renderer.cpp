#include "renderer.hpp"
#include "../managers/rendering_manager.hpp"
#include "../objects/object.hpp"
#include "base_component.hpp"

#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
namespace BE::Components {

Renderer::Renderer(Ptr<Objects::Object> object)
    : BaseComponent(object), m_type('RECT') {}

Renderer::~Renderer() {}

void Renderer::init() {
  // register this component to the rendering manager
  BE::Managers::RenderingManager::getInstance()->addComponent(
      MakePtr<Renderer>(*this));
}

void Renderer::run() {}

void Renderer::cleanup() {}

void Renderer::render(SDL_Renderer *renderer) {
  Objects::Object *rawObject = mp_object.get();

  // get position of object
  float *position = rawObject->getPosition();

  if (m_type == 'RECT') {
    std::cout << "rendering rect\n";
    SDL_FRect rect = {position[0], position[1], 100, 100};
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
  } else if (m_type == 'TEXT') {
    // render texture
  } else {
    // log error
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unknown render type");
  }
}
} // namespace BE::Components
