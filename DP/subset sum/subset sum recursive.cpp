#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    if(n<0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    return subsetSum(arr, sum-arr[n], n-1) || subsetSum(arr, sum, n-1);
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subsetSum(arr, sum, n-1);
    return 0;
}
