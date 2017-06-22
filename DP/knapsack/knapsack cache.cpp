#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int W, int n){
    if(n < 0){
        return 0;
    }
    if(wt[n] <= W){
        int including = knapsack(val, wt, W-wt[n], n-1) + val[n];
        int excluding = knapsack(val, wt, W, n-1);
        return max(including, excluding);
    }
    else{
        return knapsack(val, wt, W, n-1);
    }
}

int knapsackMemo(int val[], int wt[], int W, int n, int** cache){
    if(n < 0){
        return 0;
    }
    if(cache[n][W] != -1){
        return cache[n][W];
    }
    if(wt[n] <= W){
        int including = knapsackMemo(val, wt, W-wt[n], n-1, cache) + val[n];
        int excluding = knapsackMemo(val, wt, W, n-1, cache);
        cache[n][W] = max(including, excluding);
        return cache[n][W];
    }
    else{
        int excluding = knapsackMemo(val, wt, W, n-1, cache);
        cache[n][W] = excluding;
        return cache[n][W];
    }
}


int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val, wt, W, n-1)<<endl;

    int** cache = new int*[n+1];
    for(int i=0;i<=n;i++){
        cache[i] = new int[W+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cache[i][j] = -1;
        }
    }
    cout<<knapsackMemo(val, wt, W, n-1, cache)<<endl;

    for(int i=0;i<=n;i++){
        delete [] cache[i];
    }
    delete [] cache;
    return 0;
}
