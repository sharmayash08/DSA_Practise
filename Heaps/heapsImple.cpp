#include <bits/stdc++.h>

using namespace std;

class heap{
    private:
        vector<int>v;
    public:
        
        int size(){
            return v.size();
        }

        bool empty(){
            return v.size() == 0;
        }

        void push(int ele){
            // insert element
            v.push_back(ele);

            int index = v.size() - 1;
           

            while(index > 0)
            {
                int parentIndex = (index - 1) / 2;
                if(v[parentIndex] < v[index])
                {
                    swap(v[parentIndex] , v[index]);
                    index = parentIndex;
                }
                else{
                    return ;
                }
            }
        }

        void pop(){
            if(v.size() == 0) return ;

            // step 1 : copy last element value to root

            int index = v.size() - 1;
            v[0] = v[index];
            v.pop_back();

            // step 2 : check if the root is at its correct pos
            index = 0;
            while(index < v.size())
            {
                int leftIndex = (2 * index) + 1;
                int rightIndex = (2 * index) + 2;

                if(leftIndex < v.size() && v[leftIndex] > v[index]){
                    swap(v[index] , v[leftIndex]);
                    index = leftIndex;
                }
                else if(rightIndex < v.size() && v[rightIndex] > v[index]){
                    swap(v[index] , v[rightIndex]);
                    index = rightIndex;
                }
                else{
                    return ;
                }
            }
        }

        void print(){
            for(auto i : v){
                cout << i << " " ;
            }
            cout << endl;
        }
};


int main(){
    heap h;
    h.push(60);
    h.push(40);
    h.push(30);
    h.push(50);
    h.push(20);

    h.print();
    h.pop();
    h.pop();
    h.pop();
    h.print();

    return 0;
}