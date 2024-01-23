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