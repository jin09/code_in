/*
Print all permutations of a given string

Using Backtracking to find all the permutations of the string
*/
#include<bits/stdc++.h>
using namespace std;

void permute(char* arr, int start, int end){
    if(start == end){
        printf("%s\n",arr);
        return;
    }

    for(int i=start;i<=end;i++){
        swap(arr[start],arr[i]);
        permute(arr,start+1,end);
        swap(arr[start],arr[i]);
    }


}

int main(){

char arr[10];
cout<<"Enter string to find its permutations : ";
cin>>arr;
permute(arr,0,strlen(arr)-1);
return 0;
}
