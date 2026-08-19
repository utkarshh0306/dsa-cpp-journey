#include<iostream>
using namespace std;

class Queue{
    int* arr;
    int  capacity;
    int currSize;
    int f , r;

    public:
    Queue(int size){
        capacity = size;
        currSize = 0;
        arr = new int[size];
        f=0;
        r=-1;
    }

    void push(int data){
        if(currSize==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        r = (r+1) % capacity;
        arr[r] = data;
        currSize++ ;
    }

    void pop(){
        if(currSize==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f = (f+1) % capacity;
        currSize--;
    }

    int front(){
        return arr[f];
    }

    bool empty(){
        return currSize == 0;
    }
};

int main(){
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.front()<<endl;
    q.push(5);
    q.pop();
    q.push(5);
    cout<<q.front()<<endl;

    return 0;

}
