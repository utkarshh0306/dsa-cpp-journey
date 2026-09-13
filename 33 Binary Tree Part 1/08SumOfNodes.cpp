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

 int nodeSum(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftS = nodeSum(root -> left);
    int rightS = nodeSum(root -> right);

    int totalS = leftS + rightS  + root -> data;

    return totalS;
 }

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    cout<<"Total Sum of nodes in Tree: "<<nodeSum(root)<<endl;
    

    return 0;
}