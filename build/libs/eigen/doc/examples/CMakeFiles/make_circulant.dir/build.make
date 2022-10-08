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
include libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/progress.make

# Include the compile flags for this target's objects.
include libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/flags.make

libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o: libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/flags.make
libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o: /home/akhaten/Documents/OpenglProject/libs/eigen/doc/examples/make_circulant.cpp
libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o: libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/akhaten/Documents/OpenglProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o -MF CMakeFiles/make_circulant.dir/make_circulant.cpp.o.d -o CMakeFiles/make_circulant.dir/make_circulant.cpp.o -c /home/akhaten/Documents/OpenglProject/libs/eigen/doc/examples/make_circulant.cpp

libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/make_circulant.dir/make_circulant.cpp.i"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/akhaten/Documents/OpenglProject/libs/eigen/doc/examples/make_circulant.cpp > CMakeFiles/make_circulant.dir/make_circulant.cpp.i

libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/make_circulant.dir/make_circulant.cpp.s"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/akhaten/Documents/OpenglProject/libs/eigen/doc/examples/make_circulant.cpp -o CMakeFiles/make_circulant.dir/make_circulant.cpp.s

# Object files for target make_circulant
make_circulant_OBJECTS = \
"CMakeFiles/make_circulant.dir/make_circulant.cpp.o"

# External object files for target make_circulant
make_circulant_EXTERNAL_OBJECTS =

libs/eigen/doc/examples/make_circulant: libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/make_circulant.cpp.o
libs/eigen/doc/examples/make_circulant: libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/build.make
libs/eigen/doc/examples/make_circulant: libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/akhaten/Documents/OpenglProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable make_circulant"
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/make_circulant.dir/link.txt --verbose=$(VERBOSE)
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && ./make_circulant >/home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples/make_circulant.out

# Rule to build all files generated by this target.
libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/build: libs/eigen/doc/examples/make_circulant
.PHONY : libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/build

libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/clean:
	cd /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/make_circulant.dir/cmake_clean.cmake
.PHONY : libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/clean

libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/depend:
	cd /home/akhaten/Documents/OpenglProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/akhaten/Documents/OpenglProject /home/akhaten/Documents/OpenglProject/libs/eigen/doc/examples /home/akhaten/Documents/OpenglProject/build /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples /home/akhaten/Documents/OpenglProject/build/libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/eigen/doc/examples/CMakeFiles/make_circulant.dir/depend

