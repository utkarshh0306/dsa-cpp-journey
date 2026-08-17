#include<iostream>
using namespace std;
// sort charater array in decending order
void print(char arr[] , int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void charSort(char arr[] , int n){
    for(int i=1 ; i<n ; i++){
        int curr = i;
        int prev = i-1;
        while(prev >= 0 && arr[prev] < arr[prev+1]){
            swap(arr[prev] , arr[prev+1]);
            prev--;
        }
    }
    print(arr , n);
}
int main(){
    char arr[]={'f','b','a','e','c','d'};
    int n = 6;
    charSort(arr , n);
    return 0;
}