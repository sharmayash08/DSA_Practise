#include<bits/stdc++.h>

using namespace std;

void sayDigit(string arr[] , int n){
    // base case
    if(n == 0){
        return;
    }

    int digit = n % 10;
    n /= 10;
    // cout << arr[digit] << " "; 1 3 4 in string
    // recursive call 
    sayDigit(arr, n);
    //cout << arr[digit] << " "; 4 3 1 in string
}


int main(){
    string arr[10] = {
                        "Zero","One" , "Two" , "Three",
                        "Four" , "Five" , "Six",
                        "Seven", "Eight", "Nine"
                    };
    int n;
    cin >> n;

    sayDigit(arr,n);
}