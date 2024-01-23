#include <iostream>
#include "InputOutput.h"

//constructor
InputOutput::InputOutput() {
    
}

//checking if a single character is a digit
bool InputOutput::isDigit(char c) {
    return (c >= '0' && c <= '9');
}

//checking if every character in the inputLine is a digit or a space
bool InputOutput::containsNonNumeric(std::string inputLine) {
    for (char c : inputLine) {
        if (!isDigit(c) && c != ' ') {
            // Found a non-numeric, non-space character
            return true;
        }
    }
    // All characters are numeric or spaces
    return false;
}


//checking if the input is invalid and if it doesn't set the hash functions
bool InputOutput::invalidInput(std::string inputLine) {
    //checking if the inputLine contain only digits or a spaces
    if (this->containsNonNumeric(inputLine)) {
        //it is invalid input
        return true;
    }
    std::stringstream numbers(inputLine);
    int number;
    //skip the first number which is the array size
    numbers >> number;
    //if we got valid input that contain function (1 or 2) return false (the input is valid)
    bool nonFunctions = false;
    while (numbers >> number) {
        if ((number != 1) && (number != 2)) {
            return true;
        }
        nonFunctions = true;
    }
    return !nonFunctions;
}

