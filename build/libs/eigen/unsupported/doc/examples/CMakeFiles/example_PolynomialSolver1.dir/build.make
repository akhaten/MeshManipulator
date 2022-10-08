# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/akhaten/Documents/OpenglProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/akhaten/Documents/OpenglProject/build

# Include any dependencies generated for this target.
include libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/progress.make

# Include the compile flags for this target's objects.
include libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/flags.make

libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o: libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/flags.make
libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o: /home/akhaten/Documents/OpenglProject/libs/eigen/unsupported/doc/examples/PolynomialSolver1.cpp
libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o: libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akhaten/Documents/OpenglProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o -MF CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o.d -o CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o -c /home/akhaten/Documents/OpenglProject/libs/eigen/unsupported/doc/examples/PolynomialSolver1.cpp

libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.i"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akhaten/Documents/OpenglProject/libs/eigen/unsupported/doc/examples/PolynomialSolver1.cpp > CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.i

libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.s"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akhaten/Documents/OpenglProject/libs/eigen/unsupported/doc/examples/PolynomialSolver1.cpp -o CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.s

# Object files for target example_PolynomialSolver1
example_PolynomialSolver1_OBJECTS = \
"CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o"

# External object files for target example_PolynomialSolver1
example_PolynomialSolver1_EXTERNAL_OBJECTS =

libs/eigen/unsupported/doc/examples/example_PolynomialSolver1: libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/PolynomialSolver1.cpp.o
libs/eigen/unsupported/doc/examples/example_PolynomialSolver1: libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/build.make
libs/eigen/unsupported/doc/examples/example_PolynomialSolver1: libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akhaten/Documents/OpenglProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_PolynomialSolver1"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_PolynomialSolver1.dir/link.txt --verbose=$(VERBOSE)
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && ./example_PolynomialSolver1 >/home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples/PolynomialSolver1.out

# Rule to build all files generated by this target.
libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/build: libs/eigen/unsupported/doc/examples/example_PolynomialSolver1
.PHONY : libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/build

libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/clean:
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_PolynomialSolver1.dir/cmake_clean.cmake
.PHONY : libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/clean

libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/depend:
	cd /home/akhaten/Documents/OpenglProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akhaten/Documents/OpenglProject /home/akhaten/Documents/OpenglProject/libs/eigen/unsupported/doc/examples /home/akhaten/Documents/OpenglProject/build /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples /home/akhaten/Documents/OpenglProject/build/libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/eigen/unsupported/doc/examples/CMakeFiles/example_PolynomialSolver1.dir/depend

