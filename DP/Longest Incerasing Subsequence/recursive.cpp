#include<bits/stdc++.h>
using namespace std;

void LISHelper(int arr[], int n, int i, int current_size, int last_maxx, int &maxx){
    ///this if is placed above because if last element affects current_size then maxx must be updated before exiting function 
    if(current_size > maxx){
        maxx = current_size;
    }
    if(i == n){
        return;
    }
    ///INCLUDING
    if(last_maxx == INT_MIN){
        LISHelper(arr, n, i+1, current_size+1, arr[i], maxx);
    }
    else if(last_maxx != INT_MIN && arr[i] > last_maxx){
        LISHelper(arr, n, i+1, current_size+1, arr[i], maxx);
    }
    ///EXCLUDING
    LISHelper(arr, n, i+1, current_size, last_maxx, maxx);
}

int LongestIncreasingSubsequence(int arr[], int n){
    int maxx = 0;
    LISHelper(arr, n, 0, 0, INT_MIN, maxx);
    return maxx;
}

int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<LongestIncreasingSubsequence(arr, n)<<endl;
    return 0;
}
