//sudoku solver
#include<bits/stdc++.h>
using namespace std;

bool canPlace(int number, int row, int col, int arr[][9]){

    //check the row
    for(int i=0;i<9;i++){
        if(arr[row][i] == number){
            return false;
        }
    }

    //check the col
    for(int i=0;i<9;i++){

        if(arr[i][col]==number){
            return false;
        }
    }

    //check the sub-grid
    int x = (row/3) * 3;
    int y = (col/3) * 3;
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){

            if(arr[i][j] == number){
                return false;
            }
        }
    }
return true;
}

bool solveThisSudoku(int arr[][9], int row, int col, bool marked[][9]){

    if(row==9){
        return true;
    }

    if(col==9){
        return solveThisSudoku(arr,row+1,0,marked);
    }

    if(marked[row][col] == false){
        //try some value
        for(int i=1;i<=9;i++){
            if(canPlace(i,row,col,arr)){
                arr[row][col] = i;

                bool replyFromFuture = solveThisSudoku(arr,row,col+1,marked);
                if(replyFromFuture == true){
                    return true;
                }
                else{
                    arr[row][col] = 0;
                }
            }
        }
        return false;
    }
    else{
        return solveThisSudoku(arr,row,col+1,marked);
    }

}

int main(){

int arr[9][9] = {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

bool marked[9][9] = {0};

for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        if(arr[i][j] != 0){
            marked[i][j] = 1;
        }
    }
}

bool result = solveThisSudoku(arr,0,0,marked);
if(result==false){

    cout<<"No solution exists to the sodoku !"<<endl;
}
else{
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

return 0;
}
