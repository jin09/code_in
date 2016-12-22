#include<iostream>
using namespace std;


void mergeSortHelper(int* arr, int start, int end){
    if(start >= end){
        return;
    }

    int mid = (start + end)/2;

    mergeSortHelper(arr, start, mid);
    mergeSortHelper(arr, mid+1, end);

    int i = start;
    int j = mid + 1;
    int k = 0;
    int output_arr[end-start+1];

    //merge procedure
    while(i<=mid && j <= end){
        if(arr[i] <= arr[j]){
            output_arr[k] = arr[i];
            i++;
            k++;
        }
        else{
            output_arr[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        output_arr[k] = arr[i];
        i++;
        k++;
    }
    while(j<=end){
        output_arr[k] = arr[j];
        j++;
        k++;
    }

    //copy elements back to the orginal array
    int temp_start = start;
    for(i=0;i<end-start+1;i++){
        arr[temp_start] = output_arr[i];
        temp_start++;
    }
}

void mergeSort(int * arr, int n){
    mergeSortHelper(arr, 0, n-1);
}

int main(){

int arr[] = {6,2,6,8,4,1,9};
mergeSort(arr, 7);

for(int i=0;i<7;i++){
    cout<<arr[i]<<" ";
}
return 0;
}
