#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[], int wt[], int capacity, int n, int** cache){
    if(n<0){
        return 0;
    }
    if(capacity >= wt[n]){
        int first,second;
        int a = capacity-wt[n];
        if(n-1 >= 0){
            if(cache[n-1][a] != -1){
                first = cache[n-1][a];
            }
            else{
                first = knapsack(val, wt, capacity-wt[n], n-1, cache);
                cache[n-1][a] = first;
                //cout<<n-1<<" "<<a<<endl;
            }
        }
        else{
            first = knapsack(val, wt, capacity-wt[n], n-1, cache);
        }
        if(n-1 >= 0){
            if(cache[n-1][capacity] != -1){
                second = cache[n-1][capacity];
            }
            else{
                second = knapsack(val, wt, capacity, n-1, cache);
                cache[n-1][capacity] = second;
                //cout<<n-1<<" "<<capacity<<endl;
            }
        }
        else{
            second = knapsack(val, wt, capacity, n-1, cache);
        }
        return max(first+val[n],second);
    }
    else{
        int temp;
        if(n-1 >= 0){
            if(cache[n-1][capacity] != -1){
                temp = cache[n-1][capacity];
            }
            else{
                temp = knapsack(val, wt, capacity, n-1, cache);
                cache[n-1][capacity] = temp;
                //cout<<n-1<<" "<<capacity<<endl;
            }
        }
        else{
            temp = knapsack(val, wt, capacity, n-1, cache);
        }
        return temp;
    }
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    int** cache = new int*[n+1];
    for(int i=0;i<n+1;i++){
        cache[i] = new int[W+1];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cache[i][j] = -1;
        }
    }
    cout<<"Maximum value we can get from bag can be: "<<knapsack(val, wt, W, n-1, cache)<<endl;
    /*
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<cache[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    for(int i=0;i<n+1;i++){
        delete[] cache[i];
    }
    delete[] cache;
    return 0;
}
