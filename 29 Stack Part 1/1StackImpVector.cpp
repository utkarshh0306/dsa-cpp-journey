#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class T>
class Stack{
    vector<T> vec;
    public:
        void push(T n){
            vec.push_back(n);
        }

        void pop(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
            }
            vec.pop_back();
        }

        T top(){
            if(isEmpty()){
                cout<<"Stack is Empty"<<endl;
            }
            int lastIdx = vec.size()-1;
            return vec[lastIdx];
        }

        bool isEmpty(){
            return vec.size() == 0;
        }
};

int main(){
    Stack<int> s;
    Stack<string> a;

    s.push(3);
    s.push(2);
    s.push(1);
    
    a.push("jadhav");
    a.push("tanaji");
    a.push("utkarsh");
    


    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    while(!a.isEmpty()){
        cout<<a.top()<<" ";
        a.pop();
    }


    return 0;
}