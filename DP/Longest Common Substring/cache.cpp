#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubstring(char* s1, char* s2){
    if(strlen(s1) == 0 || strlen(s2) == 0){
        return 0;
    }
    if(s1[0] == s2[0]){
        int include_current = LongestCommonSubstring(s1+1, s2+1) + 1;
        int exclude_current = LongestCommonSubstring(s1+1, s2+1);
        return max(include_current, exclude_current);
    }
    else{
        return LongestCommonSubstring(s1+1, s2+1);
    }
}

int LongestCommonSubstringCacheHelper(char* s1, char* s2, int** cache){
    if(s1[0] == '\0' || s2[0] == '\0'){
        return 0;
    }
    if(cache[strlen(s1)][strlen(s2)] != -1){
        return cache[strlen(s1)][strlen(s2)];
    }
    if(s1[0] == s2[0]){
        int include_current = LongestCommonSubstring(s1+1, s2+1) + 1;
        int exclude_current = LongestCommonSubstring(s1+1, s2+1);
        cache[strlen(s1)][strlen(s2)] = max(include_current, exclude_current);
        return cache[strlen(s1)][strlen(s2)];
    }
    else{
        cache[strlen(s1)][strlen(s2)] = LongestCommonSubstring(s1+1, s2+1);
        return cache[strlen(s1)][strlen(s2)];
    }
}

int LongestCommonSubstringCache(char* s1, char* s2){
    int** cache = new int*[strlen(s1)+1];
    for(int i=0;i<=strlen(s1);i++){
        cache[i] = new int[strlen(s2)+1];
    }
    for(int i=0;i<=strlen(s1);i++){
        for(int j=0;j<=strlen(s2);j++){
            cache[i][j] = -1;
        }
    }

    int answer = LongestCommonSubstringCacheHelper(s1, s2, cache);

    for(int i=0;i<=strlen(s1);i++){
        delete [] cache[i];
    }
    delete [] cache;
    return answer;
}

int main(){
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
    cout<<LongestCommonSubstring(X, Y)<<endl;
    cout<<LongestCommonSubstringCache(X, Y)<<endl;
    return 0;
}
