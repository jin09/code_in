/*
Minimum Edit Distance DP
*/
#include<bits/stdc++.h>
using namespace std;

int minimumEditDistanceDP(char* arr, char* brr, int m, int n){
    int dp[m+1][n+1];
    //set first col to 0,1,2,3,.......
    for(int i=0;i<=m;i++){
        dp[i][0] = i;
    }
    //set first row to 0,1,2,3,.......
    for(int i=0;i<=n;i++){
        dp[0][i] = i;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(arr[i-1] == brr[j-1]){
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
            else{
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
            }
        }
    }

    return dp[m][n];
}

int main(){
char* arr = {"intention"};
char* brr = {"execution"};

int result = minimumEditDistanceDP(arr,brr,strlen(arr),strlen(brr));
cout<<"Minimum edit distance is : "<<result;
return 0;
}
