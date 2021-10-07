/**
 * Misha Butt
 * commandclass is responsible for executing the command and storing the result and exit code
 * October 6 2021
 * **/

#include "commandclass.h"
#include <string>
#include <boost/process.hpp>

using namespace boost::process;
using namespace std;

/**
 * commandclass constructor 
 * sets the string to be executed, the result and the code
 * no return type
 * takes the string to be executed (user's input) as a parameter
 * **/
commandclass::commandclass(string stringToBeExecuted) {
    unexecutedInput = stringToBeExecuted;
    result = "";
    code = 0;
}

/**
 * getUnexecutedInput() function
 * returns the input entered by the user
 * **/
string commandclass::getUnexecutedInput() {
    return unexecutedInput;
}

/**
 * setUnexecutedInput() function
 * sets the input to be executed
 * **/
void commandclass::setUnexecutedInput(string setInput) {
    unexecutedInput = setInput;
}

/**
 * getResult() function
 * returns the output of the command
 * **/
string commandclass::getResult() {
    return result;
}

/**
 * getCode() function
 * returns the exit code of the command
 * **/
int commandclass::getCode() {
    return code;
}

/**
 * execute() function
 * takes the user's input and passes it through the shell to get the output and set it
 * **/
void commandclass::execute() {

    //try and catch block is used to catch exceptions when the user input is invalid
    try {
        ipstream pipe_stream;
        child c(unexecutedInput, (std_out & std_err) > pipe_stream);
        std::string line;
        result = line;
        while (pipe_stream && std::getline(pipe_stream, line) && !line.empty()) {
            result.append(line);
        }
        c.wait();
    }

    catch(...) {
        code = -1;
        result = "The command does not exist.\n";
    }       
}

/**
 * destructor
 * **/
commandclass::~commandclass() {
}	

      
