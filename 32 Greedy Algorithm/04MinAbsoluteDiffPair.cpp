#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a = {1,2,3};
    vector<int> b = {1,4,3};

    sort(a.begin() , a.end());
    sort(b.begin() , b.end());

    int ans = 0;
    for(int i=0 ; i<a.size() ; i++){
        ans += abs(a[i]-b[i]);
    }

    cout<<ans<<endl;

    return 0;
}