#include<bits/stdc++.h>

using namespace std;

long long int Minimum(long long int a,long long int b)
{
    return a<b?a:b;
}

long long int knapsack(int s,int n,int w[],int v[]){

long long int k[s+1];
int i,j,q;
    k[0]=0;

for(j=1;j<=s;j++){

    if(j%w[0]==0){
        q=j/w[0];
        k[j]=v[0]*q;
    }
    else{

        k[j]=INT_MAX;
    }
}

for(i=1;i<n;i++){

    for(j=1;j<=s;j++){

        if(w[i]<=j){

                if(v[i]+k[j-w[i]]>=INT_MAX){
                    k[j]=Minimum(INT_MAX,k[j]);
                }
                else{
            k[j]=Minimum(v[i]+k[j-w[i]],k[j]);
                }
        }
    }
}
return k[s];
}
