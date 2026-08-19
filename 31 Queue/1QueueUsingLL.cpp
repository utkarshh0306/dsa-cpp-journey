#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node* next;
    // construstor
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node* head ;
    Node* tail ;
    public:
    Queue(){
        head = tail = NULL;
    }
    // push from end
    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = tail = newNode;
        }else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    // pop from start
    void pop(){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    // return front element 
    int front(){
        return head->data;
    }
    // check queue is empty or not
    bool empty(){
        return head == NULL;
    }
};

int main(){
    Queue q  ;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}
