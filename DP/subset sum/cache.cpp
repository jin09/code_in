#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n){
    if(n < 0){
        return false;
    }
    if(sum < 0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(arr[n] <= sum){
        bool including = subsetSum(arr, sum-arr[n], n-1);
        bool excluding = subsetSum(arr, sum, n-1);
        return including || excluding;
    }
    else{
        bool excluding = subsetSum(arr, sum, n-1);
        return excluding;
    }
}

bool subsetSumCache(int arr[], int sum, int n, int** cache){
    if(n < 0){
        return false;
    }
    if(sum < 0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(cache[n][sum] != -1){
        return cache[n][sum];
    }
    if(arr[n] <= sum){
        bool including = subsetSumCache(arr, sum-arr[n], n-1, cache);
        bool excluding = subsetSumCache(arr, sum, n-1, cache);
        cache[n][sum] = including || excluding;
        return cache[n][sum];
    }
    else{
        bool excluding = subsetSumCache(arr, sum, n-1, cache);
        cache[n][sum] = excluding;
        return cache[n][sum];
    }
}

int main(){
    int arr[] = {6, 3, 2, 1};
    int sum = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<subsetSum(arr, sum, n-1)<<endl;
    int** cache = new int*[n+1];
    for(int i=0;i<=n;i++){
        cache[i] = new int[sum+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cache[i][j] = -1;
        }
    }
    cout<<subsetSumCache(arr,sum, n-1, cache);
    return 0;
}
