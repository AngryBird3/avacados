cmake_minimum_required(VERSION 3.19)
project(avacados)

set(CMAKE_CXX_STANDARD 14)

add_library(avacados src/maze_node.cpp src/maze_parser.cpp)
target_include_directories(avacados PUBLIC include)

#add_executable(avacados main.cpp)

add_subdirectory(test)