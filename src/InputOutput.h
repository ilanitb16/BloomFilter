#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H
#include <string>
#include <sstream>
class InputOutput {
public:
	InputOutput();
	bool isDigit(char c);
	bool containsNonNumeric(std::string str);
	bool invalidInput(std::string inputLine);
    int firstNum(std::string inputLine);
    std::string setSetting();
    std::istringstream getCommand();
    bool printMassege(bool blacklist, bool falsePosittive);
    private:
};

#endif