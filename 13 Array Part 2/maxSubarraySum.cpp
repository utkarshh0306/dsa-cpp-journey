#include<iostream>
#include <climits>
using namespace std;

void maxSubarraySum(int arr[] , int n){
    int maxSum = INT_MIN ;
    for(int st = 0 ; st<n ; st++){
        for(int en = st ; en<n ; en++){
            int currSum = 0;
            for(int i = st ; i <= en ; i++){
                currSum += arr[i];
            }
            maxSum = max(maxSum , currSum);
        }
    }
    cout<<"max sum is = "<<maxSum<<endl;
    
}

int main(){
    int arr[] = {2,-3,6,-5,4,2};
    int n = 6;
    maxSubarraySum( arr , n);
    return 0 ;
}

