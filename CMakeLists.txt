cmake_minimum_required(VERSION 3.14)
project("facebook-iso")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCE_FILES
    src/include/BitsArray.h
    src/BitsArray.cpp # this is where the code we want to test
    src/Main.cpp 
)

set(TEST_FILES
    tests/test_main.cpp # this is the main for tests
    tests/BitsArray_test.cpp # this file contain the tests
)
add_executable(BitArrayTest ${TEST_FILES})

# Link Google Test to the test executable
target_link_libraries(BitArrayTest PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(BitArrayTest PRIVATE src)
include(GoogleTest)
add_test(NAME BitArrayTest COMMAND BitArrayTest)