#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

class MyStack{
    private:
        Node* head;
    public:

        MyStack(){
            this -> head = NULL;
        }


        bool empty(){
            return head == NULL;
        }

        int size(){
            int size = 0;
            Node* temp = head;
            while(temp){
                size++;
                temp = temp -> next;
            }
            return size;
        }

        void push(int ele){
            Node* newNode = new Node(ele);
            newNode -> next = head;
            head = newNode;
            return;
        }

        int pop(){
            if(head == NULL) return -1;
            Node* temp = head;
            head = head -> next;
            return temp -> val;
            delete temp;
        }

        int top(){
            if(head == NULL) return -1;
            return head -> val;
        }
};


int main(){
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << s.size() << endl;
    return 0;

}