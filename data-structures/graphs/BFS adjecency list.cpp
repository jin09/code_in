/* BFS and Shortest Path
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

    void BFSPrint(int start){
        bool* visited = new bool[v];
        memset(visited,0,sizeof visited);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        list<int>::iterator it;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(it=arr[temp].begin();it!=arr[temp].end();it++){
                if(visited[*it] == false){
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
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
Graph g(7);
g.addEdge(0,2);
g.addEdge(0,5);
g.addEdge(2,3);
g.addEdge(2,4);
g.addEdge(3,4);
g.addEdge(4,6);
g.addEdge(5,6);
g.BFSPrint(3);
cout<< "Shortest Path is "<< g.shortestPath(0,4);

return 0;
}
