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

// Recursive way
/*bool searchInBST(Node* root , int val){
    // base case
    if(root == NULL) return false;
    if(root -> data == val) return true;

    if(val > root -> data){
        return searchInBST(root -> right , val);
    }
    else{
        return searchInBST(root -> left , val);
    }
}*/

// Iterative way
// Improved Space Complexity
bool searchInBST(Node* root , int val){
    Node* temp = root;

    while(temp != NULL){
        if(temp -> data == val){
            return true;
        }

        if(val > temp -> data){
            temp = temp -> right;
        }
        else{
            temp = temp -> left;
        }
    }
    return false;
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

    int val;
    cout << "Enter the value to be searched : ";
    cin >> val;
    cout<<searchInBST(root, val)<<endl;
}