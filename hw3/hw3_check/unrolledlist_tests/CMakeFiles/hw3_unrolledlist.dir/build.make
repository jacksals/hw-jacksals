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
include unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/depend.make

# Include the progress variables for this target.
include unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/progress.make

# Include the compile flags for this target's objects.
include unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/flags.make

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/flags.make
unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o: /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o -c /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp > CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.i

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp -o CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.s

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires:

.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires
	$(MAKE) -f unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/build.make unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides.build
.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.provides.build: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o


# Object files for target hw3_unrolledlist
hw3_unrolledlist_OBJECTS = \
"CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o"

# External object files for target hw3_unrolledlist
hw3_unrolledlist_EXTERNAL_OBJECTS =

unrolledlist_tests/libhw3_unrolledlist.a: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o
unrolledlist_tests/libhw3_unrolledlist.a: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/build.make
unrolledlist_tests/libhw3_unrolledlist.a: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhw3_unrolledlist.a"
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_unrolledlist.dir/cmake_clean_target.cmake
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw3_unrolledlist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/build: unrolledlist_tests/libhw3_unrolledlist.a

.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/build

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/requires: unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/home/cs104/cs104hw/hw-jesalisb/hw3/ulliststr.cpp.o.requires

.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/requires

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/clean:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && $(CMAKE_COMMAND) -P CMakeFiles/hw3_unrolledlist.dir/cmake_clean.cmake
.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/clean

unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/depend:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unrolledlist_tests/CMakeFiles/hw3_unrolledlist.dir/depend

