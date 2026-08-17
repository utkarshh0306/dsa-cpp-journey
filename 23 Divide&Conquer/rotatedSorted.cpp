#include<iostream>
using namespace std;

int search(int arr[] , int si , int ei , int key){
    if(si > ei){
        return -1;
    }

    int mid = si + (ei - si) / 2 ;

    if(arr[mid] == key){
        return mid ; 
    }

    if(arr[si] <= arr[mid]){
        if(arr[si] <= key && key <= arr[mid]){
            search(arr , si , mid-1 , key);
        }
        else{
            search(arr , mid+1 , ei , key);
        }
    }
    else{
        if(arr[mid] <= key && key <= arr[ei]){
            search(arr , mid+1 , ei , key);
        }
        else{
            search(arr , si , mid-1 , key);
        }
    }
}
int main(){
    int arr[] = {4,5,6,7,0,1,2};
    int key = 0;
    cout<<search(arr , 0 , 6 , key);
    return 0 ;
}