#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        this->data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root , int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }
    if(root -> data > val){
        root->left = insert(root->left , val);
    }
    else{
        root -> right = insert(root->right , val);
    }

    return root;
}

Node* buildBST(int arr[] , int n){
    Node* root = NULL;

    for(int i=0 ; i<n ; i++){
        root = insert(root , arr[i]);
    }

    return root;
}

bool search(Node* root , int k){
    if(root == NULL){
        return false;
    }

    if(root -> data == k){
        return true;
    }

    if(root->data > k){
        search(root->left , k);
    }else{
        search(root->right , k);
    }
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    int n=6;

    Node* root = buildBST(arr , n);
    int k = 9;
    cout<<search(root , k);

    return 0;
}