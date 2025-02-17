#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <chrono>
namespace BE {
const double FRAME_RATE = 60.0;
const double INV_FRAME_RATE = 1.0 / FRAME_RATE;

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
  std::chrono::time_point<std::chrono::high_resolution_clock> start;
};
} // namespace BE

#endif // ENGINE_HPP