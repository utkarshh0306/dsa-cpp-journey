#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int , int> p1 , pair<int , int> p2){
    return p1.second < p2.second ;
}

int main(){
    vector<pair<int,int>> act(3,make_pair(0,0)) ;
    act[0]=make_pair(0,9);
    act[1]=make_pair(1,2);
    act[2]=make_pair(3,4);

    for(int i=0 ; i<act.size() ; i++){
        cout<<act[i].first<<","<<act[i].second<<endl;
    }

    sort(act.begin() , act.end() , compare);

    for(int i=0 ; i<act.size() ; i++){
        cout<<act[i].first<<","<<act[i].second<<endl;
    }

    return 0;

}