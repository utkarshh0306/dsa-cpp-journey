#include<iostream>
#include<string>
using namespace std;

int substring(string str , int l , int r , int a){
    if(l == str.size()){
        return a;
    }

    if(l > r){
        l+=1;
        r = str.size()-1;
    }

    if(str[l] == str[r]){
        a += 1;
    }
    return substring(str , l , r-1 , a);
}

int main(){
    string str = "aba";

    cout<<substring(str , 0 , str.size()-1 , 0);
    return 0;
}