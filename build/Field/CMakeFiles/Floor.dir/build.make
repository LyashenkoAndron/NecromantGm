# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /snap/cmake/1345/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1345/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andron/Desktop/sem3/lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andron/Desktop/sem3/lab3/build

# Include any dependencies generated for this target.
include Field/CMakeFiles/Floor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Field/CMakeFiles/Floor.dir/compiler_depend.make

# Include the progress variables for this target.
include Field/CMakeFiles/Floor.dir/progress.make

# Include the compile flags for this target's objects.
include Field/CMakeFiles/Floor.dir/flags.make

Field/CMakeFiles/Floor.dir/Floor.cpp.o: Field/CMakeFiles/Floor.dir/flags.make
Field/CMakeFiles/Floor.dir/Floor.cpp.o: /home/andron/Desktop/sem3/lab3/Field/Floor.cpp
Field/CMakeFiles/Floor.dir/Floor.cpp.o: Field/CMakeFiles/Floor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Field/CMakeFiles/Floor.dir/Floor.cpp.o"
	cd /home/andron/Desktop/sem3/lab3/build/Field && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Field/CMakeFiles/Floor.dir/Floor.cpp.o -MF CMakeFiles/Floor.dir/Floor.cpp.o.d -o CMakeFiles/Floor.dir/Floor.cpp.o -c /home/andron/Desktop/sem3/lab3/Field/Floor.cpp

Field/CMakeFiles/Floor.dir/Floor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Floor.dir/Floor.cpp.i"
	cd /home/andron/Desktop/sem3/lab3/build/Field && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andron/Desktop/sem3/lab3/Field/Floor.cpp > CMakeFiles/Floor.dir/Floor.cpp.i

Field/CMakeFiles/Floor.dir/Floor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Floor.dir/Floor.cpp.s"
	cd /home/andron/Desktop/sem3/lab3/build/Field && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andron/Desktop/sem3/lab3/Field/Floor.cpp -o CMakeFiles/Floor.dir/Floor.cpp.s

# Object files for target Floor
Floor_OBJECTS = \
"CMakeFiles/Floor.dir/Floor.cpp.o"

# External object files for target Floor
Floor_EXTERNAL_OBJECTS =

Field/libFloor.so: Field/CMakeFiles/Floor.dir/Floor.cpp.o
Field/libFloor.so: Field/CMakeFiles/Floor.dir/build.make
Field/libFloor.so: Field/CMakeFiles/Floor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libFloor.so"
	cd /home/andron/Desktop/sem3/lab3/build/Field && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Floor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Field/CMakeFiles/Floor.dir/build: Field/libFloor.so
.PHONY : Field/CMakeFiles/Floor.dir/build

Field/CMakeFiles/Floor.dir/clean:
	cd /home/andron/Desktop/sem3/lab3/build/Field && $(CMAKE_COMMAND) -P CMakeFiles/Floor.dir/cmake_clean.cmake
.PHONY : Field/CMakeFiles/Floor.dir/clean

Field/CMakeFiles/Floor.dir/depend:
	cd /home/andron/Desktop/sem3/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andron/Desktop/sem3/lab3 /home/andron/Desktop/sem3/lab3/Field /home/andron/Desktop/sem3/lab3/build /home/andron/Desktop/sem3/lab3/build/Field /home/andron/Desktop/sem3/lab3/build/Field/CMakeFiles/Floor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Field/CMakeFiles/Floor.dir/depend
