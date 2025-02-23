#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "../util/defs.hpp"
#include "base_component.hpp"

class SDL_Renderer;

namespace BE {

namespace Objects {
class Object;
}

namespace Managers {
class RenderingManager;

}

namespace Components {

class Renderer : public BaseComponent {
public:
  Renderer(Ptr<Objects::Object> object);

  ~Renderer();

  // init
  void init() override;

  void run() override;

  void cleanup() override;

  // render
  void render(SDL_Renderer *renderer);

private:
  int m_type;
};
} // namespace Components
} // namespace BE
#endif // __RENDERER_H__