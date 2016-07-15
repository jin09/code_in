#include <bits/stdc++.h>
using namespace std;
//BellmanFord algo for shortest path


int main(){
    int a,b,c,v,e,s,d;
    printf("Enter the no of vertices:");
    scanf("%d",&v);
    vector <list<pair<int , int> > > adjlist(v+1);
    printf("Enter the no of edges:");
    scanf("%d",&e);
for(int i=0;i<e;i++){

    scanf("%d%d%d",&a,&b,&c);
    adjlist[a].push_back(make_pair(b,c));                               //DIRECTED
}

//following commented code can be used to traverse
//or to print the adjacency list.

/*printf("\nThe Adjacency List-\n");
    // Printing Adjacency List
    for (int i = 1; i < adjlist.size(); i++) {
        printf("adjlist[%d] ", i);

        list< pair<int, int> >::iterator itr = adjlist[i].begin();

        while (itr != adjlist[i].end()) {
            printf(" -> %d(%d)", itr->first, itr->second);
            itr++;
        }
        printf("\n");
    }*/


    //BellmanFord
    int i,j;
    list< pair<int, int> >::iterator itr;
    printf("Enter the start vertex:");
    scanf("%d",&s);
    bool visited[v+1];
    memset(visited,false,sizeof(visited));
    visited[s]=true;
    int brr[v+2];
    memset(brr,INT_MAX,sizeof(brr));
    brr[s]=0;
    for(i=0;i<v-1;i++){

        for(j=1;j<=v;j++){

            if(visited[j]==true){

                for(itr=adjlist[j].begin();itr!=adjlist[j].end();itr++){

                    brr[itr->first]=min(brr[itr->first],(itr->second)+brr[j]);
                    visited[itr->first]=true;
                }
            }
        }
    }
    for(i=1;i<=v;i++){

        printf("%d ",brr[i]);
    }

return 0;
}
