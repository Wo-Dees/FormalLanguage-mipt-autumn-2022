cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project(FormalLanguageCourse)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(play)
add_subdirectory(exe)
add_subdirectory(tests)