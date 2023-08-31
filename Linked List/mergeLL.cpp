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

Node* mergeLL(Node*h1, Node*h2){
    if(!h1 && !h2 ){
        return (h1 == NULL ? h2 : h1);
    }
    Node*fh = new Node(-1);
    Node*temp = fh;
    Node*t1 = h1;
    Node*t2 = h2;

    while(t1&&t2){
        if(t1->data <= t2->data){
            temp ->next = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    if(t1 || t2){
        temp->next = (t1 == NULL ? t2 : t1);
    }

    return temp->next;
}

void display(Node* &head1){
    Node* temp = head1;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head1 = makeLL();
    Node* head2 = makeLL();
    display(head1);
    display(head2);
    mergeLL(head1,head2);
    return 0;
}