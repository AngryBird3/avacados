# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.20.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.20.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dharabalaji/CLionProjects/avacados

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dharabalaji/CLionProjects/avacados/build

# Include any dependencies generated for this target.
include test/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/tests.dir/flags.make

test/CMakeFiles/tests.dir/test_maze_parser.cpp.o: test/CMakeFiles/tests.dir/flags.make
test/CMakeFiles/tests.dir/test_maze_parser.cpp.o: ../test/test_maze_parser.cpp
test/CMakeFiles/tests.dir/test_maze_parser.cpp.o: test/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/tests.dir/test_maze_parser.cpp.o"
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/tests.dir/test_maze_parser.cpp.o -MF CMakeFiles/tests.dir/test_maze_parser.cpp.o.d -o CMakeFiles/tests.dir/test_maze_parser.cpp.o -c /Users/dharabalaji/CLionProjects/avacados/test/test_maze_parser.cpp

test/CMakeFiles/tests.dir/test_maze_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test_maze_parser.cpp.i"
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dharabalaji/CLionProjects/avacados/test/test_maze_parser.cpp > CMakeFiles/tests.dir/test_maze_parser.cpp.i

test/CMakeFiles/tests.dir/test_maze_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test_maze_parser.cpp.s"
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dharabalaji/CLionProjects/avacados/test/test_maze_parser.cpp -o CMakeFiles/tests.dir/test_maze_parser.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test_maze_parser.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

test/tests: test/CMakeFiles/tests.dir/test_maze_parser.cpp.o
test/tests: test/CMakeFiles/tests.dir/build.make
test/tests: libavacados.a
test/tests: /usr/local/lib/libgtest.a
test/tests: /usr/local/lib/libgtest_main.a
test/tests: /usr/local/lib/libgtest.a
test/tests: test/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && /usr/local/Cellar/cmake/3.20.1/bin/cmake -D TEST_TARGET=tests -D TEST_EXECUTABLE=/Users/dharabalaji/CLionProjects/avacados/build/test/tests -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/dharabalaji/CLionProjects/avacados -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=tests_TESTS -D CTEST_FILE=/Users/dharabalaji/CLionProjects/avacados/build/test/tests[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/local/Cellar/cmake/3.20.1/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/CMakeFiles/tests.dir/build: test/tests
.PHONY : test/CMakeFiles/tests.dir/build

test/CMakeFiles/tests.dir/clean:
	cd /Users/dharabalaji/CLionProjects/avacados/build/test && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/tests.dir/clean

test/CMakeFiles/tests.dir/depend:
	cd /Users/dharabalaji/CLionProjects/avacados/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dharabalaji/CLionProjects/avacados /Users/dharabalaji/CLionProjects/avacados/test /Users/dharabalaji/CLionProjects/avacados/build /Users/dharabalaji/CLionProjects/avacados/build/test /Users/dharabalaji/CLionProjects/avacados/build/test/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/tests.dir/depend
