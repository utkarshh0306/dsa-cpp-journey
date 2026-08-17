#include<iostream>
#include <climits>
using namespace std;

void maxProfit(int price[] , int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    cout<<bestBuy[0]<<endl;

    for(int i=1 ; i<n ; i++){
        bestBuy[i]= min(bestBuy[i-1], price[i-1]);
        cout<<bestBuy[i]<<" ,";
    }

    int maxProfit = 0;
    for(int i=0 ; i<n ; i++){
        int currProfit = price[i] - bestBuy[i] ;
        maxProfit = max(maxProfit , currProfit);
    }

    cout<<"Max profit is :"<<maxProfit<< endl;
}

int main(){
    int price[6] = {7,1,5,3,6,4};
    int n = sizeof(price)/sizeof(int);
    maxProfit(price , n);
    return 0 ;
}