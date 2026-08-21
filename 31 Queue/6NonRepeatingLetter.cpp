#include<iostream>
#include<queue>
#include<string>
using namespace std;

char nonReapeating(string str){
    int freq[26] = {0};
    queue<char> q;

    for(int i=0 ; i<str.size() ; i++){
        char ch = str[i];
        
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty() && freq[q.front() - 'a']>1){
            q.pop();
        }
    }
    if(q.empty()){
        return -1;
    }else{
        return q.front();
    }
}

int main(){
    string str = "aabccxb";
    cout<<nonReapeating(str);

    return 0;
}