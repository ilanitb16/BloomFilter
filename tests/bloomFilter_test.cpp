#include <gtest/gtest.h>

//BitsArray tests

//Test Case 0.1: Get the array contents of a newly created BitsArray
TEST(BitsArrayTest, GetArrayTest) {
    // Create a BitsArray with size 16
    BitsArray bitsArray(16);

    // Get the array contents
    std::vector<int> array = bitsArray.getArray();

    // The expected size of the array is 16
    EXPECT_EQ(array.size(), 16);

    // Check that all elements in the array are initially set to 0
    for (int i = 0; i < 16; ++i) {
        EXPECT_EQ(array[i], 0);
    }
}

// Test case 0.2: Checks the correctness of getArraySize function 
TEST(BitsArrayTest, GetArraySizeTest) {
    // Create a BitsArray with size 8
    BitsArray bitsArray(8);

    // Get the array size
    int size = bitsArray.getArraySize();

    // The expected size is 8
    EXPECT_EQ(size, 8);
}

// Test case 0.3: Checks the correctness of getArraySize function 
TEST(BitsArrayTest, GetArraySizeTest0) {
    // Create a BitsArray with size 0
    BitsArray bitsArray(0);

    // Get the array size
    int size = bitsArray.getArraySize();

    // The expected size is 8
    EXPECT_EQ(size, 0);
}
