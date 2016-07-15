/* DFS , isConnected
   Adjacency List
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    list<int>* arr;
public:
    Graph(int vertices){
       v = vertices;
       arr = new list<int>[vertices];
    }

    void addEdge(int u, int v){
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    void DFSHelper(int source, bool*& visited){
        cout<<source<<"->";
        visited[source] = true;

        list<int>::iterator it;
        for(it=arr[source].begin();it!=arr[source].end();it++){
            if(visited[*it] == false){
                DFSHelper(*it,visited);
            }
        }
    }

    void DFSPrint(){
        bool * visited = new bool[v];
        memset(visited,0,sizeof visited);
        int component = 0;

        for(int i=0;i<v;i++){
            if(visited[i]==false){
                component++;
                cout<<"Printing component "<<component<<" : ";
                visited[i] = true;
                DFSHelper(i,visited);
            }
            cout<<endl;
        }
    }

    bool isConnected(){
        bool* visited = new bool[v];
        memset(visited,0,sizeof visited);
        DFSHelper(0,visited);
        for(int i=0;i<v;i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }

    //In this function I could have used dist array as a substitution for visited array
    int shortestPath(int source, int destination){
        if(source == destination){
            return 0;
        }
        int * dist = new int[v];
        for(int i=0;i<v;i++){
            dist[i] = -1;
        }
        bool* visited = new bool[v];
        memset(visited,0,sizeof visited);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        dist[source] = 0;
        list<int>::iterator it;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(it = arr[temp].begin();it!=arr[temp].end();it++){
                if(visited[*it] == false){
                    q.push(*it);
                    visited[*it] = true;
                    dist[*it] = dist[temp] + 1;
                    if(*it == destination){
                        return dist[*it];
                    }
                }
            }
        }
        return -1;
    }

    ~Graph(){
        delete [] arr;
    }
};

int main(){
Graph g(8);
g.addEdge(0,2);
g.addEdge(0,5);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(3,4);
g.addEdge(4,6);
g.addEdge(5,6);
g.addEdge(1,7);
g.DFSPrint();
cout<< "Shortest Path is "<< g.shortestPath(0,4)<<endl;
if(g.isConnected()){
    cout<<"The graph is connected"<<endl;
}
else{
    cout<<"Graph is not connected"<<endl;
}
return 0;
}
