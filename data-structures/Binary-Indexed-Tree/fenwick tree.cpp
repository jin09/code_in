/*
Binary Indexed Tree

NOTE:

getNextIndex : index += index & (-index);
getParentIndex : index -= index & (-index);

*/
#include<bits/stdc++.h>
using namespace std;

void updateBIT(int* BITarray,int data, int index, int n){
    index++;

    while(index <= n){
        BITarray[index] = BITarray[index] + data;

        //get next index
        index = index + (index & (-index));
    }
}

int* constructBIT(int* arr,int n){
    int* BITarray = new int[n+1];
    //initialize the array to 0
    for(int i=0;i<n+1;i++){
        BITarray[i] = 0;
    }

    for(int i=0;i<n;i++){
        updateBIT(BITarray,arr[i],i,n+1);
    }
    return BITarray;
}

int getSum(int* BITarray,int index){
    index++;
    int sum = 0;

    while(index>0){
        sum = sum + BITarray[index];

        //get parent index
        index -= index & (-index);

    }
    return sum;
}

int main(){

int arr[] = {3,2,-1,6,5,4,-3,3,7,2,3};
int n = sizeof arr/sizeof arr[0];
int* binaryIndexedTree = constructBIT(arr,n);

cout<<"sum of elements from 0 to 4 is "<<getSum(binaryIndexedTree,4)<<endl;

cout<<"sum of elements from 0 to 7 is "<<getSum(binaryIndexedTree,7)<<endl;

cout<<"sum of elements from 0 to 2 is "<<getSum(binaryIndexedTree,2)<<endl;

return 0;
}
