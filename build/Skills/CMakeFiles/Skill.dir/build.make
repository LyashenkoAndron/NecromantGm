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
include Skills/CMakeFiles/Skill.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Skills/CMakeFiles/Skill.dir/compiler_depend.make

# Include the progress variables for this target.
include Skills/CMakeFiles/Skill.dir/progress.make

# Include the compile flags for this target's objects.
include Skills/CMakeFiles/Skill.dir/flags.make

Skills/CMakeFiles/Skill.dir/Skill.cpp.o: Skills/CMakeFiles/Skill.dir/flags.make
Skills/CMakeFiles/Skill.dir/Skill.cpp.o: /home/andron/Desktop/sem3/lab3/Skills/Skill.cpp
Skills/CMakeFiles/Skill.dir/Skill.cpp.o: Skills/CMakeFiles/Skill.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Skills/CMakeFiles/Skill.dir/Skill.cpp.o"
	cd /home/andron/Desktop/sem3/lab3/build/Skills && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Skills/CMakeFiles/Skill.dir/Skill.cpp.o -MF CMakeFiles/Skill.dir/Skill.cpp.o.d -o CMakeFiles/Skill.dir/Skill.cpp.o -c /home/andron/Desktop/sem3/lab3/Skills/Skill.cpp

Skills/CMakeFiles/Skill.dir/Skill.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Skill.dir/Skill.cpp.i"
	cd /home/andron/Desktop/sem3/lab3/build/Skills && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andron/Desktop/sem3/lab3/Skills/Skill.cpp > CMakeFiles/Skill.dir/Skill.cpp.i

Skills/CMakeFiles/Skill.dir/Skill.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Skill.dir/Skill.cpp.s"
	cd /home/andron/Desktop/sem3/lab3/build/Skills && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andron/Desktop/sem3/lab3/Skills/Skill.cpp -o CMakeFiles/Skill.dir/Skill.cpp.s

# Object files for target Skill
Skill_OBJECTS = \
"CMakeFiles/Skill.dir/Skill.cpp.o"

# External object files for target Skill
Skill_EXTERNAL_OBJECTS =

Skills/libSkill.so: Skills/CMakeFiles/Skill.dir/Skill.cpp.o
Skills/libSkill.so: Skills/CMakeFiles/Skill.dir/build.make
Skills/libSkill.so: Skills/CMakeFiles/Skill.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/andron/Desktop/sem3/lab3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libSkill.so"
	cd /home/andron/Desktop/sem3/lab3/build/Skills && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Skill.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Skills/CMakeFiles/Skill.dir/build: Skills/libSkill.so
.PHONY : Skills/CMakeFiles/Skill.dir/build

Skills/CMakeFiles/Skill.dir/clean:
	cd /home/andron/Desktop/sem3/lab3/build/Skills && $(CMAKE_COMMAND) -P CMakeFiles/Skill.dir/cmake_clean.cmake
.PHONY : Skills/CMakeFiles/Skill.dir/clean

Skills/CMakeFiles/Skill.dir/depend:
	cd /home/andron/Desktop/sem3/lab3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andron/Desktop/sem3/lab3 /home/andron/Desktop/sem3/lab3/Skills /home/andron/Desktop/sem3/lab3/build /home/andron/Desktop/sem3/lab3/build/Skills /home/andron/Desktop/sem3/lab3/build/Skills/CMakeFiles/Skill.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Skills/CMakeFiles/Skill.dir/depend

