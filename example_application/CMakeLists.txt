cmake_minimum_required(VERSION 3.4)
project(example)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(example ${CMAKE_CURRENT_SOURCE_DIR}/example2.cpp)

