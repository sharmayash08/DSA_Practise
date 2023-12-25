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

// L N R 
void inOrder(Node* root){
    if(root == NULL) return ;

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

// N L R

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// L R N

void postOrder(Node* root){
    if(root == NULL) return ;

    postOrder(root->left);
    postOrder(root->right);
    cout << root -> data << " ";
}

void levelOrderTraversal(Node* root){
    int level = 0;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp->left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

int main(){
    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    cout << "Printing the Level Order Traversal " << endl;
    levelOrderTraversal(root);
    cout << endl;

    cout << "Printing the InOrder Traversal " << endl;
    inOrder(root);
    cout << endl;

    cout << "Printing the PreOrder Traversal " << endl;
    preOrder(root);
    cout << endl;
    
    cout << "Printing the PreOrder Traversal " << endl;
    postOrder(root);
}