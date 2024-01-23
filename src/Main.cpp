#include <vector>
#include "BitsArray.cpp"
#include "HashFunctions.cpp"
#include "InputOutput.cpp"

int main()
{
    InputOutput inputOutput;
    std::string setting = inputOutput.setSetting();
    int arraySize = inputOutput.firstNum(setting);
    HashFunctions hashFunctions(setting);
    BitsArray bitsArray(arraySize);   
    bitsArray.commandAndURL(inputOutput, hashFunctions);
}