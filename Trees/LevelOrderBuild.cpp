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

void levelOrderBuild(Node* &root){
    queue<Node*>q;
    cout << "Enter the root Data : ";
    int rootData;
    cin >> rootData;
    root = new Node(rootData);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the left data of " << temp -> data << " : ";
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cout << "Enter the right data of " << temp -> data << " : ";
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
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
    // 1 2 5 3 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    Node* root = NULL;

    levelOrderBuild(root);

    cout << "Print the Binary Tree" << endl;
    levelOrderTraversal(root);
}