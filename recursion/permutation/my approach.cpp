/*
Print all permutations of a given string

my style of getting all permutations
*/
#include<bits/stdc++.h>
using namespace std;

void printAllPermutations(char* arr,char* output,int start, int end, bool* visited){

    if(start > end){
        printf("%s\n",output);
        return;
    }

    for(int i=0;i<=end;i++){
        if(visited[i] == false){
            output[start] = arr[i];
            visited[i] = true;
            printAllPermutations(arr,output,start+1,end,visited);
            visited[i] = false;
        }
    }
}

int main(){

char arr[10];
cout<<"Enter string to find its permutations : ";
cin>>arr;
bool* visited = new bool[strlen(arr)];
memset(visited,0,sizeof visited);
char output[strlen(arr)];
printAllPermutations(arr,output,0,strlen(arr)-1,visited);
return 0;
}
