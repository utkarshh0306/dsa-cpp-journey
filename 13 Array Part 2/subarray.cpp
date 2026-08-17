#include<iostream>
using namespace std;

void subArray(int arr[] , int n){
    for(int st = 0 ; st<n ; st++){
        for(int en = st ; en<n ; en++){
            for(int i = st ; i <= en ; i++){
                cout<<arr[i];
            }
            cout<<", ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;
    subArray( arr , n);
    return 0 ;
}