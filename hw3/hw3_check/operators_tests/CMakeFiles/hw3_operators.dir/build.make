# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check

# Include any dependencies generated for this target.
include operators_tests/CMakeFiles/hw3_operators.dir/depend.make

# Include the progress variables for this target.
include operators_tests/CMakeFiles/hw3_operators.dir/progress.make

# Include the compile flags for this target's objects.
include operators_tests/CMakeFiles/hw3_operators.dir/flags.make

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o: operators_tests/CMakeFiles/hw3_operators.dir/flags.make
operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o: /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o -c /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp > CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp -o CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires:

.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides: operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires
	$(MAKE) -f operators_tests/CMakeFiles/hw3_operators.dir/build.make operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides.build
.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides

operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides.build: operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o


# Object files for target hw3_operators
hw3_operators_OBJECTS = \
"CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o"

# External object files for target hw3_operators
hw3_operators_EXTERNAL_OBJECTS =

operators_tests/libhw3_operators.a: operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o
operators_tests/libhw3_operators.a: operators_tests/CMakeFiles/hw3_operators.dir/build.make
operators_tests/libhw3_operators.a: operators_tests/CMakeFiles/hw3_operators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhw3_operators.a"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_operators.dir/cmake_clean_target.cmake
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw3_operators.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
operators_tests/CMakeFiles/hw3_operators.dir/build: operators_tests/libhw3_operators.a

.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/build

operators_tests/CMakeFiles/hw3_operators.dir/requires: operators_tests/CMakeFiles/hw3_operators.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires

.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/requires

operators_tests/CMakeFiles/hw3_operators.dir/clean:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_operators.dir/cmake_clean.cmake
.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/clean

operators_tests/CMakeFiles/hw3_operators.dir/depend:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/CMakeFiles/hw3_operators.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : operators_tests/CMakeFiles/hw3_operators.dir/depend

