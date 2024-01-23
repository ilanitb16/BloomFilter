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


//make an "array" of bits, if need to use the hash1 function,
//do hash and fill the array by modelo of the URL
std::vector<int> HashFunctions::hash1Function(std::string input, int arraySize) {
    std::vector<int> bits(arraySize, 0);
    if (this->hash1) {
        std::hash<std::string> hasher;
        size_t copy = hasher(input);
        size_t value = copy % arraySize;
        bits[value] = 1;
    }
    //return the array
    return bits;
}

//make an "array" of bits, if need to use the hash2 function,
//do hash, do it again and fill the array by modelo of the URL
std::vector<int> HashFunctions::hash2Function(std::string input, int arraySize) {
    std::vector<int> bits(arraySize, 0);
    if (this->hash2) {
        std::hash<std::string> hasher;
        size_t copy = hasher(input);
        //convert to string and do it again
        copy = hasher(std::to_string(copy));
        size_t value = copy % arraySize;
        bits[value] = 1;
    }
    return bits;
}
