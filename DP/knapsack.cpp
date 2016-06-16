//spoj KNAPSACK

#include <stdio.h>
#include <stdlib.h>


long long int max(long long int a,long long int b){
return a<b?b:a;
}

int knapsack(int s,int n,int w[],int v[]){

int k[n][s+1];
int i,j;
for(i=0;i<n;i++){

    k[i][0]=0;
}
for(j=1;j<=s;j++){

    if(w[0]>j){

        k[0][j]=0;
    }
    else{

        k[0][j]=v[0];
    }
}

for(i=1;i<n;i++){

    for(j=1;j<=s;j++){

        if(w[i]>j){
            k[i][j]=k[i-1][j];
        }
        else if(w[i]<=j){

            k[i][j]=max(v[i]+k[i-1][j-w[i]],k[i-1][j]);
        }
    }
}
return k[n-1][s];
}

int main(){
int t,a,b,i,j,n,s;
scanf("%d %d",&s,&n);
int weight[n+2],value[n+2];
for(i=0;i<n;i++){

    scanf("%d %d",&weight[i],&value[i]);
}
printf("%d",knapsack(s,n,weight,value));
return 0;
}
