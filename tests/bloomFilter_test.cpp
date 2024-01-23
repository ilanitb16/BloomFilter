#include <gtest/gtest.h>
#include "BitsArray.cpp"
#include "InputOutput.cpp"
#include "HashFunctions.cpp"

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
    EXPECT_EQ(size,8);
}

// Test case 0.3: Checks the correctness of getArraySize function 
TEST(BitsArrayTest, GetArraySizeTest0) {
    // Create a BitsArray with size 0
    BitsArray bitsArray(0);

    // Get the array size
    int size = bitsArray.getArraySize();

    // The expected size is 8
    EXPECT_EQ(size,0);
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


// Test Case D: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST1) {
    InputOutput inputOutput;
    std::string setting = "8 1";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_FALSE(validSetting);
}

// Test Case E: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST2) {
    InputOutput inputOutput;
    std::string setting = "8 2";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_FALSE(validSetting);
}

// Test Case F: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST3) {
    InputOutput inputOutput;
    std::string setting = "8 1 2";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_FALSE(validSetting);
}

// Test Case G: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST4) {
    InputOutput inputOutput;
    std::string setting = "8 1 2 2 2 1 1";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_FALSE(validSetting);
}

// Test Case H: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST5) {
    InputOutput inputOutput;
    std::string setting = "8 1 1 1 1 1 2";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_FALSE(validSetting);
}

// Test Case I: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST6) {
    InputOutput inputOutput;
    std::string setting = "8 1 0";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_TRUE(validSetting);
}

// Test Case J: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST7) {
    InputOutput inputOutput;
    std::string setting = "8";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_TRUE(validSetting);
}

// Test Case K: Testing if the first input that contain only number for sure is valid
TEST(InputOutputTest, invalidInputTEST8) {
    InputOutput inputOutput;
    std::string setting = "8 1 5";

    // Check if the string contains numbers diffrent from 1 and 2 after thr first number
    bool validSetting = inputOutput.invalidInput(setting);

    // Expected output: The string is valid
    EXPECT_TRUE(validSetting);
}




// Test Case 1: Testing firstNum function with a valid input line
TEST(InputOutputTest, FirstNumTest1) {
    InputOutput inputOutput;
    std::string inputLine = "8 1 2";

    // Get the first number from the input line
    int firstNumber = inputOutput.firstNum(inputLine);

    // Expected output: The first number is 8
    EXPECT_EQ(firstNumber, 8);
}

// Test Case 2: Testing firstNum function with an invalid input line
TEST(InputOutputTest, FirstNumTest2) {
    InputOutput inputOutput;
    std::string inputLine = "Invalid Input";

    // Get the first number from the input line
    int firstNumber = inputOutput.firstNum(inputLine);

    // Expected output: The first number is 0 (indicating invalid input)
    EXPECT_EQ(firstNumber, 0);
}

// Test Case 3: Testing firstNum function with an invalid input line
TEST(InputOutputTest, FirstNumTest3) {
    InputOutput inputOutput;
    std::string inputLine = "0";

    // Get the first number from the input line
    int firstNumber = inputOutput.firstNum(inputLine);

    // Expected output: The first number is 0 (indicating invalid input)
    EXPECT_EQ(firstNumber, 0);
}

// Test Case 4: Testing firstNum function with a valid input line
TEST(InputOutputTest, FirstNumTest4) {
    InputOutput inputOutput;
    std::string inputLine = "1111 524 245";

    // Get the first number from the input line
    int firstNumber = inputOutput.firstNum(inputLine);

    // Expected output: The first number is 1111 
    EXPECT_EQ(firstNumber, 1111);
}

// Test Case A: Testing setSetting function by providing valid input
TEST(InputOutputTest, SetSettingTest1) {
    InputOutput inputOutput;

    // Create a stringstream with valid input "8 1 2"
    std::istringstream validInput("8 1 2\n");

    // Redirect std::cin to the stringstream
    std::streambuf* originalCin = std::cin.rdbuf(validInput.rdbuf());

    // Call setSetting to read the setting
    std::string setting = inputOutput.setSetting();

    // Restore std::cin to its original state
    std::cin.rdbuf(originalCin);

    // Expected output: The setting is "8 1 2"
    EXPECT_EQ(setting, "8 1 2");
}

