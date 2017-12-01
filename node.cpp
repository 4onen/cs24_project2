//Node.cpp -- Implementation of node.h
//Matthew Dupree & Diego Rico, 16 November 2017


#include "node.h"


//Copy constructor
Node::Node(const Node &n, bool copyParent, Node* newParent){
    if(copyParent){
        parent = n.parent;
    }else{
        parent = newParent;
    }

    operation = n.operation;
    switch(leftType=n.leftType){
        case aConstant:
            leftConstant=n.leftConstant;
            break;
        case anExpression:
            left = new Node(*n.left,false,this);
            break;
        case aVariable: 
        case aNothing:
            break;
    }
    switch(rightType=n.rightType){
        case aConstant:
            rightConstant=n.rightConstant;
            break;
        case anExpression:
            right = new Node(*n.right,false,this);
            break;
        case aVariable:
        case aNothing:
            break;
    }
}






//Static method
Op Node::getOpForChar(char opChar){
	switch(opChar){
    case '+': return Op::ADDITION;
    case '-': return Op::SUBTRACTION;
    case '*': return Op::MULTIPLICATION;
    case '/': return Op::DIVISION;
	}
	return Op::NONE;
}

//Mutators
void Node::setParent(Node* newParent){
    parent = newParent;
}

void Node::setOp(Op newOp){
  operation = newOp;
}

bool Node::setOp(char newOpChar){
	Op newOp = getOpForChar(newOpChar);
    if(newOp!=Op::NONE){
        operation=newOp;
        return true;
    }else{
        return false;
    }
}

void Node::setLeftVariable(){
    leftType = aVariable;
}

void Node::setLeftConstant(int n){
    leftType = aConstant;
    leftConstant = n;
}

void Node::setLeftExpression(Node* expression){
    leftType = anExpression;
    left = expression;
}

void Node::setRightVariable(){
    rightType = aVariable;
}

void Node::setRightConstant(int n){
    rightType = aConstant;
    rightConstant = n;
}

void Node::setRightExpression(Node* expression){
    rightType = anExpression;
    right = expression;
}


//Direct fetch
Node* Node::getParent() const{
    return parent;
}

Op Node::getOp() const{
    return operation;
}

expEnum Node::getLeftType() const{
    return leftType;
}

expEnum Node::getRightType() const{
    return rightType;
}

int Node::getLeftConstant() const{
    return leftConstant;
}

Node* Node::getLeftExpression() const{
    return left;
}

int Node::getRightConstant() const{
    return rightConstant;
}

Node* Node::getRightExpression() const{
    return right;
}

//Indirect fetch
char Node::getOpChar() const{
    return static_cast<char>(operation);
}

std::string Node::leftString(fixEnum fixing) const{
    switch(leftType){
        case anExpression:
            return left->toString(fixing);
            break;
        case aVariable:
            return "x";
            break;
        case aConstant:
            return std::to_string(leftConstant);
            break;
        case aNothing:
            return "NaN";
            break;
    }
    return "NaN";
}

std::string Node::rightString(fixEnum fixing) const{
    switch(rightType){
        case anExpression:
            return right->toString(fixing);
            break;
        case aVariable:
            return "x";
            break;
        case aConstant:
            return std::to_string(rightConstant);
            break;
        case aNothing:
            return "NaN";
            break;
    }
    return "NaN";
}
    
    

std::string Node::toString(fixEnum fixing) const{
    std::string leftString = this->leftString(fixing);

    std::string rightString = this->rightString(fixing);

    switch(fixing){
        case INFIX:
            return "("+leftString+std::string(1,getOpChar())+rightString+")";
            break;
        case PREFIX:
            return std::string(1,getOpChar())+" "+leftString+" "+rightString;
            break;
        case POSTFIX:
            return leftString+" "+rightString+" "+std::string(1,getOpChar());
            break;
    }
    return "IMPOSSIBLE_STATE";
}

int Node::eval() const{
    int left=evalLeft();
    int right=evalRight();

    switch(operation){
        case Op::ADDITION:
            return left+right;
            break;
        case Op::SUBTRACTION:
            return left-right;
            break;
        case Op::MULTIPLICATION:
            return left*right;
            break;
        case Op::DIVISION:
            return left/right;
            break;
        case Op::NONE:
            throw "Non-operating expression encountered!";
            break;
    }
    throw "This literally can't happen! Strongly typed enums have broken in C++ in Node::eval()";
}

int Node::evalLeft() const{
    switch(leftType){
        case anExpression:
            return left->eval();
            break;
        case aVariable:
            throw "HEY! You haven't given me a value for variables like 'x'!";
            break;
        case aConstant:
            return leftConstant;
            break;
        case aNothing:
            throw "Encountered Not a Number on left side of an expression!";
            break;
    }
}

int Node::evalRight() const{
    switch(rightType){
        case anExpression:
            return right->eval();
            break;
        case aVariable:
            throw "HEY! You haven't given me a value for variables like 'x'!";
            break;
        case aConstant:
            return rightConstant;
            break;
        case aNothing:
            throw "Encountered Not-a-Number on right side of an expression!";
            break;
    }
}

