#include<iostream>
using namespace std;

void sprialM(int arr[][4] , int n , int m){
    int sr=0 , sc=0 , er=n-1 , ec=m-1;
    while(sr<=er && sc<=ec){

        // top 
        for(int i=sc ; i<=ec ; i++){
            cout<<arr[sr][i]<<" ";
        }

        // right
        for(int j=sr+1 ; j<=er ;j++){
            cout<<arr[j][ec]<<" ";
        }

        // bottom
        for(int i=ec-1 ; i>=sc ; i--){
            cout<<arr[er][i]<<" ";
        }

        // left
        for(int j=er-1 ; j>=sr+1 ; j--){
            cout<<arr[j][sc]<<" ";
        }
        sr++ ; sc++; ec-- ; er--;

    }
    cout<<endl;
}

int main(){
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,7}};
    int n=4 , m=4;
    sprialM(arr , n , m);
    return 0;
}