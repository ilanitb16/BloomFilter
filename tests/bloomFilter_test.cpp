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







//InputOutput tests

// Test Case A: Testing isDigit function with a digit character
TEST(InputOutputTest, IsDigitTest1) {
    InputOutput inputOutput;
    char digitChar = '5';

    // Check if the character '5' is a digit
    bool isDigit = inputOutput.isDigit(digitChar);

    // Expected output: '5' is a digit
    EXPECT_TRUE(isDigit);
}

// Test Case B: Testing isDigit function with a non-digit character
TEST(InputOutputTest, IsDigitTest2) {
    InputOutput inputOutput;
    char nonDigitChar = 'A';

    // Check if the character 'A' is a digit
    bool isDigit = inputOutput.isDigit(nonDigitChar);

    // Expected output: 'A' is not a digit
    EXPECT_FALSE(isDigit);
}

// Test Case C: Testing containsNonNumeric function with a string containing non-numeric characters
TEST(InputOutputTest, ContainsNonNumericTest1) {
    InputOutput inputOutput;
    std::string stringWithNonNumeric = "Hello012";

    // Check if the string contains non-numeric characters
    bool containsNonNumeric = inputOutput.containsNonNumeric(stringWithNonNumeric);

    // Expected output: The string contains non-numeric characters
    EXPECT_TRUE(containsNonNumeric);
}

// Test Case D: Testing containsNonNumeric function with a string containing only numeric characters and spaces
TEST(InputOutputTest, ContainsNonNumericTest2) {
    InputOutput inputOutput;
    std::string stringWithNumericAndSpaces = "123 456";

    // Check if the string contains non-numeric characters
    bool containsNonNumeric = inputOutput.containsNonNumeric(stringWithNumericAndSpaces);

    // Expected output: The string contains only numeric characters and spaces
    EXPECT_FALSE(containsNonNumeric);
}