#include<iostream>
#include <climits>
using namespace std;

void trapWater(int height[] , int n){
    int leftMax[20000] , rightMax[20000];
    leftMax[0] = height[0];
    rightMax[n-1] = height[n-1];
    cout<<leftMax[0]<<endl;
    cout<<rightMax[n-1]<<endl;

    // leftmax
    for(int i=1 ; i<n ; i++){
        leftMax[i]= max(leftMax[i-1], height[i-1]);
        cout<<leftMax[i]<<" ,";
    }
    cout<<endl;

    // rightMax
    for(int i=n-2 ; i>=0 ; i--){
        rightMax[i]= max(rightMax[i+1],height[i+1]);
        cout<<rightMax[i]<<" ,";
    }
    cout<<endl;

    // watertrap
    int waterTrap = 0;
    for(int i=0 ; i<n ; i++){
        int currWater = min(leftMax[i] , rightMax[i]) - height[i];
        if(currWater > 0){
            waterTrap += currWater;
        }
    }

    cout<< "Water trap is = "<< waterTrap <<endl;

     
}

int main(){
    int height[7] = {4,2,0,6,3,2,5};
    int n = sizeof(height)/sizeof(int);
    trapWater(height , n);
    return 0 ;
}