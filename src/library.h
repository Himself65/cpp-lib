#ifndef BREAD_TEST_LIBRARY_H
#define BREAD_TEST_LIBRARY_H

#include <cstring>
#include <stdexcept>
#include <string>
#include <iostream>
#include <memory>
#include <utility>
static int static_foo = 2;
int get_library_foo();
std::string hello();

class Foo {
public:
  Foo(int number) : number(number) {};

  int number;
};

template<typename... Args>
std::string SPrintF(const char *format, Args &&... args);

std::string SPrintF(const char *format);

#endif //BREAD_TEST_LIBRARY_H
