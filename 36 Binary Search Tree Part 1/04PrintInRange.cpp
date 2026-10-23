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

Node* printRange(Node* root , int st , int ed){
    if(root == NULL){
        return NULL;
    }

    if(st <= root->data && root->data <= ed){
        cout<<root->data<<",";
        printRange(root->right , st , ed);
        printRange(root->left , st , ed);
    }
    else if(root->data < st){
        printRange(root->right , st , ed);
    }
    else{
        printRange(root->left , st , ed);
    }
    return root;
}

int main(){
    int arr[6] = {5,1,3,4,2,7};
    int n=6;

    Node* root = buildBST(arr , n);

    printRange(root , 3 , 6);
    cout<<endl;
    

    return 0;
}