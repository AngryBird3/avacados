#cmake_minimum_required(VERSION 3.19)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS_DEBUG  "-g")
#add_subdirectory(/usr/src/googletest googletest)
#add_subdirectory(/usr/src/gtest gtest)
#find_package(GTest CONFIG REQUIRED)
#include(GoogleTest)
#
##include(FetchContent)
##FetchContent_Declare(
##        googletest
##        # Specify the commit you depend on and update it regularly.
##        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
##)
##FetchContent_MakeAvailable(googletest)
###add_subdirectory(${CMAKE_BINARY_DIR}/googletest)
#
#add_executable(
#        tests
#        test_maze_parser.cpp
#)
#target_link_libraries(tests avacados GTest::gtest GTest::gtest_main)
#target_include_directories(tests PUBLIC include)
##add_test(NAME test_avacados COMMAND tests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#
#gtest_discover_tests(tests WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
