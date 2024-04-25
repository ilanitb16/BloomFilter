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
    bool blackListed(std::vector<int> bitsarray);
    bool checkFalsePossitive(std::string checkURL);
    void addURLToBitsArray(HashFunctions hashFunctions, std::string inputLine);
    bool searchURLInBitArray(HashFunctions hashFunctions, std::string inputLine);
    bool bloomFilter(InputOutput inputOutput, int commandNumber, HashFunctions hashFunctions, std::string URL);
    bool commandAndURL(InputOutput inputOutput, HashFunctions hashFunctions, std::string input);
    private:
    int size;            // Size of the array
    std::vector<int> array;  // Vector to store the bits
    std::vector<std::string> URLarray; //Vector to store the blacklist URL's
};

#endif