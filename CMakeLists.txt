cmake_minimum_required(VERSION 3.19)
project(avacados)

set(CMAKE_CXX_STANDARD 14)

add_library(avacados src/maze_node.cpp src/maze_parser.cpp src/maze_graph.cpp src/A*.cpp)
target_include_directories(avacados PUBLIC include)

add_executable(avacados_main src/main.cpp)
target_include_directories(avacados_main PUBLIC include)
target_link_libraries(avacados_main avacados)

add_subdirectory(test)