#include<iostream>
using namespace std;

bool search(int arr[][4] , int n , int m , int key){
    int i = n-1 ; 
    int j = 0 ;
    
    while(i>=0 && j<m){
        if(arr[i][j] == key){
            cout<<"Key found at("<<i<<","<<j<<")";
            return true;
        }else if(arr[i][j] > key){
            i--;
        }else if(arr[i][j] < key){
            j++;
        }
    }
    cout<<"Key not found";
    return false;
}

int main(){
    int arr[][4]={{10,20,30,40},
                  {15,25,35,45},
                  {27,29,37,48},
                  {32,33,39,50}};
    int n=4 , m=4;
    int key = 40;

    search(arr , n , m , key);
    return 0 ;
}