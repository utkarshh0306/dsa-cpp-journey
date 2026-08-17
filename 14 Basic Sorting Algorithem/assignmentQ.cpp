#include<iostream>
using namespace std;

void print( int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}

// void bubble(int arr[] , int n){
//     for(int i=0 ; i<n-1 ; i++){
//         for(int j=0 ; j<n-i-1 ; j++){
//           if(arr[j] < arr[j+1]){
//             swap(arr[j] , arr[j+1]);
//           }
//         }
//     }
    
//     print(arr , n);
// }

void selction(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        int minIdx = i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j]>arr[minIdx]){
                minIdx = j;
            }
            swap(arr[i] , arr[minIdx]);
        }
    } 
    
    print(arr , n);
}


void insertion(int arr[] , int n){
     for(int i=1 ; i<n ; i++){
        int curr = i;
        int prev = i-1;
        while(prev >=0 && arr[prev] < arr[prev+1]){
            swap(arr[prev] , arr[prev+1]);
            prev--;
        }
     }
    
    print(arr , n);
}

int main(){
    int arr[]={3,6,2,1,8,7,4,5,3,1};
    int n= 10;
    // bubble(arr , n);
    // selction(arr , n);
    insertion(arr , n);
    return 0;
}