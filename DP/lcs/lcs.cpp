/*
Longest Common Subsequence DP
*/
#include<bits/stdc++.h>
using namespace std;

int LCS(char* arr,char* brr,int l1, int l2){
    int dp[l1+1][l2+2];
    //set 1st col to 0
    for(int i=0;i<=l1;i++){
        dp[i][0] = 0;
    }
    //set 1st row to 0
    for(int i=0;i<=l2;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(arr[i-1] == brr[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}

int main(){
char* a = {"abcdaf"};
char* b = {"acbcf"};

int result = LCS(a,b,strlen(a),strlen(b));
cout<<"LCS IS : "<<result;
return 0;
}
