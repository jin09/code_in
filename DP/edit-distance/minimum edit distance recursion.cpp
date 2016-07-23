/*
Minimum Edit Distance RecurSion
*/
#include<bits/stdc++.h>
using namespace std;

int minimumEditDistance(char* arr, char* brr, int m, int n){
    if(m<0){
        return n+1;
    }
    if(n<0){
        return m+1;
    }

    if(arr[m] == brr[n]){
        return minimumEditDistance(arr,brr,m-1,n-1);
    }

    else{
        int insertion = minimumEditDistance(arr,brr,m,n-1) + 1;
        int deletion = minimumEditDistance(arr,brr,m-1,n) + 1;
        int replacing = minimumEditDistance(arr,brr,m-1,n-1) + 1;

        return min(insertion,min(deletion,replacing));
    }
}

int main(){
char* arr = {"saturday"};
char* brr = {"sunday"};

int result = minimumEditDistance(arr,brr,strlen(arr)-1,strlen(brr)-1);
cout<<"Minimum edit distance is : "<<result;
return 0;
}
