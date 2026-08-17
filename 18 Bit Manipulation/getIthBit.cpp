#include<iostream>
using namespace std;

void getIthBit(int num , int ith){
    int bitMask = 1 << ith;
    if(!(num & bitMask)){
        cout<<"0"<<endl;
    }else{
        cout<<"1"<<endl;
    }
}
int main(){
    getIthBit(6,1);
    getIthBit(5,1);
    return 0;
}