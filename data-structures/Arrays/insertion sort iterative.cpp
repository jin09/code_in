/*
Insertion Sort Iteration
*/
#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i=1;i<n;i++){
        int j = i;
        while(j>0){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
            }
            else{
                break;
            }
        }
    }
    return;
}

int main(){
int arr[] ={74,32,89,55,21,64};
insertionSort(arr,sizeof arr/sizeof arr[0]);
cout<<"Sorted array is : ";
for(int i=0;i<sizeof arr/sizeof arr[0];i++){
    cout<<arr[i]<<" ";
}
return 0;
}
