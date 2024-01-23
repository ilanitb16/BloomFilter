#include "BitsArray.h"
#include "InputOutput.h"
#include "HashFunctions.h"
#include <sstream>
#include <vector>

//constructor
BitsArray::BitsArray(int size) {
    //the size of the array
    this->size = size;
    //the array itself
    this->array = std::vector<int>(size, 0);
}

//getting the size of the array
int BitsArray::getArraySize() {
    return this->size;
}

//getting the array itself
std::vector<int> BitsArray::getArray() {
    return this->array;
}

//add the URL by hash and by name to the system
void BitsArray::addURL(std::vector<int> bitsarray, std::string URL) {
    //add the URL by his hash result
    for (int i = 0; i < this->size; i++) {
        if (bitsarray[i] == 1) {
            this->array[i] = 1;
        }
    }
    //add the URL to the list of black list  URLs
    this->URLarray.push_back(URL);
}