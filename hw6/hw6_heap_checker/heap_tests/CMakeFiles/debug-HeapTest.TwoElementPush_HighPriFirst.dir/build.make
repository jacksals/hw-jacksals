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
CMAKE_SOURCE_DIR = /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker

# Utility rule file for debug-HeapTest.TwoElementPush_HighPriFirst.

# Include the progress variables for this target.
include heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/progress.make

heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging HeapTest.TwoElementPush_HighPriFirst with GDB..."
	cd /home/cs104/cs104hw/hw-jesalisb/hw6 && gdb --args /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/heap_tests/heap_tests --gtest_filter=HeapTest.TwoElementPush_HighPriFirst

debug-HeapTest.TwoElementPush_HighPriFirst: heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst
debug-HeapTest.TwoElementPush_HighPriFirst: heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/build.make

.PHONY : debug-HeapTest.TwoElementPush_HighPriFirst

# Rule to build all files generated by this target.
heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/build: debug-HeapTest.TwoElementPush_HighPriFirst

.PHONY : heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/build

heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/clean:
	cd /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/heap_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/cmake_clean.cmake
.PHONY : heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/clean

heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/depend:
	cd /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/heap_tests /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/heap_tests /home/cs104/cs104hw/hw-jesalisb/hw6/hw6_heap_checker/heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : heap_tests/CMakeFiles/debug-HeapTest.TwoElementPush_HighPriFirst.dir/depend

