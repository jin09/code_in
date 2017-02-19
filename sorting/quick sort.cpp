#include<bits/stdc++.h>
using namespace std;

void printarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void quicksortHelper(int arr[], int start, int last){
    if(start >= last){
        return;
    }
    int pivot = last;
    int first = start;
    int second = last-1;
    while(first < second){
        if(arr[first] > arr[pivot]){
            swap(arr[first], arr[second]);
            second--;
        }
        else{
            first++;
        }
    }
    if(arr[first] >= arr[pivot]){
        swap(arr[first], arr[pivot]);
        quicksortHelper(arr, start, first-1);
        quicksortHelper(arr, first+1, last);
    }
    else{
        swap(arr[first+1], arr[pivot]);
        quicksortHelper(arr, start, first);
        quicksortHelper(arr, first+2, last);
    }
}

void quicksort(int arr[], int size){
    quicksortHelper(arr, 0, size-1);
}

int main(){
int arr[] = {9,6,5,0,8,2,4,7};
cout<<"Unsorted array is : ";
printarr(arr, sizeof arr/ sizeof arr[0]);
quicksort(arr, sizeof arr/ sizeof arr[0]);
cout<<"Sorted array  is : ";
printarr(arr, sizeof arr/ sizeof arr[0]);
return 0;
}
