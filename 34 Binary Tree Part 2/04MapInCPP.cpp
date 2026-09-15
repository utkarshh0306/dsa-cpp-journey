#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    // creat map
    map<int , string> m;

    // insert values
    m[101] = "utkarsh";
    m[102] = "tanaji";
    m[103] = "jadhav";

    // access values
    cout<<m[103]<<endl;

    // key exist or not
    m.count(2);

    // loop in map
    for(auto it : m){
        cout<<"key: "<<it.first<<", value: "<<it.second<<endl;
    }

    return 0;


}