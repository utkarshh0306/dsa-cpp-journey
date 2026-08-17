#include<iostream>
using namespace std;

void display(int arr[][3] , int n , int m ){
    int count = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(arr[i][j] == 7){
                count ++;
            }
        }
    }
    cout<<count;
}

int main(){
    int arr[2][3]={{4,7,7},
                   {8,8,7}};
    int n=2 ;
    int m=3;
    display(arr , n, m);
    return 0;
            
}