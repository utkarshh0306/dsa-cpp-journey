#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

 void topView(Node* root){
    // <Node, Horizontal Distance>
    queue<pair<Node*, int>> q;

    // map<Horizontal Distance, Node Value>
    map<int, int> m;

    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> curr = q.front();
        q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        // Store only the first node at each horizontal distance
        if(m.count(currHD) == 0){
            m[currHD] = currNode->data;
        }

        // Left child
        if(currNode->left != NULL){
            pair<Node*, int> leftC =
                make_pair(currNode->left, currHD - 1);

            q.push(leftC);
        }

        // Right child
        if(currNode->right != NULL){
            pair<Node*, int> rightC =
                make_pair(currNode->right, currHD + 1);

            q.push(rightC);
        }
    }

    for(auto it : m){
        cout << it.second << ",";
    }

    cout << endl;
}
     

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* root = buildTree(nodes);
    topView(root);
     

    return 0;
}