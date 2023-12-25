#include <bits/stdc++.h>

using namespace std;

int partition_arr(vector<char>&arr , int low , int high){
    char pivot = arr[low];
    int cnt = 0;

    for(int i = low + 1; i <= high ; i++){
        if(arr[i] > pivot){
            cnt++;
        }
    }
    int pivotIndex = low + cnt;
    swap(arr[pivotIndex] , arr[low]);

    int i = low;
    int j = high;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] > pivot){
            i++;
        }
        while(arr[j] < pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(vector<char>&arr , int low , int high){
    if(low < high){
        int pos = partition_arr(arr , low , high);

        quickSort(arr , low , pos - 1);
        quickSort(arr,pos + 1 ,high );
    }
}

int main(){
    vector<char>arr={'q' , 'w' , 'e' , 'r' , 't'};
    int low = 0;
    int high = arr.size() - 1;
    quickSort(arr , low , high);

    for(int i = 0 ; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}