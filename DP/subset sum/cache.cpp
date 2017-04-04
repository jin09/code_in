#include<bits/stdc++.h>
using namespace std;

bool subsetSumCache(int arr[], int sum, int n, int** cache){
    if(n < 0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(sum < 0){
        return false;
    }
    int including, excluding;
    if(n-1 >= 0){
        if(cache[n-1][sum-arr[n]] != -1){
            including = cache[n-1][sum-arr[n]];
        }
        else{
            including = subsetSumCache(arr, sum-arr[n], n-1, cache);
            cache[n-1][sum-arr[n]] = including;
        }
        if(cache[n-1][sum] != -1){
            excluding = cache[n-1][sum];
        }
        else{
            excluding = subsetSumCache(arr, sum, n-1, cache);
            cache[n-1][sum] = excluding;
        }
        cache[n][sum] = including || excluding;
        return cache[n][sum];
    }
    else{
        if(sum-arr[n] == 0){
            cache[n][sum] = 1;
            return cache[n][sum];
        }
        else{
            cache[n][sum] = 0;
            return cache[n][sum];
        }
    }
}

int main(){
    int arr[] = {6, 3, 2, 1};
    int sum = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    int** cache = new int*[n+1];
    for(int i=0;i<n+1;i++){
        cache[i] = new int[sum+1];
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            cache[i][j] = -1;
        }
    }
    cout<<subsetSumCache(arr, sum, n-1, cache);
    for(int i=0;i<n+1;i++){
        delete[] cache[i];
    }
    delete [] cache;
    return 0;
}
