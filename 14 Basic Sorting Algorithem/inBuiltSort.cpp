#include<iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}
 

int main(){
    int arr[]={3,2,4,1,5};
    int n=5;
    sort(arr , arr+5);
    print(arr , n);
    sort(arr , arr+5 , greater<int>());
    print(arr , n);
     return 0;
}