/*
Matrix Chain Multiplication Recursion
*/
#include<bits/stdc++.h>
using namespace std;

int matrixChainMulRecursive(int arr[], int start, int end){

    if(end-start <= 1){
        return 0;
    }

    int minimum = INT_MAX;
    for(int i=start+1;i<end;i++){

        int compute = matrixChainMulRecursive(arr,start,i) + matrixChainMulRecursive(arr,i,end) + arr[start]*arr[i]*arr[end];

        if(compute<minimum){
            minimum = compute;
        }
    }
    return minimum;
}

int main(){

int arr[] = {2,3,6,4,5};
int result = matrixChainMulRecursive(arr,0,4);
cout<<"Minimum Number of Multiplications are: "<<result;
return 0;
}
