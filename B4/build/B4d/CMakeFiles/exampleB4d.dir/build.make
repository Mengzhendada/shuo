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

# Include any dependencies generated for this target.
include B4d/CMakeFiles/exampleB4d.dir/depend.make

# Include the progress variables for this target.
include B4d/CMakeFiles/exampleB4d.dir/progress.make

# Include the compile flags for this target's objects.
include B4d/CMakeFiles/exampleB4d.dir/flags.make

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o: ../B4d/exampleB4d.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/exampleB4d.cc.o -c /home/shuojia/geant4/example/B4/B4d/exampleB4d.cc

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/exampleB4d.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/exampleB4d.cc > CMakeFiles/exampleB4d.dir/exampleB4d.cc.i

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/exampleB4d.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/exampleB4d.cc -o CMakeFiles/exampleB4d.dir/exampleB4d.cc.s

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o


B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o: ../B4d/src/B4PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o -c /home/shuojia/geant4/example/B4/B4d/src/B4PrimaryGeneratorAction.cc

B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/src/B4PrimaryGeneratorAction.cc > CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.i

B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/src/B4PrimaryGeneratorAction.cc -o CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.s

B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o


B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o: ../B4d/src/B4RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o -c /home/shuojia/geant4/example/B4/B4d/src/B4RunAction.cc

B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/src/B4RunAction.cc > CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.i

B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/src/B4RunAction.cc -o CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.s

B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o


B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o: ../B4d/src/B4dActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o -c /home/shuojia/geant4/example/B4/B4d/src/B4dActionInitialization.cc

B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/src/B4dActionInitialization.cc > CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.i

B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/src/B4dActionInitialization.cc -o CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.s

B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o


B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o: ../B4d/src/B4dDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o -c /home/shuojia/geant4/example/B4/B4d/src/B4dDetectorConstruction.cc

B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/src/B4dDetectorConstruction.cc > CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.i

B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/src/B4dDetectorConstruction.cc -o CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.s

B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o


B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o: B4d/CMakeFiles/exampleB4d.dir/flags.make
B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o: ../B4d/src/B4dEventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o -c /home/shuojia/geant4/example/B4/B4d/src/B4dEventAction.cc

B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.i"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shuojia/geant4/example/B4/B4d/src/B4dEventAction.cc > CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.i

B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.s"
	cd /home/shuojia/geant4/example/B4/build/B4d && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shuojia/geant4/example/B4/B4d/src/B4dEventAction.cc -o CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.s

B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.requires:

.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.requires

B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.provides: B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.requires
	$(MAKE) -f B4d/CMakeFiles/exampleB4d.dir/build.make B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.provides.build
.PHONY : B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.provides

B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.provides.build: B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o


# Object files for target exampleB4d
exampleB4d_OBJECTS = \
"CMakeFiles/exampleB4d.dir/exampleB4d.cc.o" \
"CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o" \
"CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o" \
"CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o" \
"CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o" \
"CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o"

# External object files for target exampleB4d
exampleB4d_EXTERNAL_OBJECTS =

B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/build.make
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4Tree.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4GMocren.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4visHepRep.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4RayTracer.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4VRML.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4OpenGL.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4gl2ps.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4interfaces.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4persistency.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4error_propagation.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4readout.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4physicslists.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4parmodels.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4FR.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4vis_management.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4modeling.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libGL.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libSM.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libICE.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libX11.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libXext.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libXmu.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4run.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4event.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4tracking.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4processes.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4analysis.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4zlib.so
B4d/exampleB4d: /usr/lib/x86_64-linux-gnu/libexpat.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4digits_hits.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4track.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4particles.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4geometry.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4materials.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4graphics_reps.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4intercoms.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4global.so
B4d/exampleB4d: /home/shuojia/geant4/G4build/BuildProducts/lib/libG4clhep.so
B4d/exampleB4d: B4d/CMakeFiles/exampleB4d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shuojia/geant4/example/B4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable exampleB4d"
	cd /home/shuojia/geant4/example/B4/build/B4d && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exampleB4d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
B4d/CMakeFiles/exampleB4d.dir/build: B4d/exampleB4d

.PHONY : B4d/CMakeFiles/exampleB4d.dir/build

B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/exampleB4d.cc.o.requires
B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/src/B4PrimaryGeneratorAction.cc.o.requires
B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/src/B4RunAction.cc.o.requires
B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/src/B4dActionInitialization.cc.o.requires
B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/src/B4dDetectorConstruction.cc.o.requires
B4d/CMakeFiles/exampleB4d.dir/requires: B4d/CMakeFiles/exampleB4d.dir/src/B4dEventAction.cc.o.requires

.PHONY : B4d/CMakeFiles/exampleB4d.dir/requires

B4d/CMakeFiles/exampleB4d.dir/clean:
	cd /home/shuojia/geant4/example/B4/build/B4d && $(CMAKE_COMMAND) -P CMakeFiles/exampleB4d.dir/cmake_clean.cmake
.PHONY : B4d/CMakeFiles/exampleB4d.dir/clean

B4d/CMakeFiles/exampleB4d.dir/depend:
	cd /home/shuojia/geant4/example/B4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shuojia/geant4/example/B4 /home/shuojia/geant4/example/B4/B4d /home/shuojia/geant4/example/B4/build /home/shuojia/geant4/example/B4/build/B4d /home/shuojia/geant4/example/B4/build/B4d/CMakeFiles/exampleB4d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : B4d/CMakeFiles/exampleB4d.dir/depend

