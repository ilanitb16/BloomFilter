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

//check if URL (by array after hashing) is in the system
bool BitsArray::blackListed(std::vector<int> bitsarray) {
    //if return true the URL is indeed in the list
    for (int i = 0; i < this->getArraySize(); i++) {
        if (this->array[i] == 0 && bitsarray[i] == 1) {
            return false;
        }
    }
    return true;
}


//checking if the URL is in the black listed URL
bool BitsArray::checkFalsePossitive(std::string checkURL) {
    for (int i = 0; i < this->URLarray.size(); i++){
        if (URLarray[i] == checkURL) {
            return true;
        }
    }
    return false;
}
//getting the hashing result and add the URL to the black list
void BitsArray::addURLToBitsArray(HashFunctions hashFunctions, std::string inputLine) {
    std::vector<int> hash = hashFunctions.mixHashArray(inputLine, this->getArraySize());
    this->addURL(hash, inputLine);
}

//checking out if the URL is in the system by his hashing array
bool BitsArray::searchURLInBitArray(HashFunctions hashFunctions, std::string inputLine) {
    //get the hash result
    std::vector<int> checking = hashFunctions.mixHashArray(inputLine, this->getArraySize());
    //check if the URL is in the system
    return this->blackListed(checking);
}


//checks what to do, insert or search and do it
bool BitsArray::bloomFilter(InputOutput inputOutput, int commandNumber, HashFunctions hashFunctions, std::string URL) {
    //if need to add URL
    if (commandNumber == 1) {
        this->addURLToBitsArray(hashFunctions, URL);
    }
    //if need to search for URL
    else if (commandNumber == 2) {
        //checking out if the URL is in the system by his hashing array
        bool blackList = this->searchURLInBitArray(hashFunctions, URL);
        //checking if the URL is in the black listed URL
        bool falsePossitive = this->checkFalsePossitive(URL);
        //print the massege according to the results
        return inputOutput.printMassege(blackList, falsePossitive);
    }
    //done an insertion, we don't care about the return
    return false;
}

//run the code forever, getting the URL with a number and doing the bloom filter
bool BitsArray::commandAndURL(InputOutput inputOutput, HashFunctions hashFunctions, std::string input) {
        //getting input
        std::istringstream command(input);
        int commandNumber;
        std::string URL;
        // take the number and the URL if valid
        command >> commandNumber >> URL;
        if (command) {
            //bloom filter
            return this->bloomFilter(inputOutput, commandNumber, hashFunctions, URL);    
        }
        //if invalid return false
        return false;
}