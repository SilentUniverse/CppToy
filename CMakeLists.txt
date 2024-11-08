cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(err VERSION 0.0.1 LANGUAGES C CXX)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)