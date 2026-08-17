#include<iostream>
#include<vector>
using namespace std;

int firstOccurence(vector<int> vec , int i , int target){
   
    

    return firstOccurence(vec , i+1 , target);
     if(i == vec.size()){
        return -1;
    }
    if(vec[i] == target){
        return i;
    }
}

int main(){
    vector<int> vec={1,2,3,3,3,4};
    cout<<firstOccurence(vec , 0 , 3);
    return 0;
}