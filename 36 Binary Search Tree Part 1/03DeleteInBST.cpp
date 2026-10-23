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

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

Node* getIS(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* del(Node* root , int val){
    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = del(root->left , val);
    }
    else if(val > root->data){
        root->right = del(root->right , val);
    }
    else{
        // case 1 : 0 childern
        if(root->left == NULL && root->right == NULL){
            return NULL;
            delete root;
        }
        // case 2 : 1 childern
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left ;
        }

        // case 3 : 2 childern
        Node* IS = getIS(root->right);
        root->data = IS->data ;
        root->right = del(root->right , IS->data);
        return root;
    }
    return root;
}



int main(){
    int arr[6] = {5,1,3,4,2,7};
    int n=6;

    Node* root = buildBST(arr , n);
    inorder(root);
    cout<<endl;

    del(root , 5);
    inorder(root);
    cout<<endl;

    return 0;
}