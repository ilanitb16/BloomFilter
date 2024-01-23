//this is the BitsArray header file


#ifndef BITSARRAY_H
#define BITSARRAY_H
#include <vector>
#include "InputOutput.h"
#include "HashFunctions.h"
#include <string>

class BitsArray {
public:
    BitsArray(int size);
    int getArraySize();
    std::vector<int> getArray();
    void addURL(std::vector<int> bitsarray, std::string URL);
    private:
    int size;            // Size of the array
    std::vector<int> array;  // Vector to store the bits
    std::vector<std::string> URLarray; //Vector to store the blacklist URL's
};

#endif