#include<bits/stdc++.h>

using namespace std;


char * strtoken(char * arr, char delim){

static int pointer = 0;

if(arr == NULL){

    return NULL;
}
if(pointer>=strlen(arr)){

    return NULL;
}
else{

    int temp = pointer;
    while(arr[pointer]!=delim && arr[pointer]!='\0'){

        pointer++;
    }
    int sizing = pointer - temp;
    char * newarr = new char[sizing];
    for(int i=0;i<sizing;i++){

        newarr[i] = arr[temp];
        temp++;
    }
    newarr[sizing] = '\0';
    pointer++;
    return newarr;
}

}


int main(){

char * arr = new char[100];
cin.getline(arr,100);
char delim;
scanf("%c",&delim);

char *token = strtoken(arr,delim);
cout<<token<<endl;
while(1){

    token = strtoken(arr,delim);
    if(token==NULL){
        break;
    }
    else{
        printf("%s\n",token);
    }
}

return 0;
}
