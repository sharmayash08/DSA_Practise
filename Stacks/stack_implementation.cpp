#include<bits/stdc++.h>

using namespace std;

class MyStack{
    int capacity;
    vector<int>v;
    int top;
    
    public:
    MyStack(int cap){
        this->capacity = cap;
        vector<int>v(cap);
        this->top=-1;
    }

    void push(int data){
        if(top == this->capacity - 1){
            cout<<"OverFlow"<<endl;
            return;
        }
        top =  top +1;
        v.push_back(data);
        cout<<"Element Pushed "<<data<<endl;
    }

    int pop(){
        if(top == -1){
            cout<<"UnderFlow" <<endl;
            return -1;
        }
        else{
            
            v.pop_back();
            --top;
        }

    }

    void view(){
        if(isEmpty()){
            cout << "Stack empty" << endl;
        }
        else{
            for(int i = top; i >= 0; i--){
            cout << v[i] << " ";
        }
        }
        
    }

    int size(){
        return top+1;
    }

    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==this->capacity-1;
    }
};


int main(){
    MyStack S(5);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cout<<S.size()<<endl;
    cout<<S.isEmpty()<<endl;
    cout<<S.isFull()<<endl;
    return 0;

}