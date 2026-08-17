#include<iostream>
using namespace std;

int way(int r , int c , int n , int m){
    // base case
    if(r == n-1 && c == m-1){
        return 1 ;
    }
    if(r >= n || c >= m){
        return 0;
    }

    // right 
    int v1 = way(r , c+1 , n , m);
    // down
    int v2 = way(r+1 , c , n , m);

    return v1 + v2 ;
}

int main(){
    int n = 3;
    int m = 3;
    cout<<"Total no of ways : "<<way(0,0,n,m);
    return 0;
}