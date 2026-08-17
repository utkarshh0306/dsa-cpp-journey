#include<iostream>
#include<cstring>
using namespace std;

void utk(string str){
    for(int i=0 ; i<str.length() ; i++){
        if('a'<! str[i] <! 'z'){
            str.erase(i, 1);
        }
    }
    cout<<str;
}

int main(){
    string str = "u.";
    utk(str);
    return 0 ;
}