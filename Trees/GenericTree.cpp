#include<bits/stdc++.h>

using namespace std;

class GTNode{
    public:
        int data;
        vector<GTNode*>child;

        GTNode(int data){
            this->data = data;
        }
};

GTNode make(){
    int data;
    cin >> data;
    

    if(data == -1){
        return NULL;
    }
    GTNode* root = new GTNode(data);
    int n;
    cin >> n;

    for(int i = 0; i < n ; i++){
        root->child.push_back(make());
    }

    return root;
    
}

int main(){
    GTNode* root = make();
    return 0;
}