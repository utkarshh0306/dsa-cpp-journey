#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int , int> p1 , pair<int,int> p2){
    return p1.second < p2.second ;

}

int main(){
    int n = 5;
    vector<pair<int , int>>pairs(n , make_pair(0,0));
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    sort(pairs.begin(),pairs.end(),compare);
    int ans = 1;
    int currEnd = 24;

    for(int i=1 ; i<n ; i++){
        if(pairs[i].first > currEnd){
            ans ++;
            currEnd = pairs[i].second;
        }
    }

    cout<<ans<<endl;

    return 0;
}