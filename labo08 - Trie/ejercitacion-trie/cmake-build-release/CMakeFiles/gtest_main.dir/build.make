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
CMAKE_COMMAND = /opt/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/gtest_main.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest_main.dir/flags.make

CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o: CMakeFiles/gtest_main.dir/flags.make
CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o: ../tests/gtest-1.8.1/gtest_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o -c /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/tests/gtest-1.8.1/gtest_main.cc

CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/tests/gtest-1.8.1/gtest_main.cc > CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.i

CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/tests/gtest-1.8.1/gtest_main.cc -o CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

libgtest_main.a: CMakeFiles/gtest_main.dir/tests/gtest-1.8.1/gtest_main.cc.o
libgtest_main.a: CMakeFiles/gtest_main.dir/build.make
libgtest_main.a: CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest_main.dir/build: libgtest_main.a
.PHONY : CMakeFiles/gtest_main.dir/build

CMakeFiles/gtest_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gtest_main.dir/clean

CMakeFiles/gtest_main.dir/depend:
	cd /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release /home/julian/CLionProjects/Algo2-labos/labo08/ejercitacion-trie/cmake-build-release/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest_main.dir/depend
