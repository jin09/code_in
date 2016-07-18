/*
KMP String matching
text = n chars
pattern = m chars
Time: O(n+m)
Extra space : O(m)  {to compute prefix array}
*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void prefix(char* pattern,int* prefixArray,int n){
    prefixArray[0] = 0;
    int i = 1;
    int j = 0;

    while(i<n){
        //case 1
        if(j == 0 && pattern[i] != pattern[j]){
            prefixArray[i] = prefixArray[j];
            i++;
        }
        //case 2
        else if(pattern[i] == pattern[j]){
            prefixArray[i] = j + 1;
            i++;
            j++;
        }
        //case 3 : tricky case
        else if(j != 0 && pattern[j] != pattern[i]){
            j = prefixArray[j-1];
        }
    }
    return ;
}
/*
We can have cases here as well
if pattern and text match
    case 1: pattern index is the last so return true
    case 2: pattern index is not last so increment j and i
if pattern and text dont match
    case 1 : j==0 so i++
    case 2 : j = prefix[j-1]
*/
bool KMPSearch(char* text,char* pattern,int* prefixArray,int patternLength, int textLength){
    int i = 0; //pointer for text
    int j = 0; //pointer for pattern
    while(i<textLength){
        if(text[i] == pattern[j]){
            if(j == patternLength-1){
                return true;
            }
            else{
                i++;
                j++;
            }
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j = prefixArray[j-1];
            }
        }
    }
    return false;
}

int main(){
char text[] ={"abxabcabcaby"};
char pattern[] = {"abcaby"};
int patternLength = strlen(pattern);
int* prefixArray = new int[patternLength];
prefix(pattern,prefixArray,patternLength);
int textLength = strlen(text);
if(KMPSearch(text,pattern,prefixArray,patternLength,textLength)){
    cout<<"Pattern exists in the array !! ";
}
else{
    cout<<"Pattern does not exists in the array !";
}
return 0;
}
