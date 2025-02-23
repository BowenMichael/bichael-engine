#include "base_component.hpp"

namespace BE::Components {

int BaseComponent::getComponentType() const {
  // return the component type
  return m_component_type;
}

} // namespace BE::Components