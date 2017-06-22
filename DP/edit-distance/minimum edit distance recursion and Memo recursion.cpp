#include<bits/stdc++.h>
using namespace std;

int editDistance(char* arr, char* brr){
    if(arr[0] == '\0'){
        return strlen(brr);
    }
    if(brr[0] == '\0'){
        return strlen(arr);
    }
    if(arr[0] == brr[0]){
        return editDistance(arr+1, brr+1);
    }
    int insertion = editDistance(arr+1, brr) + 1;
    int removal = editDistance(arr, brr+1) + 1;
    int modifyBoth = editDistance(arr+1, brr+1) + 1;
    return min(insertion, min(removal, modifyBoth));
}

int editDistanceMemo(char* arr, char* brr, int** cache){
    if(arr[0] == '\0'){
        return strlen(brr);
    }
    if(brr[0] == '\0'){
        return strlen(arr);
    }
    if(cache[strlen(arr)][strlen(brr)] != -1){
        return cache[strlen(arr)][strlen(brr)];
    }
    if(arr[0] == brr[0]){
        return editDistance(arr+1, brr+1);
    }
    int insertion = editDistanceMemo(arr+1, brr, cache) + 1;
    int removal = editDistanceMemo(arr, brr+1, cache) + 1;
    int modifyBoth = editDistanceMemo(arr+1, brr+1, cache) + 1;
    cache[strlen(arr)][strlen(brr)] = min(insertion, min(removal, modifyBoth));
    return cache[strlen(arr)][strlen(brr)];
}

int main(){
    char* arr = {"saturday"};
    char* brr = {"sunday"};
    cout<<editDistance(arr, brr)<<endl;
    int** cache = new int*[strlen(arr)+1];
    for(int i=0;i<=strlen(arr);i++){
        cache[i] = new int[strlen(brr)+1];
    }
    for(int i=0;i<=strlen(arr);i++){
        for(int j=0;j<=strlen(brr);j++){
            cache[i][j] = -1;
        }
    }
    cout<<editDistanceMemo(arr, brr, cache)<<endl;
    for(int i=0;i<=strlen(arr);i++){
        delete [] cache[i];
    }
    delete [] cache;
    return 0;
}
