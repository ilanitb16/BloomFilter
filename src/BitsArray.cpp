#include "include/BitsArray.h"
#include <string.h>


BitsArray::BitsArray(int size){
    this->size = size;
    this->array = new int[size];

    for (int i = 0; i < size; i++){
        array[i] = 0;
    }
}

int BitsArray::getArraySize(){
    return this->size;
}

int* BitsArray::getArray(){
    return this->array;
}

void BitsArray::h1(std::string url){
    std::size_t size = hashUrl(url, "h1");
    int bit = size % 8;
    this->array[bit] = 1;
}

void BitsArray::h2(std::string url){
    std::size_t size = hashUrl(url, "h2");
    int bit = size % 8;
    this->array[bit] = 1;
}

std::size_t BitsArray::hashUrl(std::string url, std::string key){
    std::size_t size = std::hash<std::string>{}(url + key);
    return size;
}

bool BitsArray::addUrlToArray(std::string url){
    h1(url);
    h2(url);
    return true;
}

/**  * Check if a url is blacklisted in the filter or not.
 *
 * @param url The url to check.
 * @return true if the url might have false positive, false otherwise.
 */

bool BitsArray::isBlackListed(std::string url){
    std::size_t size1 = hashUrl(url, "h1");
    int bit1 = size1 % 8;

    std::size_t size2 = hashUrl(url, "h2");
    int bit2 = size2 % 8;

    if(this->array[bit1] == 1 && this->array[bit2] == 1){
        return true;
    }
    else{
        return false;
    }
}

