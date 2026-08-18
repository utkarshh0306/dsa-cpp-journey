#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValidP(string str){
    // creating a stack for check reverse order
    stack<char> s;

    // traverce on string 
    for(int i=0 ; i<str.size() ; i++){
        char ch = str[i];
        // check opening paranthesis and expression
        if(ch != ')'){
            s.push(ch);
        }
        // clossing paranthesis
        else{
            if(s.top() == '('){
                // duplicate is here
                return true;
            }
            // remove all expresion upto opening paranthesis
            while(s.top() == '('){
                s.pop();
            }
            // remove 1st opening paranthesis
            s.pop();
        }
    }
    return false;
                
}

int main(){
    string str = "(a)";
    cout<<isValidP(str);
    return 0;
}