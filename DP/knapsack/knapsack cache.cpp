#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int capacity, int n){
    if(n<0){
        return 0;
    }
    if(capacity <= 0){
        return 0;
    }
    if(capacity >= wt[n]){
        return max(knapsack(val, wt, capacity-wt[n], n-1) + val[n], knapsack(val, wt, capacity, n-1));
    }
    else{
        return knapsack(val, wt, capacity, n-1);
    }
}

int knapsackMemo(int val[], int wt[], int capacity, int n, int** cache){

    if(n < 0){
        return 0;
    }
    if(capacity <= 0){
        return 0;
    }
    if(capacity >= wt[n]){
        int including, excluding;
        if(n-1 >= 0){
            if(cache[n-1][capacity-wt[n]] != -1){
                including = cache[n-1][capacity-wt[n]] + val[n];
            }
            else{
                int temp = knapsackMemo(val, wt, capacity-wt[n], n-1, cache);
                cache[n-1][capacity-wt[n]] = temp;
                including = cache[n-1][capacity-wt[n]] + val[n];
            }
            if(cache[n-1][capacity] != -1){
                excluding = cache[n-1][capacity];
            }
            else{
                excluding = knapsackMemo(val, wt, capacity, n-1, cache);
                cache[n-1][capacity] = excluding;
            }
            cache[n][capacity] = max(including, excluding);
            return cache[n][capacity];
        }
        else{
            including = val[n];
            excluding = 0;
            cache[n][capacity] = max(including, excluding);
            return cache[n][capacity];
        }
    }
    else{
        int excluding;
        if(n-1 >= 0){
            if(cache[n-1][capacity] != -1){
                excluding = cache[n-1][capacity];
                return excluding;
            }
            else{
                excluding = knapsackMemo(val, wt, capacity, n-1, cache);
                cache[n-1][capacity] = excluding;
                return excluding;
            }
        }
        else{
            return 0;
        }
    }
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val, wt, W, n-1);
    cout<<endl;

    int** cache = new int*[n+1];
    for(int i=0;i<=n;i++){
        cache[i] = new int[W+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            cache[i][j] = -1;
        }
    }
    cout<<knapsackMemo(val, wt, W, n-1, cache);

    for(int i=0;i<=n;i++){
        delete [] cache[i];
    }
    delete [] cache;
    return 0;
}

