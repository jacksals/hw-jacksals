
add_makefile_problem(
    NAME amazon
    EXECUTABLE_NAME amazon
    TEST_SOURCE
        amazon_reviews_tests.cpp
        amazon_login_tests.cpp
        amazon_sorting_tests.cpp
        amazon_stress_tests.cpp
        ConsoleParser.cpp
        DatabaseParser.cpp
        Utility.cpp
        amazon_checker.cpp)