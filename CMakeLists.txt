cmake_minimum_required(VERSION 3.19)
project(avacados)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG  "-g")
set(CMAKE_BUILD_TYPE Debug)

add_library(avacados
        src/maze_node.cpp
        src/maze_parser.cpp
        src/shortest_path.cpp
        src/A*.cpp
        src/shortest_path_astar.cpp )

target_include_directories(avacados PUBLIC include)

add_executable(avacados_main src/main.cpp)
target_include_directories(avacados_main PUBLIC include)
target_link_libraries(avacados_main avacados)

add_subdirectory(test)