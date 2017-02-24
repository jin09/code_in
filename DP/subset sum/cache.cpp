#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int sum, int n, int** cache){
    if(n<0){
        return false;
    }
    if(sum == 0){
        return true;
    }
    if(sum >= arr[n]){
        int first, second;
        if(n-1 >= 0 && sum-arr[n] >= 0){
            if(cache[n-1][sum-arr[n]] != -1){
                first = cache[n-1][sum-arr[n]];
                cout<<"cache hit!!"<<endl;
            }
            else{
                first = subsetSum(arr, sum-arr[n], n-1, cache);
                cache[n-1][sum-arr[n]] = first;
                cout<<"cache miss!!"<<endl;
            }
        }
        else{
            first = subsetSum(arr, sum-arr[n], n-1, cache);
        }
        if(n-1 >= 0){
            if(cache[n-1][sum] != -1){
                second = cache[n-1][sum];
                cout<<"cache hit!!"<<endl;
            }
            else{
                second = subsetSum(arr, sum, n-1, cache);
                cache[n-1][sum] = second;
                cout<<"cache miss!!"<<endl;
            }
        }
        else{
            second = subsetSum(arr, sum, n-1, cache);
        }
        return first || second;
    }
    else{
        int second;
        if(n-1 >= 0){
            if(cache[n-1][sum] != -1){
                second = cache[n-1][sum];
                cout<<"cache hit!!"<<endl;
            }
            else{
                second = subsetSum(arr, sum, n-1, cache);
                cache[n-1][sum] = second;
                cout<<"cache miss!!"<<endl;
            }
        }
        else{
            second = subsetSum(arr, sum, n-1, cache);
        }
        return second;
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
    cout<<subsetSum(arr, sum, n-1, cache);
    for(int i=0;i<n+1;i++){
        delete[] cache[i];
    }
    delete [] cache;
    return 0;
}
