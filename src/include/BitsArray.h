#ifndef BITSARRAY_H
#define BITSARRAY_H

class BitsArray {
public:
    BitsArray(int size);
    int getArraySize();
    int* getArray();
private:
int size;
int* array;
};

#endif