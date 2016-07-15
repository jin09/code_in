/*BFS By Adjecency matrix*/
#include <bits/stdc++.h>
#define max 20
using namespace std;

queue <int> myqueue;
int arr[max];
int brr[max][max];

void bfs(int x,int n){
int flag,t,i;
myqueue.push(x);
    arr[x]=1;
    printf("%d ",x);
    while(myqueue.empty()==false){

        t=myqueue.front();
        myqueue.pop();
        for(i=1;i<=n;i++){

            if(brr[t][i]==1 && arr[i]!=1){

                myqueue.push(i);
                printf("%d ",i);
                arr[i]=1;
            }
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
    printf("\nEnter the start vertex: ");
    scanf("%d",&q);
    bfs(q,n);
	return 0;
}
