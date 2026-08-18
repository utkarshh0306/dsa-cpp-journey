#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void maxArea(vector<int> height){
    int n = height.size();
    stack<int> s;
    // next smaller left
    vector<int> nsl(n);
    // next smaller right
    vector<int> nsr(n);

    // calculate nsl
    nsl[0] = -1;
    s.push(0);

    for(int i=1 ; i<n ; i++){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }else{
            nsl[i] = s.top();
        }
        s.push(i);
    }

    // for make empty stack for use in nsr
    while(!s.empty()){
        s.pop();
    }

    // calculate nsr
    nsr[n-1] = n;
    s.push(n-1);

    for(int i=n-2 ; i>=0 ; i--){
        int curr = height[i];
        while(!s.empty() && curr <= height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int mArea  = 0;
    for(int i=0 ; i<n ; i++){
        int area = height[i] * (nsr[i] - nsl[i] - 1);
        mArea = max(area , mArea);
    }

    cout<<mArea<<endl;
}

int main(){
    vector<int> height = {2,1,5,6,2,3};
    maxArea(height);
    return 0;
}