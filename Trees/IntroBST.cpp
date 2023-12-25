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

Node* insertIntoBST(Node* root , int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        // right mai insert krna hai 
        root->right = insertIntoBST(root->right , d); // recursive call
    }
    else{
        // left mai insert krna hai
        root->left = insertIntoBST(root->left , d);
    }
    return root;
}

void takeInput(Node* &root){
    int d;
    cin >> d;

    while(d != -1){
        root = insertIntoBST(root , d);
        cin >> d;
    }
}

int main(){
    Node* root = NULL;

    cout << "Enter data to create BST"<<endl;
    takeInput(root);
}