#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

void kthHelper(Node* root , int k , int currL){
    if(root == NULL){
        return ;
    }

    if(currL == k){
        cout<<root->data<<" ";
    }

    kthHelper(root->left , k , currL+1);
    kthHelper(root->right , k , currL+1);
}

void kthLevel(Node* root , int k){
    kthHelper(root , k , 1);
    cout<<endl;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    kthLevel(root , 2);    

    return 0;
}