# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shuojia/geant4/example/B4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shuojia/geant4/example/B4/build

# Utility rule file for B4.

# Include the progress variables for this target.
include CMakeFiles/B4.dir/progress.make

CMakeFiles/B4: B4a/exampleB4a
CMakeFiles/B4: B4b/exampleB4b
CMakeFiles/B4: B4c/exampleB4c
CMakeFiles/B4: B4d/exampleB4d


B4: CMakeFiles/B4
B4: CMakeFiles/B4.dir/build.make

.PHONY : B4

# Rule to build all files generated by this target.
CMakeFiles/B4.dir/build: B4

.PHONY : CMakeFiles/B4.dir/build

CMakeFiles/B4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/B4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/B4.dir/clean

CMakeFiles/B4.dir/depend:
	cd /home/shuojia/geant4/example/B4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shuojia/geant4/example/B4 /home/shuojia/geant4/example/B4 /home/shuojia/geant4/example/B4/build /home/shuojia/geant4/example/B4/build /home/shuojia/geant4/example/B4/build/CMakeFiles/B4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/B4.dir/depend

