/**  Rod Cutting problem Dynamin programming Solution
*/

#include<bits/stdc++.h>
using namespace std;

int rodCutting(int* prices, int n){
    int dp[n+1][n+1];
    //set first row to 0
    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }
    //set first column to 0
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i){
                dp[i][j] = max(dp[i-1][j], prices[i-1] + dp[i][j-i]);
                //cout<<dp[i][j]<<endl;
            }
            else{
                dp[i][j] = dp[i-1][j];
                //cout<<dp[i][j]<<endl;
            }
        }
    }
    return dp[n][n];
}

int main(){

int prices[] = {2,5,7,8,1};
int n = sizeof prices/sizeof prices[0];
int profit = rodCutting(prices,n);
cout<<"Maximum profit in cutting the rod is : "<<profit;

return 0;
}
