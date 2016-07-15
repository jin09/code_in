/* Topological Sort
   Directed Graph
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
        //arr[v].push_back(u);
    }

    void topologicalSort(){
        //int* indegree = new int[v];
        int indegree[8];
        //initialize the indegree array to 0;
        memset(indegree,0,sizeof indegree);
        //set the indegree of each node
        list<int>::iterator it;
        for(int i=0;i<v;i++){
            for(it=arr[i].begin();it!=arr[i].end();it++){
                indegree[*it]++;
            }
        }
        //find all the elements that have indegree 0 and push them in a queue
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        //pop from queue

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(it=arr[temp].begin();it!=arr[temp].end();it++){
                indegree[*it]--;
                if(indegree[*it] == 0){
                    q.push(*it);
                }
            }
        }
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
cout<<"Topological Sort : ";
g.topologicalSort();
return 0;
}
