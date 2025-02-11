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
include CMakeFiles/integration_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/integration_library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/integration_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/integration_library.dir/flags.make

CMakeFiles/integration_library.dir/numerical_integration.cpp.o: CMakeFiles/integration_library.dir/flags.make
CMakeFiles/integration_library.dir/numerical_integration.cpp.o: /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/numerical_integration.cpp
CMakeFiles/integration_library.dir/numerical_integration.cpp.o: CMakeFiles/integration_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/integration_library.dir/numerical_integration.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/integration_library.dir/numerical_integration.cpp.o -MF CMakeFiles/integration_library.dir/numerical_integration.cpp.o.d -o CMakeFiles/integration_library.dir/numerical_integration.cpp.o -c /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/numerical_integration.cpp

CMakeFiles/integration_library.dir/numerical_integration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/integration_library.dir/numerical_integration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/numerical_integration.cpp > CMakeFiles/integration_library.dir/numerical_integration.cpp.i

CMakeFiles/integration_library.dir/numerical_integration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/integration_library.dir/numerical_integration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/numerical_integration.cpp -o CMakeFiles/integration_library.dir/numerical_integration.cpp.s

# Object files for target integration_library
integration_library_OBJECTS = \
"CMakeFiles/integration_library.dir/numerical_integration.cpp.o"

# External object files for target integration_library
integration_library_EXTERNAL_OBJECTS =

libintegration_library.a: CMakeFiles/integration_library.dir/numerical_integration.cpp.o
libintegration_library.a: CMakeFiles/integration_library.dir/build.make
libintegration_library.a: CMakeFiles/integration_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libintegration_library.a"
	$(CMAKE_COMMAND) -P CMakeFiles/integration_library.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/integration_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/integration_library.dir/build: libintegration_library.a
.PHONY : CMakeFiles/integration_library.dir/build

CMakeFiles/integration_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/integration_library.dir/cmake_clean.cmake
.PHONY : CMakeFiles/integration_library.dir/clean

CMakeFiles/integration_library.dir/depend:
	cd /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1 /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1 /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build /home/kairvilodhiya/MANE6965/computing-at-scale/Assignment1/build/CMakeFiles/integration_library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/integration_library.dir/depend

