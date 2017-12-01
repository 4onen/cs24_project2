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
        try{
            if(input=="1"){
                string eStr = getExpr("Expression to evaluate: ");
                Expression e(eStr);
                cout<<e.evaluate()<<endl;
            }
            else if(input=="2"){
                string e1Str = getExpr("Expression 1: ");
                string e2Str = getExpr("Expression 2: ");
                Expression e1(e1Str);
                Expression e2(e2Str);
                char compare = e1.compare(e2);
                switch(compare){
                    case '<':
                        cout<<e1Str<<" is less than "<<e2Str<<endl;
                        break;
                    case '=':
                        cout<<e1Str<<" is equal to "<<e2Str<<endl;
                        break;
                    case '>':
                        cout<<e1Str<<" is greater than "<<e2Str<<endl;
                        break;
                    default:
                        throw "Impossible compare function result.";
                        break;
                }
            }
            else{
                cout<<"Yeah that made no sense to me. 1 or 2, please!"<<endl
                    <<"Empty selection to exit."<<endl;
            }
        }catch(std::string err){
            cout<<"Error while performing operation: "<<endl<<err<<endl;
        }catch(const char *err){
            cout<<"Error while performing operation: "<<endl<<err<<endl;
        }
    }
    return 0;
}

string getExpr(string prompt){
    while(true){
        cout<<prompt;
        string ret;
        getline(cin,ret);
        if(ret.length()<1) throw "Operation cancelled by user.";
        int n = parenCheck(ret);
        if(n==0) return ret;
        if(n<0){ 
            cout<<"Missing '(' before character "<<-n<<endl;
            continue;
        }else{
            cout<<"Missing "<<n<<" ')'s at end of input."<<endl;
        }
    }
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
