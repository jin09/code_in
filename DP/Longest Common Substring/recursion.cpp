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

int main(){
    char X[] = "OldSite:GeeksforGeeks.org";
    char Y[] = "NewSite:GeeksQuiz.com";
    cout<<LongestCommonSubstring(X, Y)<<endl;
    return 0;
}

