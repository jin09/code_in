/*
Coin change recursive
Given an infinite supply of coins of different denominations
We are to calculate the number of ways in which one can form the sum from the given supply of coins
*/
#include<bits/stdc++.h>
using namespace std;

int ways = 0;

void coinChangeRecursive(int* arr, int sum, int n){

    if(n<0){
        return;
    }

    if(sum < 0){
        return ;
    }

    if(sum == 0){
        ways++;
        return;
    }
    //you want to include the current value again and again
    coinChangeRecursive(arr,sum-arr[n],n);
    
    //you dont even consider the value of the coin at this pos
    coinChangeRecursive(arr,sum,n-1);
}

int main(){

int arr[] = {2,5,3,6};
int sum = 10;
int n = sizeof arr/sizeof arr[0];
coinChangeRecursive(arr,sum,n-1);
cout<<"Number of ways in which one can form the sum are : "<< ways;
return 0;
}
