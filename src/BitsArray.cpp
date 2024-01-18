#include "include/BitsArray.h"

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