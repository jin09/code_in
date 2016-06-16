#include <bits/stdc++.h>
#define max 20
using namespace std;

stack <int> mystack;
int arr[max];
int brr[max][max];

void dfs(int x,int n){
int flag,t,i;
mystack.push(x);
    arr[x]=1;
    printf("%d ",x);
    while(mystack.empty()==false){
        flag=0;
        t=mystack.top();
        for(i=1;i<=n;i++){

            if(brr[t][i]==1 && arr[i]!=1){

                mystack.push(i);
                printf("%d ",i);
                arr[i]=1;
                flag=1;
                break;
            }
        }
        if(flag==0){

            mystack.pop();
        }
    }


}

int main(){
    int n,e,i,a,b,q;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    memset(arr,0,sizeof(arr));
    memset(brr,0,sizeof(brr));
    printf("\nEnter the number of edges: ");
    scanf("%d",&e);
    printf("\nEnter the edge list: ");
    for(i=0;i<e;i++){

        scanf("%d%d",&a,&b);
        brr[a][b]=1;
        brr[b][a]=1;
    }
    printf("\nEnter the start verttex: ");
    scanf("%d",&q);
    dfs(q,n);
	return 0;
}
