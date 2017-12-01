// string.cpp -- Testing program for project 1 files
// Matthew Dupree and Diego Rico, 16 November 2017


#include "string.h"

#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
    while(true){
        string input;
        cout<<"1. Expression Evaluation, 2. Expression Comparison"<<endl;
        getline(cin, input);
        if(input.length()<1) break;
        if(input.length()>1){ cout<<"Expecting a single number!"
            <<endl<<"Empty expression to exit."<<endl;
            continue;
        }
        if(input=="1"){ cout<<"Do the 1 thing."<<endl; }
        else if(input=="2"){ cout<<"Do the 2 thing.2."<<endl; }
        else{
            cout<<"Yeah that made no sense to me. 1 or 2, please!"<<endl
                <<"Empty selection to exit."<<endl;
        }
    }
    return 0;
}

/* Useful cruft from the last project
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
*/
