#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "util/defs.hpp"
#include <chrono>

class SDL_Window;
class SDL_Renderer;

namespace BE {
const double FRAME_RATE = 60.0;
const double INV_FRAME_RATE = 1.0 / FRAME_RATE;

namespace Managers {
class RenderingManager;
}

class Engine {
public:
  Engine();
  ~Engine();

  void init();
  void run();
  void stop();
  void cleanup();
  bool isRunning() const;

private:
  void startLoopTimer();
  void handleLoopTiming();

private:
  bool m_isRunning;
  long frame = 0;
  std::chrono::time_point<std::chrono::high_resolution_clock> m_start;
};
} // namespace BE

#endif // ENGINE_HPP