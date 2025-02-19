#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_scancode.h>
#include <SDL3/SDL_stdinc.h>
#include <cassert>
namespace BE::Managers {
class InputManager {
public:
  InputManager();

  ~InputManager();

  void init();

  void run();

  // Get Key State
  bool getKeyState(SDL_Scancode key);
  bool getKeyStateDown(SDL_Scancode key);
  bool getKeyStateUp(SDL_Scancode key) const;

  // Get Mouse State
  bool getMouseState(int button) const;
  bool getMouseStateDown(int button) const;
  bool getMouseStateUp(int button) const;

  // singleton pattern
  static InputManager *getInstance();
  static void initInstance();
  static void cleanupInstance();

private:
  // keybord state
  const bool *mp_keyborad_state;
  const Uint32 *mp_mouse_state;

  SDL_Scancode m_last_key_pressed;
};
} // namespace BE::Managers
#endif // __INPUT-MANAGER_H__