/*
Matrix Chain Mul
*/
#include<bits/stdc++.h>
using namespace std;

int matrixChainMul(int* arr, int n){
    int dp[n][n];

    for(int i=0;i<n-1;i++){
        dp[i][i] = 0;
    }

    for(int l=1;l<n-1;l++){

        for(int i=0;i<n-l-1;i++){

            int j = i+l;
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++){

                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
                cout<<dp[i][j]<<endl;
            }
        }
    }
    return dp[0][n-2];
}

int main(){

int arr[] = {2,3,6,4,5};
int result = matrixChainMul(arr,sizeof arr/sizeof arr[0]);
cout<<"Minimum Number of Multiplications are: "<<result;
return 0;
}
