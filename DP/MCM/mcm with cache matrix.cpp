#include<bits/stdc++.h>
using namespace std;

int mcm(int arr[], int start, int end, int** brr){
    if(end-start <= 0){
        return 0;
    }
    int mini = INT_MAX;
    for(int k=start;k<end;k++){
        int firstHalf;
        int secondHalf;

        if(brr[start][k] != INT_MAX){
            firstHalf = brr[start][k];
        }
        else{
            firstHalf = mcm(arr, start, k, brr);
            brr[start][k] = firstHalf;
        }
        if(brr[k+1][end] != INT_MAX){
            secondHalf = brr[k+1][end];
        }
        else{
            secondHalf = mcm(arr, k+1, end, brr);
            brr[k+1][end] = secondHalf;
        }
        int resultantmatrix = arr[start]*arr[k+1]*arr[end+1];
        int mul = firstHalf + secondHalf + resultantmatrix;
        if(mul < mini){
            mini = mul;
        }
    }
    return mini;
}

int main(){
int arr[] = {1, 2, 3, 4};
int** brr = new int*[4];
for(int i=0;i<4;i++){
    brr[i] = new int[4];
}
for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
        brr[i][j] = INT_MAX;
    }
}
cout<<mcm(arr, 0, 2, brr);
for(int i=0;i<4;i++){
    delete [] brr[i];
}
delete [] brr;
return 0;
}
