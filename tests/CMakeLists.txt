cmake_minimum_required(VERSION 3.15)

enable_testing()

set(GTEST_DIR ${PROJECT_SOURCE_DIR}/deps/googletest)

include_directories(${GTEST_DIR})
include_directories(../src)

add_subdirectory(${GTEST_DIR} gtest)

set(lib_test_source
        library.cpp)

add_executable(lib_run_tests ${lib_test_source})
target_link_libraries(lib_run_tests bread-lib gtest gtest_main)
add_test(NAME lib_tests
        COMMAND lib_run_tests
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})