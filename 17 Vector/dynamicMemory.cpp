#include<iostream>
using namespace std;
int main(){
    int size ;
    cin>>size;

    int *ptr = new int[size];
    int x=1;
    for(int i =0 ; i<size ; i++){
        ptr[i] = x++;
        cout<<ptr[i]<<" ";
    }

    return 0 ;
}