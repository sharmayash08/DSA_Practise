#include<bits/stdc++.h>

using namespace std;

class MyStack{
    private:
        vector<int>arr;
    public:

        void push(int ele){
            arr.push_back(ele);
            return;
        }

        int pop(){
            if(arr.size() == 0) return -1;

            int t = arr[arr.size() - 1];
            arr.pop_back();
            return t;
        }

        int size(){
            return arr.size();
        }

        bool empty(){
            return arr.size() == 0;
        }

        int top(){
            return arr[arr.size() - 1];
        }
};


int main(){
    
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "The size of the Stack is : " << s.size() << endl;
    cout << s.empty() << endl;
    while(!s.empty()){
        cout<< "Top element in the Stacks is " <<s.top()<<" ";
        cout<<endl;
        cout << "Popped element from stack is " << s.pop() << "\n";
    }
    cout << s.empty();
    return 0;

}