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

Node* minValue(Node* root){
    Node* temp = root;

    // for min value
    while(temp -> left != NULL){
        temp = temp -> left;
    }

    return temp;

}

// L N R 
void inOrder(Node* root){
    if(root == NULL) return ;

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}



Node* deleteFromBST(Node* root , int val){
    if(root == NULL) return root;
    
    if(root -> data == val){
        // 0 child
    
        if(root -> right == NULL && root -> left == NULL){
            delete root;
            return NULL;
        }

        // 1 child

        if(root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        if(root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        // 2 child

        if(!root -> left && !root->right){
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root->right , mini);
            return root;
        }
    }
    else if(root -> data > val){
        root -> left = deleteFromBST(root->left , val);
        return root;
    }
    else{
        root -> right = deleteFromBST(root -> right , val);
        return root;
    }
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
    // 50 , 20 , 70 , 10 , 30 , 90 , 110 , -1
    Node* root = NULL;

    cout << "Enter data to create BST"<<endl;
    takeInput(root);

    inOrder(root);

    cout << endl;

    //int val;
    //cout << "Enter the node to be deleted : ";
    //cin >> val;

    root = deleteFromBST(root , 30);

    inOrder(root);

}