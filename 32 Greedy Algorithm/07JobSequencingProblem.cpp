#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1 ,pair<int,int> p2 ){
    return p1.second < p2.second;
}

int main(){
    int n = 4;
    vector<pair<int,int>> job(n, make_pair(0,0));
    job[0] = make_pair(4,20);
    job[1] = make_pair(1,10);
    job[2] = make_pair(1,40);
    job[3] = make_pair(1,30);

    sort(job.begin() , job.end() , compare);

    int safeDead = 0;
    int profit = job[0].second;
    for(int i=1 ; i<n ; i++){
        if(job[i].first >= safeDead){
            profit += job[i].second;
            safeDead ++;
        }
    }

    cout<<profit<<endl;
    return 0;


}