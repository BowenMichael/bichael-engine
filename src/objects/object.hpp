#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "../components/renderer.hpp"
#include "/home/mbowen/repos/c++/example/src/util/defs.hpp"
#include <SDL3/SDL_log.h>
#include <bits/stdc++.h>
#include <vector>

namespace BE::Components {
class BaseComponent;
}

namespace BE::Objects {
class Object {
public:
  Object() : Object(nullptr, (float[3]){0.0f, 0.0f, 0.0f}){};

  // constructor with name
  Object(char *name) : Object(name, (float[3]){0.0f, 0.0f, 0.0f}) {}

  // constructor with name and position
  Object(char *name, float position[3])
      : m_id(generateId()), m_name(name),
        m_position{position[0], position[1], position[2]} {}

  ~Object();

  void init();

  void run();

  void cleanup();

  // add, remove and get template components
  template <typename T, typename... Args> Ptr<T> addComponent(Args &&...args) {
    // check if component already exists
    for (auto &component : m_components) {
      if (dynamic_cast<T *>(component.get())) {
        // log an error
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Component already exists");
        return nullptr;
      }
    }

    Ptr<T> new_component = MakePtr<T>(std::forward<Args>(args)...);

    m_components.push_back(new_component);
    return new_component;
  }

  template <typename T>
  Ptr<T> getComponent() { // check if component already exists
    for (auto &component : m_components) {
      if (dynamic_cast<T *>(component.get())) {
        return std::dynamic_pointer_cast<T>(component);
      }
    }

    // log an error
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Component does not exist");

    return nullptr;
  }

  template <typename T> void removeComponent() {
    // check if component already exists
    for (auto &component : m_components) {
      if (dynamic_cast<T *>(component.get())) {
        // remove the component from vector
        auto it =
            std::remove(m_components.begin(), m_components.end(), component);
        m_components.erase(it, m_components.end());
        return;
      }
    }
    // log an error
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Component does not exist");
  }

  // get position
  float *getPosition() { return m_position; }

private:
  int m_id;
  char *m_name;
  float m_position[3];
  std::vector<Ptr<Components::BaseComponent>> m_components;

  static int generateId() {
    static int s_id = 0;
    return s_id++;
  }
};
} // namespace BE::Objects
#endif // __OBJECT_H__