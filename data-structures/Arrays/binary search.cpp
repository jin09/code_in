/*
Binary Search
*/
#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int* arr, int startIndex, int endIndex, int key){ 

    if(startIndex > endIndex){

        return false;
    }

    int mid = (startIndex + endIndex)/2;
    if(arr[mid] == key){
        return true;
    }
    if(key < arr[mid]){
        return binarySearch(arr,startIndex,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,endIndex,key);
    }
}

int main(){
int arr[] = {1,2,3,4,5,6,7,8,9};
int key = 7;
if(binarySearch(arr,0,8,key)){
    cout<<"Key is Present !!";
}
else{
    cout<<"Key is absent";
}
return 0;
}
