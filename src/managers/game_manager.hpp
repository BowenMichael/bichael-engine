#pragma once

namespace BE {
namespace Managers {

class GameManager {
public:
  GameManager();

  ~GameManager();

  void init();

  void run();

  void stop();

  void cleanup();

  bool isRunning() const;

private:
  bool m_isRunning;
};
} // namespace Managers
} // namespace BE