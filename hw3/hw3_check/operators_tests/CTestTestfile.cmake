# CMake generated Testfile for 
# Source directory: /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests
# Build directory: /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ListCopy.OneElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListCopy.OneElement")
add_test(ListCopy.NoElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListCopy.NoElements")
add_test(ListCopy.15Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListCopy.15Elements")
add_test(ListCopy.SourceNotModified "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListCopy.SourceNotModified")
add_test(ListAssign.OneElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListAssign.OneElement")
add_test(ListAssign.OneElementToEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListAssign.OneElementToEmpty")
add_test(ListAssign.NoElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListAssign.NoElements")
add_test(ListAssign.NoElementsToEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListAssign.NoElementsToEmpty")
add_test(ListAssign.15Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListAssign.15Elements")
add_test(ListPlus.EmptyPlusEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListPlus.EmptyPlusEmpty")
add_test(ListPlus.EmptyPlusOne "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListPlus.EmptyPlusOne")
add_test(ListPlus.TwoPlusEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListPlus.TwoPlusEmpty")
add_test(ListMinusEquals.OneElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListMinusEquals.OneElement")
add_test(ListMinusEquals.ThreeElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListMinusEquals.ThreeElements")
add_test(ListMinusEquals.RemoveNoElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListMinusEquals.RemoveNoElements")
add_test(ListMinusEquals.RemoveAllElements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListMinusEquals.RemoveAllElements")
add_test(ListMinusEquals.15Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListMinusEquals.15Elements")
add_test(ListBracket.OneElement "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListBracket.OneElement")
add_test(ListBracket.ElementAssignment "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/operators_tests/operators_tests" "--gtest_filter=ListBracket.ElementAssignment")
