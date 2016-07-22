/*
Given a String print all the subsequences. e.g. for input = abc you need to print “”,
a, b, c, ab, ac, bc, abc

This is also a good approach as the code is short and less arguments

Process:

*recursively reach the last element in the array
*last element will be '\0' so put output[0][0] = '\0' and return 1
*now we have reached 'c' and we know that there are 1 row(s) above it in the output array
*put c and all the rows above it one by one
*return 2*rows as we know that the number of rows have doubled
now we have reached 'b' and we can see that the number of rows above it are 2 
*put 'b' and all the rows above it in the output array
*number of rows have doubled so now return 2*rows which is 4
and so on .....
*/
#include<bits/stdc++.h>
using namespace std;

int findAllSubsequences(char arr[], char output[][10], int start){
    if(arr[start] == '\0'){
        output[0][0] = '\0';
        return 1;
    }

    int rows = findAllSubsequences(arr,output,start+1);

    for(int i=0;i<rows;i++){

        output[rows+i][0] = arr[start];
        int j=0;
        for(j=0;output[i][j]!='\0';j++){
            output[rows+i][j+1] = output[i][j];
        }
        output[rows+i][j+1] = '\0';
    }
    return 2*rows;
}

int main(){

char arr[10];
cout<<"Enter string to find its subsequences : ";
cin>>arr;
char output[50][10];
output[0][0] = '\0';
int subs = findAllSubsequences(arr,output,0);
for(int i=0;i<subs;i++){
    printf("%s\n",output[i]);
}
return 0;
}
