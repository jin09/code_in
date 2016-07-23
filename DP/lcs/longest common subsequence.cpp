/*
Longest Common Subsequence Recursion
*/
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(char* a, char* b, int l1, int l2){
    if(l1<0 || l2<0){
        return 0;
    }

    if(a[l1] == b[l2]){
        return longestCommonSubsequence(a,b,l1-1,l2-1) + 1;
    }

    if(a[l1] != b[l2]){
        return max(longestCommonSubsequence(a,b,l1-1,l2),longestCommonSubsequence(a,b,l1,l2-1));
    }
}

int main(){
char* a = {"abcdgh"};
char* b = {"aedfhr"};

int result = longestCommonSubsequence(a,b,strlen(a)-1,strlen(b)-1);
cout<<"LCS IS : "<<result;
return 0;
}
