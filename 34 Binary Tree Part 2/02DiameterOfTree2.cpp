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

pair<int,int> diam(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftInfo = diam(root->left);
    pair<int,int> rightInfo = diam(root->right);

    int currDiam = leftInfo.second + rightInfo.second + 1;

    int finalDiam = max(currDiam , max(leftInfo.first , rightInfo.first));
    int finalHt = max(leftInfo.second , rightInfo.second) +1;

    return make_pair(finalDiam , finalHt);
} 

 

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    cout<<"Diameter of Tree: "<<diam(root).first<<endl;
    

    return 0;
}