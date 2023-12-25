#include<bits/stdc++.h>
using namespace std;

class BTnode{
	public:
	int data;
	BTnode* left;
	BTnode* right;
	
	BTnode(int data)
	{
		this->data =data;
		this->left=NULL;
		this->right=NULL;
	}
};

//not level wise

BTnode* make(){
	int n;
	cin>>n;
	if(n==-1) return NULL;
	BTnode* root = new BTnode(n);
	cout << "Enter data for inserting in left of " << n <<endl;
	root->left=make();
	cout << "Enter data for inserting in right of " << n <<endl;
	root->right=make();
	return root;
}

void print(BTnode* root){
	if(root==NULL) return;
	cout<<root->data<<"-";
	if(root->left) cout<<root->left->data<<",";
	if(root->right) cout<<root->right->data;
    cout << endl;
	print(root->left);
	print(root->right);
	return;
	
}
int main(){
	BTnode*root=make();
	print(root);
}