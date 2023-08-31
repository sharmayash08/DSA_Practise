#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* makeLL(){
    int val;
    cin>>val;
    if(val == -1){
        return NULL;
    }
    Node* head = new Node(val);
    Node* temp = head;
    while(1){
        cin >> val;
        if(val == -1) break;
        Node* new_node = new Node(val);
        temp ->next = new_node;
        temp = temp ->next;
    }
    return head;
    
}


Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* temp = head;
    Node* next;

    while(temp){
        next = temp->next;
        temp ->next = prev;

        prev = temp;
        temp =  next;
    }
    head = prev;

}

void display(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = makeLL();
    display(head);
    reverse(head);
    display(head);
    return 0;
}