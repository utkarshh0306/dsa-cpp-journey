#include<iostream>
using namespace std;

void print(int arr[], int n ){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void insertion(int arr[] , int n){
    // unsorted 
    for(int i=1 ; i<n ; i++){
        int curr = arr[i];
        int prev = i-1;
        // insert
        while(prev >= 0 && arr[prev] > arr[prev+1]){
            swap(arr[prev],arr[prev+1]);
            prev --;
        }
    }
    print(arr , n);
}

int main(){
    int arr[]={5,4,1,3,2};
    int n = 5;
    insertion(arr , n);
    return 0;
}