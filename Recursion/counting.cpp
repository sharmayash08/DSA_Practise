#include<bits/stdc++.h>

using namespace std;

void printNumbers(int n){
    // base case
    if(n == 0){
        return ;
    }
    cout << n << endl; // tail recursion for n to 1
    // recursive call 
    printNumbers(n-1);
    // cout<<n<<endl; // head recursion for 1 to n
}

int main(){
    int n;
    cin >> n;

    printNumbers(n);
}