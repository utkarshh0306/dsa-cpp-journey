#include<iostream>
#include<cstring>
using namespace std;

bool check(string str1 , string str2){
    int a[2] , b=0;
    for(int i=0 ; i<str1.length() ; i++){
        if(str1[i]!=str2[i]){
            a[b++]=i;
        }
    }
    swap(str2[a[0]],str2[a[1]]);
    if(str1 == str2){
        cout<<"yes";
        return true;
    }
    else{
        cout<<"no";
        return false;
    }
}

int main(){
    string str1;
    getline(cin , str1);
    string str2;
    getline(cin , str2);

    check(str1 , str2);
    return 0;
}