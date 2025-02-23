#ifndef __RENDERING_MANAGER_H__
#define __RENDERING_MANAGER_H__

#include "../util/defs.hpp"
#include <array>
#include <vector>

class SDL_Window;
class SDL_Renderer;
namespace BE {

namespace Components {
class Renderer;
}

namespace Managers {
class RenderingManager {
public:
  RenderingManager();

  ~RenderingManager();

  void init(int width, int height);

  void cleanup();

  void render();

  // function to add renderer component
  void addComponent(Ptr<Components::Renderer> renderer_component);

  // singleton pattern
  static RenderingManager *getInstance();
  static void initInstance();
  static void cleanupInstance();

private:
  SDL_Window *mp_window = nullptr;
  SDL_Renderer *mp_renderer = nullptr;

  // window size
  std::array<int, 2> m_window_size;

  // list of render components
  std::vector<Ptr<Components::Renderer>> m_renderer_components;
};
} // namespace Managers
} // namespace BE

#endif // __RENDERING_MANAGER_H__