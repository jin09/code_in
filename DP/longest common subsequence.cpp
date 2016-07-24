/*
Longest Increasing subsequence
*/
#include<bits/stdc++.h>
using namespace std;



int LongestIncreasingSubsequence(int* arr, int n){
    int dp[n];
    dp[0] = 1;
    int i = 1;
    for(int i=1;i<n;i++){
        int maxsofar = 1;
        for(int j=i-1;j>=0;j--){
            if(arr[i] > arr[j]){
                maxsofar = max(maxsofar,dp[j]+1);
            }
        }
        dp[i] = maxsofar;
    }
    //find minimum in the array
    int findMax = dp[0];
    for(int i=1;i<n;i++){
        if(dp[i]>findMax){
            findMax = dp[i];
        }
    }
    return findMax;
}

int main(){
int arr[] = {2,5,1,8,3};
int result = LongestIncreasingSubsequence(arr,sizeof arr/ sizeof arr[0]);

cout<<"Longest Increasing Subsequence is : "<< result;
return 0;
}
