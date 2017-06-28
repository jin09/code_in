/*
Coin change min coins recursive
Given an infinite supply of coins of different denominations
We are to calculate the minimum number of coins that are needed to get to a sum.
*/
#include<bits/stdc++.h>
using namespace std;

int MinCoinChangeHelper(int arr[], int n, int target, int current){
    if(target == 0){
        return current;
    }
    if(target < 0){
        return INT_MAX;
    }
    if(n < 0){
        return INT_MAX;
    }
    
    int including = MinCoinChangeHelper(arr, n, target-arr[n], current+1);
    int excluding = MinCoinChangeHelper(arr, n-1, target, current);

    return min(including, excluding);
}

int MinCoinChange(int arr[], int n, int target){
    return MinCoinChangeHelper(arr, n-1, target, 0);
}

int main(){
    int arr[] = {1, 5, 10, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 32;
    cout<<MinCoinChange(arr, n, target);
    return 0;
}
