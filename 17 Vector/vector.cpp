#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2 = {1,2,3,4,5};
    vector<int> vec3(5 , -2);

    for(int i=0 ; i<vec2.size() ; i++){
        cout<<vec2[i]<<","<<endl;
    }

    for(int i=0 ; i<vec3.size() ; i++){
        cout<<vec2[i]<<",";
    }

    return 0;
}