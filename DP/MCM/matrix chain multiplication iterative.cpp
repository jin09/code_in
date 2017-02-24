#include<bits/stdc++.h>
#include<ctime>
using namespace std;

int MatrixChainOrder(int p[], int n){
    int arr[n-1][n-1];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            arr[i][j] = INT_MAX;
        }
    }
    for(int i=0;i<n-1;i++){
        arr[i][i] = 0;
    }
    for(int iterations=0;iterations<n-2;iterations++){
        for(int i=0;i<n-2-iterations;i++){
            int j = i+1+iterations;
            int mul = INT_MAX;
            for(int k=i;k<j;k++){
                int temp = arr[i][k] + arr[k+1][j] + p[i]*p[j+1]*p[k+1];
                if(temp < mul){
                    mul = temp;
                }
            }
            arr[i][j] = mul;
        }
    }
    return arr[0][n-2];
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t b;
    b=clock();
    cout<<MatrixChainOrder(arr, n)<<endl;
    b = clock() - b;
    double elapsed_secs = double(b) / CLOCKS_PER_SEC;
    cout<<"The time taken to execute for iterative solution is "<<elapsed_secs<<endl;

return 0;
}

