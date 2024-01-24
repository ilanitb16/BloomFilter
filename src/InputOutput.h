#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

class InputOutput {
public:
	InputOutput();
	bool isDigit(char c);
	bool containsNonNumeric(std::string str);
	bool invalidInput(std::string inputLine);
    int firstNum(std::string inputLine);
    std::string setSetting();
    std::istringstream getCommand();
    void printMassege(bool blacklist, bool falsePosittive);
    private:
};

#endif