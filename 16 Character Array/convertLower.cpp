#include<iostream>
#include<cstring>
using namespace std;

void print(char arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}

void lower(char arr[], int n){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z'){
            arr[i] = arr[i] - 'A' + 'a';
        }
    }
    print(arr , n);
}

int main(){
    char arr[] = "UTKAR";
    int n = strlen(arr);
    lower(arr , n);
    return 0;
}