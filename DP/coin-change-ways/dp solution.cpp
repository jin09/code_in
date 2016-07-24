/*
Coin change DP solution
Given an infinite supply of coins of different denominations
We are to calculate the number of ways in which one can form the sum from the given supply of coins
*/
#include<bits/stdc++.h>
using namespace std;


int coinChange(int* arr, int sum, int n){
    int dp[n][sum+1];
    //initialize the first col with 1
    for(int i=0;i<n;i++){
        dp[i][0] = 1;
    }

    //fill the first row
    for(int i=1;i<=sum;i++){
        if(i<arr[0]){
            dp[0][i] = 0;
        }
        else if(i%arr[0] == 0){
            dp[0][i] = 1;
        }
        else{
            dp[0][i] = 0;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j >= arr[i]){
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n-1][sum];
}

int main(){

int arr[] = {1,2,3};
int sum = 5;
int n = sizeof arr/sizeof arr[0];
int result = coinChange(arr,sum,sizeof arr/sizeof arr[0]);
cout<<"Number of ways in which one can form the sum are : "<< result;
return 0;
}
