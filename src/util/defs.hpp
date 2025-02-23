#ifndef __DEFS_H__
#define __DEFS_H__


#include <memory>

// Date: 2021-09-26

// typedef shorthand template for a shared_ptr

template <typename T> using Ptr = std::shared_ptr<T>;
template <typename T> using uPtr = std::unique_ptr<T>;

// create a template for a make shared pointer
template <typename T, typename... Args> Ptr<T> MakePtr(Args &&...args) {
  return std::make_shared<T>(std::forward<Args>(args)...);
}

template <typename T, typename... Args> Ptr<T> MakeUPtr(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

#endif // __DEFS_H__