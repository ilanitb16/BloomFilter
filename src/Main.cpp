#include <vector>
#include "BitsArray.h"
#include "HashFunctions.h"
#include "InputOutput.h"

int main()
{
    InputOutput inputOutput;
    std::string setting = inputOutput.setSetting();
    int arraySize = inputOutput.firstNum(setting);
    HashFunctions hashFunctions(setting);
    BitsArray bitsArray(arraySize);   
    bitsArray.commandAndURL(inputOutput, hashFunctions);
}