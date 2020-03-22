#ifndef BREAD_TEST_LIBRARY_H
#define BREAD_TEST_LIBRARY_H

#include <stdexcept>
#include <string>
#include <iostream>

std::string hello();

template<typename... Args>
std::string SPrintF(const char *format, Args &&... args);

std::string SPrintF(const char *format);

#endif //BREAD_TEST_LIBRARY_H
