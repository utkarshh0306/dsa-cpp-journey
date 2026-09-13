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

 int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root -> left);
    int rightHt = height(root -> right);

    int currHt = max(leftHt , rightHt) + 1;

    return currHt;
 }

 int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int currDiam = height(root -> left) + height(root -> right) + 1;

    int leftDiam = diameter(root -> left);
    int rightDiam = diameter(root -> right);

    return max(currDiam , max(leftDiam , rightDiam));
 }

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    cout<<"Diameter of Tree: "<<diameter(root)<<endl;
    

    return 0;
}