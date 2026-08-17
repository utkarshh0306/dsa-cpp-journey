#include<iostream>
using namespace std;

void print( int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}

void bubble(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n-i-1 ; j++ ){
            if(arr[j]>arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    print(arr , n);
}

int main(){
    int arr[]={5,4,1,3,2};
    int n= 5;
    bubble(arr , n);
    return 0;
}