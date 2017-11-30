//Node.h -- Core data representation class
//Matthew Dupree & Diego Rico, 16 November 2017


#ifndef NODE_H
#define NODE_H

#include <string>

enum class Op:char
    { ADDITION='+'
    , SUBTRACTION='-'
    , MULTIPLICATION='*'
    , DIVISION='/'
    , NONE='N'
    };

enum expEnum
    { anExpression
    , aVariable
    , aConstant
    , aNothing
    };

enum fixEnum
    { INFIX
    , PREFIX
    , POSTFIX
    };


class Node {
    Node* parent;
    Op operation;
    expEnum leftType;
    Node* left;
    int leftConstant;
    expEnum rightType;
    Node* right;
    int rightConstant;

  public:
    Node(): 
        operation(Op::NONE),
        leftType(aNothing),left(0),leftConstant(-1),
        rightType(aNothing),right(0),rightConstant(-1){}

    Node(const Node& n, bool copyParent=false, Node* newParent=0);

    static Op getOpForChar(char opChar);
    
    //Mutators
    void setParent(Node* newParent);
    void setOp(Op newOp);
    bool setOp(char newOpChar);
    void setLeftVariable();
    void setLeftConstant(int n);
    void setLeftExpression(Node* expression);
    void setRightVariable();
    void setRightConstant(int n);
    void setRightExpression(Node* expression);

    //Direct fetch
    Node* getParent() const;
    Op getOp() const;
    expEnum getLeftType() const;
    expEnum getRightType() const;
  
    int getLeftConstant() const;
    Node* getLeftExpression() const;

    int getRightConstant() const;
    Node* getRightExpression() const;

    //Indirect fetch
    char getOpChar() const;
    std::string leftString(const fixEnum fixing=INFIX) const;
    std::string rightString(const fixEnum fixing=INFIX) const;
    std::string toString(const fixEnum fixing=INFIX) const;
    std::string toInfix() const{ return toString(); }
    std::string toPrefix() const{ return toString(PREFIX); }
    std::string toPostfix() const{ return toString(POSTFIX); }
};

#endif //NODE_H
