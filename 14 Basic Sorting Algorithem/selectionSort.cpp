#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void selction(int arr[], int n){
    for(int i=0 ; i<n ; i++){
        int minIdx = i;

        for(int j=i+1 ; j<n ; j++){
            if(arr[j]<arr[i]){
                minIdx = j;
            }
        }
        swap(arr[i],arr[minIdx]);
    }
    print(arr , n);
}

int main(){
    int arr[]={3,2,4,1,5};
    int n=5;
    selction(arr , n);
    return 0;
}