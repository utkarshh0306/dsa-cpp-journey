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

Node* LCA(Node* root , int n1 , int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = LCA(root->left , n1 , n2);
    Node* rightLCA = LCA(root->right , n1 , n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}

int kthAncestor(Node* root , int node , int k){
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftDist = kthAncestor(root->left , node , k);
    int rightDist = kthAncestor(root->right , node , k);

    if(leftDist==-1 && rightDist==-1){
        return -1;
    }

    int validDist = leftDist == -1 ? rightDist : leftDist;

    if(validDist+1 == k){
        cout<<"ancestor is "<<root->data<<endl;
    }

    return validDist+1;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    kthAncestor(root , 5 , 2);
    return 0;
}