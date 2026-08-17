#include<iostream>
#include<cstring>


using namespace std;

void print(char arr[] , int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void reverse(char arr[] , int n){
    int st=0 , end=n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
    print(arr , n);
}

int main(){
    char arr[]="code";
    int n = strlen(arr);
    reverse(arr , n);
    return 0;
}