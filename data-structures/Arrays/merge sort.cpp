/*
Merge Sort
*/
#include<bits/stdc++.h>
using namespace std;

void mergeSort(int* arr, int start, int end){
    if(start >= end){
        return;
    }
    //divide into 2 halves
    int mid = (start+end)/2;
    int left[100];
    int right[100];
    for(int i=start;i<=mid;i++){
        left[i] = arr[i];
    }
    for(int i=mid+1;i<=end;i++){
        right[i] = arr[i];
    }
    //recursively sort the 2 halves
    mergeSort(left,start,mid);
    mergeSort(right,mid+1,end);
    //merge the 2 sorted arrays
    int i= start;
    int j = mid+1;
    int k = start;

    while(i<=mid && j<=end){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    while(i<=mid){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<=end){
        arr[k] = right[j];
        j++;
        k++;
    }

}

int main(){
int arr[] ={74,32,89,55,21,64};
mergeSort(arr,0,5);
cout<<"Sorted array is : ";
for(int i=0;i<sizeof arr/sizeof arr[0];i++){
    cout<<arr[i]<<" ";
}
return 0;
}
