#include<iostream>
using namespace std;

int assiQ2(int arr[] , int n ,int i , int key){
    if(i>n){
        return -1;
    }

    if(arr[i] == key){
        cout<<i;
     }
    
    return assiQ2(arr , n , i+1 , key);
    
}

int main(){
    int arr[9] = {3,2,4,5,6,2,7,2,2};
    assiQ2(arr , 9 , 0 , 2);
    return 0 ;
}