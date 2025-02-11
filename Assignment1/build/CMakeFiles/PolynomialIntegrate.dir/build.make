# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build

# Include any dependencies generated for this target.
include CMakeFiles/PolynomialIntegrate.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PolynomialIntegrate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PolynomialIntegrate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PolynomialIntegrate.dir/flags.make

CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o: CMakeFiles/PolynomialIntegrate.dir/flags.make
CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o: /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/PolynomialIntegrate.cpp
CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o: CMakeFiles/PolynomialIntegrate.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o -MF CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o.d -o CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o -c /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/PolynomialIntegrate.cpp

CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/PolynomialIntegrate.cpp > CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.i

CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/PolynomialIntegrate.cpp -o CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.s

# Object files for target PolynomialIntegrate
PolynomialIntegrate_OBJECTS = \
"CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o"

# External object files for target PolynomialIntegrate
PolynomialIntegrate_EXTERNAL_OBJECTS =

PolynomialIntegrate: CMakeFiles/PolynomialIntegrate.dir/PolynomialIntegrate.cpp.o
PolynomialIntegrate: CMakeFiles/PolynomialIntegrate.dir/build.make
PolynomialIntegrate: libintegration_library.a
PolynomialIntegrate: CMakeFiles/PolynomialIntegrate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PolynomialIntegrate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PolynomialIntegrate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PolynomialIntegrate.dir/build: PolynomialIntegrate
.PHONY : CMakeFiles/PolynomialIntegrate.dir/build

CMakeFiles/PolynomialIntegrate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PolynomialIntegrate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PolynomialIntegrate.dir/clean

CMakeFiles/PolynomialIntegrate.dir/depend:
	cd /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1 /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1 /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles/PolynomialIntegrate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PolynomialIntegrate.dir/depend

