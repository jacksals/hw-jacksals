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

# Utility rule file for debug-ListInsertFront.OneItemAdd.

# Include the progress variables for this target.
include unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/progress.make

unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Debugging ListInsertFront.OneItemAdd with GDB..."
	cd /home/cs104/cs104hw/hw-jesalisb/hw3 && gdb --args /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests/unrolledlist_tests --gtest_filter=ListInsertFront.OneItemAdd

debug-ListInsertFront.OneItemAdd: unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd
debug-ListInsertFront.OneItemAdd: unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/build.make

.PHONY : debug-ListInsertFront.OneItemAdd

# Rule to build all files generated by this target.
unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/build: debug-ListInsertFront.OneItemAdd

.PHONY : unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/build

unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/clean:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests && $(CMAKE_COMMAND) -P CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/cmake_clean.cmake
.PHONY : unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/clean

unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/depend:
	cd /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unrolledlist_tests/CMakeFiles/debug-ListInsertFront.OneItemAdd.dir/depend

