#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int val = 2430;
    int n = coins.size();
    int ans = 0;
    for(int i=n-1 ; i>0 && val>0 ; i--){
        if(val >= coins[i]){
            ans += val / coins[i];
            val = val % coins[i];
        }
    }

    cout<<"min count of coins is "<<ans<<endl;

    return 0;
}