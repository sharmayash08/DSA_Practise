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
void inOrder(Node* root , vector<int>&temp){
    if(root == NULL) return ;

    inOrder(root -> left , temp);
    temp.push_back(root->data);
    inOrder(root -> right , temp);
}



int main(){
    // 10 5 2 -1 -1 20 -1 -1 8 -1 -1
    Node* root = NULL;

    root = buildTree(root);

    vector<int>temp;
    inOrder(root , temp);
    vector<int>temp2 = temp;
    

    sort(temp2.begin() , temp2.end());

    vector<int>ans;
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] != temp2[i]){
            ans.push_back(temp[i]);
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

}