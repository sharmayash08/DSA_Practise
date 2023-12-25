// power of x^n

#include<bits/stdc++.h>

using namespace std;

int power(int x, int n){
    //base case
    if(n == 0){
        return 1;
    }

    // recursive call
    return x * power(x,n-1);
}

int main(){
    int n; // kitni power nikalni hai
    cin >> n; 

    int x ; // number whose power want to find
    cin >> x;
    cout << power(x,n);
}