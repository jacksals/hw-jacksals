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

# Utility rule file for debug-Stack.FiveElementPush.

# Include the progress variables for this target.
include stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/progress.make

stack_tests/CMakeFiles/debug-Stack.FiveElementPush:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging Stack.FiveElementPush with GDB..."
	cd /home/cs104/cs104hw/hw-jesalisb/hw3 && gdb --args /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests --gtest_filter=Stack.FiveElementPush

debug-Stack.FiveElementPush: stack_tests/CMakeFiles/debug-Stack.FiveElementPush
debug-Stack.FiveElementPush: stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/build.make

.PHONY : debug-Stack.FiveElementPush

# Rule to build all files generated by this target.
stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/build: debug-Stack.FiveElementPush

.PHONY : stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/build

stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/clean:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-Stack.FiveElementPush.dir/cmake_clean.cmake
.PHONY : stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/clean

stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/depend:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : stack_tests/CMakeFiles/debug-Stack.FiveElementPush.dir/depend

