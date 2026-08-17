#include<iostream>
using namespace std ;

int check(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            if(arr[i] == arr[j]){
                cout<<"Yes";
                return 0 ;
            }
            else{
                cout<<"No";
                return 0 ;
            }
        }
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    check(arr , n);
    return 0 ;
}