/*
quickSort
*/
#include<bits/stdc++.h>
using namespace std;

int Partition(int* arr, int start, int end){
    int pindex = start;
    int pivot = arr[end];
    for(int i=start;i<end;i++){
        if(arr[i] < pivot){
            swap(arr[i],arr[pindex]);
            pindex++;
        }
    }
    swap(arr[pindex],arr[end]);
    return pindex;
}

void quickSort(int* arr, int start, int end){
    if(start > end){
        return;
    }
    int pindex = Partition(arr,start,end);
    quickSort(arr,start,pindex-1);
    quickSort(arr,pindex+1,end);
}

int main(){
int arr[] = {7,2,1,6,8,5,3,4};
quickSort(arr,0,sizeof arr/sizeof arr[0]);
for(int i=0;i<sizeof arr/sizeof arr[0];i++){
    cout<<arr[i]<<" ";
}
return 0;
}
