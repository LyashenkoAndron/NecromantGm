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
include Skills/Necromancy/CMakeFiles/Necromancy.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Skills/Necromancy/CMakeFiles/Necromancy.dir/compiler_depend.make

# Include the progress variables for this target.
include Skills/Necromancy/CMakeFiles/Necromancy.dir/progress.make

# Include the compile flags for this target's objects.
include Skills/Necromancy/CMakeFiles/Necromancy.dir/flags.make

Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o: Skills/Necromancy/CMakeFiles/Necromancy.dir/flags.make
Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o: /home/andron/Desktop/sem3/lab3/Skills/Necromancy/Necromancy.cpp
Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o: Skills/Necromancy/CMakeFiles/Necromancy.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o"
	cd /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o -MF CMakeFiles/Necromancy.dir/Necromancy.cpp.o.d -o CMakeFiles/Necromancy.dir/Necromancy.cpp.o -c /home/andron/Desktop/sem3/lab3/Skills/Necromancy/Necromancy.cpp

Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Necromancy.dir/Necromancy.cpp.i"
	cd /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andron/Desktop/sem3/lab3/Skills/Necromancy/Necromancy.cpp > CMakeFiles/Necromancy.dir/Necromancy.cpp.i

Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Necromancy.dir/Necromancy.cpp.s"
	cd /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andron/Desktop/sem3/lab3/Skills/Necromancy/Necromancy.cpp -o CMakeFiles/Necromancy.dir/Necromancy.cpp.s

# Object files for target Necromancy
Necromancy_OBJECTS = \
"CMakeFiles/Necromancy.dir/Necromancy.cpp.o"

# External object files for target Necromancy
Necromancy_EXTERNAL_OBJECTS =

Skills/Necromancy/libNecromancy.so: Skills/Necromancy/CMakeFiles/Necromancy.dir/Necromancy.cpp.o
Skills/Necromancy/libNecromancy.so: Skills/Necromancy/CMakeFiles/Necromancy.dir/build.make
Skills/Necromancy/libNecromancy.so: Skills/Necromancy/CMakeFiles/Necromancy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libNecromancy.so"
	cd /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Necromancy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Skills/Necromancy/CMakeFiles/Necromancy.dir/build: Skills/Necromancy/libNecromancy.so
.PHONY : Skills/Necromancy/CMakeFiles/Necromancy.dir/build

Skills/Necromancy/CMakeFiles/Necromancy.dir/clean:
	cd /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy && $(CMAKE_COMMAND) -P CMakeFiles/Necromancy.dir/cmake_clean.cmake
.PHONY : Skills/Necromancy/CMakeFiles/Necromancy.dir/clean

Skills/Necromancy/CMakeFiles/Necromancy.dir/depend:
	cd /home/andron/Desktop/sem3/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andron/Desktop/sem3/lab3 /home/andron/Desktop/sem3/lab3/Skills/Necromancy /home/andron/Desktop/sem3/lab3/build /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy /home/andron/Desktop/sem3/lab3/build/Skills/Necromancy/CMakeFiles/Necromancy.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Skills/Necromancy/CMakeFiles/Necromancy.dir/depend
