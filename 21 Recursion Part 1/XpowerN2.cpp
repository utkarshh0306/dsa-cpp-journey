#include<iostream>
using namespace std;

int power(int x , int n){
    if(n==0){
        return 1;
    }

    int halfpow = power(x , n/2);
    int halfpowSqu = halfpow * halfpow;

    if(n % 2 != 0){
        return x*halfpowSqu;
    }

    return halfpowSqu;
}

int main(){
    cout<<power(2,10);
    return 0;
}