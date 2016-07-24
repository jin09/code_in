/*
Coin change min coins recursive
Given an infinite supply of coins of different denominations
We are to calculate the minimum number of coins that are needed to get to a sum.
*/
#include<bits/stdc++.h>
using namespace std;


int minCoins = INT_MAX;

void minCoinsRecursive(int* arr, int sum, int n, int numberOfCoins){
    if(sum==0){
        minCoins = min(minCoins,numberOfCoins);
        return;
    }
    if(sum<0){
        return;
    }
    if(n<0){
        return;
    }
    //include the coin
    minCoinsRecursive(arr,sum-arr[n],n,numberOfCoins+1);
    //dont include the coin
    minCoinsRecursive(arr,sum,n-1,numberOfCoins);
}

int main(){

int arr[] = {1,5,6,8};
int sum = 11;
int n = sizeof arr/sizeof arr[0];
minCoinsRecursive(arr,sum,sizeof arr/sizeof arr[0],0);
cout<<"Min number of coins that are needed to get a sum of 11 are : "<< minCoins;
return 0;
}
