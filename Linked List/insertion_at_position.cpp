#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int data){
            val = data;
            next = NULL;
        }
};

void insertAtStart(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}

void insertAtLast(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    // temp has reached last node next which will now point to new node  
    temp->next = new_node; 
    
    // by default new node's next is pointing to null 
}

void insertAtPosition(Node* &head, int val, int pos){
    if(pos == 1){
        insertAtStart(head, val);
        return;
    }

    Node* new_node = new Node(val);
    Node* temp = head;
    int curr_pos = 1;
    while(curr_pos!=pos-1){
        temp = temp->next;
        curr_pos++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void display( Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = NULL;
    insertAtStart(head, 2);
    display(head);
    insertAtStart(head,1);
    display(head);
    insertAtLast(head, 3);
    display(head);

    insertAtPosition(head, 10, 1);
    display(head);
}