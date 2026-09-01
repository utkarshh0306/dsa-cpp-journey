#include<iostream>
#include<vector>
using namespace std;

int maxSelection(vector<int> st , vector<int> end){
    cout<<"A0"<<endl;
    int count = 1;
    int currEnd = end[0];

    for(int i=1 ; i<end.size() ; i++){
        if(st[i]>=currEnd){
            cout<<"A"<<i<<endl;
            count++;
            currEnd = end[i];
        }
    }
    return count;
}

int main(){
    vector<int> st = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout<<maxSelection(st , end)<<endl;

    return 0;
}