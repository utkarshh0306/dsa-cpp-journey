#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

// collection of Node
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = NULL;
        tail = NULL;
    }
    //Push Front in LL:-
    void pushFront(int val){
        Node* newNode = new Node(val);//Dynamic

        if(head == NULL){
            head=tail=newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }
    // Push back in LL;
    void pushBack(int val){
        Node* newNode = new Node(val);//Dynamic

        if(head == NULL){
            head=tail=newNode;
        }
        else{
             tail -> next = newNode;
             tail = newNode;
        }
    }

    void printll(){
        Node* temp = head;
        while(temp != NULL){
            cout<< temp -> data << " -> ";
            temp = temp -> next;
        }
        cout<<"NULL"<<endl;
    }

    void insert(int val , int pos){
        Node* newNode = new Node(val);//Dynamic
        Node* temp = head;
        
        for(int i=0 ; i<pos-1 ; i++){
            if(temp == NULL){
                cout<<"INVALID POS"<<endl;
            }
            temp = temp -> next;
        }

        newNode -> next = temp -> next ;
        temp -> next = newNode;

    }

    void popFront(){
        if(head == NULL){
            cout<<"LL is empty"<<endl;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp ;
    }

    void popBack(){
        Node* temp = head;
        while(temp -> next -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    int searchItr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp -> next != NULL){
            if(temp -> data == key){
                return idx;
            }
            temp = temp -> next;
            idx++;
        }
        return -1;
    }

    int helper(Node* temp , int key){
        if(temp == NULL){
            return -1;
        }
        if(temp -> data == key){
            return 0;
        }
        int idx = 1 + helper(temp -> next , key);
        if(idx == -1){
            return -1;
        }
        return idx;
    }
    int searchRec(int key){
        return helper(head , key);
    }

    void reverse(){
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
            Node* next = curr -> next;
            curr -> next = prev;

            // for next iterations
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    int getSize(){
        int sz = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp -> next;
            sz++;
        }
        return sz;
    }
    void removeNth(int n){
        int size = getSize();
        Node* prev = head;
        for(int i=0 ; i<size-n-1 ; i++){
            prev = prev -> next;
        }
        Node* toDel = prev -> next;
        cout<<"going to delete"<< toDel -> data <<endl;
        prev -> next = prev -> next -> next;
    }
};

int main(){
    List ll;
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.pushFront(0);
    ll.printll();
    ll.pushBack(4);
    ll.pushBack(5);
    ll.printll();
    ll.insert(100 , 3);
    ll.printll();
    ll.popFront();
    ll.popBack();
    ll.printll();
    cout<<ll.searchItr(3)<<endl;
    cout<<ll.searchRec(3)<<endl;
    ll.reverse();
    ll.printll();
    ll.removeNth(2);
    ll.printll();

    return 0;
}