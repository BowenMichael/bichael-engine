#ifndef __BASE_COMPONENT_H__
#define __BASE_COMPONENT_H__

#include "../util/defs.hpp"

namespace BE::Objects {
class Object;
}

namespace BE::Components {
class BaseComponent {
public:
  BaseComponent(Ptr<Objects::Object> object)
      : mp_object(object), m_id(generateId()) {}

  virtual ~BaseComponent() = default;

  // get component type
  int getComponentType() const;

  // get component id
  int getId() const { return m_id; }

  virtual void init() = 0;

  virtual void run() = 0;

  virtual void cleanup() = 0;

protected:
  Ptr<Objects::Object> mp_object;

private:
  char *m_name;
  int m_component_type;
  int m_id;

  static int generateId() {
    static int s_id = 0;
    return s_id++;
  }
};
} // namespace BE::Components
#endif // __BASE_COMPONENT_H__