/*
Knapsack problem Recursion
*/
#include<bits/stdc++.h>
using namespace std;

int knapsackRecursive(int* wts,int* values,int capacity, int n ){
    if(n<0){
        return 0;
    }

    if(wts[n]>capacity){
        return knapsackRecursive(wts,values,capacity,n-1);
    }

    int includingCurrentItem = knapsackRecursive(wts,values,capacity-wts[n],n-1) + values[n];
    int excludingCurrentItem = knapsackRecursive(wts,values,capacity,n-1);

    return max(includingCurrentItem,excludingCurrentItem);
}

int main(){
int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int  W = 50;
int n = sizeof val/sizeof val[0];
int result = knapsackRecursive(wt,val,W,n-1);
cout<<"Total value that can be picked is : "<<result;
return 0;
}
