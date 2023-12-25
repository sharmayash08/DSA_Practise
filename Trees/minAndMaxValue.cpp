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

int MinAndMax(Node* root){

    Node* temp = root;

    // for min value
    /*while(temp -> left != NULL){
        temp = temp -> left;
    }

    return temp -> data;

    temp = root;*/

    // for max value
    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp->data;

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
    // 4 2 7 1 3 -1
    Node* root = NULL;

    cout << "Enter data to create BST"<<endl;
    takeInput(root);

    cout << MinAndMax(root);
    
}