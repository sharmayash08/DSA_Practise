#include<bits/stdc++.h>

using namespace std;

int climbStairs(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    // recursive call

    return climbStairs(n-1) + climbStairs(n - 2);
}

int main(){
    int n;
    cin >> n;

    cout << "Total Number of ways to climb is " << climbStairs(n);
}