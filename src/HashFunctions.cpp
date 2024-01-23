#include <vector>
#include <sstream>
#include "HashFunctions.h"

//constructor
HashFunctions::HashFunctions(std::string setting) {
    this->hash1 = false;
    this->hash2 = false;
    //checking the first input, which functions to operate
    std::stringstream numbers(setting);
    int number;
    //skip the first number which is the array size
    numbers >> number;
    while (numbers >> number) {
        //if need to use the first function
        if (number == 1) {
            this->hash1 = true;
        }
        //if need to use the second function
        if (number == 2) {
            this->hash2 = true;
        }
    }
}


//return if need to use the first function
bool HashFunctions::getHash1(){
    return this->hash1;
}

//return if need to use the second function
bool HashFunctions::getHash2(){
    return this->hash2;
}