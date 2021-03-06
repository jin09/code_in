#include<bits/stdc++.h>
using namespace std;

int lcs(char* arr, char* brr, int first, int second, int** cache){
    if(arr[first] == '\0' || brr[second] == '\0'){
        return 0;
    }
    if(cache[first][second] != -1){
        return cache[first][second];
    }
    if(arr[first] == brr[second]){
        cache[first][second] = 1 + lcs(arr, brr, first+1, second+1, cache);
        return cache[first][second];
    }
    int one,two;
    if(cache[first][second+1] != -1){
        //cout<<"cached"<<endl;
        one = cache[first][second+1];
    }
    else{
        //cout<<"no cached"<<endl;
        one = lcs(arr, brr, first, second+1, cache);
        cache[first][second+1] = one;
    }
    if(cache[first+1][second] != -1){
        //cout<<"cached"<<endl;
        two = cache[first+1][second];
    }
    else{
        //cout<<"no cached"<<endl;
        two = lcs(arr, brr, first+1, second, cache);
        cache[first+1][second] = two;
    }
    return max(one, two);
}


int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int l1 = strlen(X);
    int l2 = strlen(Y);

    //allocate cache 2d array
    int ** arr = new int*[l1+1];
    for(int i=0;i<l1+1;i++){
        arr[i] = new int[l2+1];
    }

    //set 2d array to -1
    for(int i=0;i<l1+1;i++){
        for(int j=0;j<l2+1;j++){
            arr[i][j] = -1;
        }
    }

    cout<<"length of LCS is : "<<lcs(X, Y, 0, 0, arr)<<endl;

    //free the allocated space
    for(int i=0;i<l1+1;i++){
        delete[] arr[i];
    }
    delete [] arr;
    return 0;
}
