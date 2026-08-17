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

class  List{
    public:
        Node* head;
        Node* tail;

        List(){
            head = NULL;
            tail = NULL;
        }

        void pushFront(int val){
            Node* newNode = new Node(val);

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                newNode -> next = head;
                head = newNode;
            }

        }
};

void printll(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

bool isCycle(Node* head){
    Node* slow = head ;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            cout<<"Cycle exist"<<endl;
            return true;
        }
    }
    cout<<"Cycle does not exist"<<endl;
    return false;
}

void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            cout<<"Cycle exist"<<endl;
            isCycle = true;
            break ;
        }
    }
    if(!isCycle){
        cout<<"not exits"<<endl;
        return ;
    }

    slow = head;
    if(slow == fast){
        while(fast -> next != slow){// special case which is last node connect to first
            fast = fast -> next;
        }
        fast -> next = NULL;
    }else{
        Node* prev = fast;
        while(fast != slow){
            slow = slow -> next;
            prev = fast;
            fast = fast -> next ;
        }
        prev -> next = NULL; //here remove cycle
    }
}
int main(){
    List ll;
    ll.pushFront(4);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    ll.tail -> next = ll.head;
    removeCycle(ll.head);
    printll(ll.head);
    return 0;
}