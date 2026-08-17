#include<iostream>
using namespace std;

void sum(int arr[][3] , int n ,int m){
    int   j=0;
    int sum = 0;
    while(j<m){
        sum += arr[1][j];
        j++;
    }
    cout<<sum;
}

int main(){
    int arr[][3]={{1,2,9},
                  {11,4,3},
                  {2,2,3}};
    int m = 3 , n=3;
    sum(arr , n , m);
    return 0 ;
}