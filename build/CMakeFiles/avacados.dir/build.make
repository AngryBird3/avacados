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
include CMakeFiles/avacados.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/avacados.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/avacados.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/avacados.dir/flags.make

CMakeFiles/avacados.dir/src/maze_node.cpp.o: CMakeFiles/avacados.dir/flags.make
CMakeFiles/avacados.dir/src/maze_node.cpp.o: ../src/maze_node.cpp
CMakeFiles/avacados.dir/src/maze_node.cpp.o: CMakeFiles/avacados.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/avacados.dir/src/maze_node.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avacados.dir/src/maze_node.cpp.o -MF CMakeFiles/avacados.dir/src/maze_node.cpp.o.d -o CMakeFiles/avacados.dir/src/maze_node.cpp.o -c /Users/dharabalaji/CLionProjects/avacados/src/maze_node.cpp

CMakeFiles/avacados.dir/src/maze_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avacados.dir/src/maze_node.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dharabalaji/CLionProjects/avacados/src/maze_node.cpp > CMakeFiles/avacados.dir/src/maze_node.cpp.i

CMakeFiles/avacados.dir/src/maze_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avacados.dir/src/maze_node.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dharabalaji/CLionProjects/avacados/src/maze_node.cpp -o CMakeFiles/avacados.dir/src/maze_node.cpp.s

CMakeFiles/avacados.dir/src/maze_parser.cpp.o: CMakeFiles/avacados.dir/flags.make
CMakeFiles/avacados.dir/src/maze_parser.cpp.o: ../src/maze_parser.cpp
CMakeFiles/avacados.dir/src/maze_parser.cpp.o: CMakeFiles/avacados.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/avacados.dir/src/maze_parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/avacados.dir/src/maze_parser.cpp.o -MF CMakeFiles/avacados.dir/src/maze_parser.cpp.o.d -o CMakeFiles/avacados.dir/src/maze_parser.cpp.o -c /Users/dharabalaji/CLionProjects/avacados/src/maze_parser.cpp

CMakeFiles/avacados.dir/src/maze_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/avacados.dir/src/maze_parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dharabalaji/CLionProjects/avacados/src/maze_parser.cpp > CMakeFiles/avacados.dir/src/maze_parser.cpp.i

CMakeFiles/avacados.dir/src/maze_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/avacados.dir/src/maze_parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dharabalaji/CLionProjects/avacados/src/maze_parser.cpp -o CMakeFiles/avacados.dir/src/maze_parser.cpp.s

# Object files for target avacados
avacados_OBJECTS = \
"CMakeFiles/avacados.dir/src/maze_node.cpp.o" \
"CMakeFiles/avacados.dir/src/maze_parser.cpp.o"

# External object files for target avacados
avacados_EXTERNAL_OBJECTS =

libavacados.a: CMakeFiles/avacados.dir/src/maze_node.cpp.o
libavacados.a: CMakeFiles/avacados.dir/src/maze_parser.cpp.o
libavacados.a: CMakeFiles/avacados.dir/build.make
libavacados.a: CMakeFiles/avacados.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libavacados.a"
	$(CMAKE_COMMAND) -P CMakeFiles/avacados.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/avacados.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/avacados.dir/build: libavacados.a
.PHONY : CMakeFiles/avacados.dir/build

CMakeFiles/avacados.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/avacados.dir/cmake_clean.cmake
.PHONY : CMakeFiles/avacados.dir/clean

CMakeFiles/avacados.dir/depend:
	cd /Users/dharabalaji/CLionProjects/avacados/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dharabalaji/CLionProjects/avacados /Users/dharabalaji/CLionProjects/avacados /Users/dharabalaji/CLionProjects/avacados/build /Users/dharabalaji/CLionProjects/avacados/build /Users/dharabalaji/CLionProjects/avacados/build/CMakeFiles/avacados.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/avacados.dir/depend
