/*
Coin change DP
Given an infinite supply of coins of different denominations
We are to calculate the minimum number of coins that will be needed to reach a particular sum
*/
#include<bits/stdc++.h>
using namespace std;


int minCoins(int* arr, int sum, int n){
    int dp[n][sum+1];
    //initialize first col to 0
    for(int i=0;i<n;i++){
        dp[i][0] = 0;
    }
    //fill the first row
    for(int i=1;i<=sum;i++){
        if(i<arr[0]){
            dp[0][i] = 0;
            //cout<<dp[0][i]<<endl;
        }
        else{
            if(i%arr[0] == 0){
                dp[0][i] = i/arr[0];
                //cout<<dp[0][i]<<endl;
            }
            else{
                dp[0][i] = 0;
                //cout<<dp[0][i]<<endl;
            }
        }
    }
    //fill the rest of the matrix
    for(int i=1;i<n;i++){
        for(int j=1;j<=sum;j++){
            if(j>=arr[i]){
                dp[i][j] = min(dp[i-1][j],dp[i][j-arr[i]]+1);
                //cout<<dp[i][j]<<endl;
            }
            else{
                dp[i][j] = dp[i-1][j];
                //cout<<dp[i][j]<<endl;
            }
        }
    }
    return dp[n-1][sum];
}

int main(){

int arr[] = {1,5,6,8};
int sum = 11;
int n = sizeof arr/sizeof arr[0];
int result = minCoins(arr,sum,sizeof arr/sizeof arr[0]);
cout<<"Min number of coins that are needed to get a sum of 11 are : "<< result;
return 0;
}
