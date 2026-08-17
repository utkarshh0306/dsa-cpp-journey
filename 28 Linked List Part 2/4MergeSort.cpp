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

Node* merge(Node* left , Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }
        else{
            ans.push_back(j->data);
                        j = j->next;

        }
    }
    while(i != NULL){
            ans.push_back(i->data);
                        i = i->next;

        }
    while(j != NULL){
            ans.push_back(j->data);
                        j = j->next;

    }
    return ans.head;
}

Node* splitAtMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast -> next != NULL){
        prev = slow;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    if(prev != NULL){
        prev -> next = NULL;
    }
    return slow;
}

Node* mergeSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* rightHead = splitAtMid(head);
    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left , right);
}
int main(){
    List ll;
    ll.pushFront(1);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(4);
    printll(ll.head);
    ll.head = mergeSort(ll.head);
    printll(ll.head);
    return 0;
}