#include "library.h"

std::string hello() {
  return std::string("hello");
}

std::string SPrintFImpl(const char *format) {
  const char *p = strchr(format, '%');
  if (p == nullptr) {
    return format;
  } else if (*(p + 1) != '%') {
    throw std::runtime_error("Expected '%' behind %");
  }
  return std::string(format, p + 1) + SPrintFImpl(p + 2);
}

template<typename Arg, typename... Args>
std::string SPrintFImpl(
    const char *format, Arg &&arg, Args &&... args) {
  const char *p = strchr(format, '%');
  if (p == nullptr) {
    throw std::runtime_error("cannot find more '%' in format");
  }
  std::string ret(format, p);
  switch (*p) {
    case 'd':
      ret += "%D";
      break;
    default:
      ret += "UNFINISHED";
      break;
  }
  return ret + SPrintFImpl(p + 1, std::forward<Args>(args)...);
}

template<typename... Args>
std::string SPrintF(const char *format, Args &&... args) {
  return SPrintFImpl(format, std::forward<Args>(args)...);
}

std::string SPrintF(const char *format) {
  return SPrintFImpl(format);
}