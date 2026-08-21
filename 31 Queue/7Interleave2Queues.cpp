#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void interLeave(queue<int> &o){
    int n = o.size();
    queue<int> q1;
    for(int i=1 ; i<=(n/2) ; i++ ){
        q1.push(o.front());
        o.pop();
    }

    while(!q1.empty()){
        o.push(q1.front());
        q1.pop();
        o.push(o.front());
        o.pop();
    }

}
int main(){
    queue<int> o;
    for(int i=1 ; i<=10 ; i++){
        o.push(i);
    }

    interLeave(o);

    for(int i=1 ; i<=10 ; i++){
        cout<<o.front()<<" ";
        o.pop();
    }
    return 0;

}