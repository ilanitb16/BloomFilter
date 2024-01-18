#include "BitsArray.cpp"
/*
int main(){
while (true)
{
    std::cout << "put a number" << std::end;
    std::cin >> x;
    createArray(x);
}
return 0;
}
*/

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool containsNonNumeric(std::string str) {
    for (char c : str) {
        if (!isDigit(c) && c != ' ') {
            return true;  // Found a non-numeric, non-space character
        }
    }
    return false;  // All characters are numeric or spaces
}

int firstNum(std::string inputLine){
    if (containsNonNumeric(inputLine)) {
            return 0;
    }
    // Extract and store the first number in a variable
        int firstNumber = 0;
        std::size_t i = 0;
        while (i < inputLine.length() && !isDigit(inputLine[i])) {
            ++i;
        }
        while (i < inputLine.length() && isDigit(inputLine[i])) {
            firstNumber = firstNumber * 10 + (inputLine[i] - '0');
            ++i;
        }
        return firstNumber;

}


int createArray(std::string inputLine){
    BitsArray bitsArray(firstNum(inputLine));
    return bitsArray.getArraySize();
}