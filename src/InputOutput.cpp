#include <iostream>
#include <sstream>
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

//getting the first number in the first input- the array size
int InputOutput::firstNum(std::string inputLine) {
    int firstNumber = 0;
    std::size_t i = 0;
   //we already knoe that the input is valid, here we get the first number char by char
    while (i < inputLine.length() && this->isDigit(inputLine[i])) {
        firstNumber = firstNumber * 10 + (inputLine[i] - '0');
        ++i;
    }
    return firstNumber;
}

//getting the "setting"- the array size and the functions
std::string InputOutput::setSetting() {
    std::string setting;
    //ask for the "setting"
    do {
        std::getline(std::cin, setting);
        //check that the input is valid
    } while (invalidInput(setting));
    return setting;
}

//getting the input line
std::istringstream InputOutput::getCommand() {
    std::string inputLine;
    std::getline(std::cin, inputLine);
    std::istringstream command(inputLine);
    return command;
}


//printing the true/ false/ true true/ true false according to the conditions
void InputOutput::printMassege(bool blacklist, bool falsePosittive) {
    //if the URL is in the array by hash
    if (blacklist) {
        std::cout << "true ";
        //if the URL is in the array by value (in the list)
        if (falsePosittive) {
            std::cout << "true" << std::endl;
        }
        else {
            std::cout << "false" << std::endl;
        }
    }
    else {
         std::cout << "false" << std::endl;
    }
}
