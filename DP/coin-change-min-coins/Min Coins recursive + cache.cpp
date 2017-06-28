#include<bits/stdc++.h>
using namespace std;

int MinCoinChangeHelper(int arr[], int n, int target, int current){
    if(target == 0){
        return current;
    }
    if(target < 0){
        return INT_MAX;
    }
    if(n < 0){
        return INT_MAX;
    }

    int including = MinCoinChangeHelper(arr, n, target-arr[n], current+1);
    int excluding = MinCoinChangeHelper(arr, n-1, target, current);

    return min(including, excluding);
}

int MinCoinChange(int arr[], int n, int target){
    return MinCoinChangeHelper(arr, n-1, target, 0);
}

int MinCoinsCacheHelper(int arr[], int n, int target, int current, int** cache){
    if(target == 0){
        return current;
    }
    if(target < 0){
        return INT_MAX;
    }
    if(n < 0){
        return INT_MAX;
    }
    if(cache[n][target] != -1){
        return cache[n][target];
    }

    int including = MinCoinsCacheHelper(arr, n, target-arr[n], current+1, cache);
    int excluding = MinCoinsCacheHelper(arr, n-1, target, current, cache);

    cache[n][target] = min(including, excluding);
    return cache[n][target];

}

int MinCoinsCache(int arr[], int n, int target){

    ///make cache 2d array to cache overlapping calls
    int** cache = new int*[n+1];
    for(int i=0;i<=n;i++){
        cache[i] = new int[target+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            cache[i][j] = -1;
        }
    }
    int min_coins = MinCoinsCacheHelper(arr, n-1, target, 0, cache);

    ///delete cache array
    for(int i=0;i<=n;i++){
        delete [] cache[i];
    }
    delete [] cache;

    return min_coins;
}

int main(){
    int arr[] = {1, 5, 10, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 32;
    cout<<MinCoinChange(arr, n, target)<<endl;
    cout<<MinCoinsCache(arr, n, target)<<endl;
    return 0;
}
