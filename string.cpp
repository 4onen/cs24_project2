// string.cpp -- Testing program for project 1 files
// Matthew Dupree and Diego Rico, 16 November 2017


#include "string.h"

#include <string>
#include <iostream>



int main(int argc, char* argv[]){
    std::string input = argsToString(argc, argv);

    if(input.length()<1){
        std::cout<<"No input found!"<<std::endl;
        std::cout<<"Usage: "<<argv[0]<<" [parenthesized infix expression]"<<std::endl;
        return 0;
    }else{
        std::cout<<"You entered: "<<input<<std::endl;
    }

    Expression exp(input);

    if(exp.infixString()=="No Tree!"){
        int n = parenCheck(input);
        if(n>0){
            std::cout<<"Missing "<<n<<" ')'s at end of input."<<std::endl;
        }else if(n<0){
            std::cout<<"             "<<nSpaces(-n-1)<<"^"<<std::endl;
            std::cout<<"Missing '(' before marked ')'."<<std::endl;
        }else{
            std::cout<<"Unspecified internal error. Sorry!"<<std::endl;
        }
    }else{//No errors! In theory.
        std::cout<<"Infix: "<<exp.infixString()<<std::endl;
        std::cout<<"Prefix: "<<exp.prefixString()<<std::endl;
        std::cout<<"Postfix: "<<exp.postfixString()<<std::endl;
    }

    return 0;
}



std::string argsToString(int argc, char* argv[]){
    std::string ret = "";
    for(int i=1;i<argc;i++){
        ret.append(argv[i]);
        ret+=" ";
    }
    return ret;
}

std::string nSpaces(int n){
    return std::string(n,'.');
}
