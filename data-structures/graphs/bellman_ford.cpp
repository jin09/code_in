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
        arr[u].push_back(make_pair(v,w));
    }

    void bellmanford(int source){
        int* dist = new int[vertices];
        for(int i=0;i<vertices;i++){
            dist[i] = INT_MAX;
        }
        dist[source] = 0;
        bool isDistGettingBetter = false;
        for(int i=0;i<vertices;i++){
                isDistGettingBetter = false;
            for(int j=0;j<arr.size();j++){
                if(dist[j] != -1){
                    for(int k=0;k<arr[j].size();k++){
                        pair<int, int> top = arr[j][k];
                        int new_dist = dist[j] + top.second;
                        if(new_dist < dist[top.first]){
                            dist[top.first] = new_dist;
                            isDistGettingBetter = true;
                        }
                    }
                }
            }
            if(isDistGettingBetter == false){
                break;
            }
        }
        if(isDistGettingBetter == true){
            cout<<"The graph has negative edge cycles, so shortest dist cannot be found!!"<<endl;
        }
        else{
            //print the dist
            cout<<"shortest distance from source "<<source<<" is : "<<endl;
            for(int i=0;i<vertices;i++){
                cout<<"distance to "<<i<<" is: "<<dist[i]<<endl;
            }
        }
        delete [] dist;
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
    //test the -ve edge case
    g.addEdge(7,8,-50);
    g.bellmanford(0);
return 0;
}
