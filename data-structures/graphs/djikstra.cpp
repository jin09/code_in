/**
* Refer this link for graph image http://www.geeksforgeeks.org//wp-content/uploads/Fig-11.jpg
*/
#include<bits/stdc++.h>
using namespace std;

class comp{
public:
    bool operator()(const pair<int,int> &a, const pair<int,int> &b)const{
        return a.second < b.second;
    }
};

class Graph{
vector<vector<pair<int, int> > > arr;
int vertices;
public:
    Graph(int v){
        this->vertices = v;
        arr.resize(v);
    }
    void addEdge(int u, int v, int w){
        arr[u].push_back(make_pair(v,w));
        arr[v].push_back(make_pair(u,w));
    }

    int shortestPath(int source, int destination){
        int* dist = new int[vertices];
        for(int i=0;i<vertices;i++){
            dist[i] = -1;
        }
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
        pq.push(make_pair(source, 0));
        while(!pq.empty()){
            pair<int, int> top = pq.top();
            pq.pop();
            for(int i=0;i<arr[top.first].size();i++){
                pair<int, int> edge = arr[top.first][i];
                if(dist[edge.first] == -1){
                    int distance = dist[top.first] + edge.second;
                    dist[edge.first] = distance;
                    pq.push(make_pair(edge.first, distance));
                }
                else if(dist[top.first] + edge.second < dist[edge.first]){
                    dist[edge.first] = dist[top.first] + edge.second;
                    pq.push(make_pair(edge.first, dist[edge.first]));
                }
            }
        }
        int ans = dist[destination];
        delete [] dist;
        return ans;
    }

};

int main(){
Graph g(9);
g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout<<g.shortestPath(0,8);
return 0;
}
