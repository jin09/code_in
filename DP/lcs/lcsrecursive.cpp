#include<bits/stdc++.h>
using namespace std;

int lcs(char* arr, char* brr){
    if(*arr == '\0' || *brr == '\0'){
        return 0;
    }
    if(*arr == *brr){
        return 1 + lcs(arr+1, brr+1);
    }
    else{
        return max(lcs(arr+1, brr), lcs(arr, brr+1));
    }
}


int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    cout<<"length of LCS is : "<<lcs(X,Y);
    return 0;
}
