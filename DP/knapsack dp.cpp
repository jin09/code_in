/*
Knapsack DP
*/
#include<bits/stdc++.h>
using namespace std;

int knapsack(int* wts,int* values, int capacity, int n){
    int dp[n+1][capacity+1];
    //set first column to 0
    for(int i=0;i<n+1;i++){
        dp[i][0] = 0;
    }
    //set first row as 0
    for(int i=0;i<capacity+1;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<capacity+1;j++){
            if(wts[i-1] <= j){
               // int a,b,c;
                //a=values[i-1];
                //b=dp[i-1][j-wts[i-1]];
                //c=dp[i-1][j];
                dp[i][j] = max(values[i-1] + dp[i-1][j-wts[i-1]],dp[i-1][j]);
                //cout<<dp[i][j]<<endl;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][capacity];
}

int main(){
int val[] = {1,4,5,7};
int wt[] = {1,3,4,5};
int  W = 7;
int n = sizeof val/sizeof val[0];
int result = knapsack(wt,val,W,n);
cout<<"Total value that can be picked is : "<<result;
return 0;
}
