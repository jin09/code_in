/**
* refer this image for DAG graph http://d1hyf4ir1gqw6c.cloudfront.net//wp-content/uploads/TopologicalSort.png
*/
#include<bits/stdc++.h>
using namespace std;

class Graph{
vector<vector<pair<int, int> > > arr;
int vertices;

public:
    Graph(int v){
        this->vertices = v;
        this->arr.resize(vertices);
    }

    void addEdge(int v, int u, int w){
        arr[v].push_back(make_pair(u,w));
    }

    vector<int>* topologicalSort(){
        vector<int>* res = new vector<int>;
        int* indegree = new int[vertices];
        for(int i=0;i<vertices;i++){
            indegree[i] = 0;
        }
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                indegree[arr[i][j].first] += 1;
            }
        }
        queue<int> q;
        for(int i=0;i<vertices;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top = q.front();
            res->push_back(top);
            q.pop();
            for(int i=0;i<arr[top].size();i++){
                indegree[arr[top][i].first] -= 1;
                if(indegree[arr[top][i].first] == 0){
                    q.push(arr[top][i].first);
                }
            }
        }
        delete [] indegree;
        return res;
    }

    int* shortestPathDAG(int source){
        int* dist = new int[vertices];
        for(int i=0;i<vertices;i++){
            dist[i] = INT_MAX-500;
        }
        dist[source] = 0;
        vector<int>* topological = topologicalSort();
        for(int i=0;i<topological->size();i++){
            for(int j=0;j<arr[topological->at(i)].size();j++){
                if(dist[topological->at(i)] + arr[topological->at(i)][j].second < dist[arr[topological->at(i)][j].first]){
                    dist[arr[topological->at(i)][j].first] = dist[topological->at(i)] + arr[topological->at(i)][j].second;
                }
            }
        }
        return dist;
    }
};

int main(){
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    int* dist = g.shortestPathDAG(1);
    for(int i=0;i<6;i++){
        cout<<dist[i]<<endl;
    }
return 0;
}
