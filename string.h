//string.h -- header file for test program
//Contains no nuts!
//Matthew Dupree & Diego Rico, 16 November 2017

#ifndef STRING_H
#define STRING_H

#include "expression.h"

#include <string>

int main(int argc, char* argv[]);

//Concatenates the command-line arguments together into a string.
std::string argsToString(int argc, char* argv[]);

//Produces a string with n spaces.
std::string nSpaces(int n);

#endif //STRING_H
