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
        void push_back(int val){
        Node* newNode = new Node(val);//Dynamic

        if(head == NULL){
            head=tail=newNode;
        }
        else{
             tail -> next = newNode;
             tail = newNode;
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

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node* reverse(Node* rightHead){
    Node* curr = rightHead;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next; 
    }
    rightHead = prev;
    return rightHead;
}

Node* zigZag(Node* head){
    Node* rightHead = splitAtMid(head);
    Node* rightRevHead = reverse(rightHead);
    
    // alternate merging
    Node* left = head;
    Node* right = rightRevHead;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node* nextleft = left -> next;
        Node* nextright = right -> next;

        left -> next = right;
        right -> next = nextleft;
        tail = right;

        left = nextleft;
        right = nextright;
    }
    if(right != NULL){
        tail -> next = right;
    }
    return head;
}
int  main(){
    List ll;
    ll.pushFront(5);
    ll.pushFront(4);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    printll(ll.head);
    zigZag(ll.head);
    printll(ll.head);

    return 0;


}