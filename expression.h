//Expression.h -- declaration of Node class encapsulation
//Matthew Dupree & Diego Rico, 16 November 2017


#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>

#include "list.h"

class Expression{
    public:
        Expression(std::string pInfix);
        Expression(const Expression &source);
        std::string infixString() const;
        std::string prefixString() const;
        std::string postfixString() const;
    private:
        Node* tree;
};

#endif //EXPRESSION_H
