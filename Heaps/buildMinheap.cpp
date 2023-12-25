// Code to build Min heap using Heapify algorithm
// Can also be written for Max heap by making some changes in if conditions

#include <bits/stdc++.h>

using namespace std;


// heapify algorithm


void buildMinHeap(vector<int>&arr , int n , int i){
    int smallest = i;
    int leftIndex = (2*i) + 1;
    int rightIndex = (2*i) + 2;

    if(leftIndex < n && arr[leftIndex] < arr[smallest]){
        smallest = leftIndex;
    }

    if(rightIndex < n && arr[rightIndex] < arr[smallest]){
        smallest = rightIndex;
    }

    if(smallest != i){
        swap(arr[smallest] , arr[i]);
        buildMinHeap(arr, n , smallest);
    }
}

vector<int> solve(vector<int> &arr)
{
    int n = arr.size();
    for(int i = n/2 - 1 ; i >= 0; i--){
        buildMinHeap(arr , n , i);
    }

    return arr;
}