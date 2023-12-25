#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* buildTree(Node* root){
    int data;
    cin >> data;

    root = new Node(data);

    // base case
    if(data == -1){
        return NULL;
    }
    cout << "Enter data for inserting in left of " << data <<endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data <<endl;
    root->right=buildTree(root->right);

    return root;
}

int main(){
    Node* root = NULL;

    root = buildTree(root);
}