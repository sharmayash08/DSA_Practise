#include<bits/stdc++.h>

using namespace std;


int main(){
    stack<int>S;
    S.push(1);
    S.push(2);

    while(!S.empty()){
        cout << S.top() <<" ";
        S.pop();
    }
    return 0;

}