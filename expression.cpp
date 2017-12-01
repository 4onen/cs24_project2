//Expression.cpp -- Implementation of node encapsulation class
//Matthew Dupree & Diego Rico, 16 November 2017

#include "expression.h"

Expression::Expression(std::string pInfix){
    tree = parenInfixToAST(pInfix);
}

Expression::Expression(const Expression &source){
    tree = new Node(*source.tree);
}

std::string Expression::infixString() const{
    if(tree != 0)
        return tree->toInfix();
    return "No Tree!";
}

std::string Expression::prefixString() const{
    if(tree != 0)
        return tree->toPrefix();
    return "No Tree!";
}

std::string Expression::postfixString() const{
    if(tree != 0)
        return tree->toPostfix();
    return "No Tree!";
}

int Expression::evaluate() const{
    if(tree != 0)
        return tree->eval();
    throw "No Tree!"; 
}

char Expression::compare(const Expression &other) const{
    int me = evaluate();
    int them = other.evaluate();
    if(me>them) return '>';
    if(them>me) return '<';
    return '=';
}
