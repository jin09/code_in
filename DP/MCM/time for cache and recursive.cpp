#include<bits/stdc++.h>
#include<ctime>
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

int matrixChainMulRecursive(int arr[], int start, int end){

    if(end-start <= 1){
        return 0;
    }

    int minimum = INT_MAX;
    for(int i=start+1;i<end;i++){

        int compute = matrixChainMulRecursive(arr,start,i) + matrixChainMulRecursive(arr,i,end) + arr[start]*arr[i]*arr[end];

        if(compute<minimum){
            minimum = compute;
        }
    }
    return minimum;
}

int main(){
    int arr[] = {2,3,6,4,5,50,35,66,87,123,22,654,55,43,234,543,543,345,432,543};
    int n = sizeof(arr)/sizeof(arr[0]);
    int** brr = new int*[n];
    for(int i=0;i<n;i++){
        brr[i] = new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j] = INT_MAX;
        }
    }
    clock_t b = clock();

    cout<<mcm(arr, 0, n-2, brr);

    b = clock() - b;
    double elapsed_secs = double(b) / CLOCKS_PER_SEC;
    cout<<endl<<"Time taken to calculate with cache is : "<<elapsed_secs<<endl;
    b=clock();
    cout<<matrixChainMulRecursive(arr, 0, n-1)<<endl;
    b = clock() - b;
    elapsed_secs = double(b) / CLOCKS_PER_SEC;
    cout<<"The time taken to execute for recursive is "<<elapsed_secs<<endl;
    for(int i=0;i<n;i++){
        delete [] brr[i];
    }
    delete [] brr;
return 0;
}
