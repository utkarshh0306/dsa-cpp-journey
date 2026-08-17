#include<iostream>
using namespace std;

int friendParing(int n){
    if(n==1 || n==2){
        return n;
    }

    return friendParing(n-1) + n-1 * friendParing(n-2);
}

int main(){
    cout<<friendParing(3);
    return 0;
}