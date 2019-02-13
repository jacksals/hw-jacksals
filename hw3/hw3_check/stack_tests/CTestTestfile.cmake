# CMake generated Testfile for 
# Source directory: /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests
# Build directory: /home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(Stack.Empty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.Empty")
add_test(Stack.TopEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.TopEmpty")
add_test(Stack.OneElementPush "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.OneElementPush")
add_test(Stack.FiveElementPush "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.FiveElementPush")
add_test(Stack.OneElementPop "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.OneElementPop")
add_test(Stack.FiveElementPop "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.FiveElementPop")
add_test(Stack.PopEmpty "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.PopEmpty")
add_test(Stack.PopThenAdd "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=Stack.PopThenAdd")
add_test(StackStress.50x50Elements "/usr/bin/valgrind" "--tool=memcheck" "--leak-check=yes" "--trace-children=no" "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_tests" "--gtest_filter=StackStress.50x50Elements")
add_test(StackRuntime.Push "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_runtime_tests" "--gtest_filter=StackRuntime.Push")
add_test(StackRuntime.Pop "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_runtime_tests" "--gtest_filter=StackRuntime.Pop")
add_test(StackRuntime.Top "/home/cs104/cs104hw/hw-jesalisb/hw3/hw3_check/stack_tests/stack_runtime_tests" "--gtest_filter=StackRuntime.Top")
