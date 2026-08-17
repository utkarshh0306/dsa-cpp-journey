#include<iostream>
#include<cstring>


using namespace std;

void print(char arr[] , int n){
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}

void palindrome(char arr[] , int n){
    int st=0 , end=n-1;
    while(st<end){
        if(arr[st++]==arr[end--]){
            return true;
        }
        else{
            cout<<"not";
            break ;
        }
                    cout<<"valid ";

    }
}

int main(){
    char arr[]="cooc";
    int n = strlen(arr);
    palindrome(arr , n);
    return 0;
}