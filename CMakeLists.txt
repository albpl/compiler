cmake_minimum_required(VERSION 3.12)
project(alb)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(abseil-cpp)

add_subdirectory(src)

add_subdirectory(executable)

add_subdirectory(tests)
