#ifndef HASHFUNCTIONS_H
#define HASHFUNCTIONS_H
#include <vector>
#include <string>
#include "HashFunctions.h"
class HashFunctions {
public:
    HashFunctions(std::string setting);
    bool getHash1();
    bool getHash2();
private:
    bool hash1;
    bool hash2;
};

#endif