#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "../util/defs.hpp"

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

  // singleton pattern
  static GameManager *getInstance();
  static void initInstance();
  static void cleanupInstance();

private:
};
} // namespace Managers
} // namespace BE
#endif // __GAME_MANAGER_H__