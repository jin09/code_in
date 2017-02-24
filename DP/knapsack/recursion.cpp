#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int capacity, int n){
    if(n<0){
        return 0;
    }
    if(capacity >= wt[n]){
        return max(knapsack(val, wt, capacity-wt[n], n-1)+val[n],knapsack(val, wt, capacity, n-1));
    }
    else{
        return knapsack(val, wt, capacity, n-1);
    }
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val, wt, W, n-1);
    return 0;
}
