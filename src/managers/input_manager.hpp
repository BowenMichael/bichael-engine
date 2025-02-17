#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include <SDL3/SDL_scancode.h>
#include <cassert>
namespace BE::Managers {
class InputManager {
public:
  InputManager();

  ~InputManager();

  void init();

  void run();

  // Get Key State
  bool getKeyState(SDL_Scancode key) const;
  bool getKeyState(SDL_Scancode key, int state) const;

  // Get Mouse State
  bool getMouseState(int button) const;
  bool getMouseState(int button, int state) const;

  // singleton pattern
  static InputManager *getInstance();
  static void initInstance();
  static void cleanupInstance();
};
} // namespace BE::Managers
#endif // __INPUT-MANAGER_H__