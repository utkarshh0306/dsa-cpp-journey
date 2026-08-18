#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValidP(string str){
    // creating a stack for check reverse order
    stack<char> s;

    // traverce on string 
    for(int i=0 ; i<str.size() ; i++){
        // check for open paranthesis
        if((str[i]=='(') ||
           (str[i]=='{') ||
           (str[i]=='[') ){
            // push in stack it is opening
            s.push(str[i]);
        }else{
            // this is closing paranthesis
            // check first stack is empty for less or nothing opening paranthesis
            if(s.empty()){
                return false;
            }
            // check pair happening
            char top = s.top();
            char ch = str[i];
            if((top=='(' && ch==')')||
               (top=='{' && ch=='}')||
               (top=='[' && ch==']')){
                s.pop();
            }else{
                return false;
            }

        }
    }
    // at last check if stack is empty 
    return s.empty();
}

int main(){
    string str = "({[])";
    cout<<isValidP(str);
    return 0;
}