//List.cpp -- Implementation of tree-parsing and infix parenthesization checks
//Matthew Dupree & Diego Rico, 16 November 2017

#include "list.h"

Node* parenInfixToAST(const std::string pInfix){
    if(pInfix.length()<3) //Can't be real expression
        return 0;

    if(!properlyParenthesized(pInfix))
        return 0;

    unsigned cursor = 0;
    Node* currentNode = new Node();
    Node* n;

    for(cursor=0;cursor<pInfix.length();cursor++){
        switch(pInfix[cursor]){
            case '(':
                n = new Node();
                n->setParent(currentNode);
                if(currentNode->getLeftType()==aNothing)
                    currentNode->setLeftExpression(n);
                else if(currentNode->getRightType()==aNothing)
                    currentNode->setRightExpression(n);
                else
                    //Reaching this branch is an error. Please don't!
                    return 0;
                currentNode = n;
                break;
            case '+': 
            case '-':
                if(currentNode->getLeftType()==aNothing 
                        || currentNode->getOp()!=Op::NONE){
                    if(currentNode->getLeftType()==aNothing){
                        currentNode->setLeftConstant(atoi(pInfix.c_str()+cursor));
                    }else{
                        currentNode->setRightConstant(atoi(pInfix.c_str()+cursor));
                    }
                    cursor++;
                    while(pInfix[cursor]<='9'&&pInfix[cursor]>='0'){
                        cursor++;
                    }
                    cursor--;
                    break;
                }
            case '*':
            case '/':
                currentNode->setOp(pInfix[cursor]);
                break;
            case 'x': case 'X':
                if(currentNode->getLeftType()==aNothing)
                    currentNode->setLeftVariable();
                else if(currentNode->getRightType()==aNothing)
                    currentNode->setRightVariable();
                else
                    //Reaching this branch is an error. Please don't!
                    return 0;
                break;
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                if(currentNode->getLeftType()==aNothing)
                    currentNode->setLeftConstant(atoi(pInfix.c_str()+cursor));
                else if(currentNode->getRightType()==aNothing)
                    currentNode->setRightConstant(atoi(pInfix.c_str()+cursor));
                else
                    //Reaching this branch is an error. Please don't!
                    return 0;
                while(pInfix[cursor]<='9'&&pInfix[cursor]>='0'){
                    cursor++;
                }
                cursor--; //Undo last step before next loop cycle.
                break;
            case ')':
                currentNode=currentNode->getParent();
        }
    }

    if(currentNode->getParent()!=0)//Mismatched Parentheses
        return 0;//Memory leak, but whatever.

    if(currentNode->getLeftType()==anExpression 
            && currentNode->getOp()==Op::NONE 
            && currentNode->getRightType()==aNothing){//Over-parenthesization
        n = currentNode->getLeftExpression();
        delete currentNode;
        return n;
    }

    return currentNode;
}


int parenCheck(const std::string pInfix){
    int n = 0;

    for(int cursor=0;cursor<pInfix.length(); cursor++){
        if(n<0) return (-1)*(cursor);
        switch(pInfix[cursor]){
            case '(':
                n++;
                break;
            case ')':
                n--;
                break;
        }
    }
    return n;
}

bool properlyParenthesized(const std::string pInfix){
    return parenCheck(pInfix)==0;
}
