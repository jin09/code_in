/*
Given a String print all the subsequences. e.g. for input = abc you need to print “”,
a, b, c, ab, ac, bc, abc 
*/
#include<bits/stdc++.h>
using namespace std;

void concatenate(char output[][10],int rowOfInsertion, int rowToConcatenate, char charToConcatenate){
    if(output[rowToConcatenate][0] == '\0'){
        output[rowOfInsertion][0] = charToConcatenate;
        output[rowOfInsertion][1] = '\0';
        return;
    }

    output[rowOfInsertion][0] = charToConcatenate;
    int i=0;
    while(output[rowToConcatenate][i] != '\0'){
        output[rowOfInsertion][i+1] = output[rowToConcatenate][i];
        i++;
    }
    output[rowOfInsertion][i+1] = '\0';
    return;
}

int getAllSubsequences(char* arr,char output[][10], int lastCharPos, int rowOfOutput){

    if(lastCharPos < 0){
        return rowOfOutput;
    }

    int x = rowOfOutput;
    for(int i=0;i<x;i++){

        concatenate(output,rowOfOutput,i,arr[lastCharPos]);
        rowOfOutput++;
    }

    getAllSubsequences(arr,output,lastCharPos-1,rowOfOutput);

}

int main(){

char arr[10];
cout<<"Enter string to find its subsequences : ";
cin>>arr;
char output[50][10];
output[0][0] = '\0';
int subs = getAllSubsequences(arr,output,strlen(arr)-1,1);
for(int i=0;i<subs;i++){
    printf("%s\n",output[i]);
}
return 0;
}
