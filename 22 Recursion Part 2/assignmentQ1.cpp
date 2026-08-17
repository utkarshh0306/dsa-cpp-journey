#include<iostream>
using namespace std;

int assiQ1(int arr[] , int l , int r , int key){
    if(r<l){
        return -1;
    }

    int mid = (l+r)/ 2;

    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        return assiQ1(arr , l , mid-1 , key);
    }
    else{
        return assiQ1(arr , mid+1 , r , key);
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    cout<<assiQ1(arr , 0 , 4 , 5)<<endl;
    return 0;
}