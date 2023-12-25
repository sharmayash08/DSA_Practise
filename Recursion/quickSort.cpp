#include <bits/stdc++.h>

using namespace std;

int partition_arr(vector<int>&arr , int low , int high){
    /*int pivot = arr[low];
    
    int cnt = 0 ;

    for(int i = low + 1; i <= high; i++){
        if(arr[i] < pivot){
            cnt++;
        }
    }

    // pivot ka sahi index nikal lo aur usse uski jagah pahucha do
    int pivotIndex = low + cnt;
    swap(arr[pivotIndex] , arr[low]);

    int i = low;
    int j = high;

    // phir check karo kahi koi element left part mai esa hai jo pivot se bada hai toh usse right mai uske corresponsing se swap kr do 

    while(i < pivotIndex && j > pivotIndex){
        // left mai check kiya sahi elements hai toh annge badh jao
        while(arr[i] < pivot){
            i++;
        }
        // same for the right part agar sahi element hai toh peeche aate jao
        while(arr[j] > pivot){
            j--;
        }

        // phir bhi agar initial condition satisfy ho rhi hai toh swap kar do left part mai aur right part mai jin elements pe ho unhe
        

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
        }
    }

    return pivotIndex;*/

     // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates
    // the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
 
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
 
            // Increment index of smaller element
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>&arr , int low , int high){
    if(low < high){
        int pos = partition_arr(arr , low , high);

        quickSort(arr , low , pos - 1);
        quickSort(arr,pos + 1 ,high );
    }
}

int main(){
    vector<int>arr={3,5,1,8,2,4};
    int low = 0;
    int high = arr.size() - 1;
    quickSort(arr , low , high);

    for(int i = 0 ; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}