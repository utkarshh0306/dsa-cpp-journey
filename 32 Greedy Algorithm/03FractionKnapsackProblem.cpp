#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<double , int> p1 ,pair<double , int> p2){
    return p1.first > p2.first ;
}

void fractionKnapsack(vector<int> val , vector<int> weight , int w){
    int n = val.size();
    // ratio(double ,  index)
    vector<pair<double , int>> ratio(n , make_pair(0.0,0));
    // calculate ratio and insert in that vector
    for(int i=0 ; i<n ; i++){
        double r = val[i]/weight[i];
        ratio[i] = make_pair(r,i);
    }

    // sort ratio for get max value first
    sort(ratio.begin() , ratio.end() , compare);

    // now part of knapsack
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        int idx = ratio[i].second ;
        if(weight[idx]<=w){
            ans += val[idx];
            w -= weight[idx];
        }else{
            ans += ratio[i].first * w;
            w = 0;
            break;
        }
    }
    cout<<"Max value: "<<ans<<endl;
}

int main(){
    vector<int> val = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;

    fractionKnapsack(val , weight , w);

    return 0;
}