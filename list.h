//List.h -- Tree-building and infix parsing algorithm declaration
//Matthew Dupree & Diego Rico, 16 November 2017

#ifndef LIST_H
#define LIST_H

#include "node.h"

Node* parenInfixToAST(const std::string pInfix);

int parenCheck(const std::string pInfix);

bool properlyParenthesized(const std::string pInfix);

#endif //LIST_H
