#include<iostream>
#include<cstring>
using namespace std;

void lowerCase(string str1){
    int count=0;
    for(int i=0 ; i<str1.length() ; i++){
        if( str1[i]=='a'|| str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u' ){
            count++;
        }
    }
    cout<<"Count is "<<count;
}

int main(){
    string str1;
     getline(cin , str1);
    lowerCase(str1 );
    return 0;
}