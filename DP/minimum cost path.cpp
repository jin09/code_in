/*
Minimum cost path
*/
#include<bits/stdc++.h>
using namespace std;



int minCostPath(int arr[][3], int rows, int col){

    for(int i=1;i<rows;i++){
        arr[i][0] = arr[i-1][0] + arr[i][0];
    }
    for(int i=1;i<col;i++){
        arr[0][i] = arr[0][i-1] + arr[0][i];
    }
    for(int i=1;i<rows;i++){
        for(int j=1;j<col;j++){
            arr[i][j] = min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1])) + arr[i][j];
        }
    }
    return arr[rows-1][col-1];
}

int main(){
    int R=3,C=3;
int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
int result = minCostPath(cost,R,C);

cout<<"Minimum cost path is : "<< result;
return 0;
}
