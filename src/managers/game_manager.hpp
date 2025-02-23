#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "../util/defs.hpp"
#include <SDL3/SDL_log.h>
#include <vector>

namespace BE {
namespace Objects {
class Object;
}
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

  // add object with generic constructor arguments
  Ptr<Objects::Object> addObject(const Objects::Object &object);

private:
  std::vector<Ptr<Objects::Object>> m_objects;
};

} // namespace Managers
} // namespace BE


#endif // __GAME_MANAGER_H__