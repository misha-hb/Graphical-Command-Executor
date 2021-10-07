/**
 * Misha Butt
 * Header file for commandclass
 * October 6 2021
 * **/

#ifndef COMMANDCLASS_H
#define COMMANDCLASS_H

#include <iostream>
#include <string>
#include <boost/process.hpp>

using namespace std;

class commandclass {
    private:
	string unexecutedInput;
	string result;
        int code;
    public:
        commandclass(string stringToBeExecuted);
        string getUnexecutedInput();
        void setUnexecutedInput(string setInput);
	string getResult();
        int getCode();
        void execute();

	~commandclass();
};

#endif
