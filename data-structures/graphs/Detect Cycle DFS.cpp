#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vertices;
    vector<vector<int> > arr;
    Graph(int v):vertices(v){
        arr.resize(vertices);
    }

    void addEdge(int v, int u){
        arr[v].push_back(u);
    }

    bool detectCycleHelper(bool* visited, bool* recursion_stack, int current_node){
        visited[current_node] = true;
        recursion_stack[current_node] = true;
        for(int i=0;i<arr[current_node].size();i++){
            if(recursion_stack[arr[current_node][i]] == true){
                return true;
            }
            else if(visited[arr[current_node][i]] == false){
                bool res = detectCycleHelper(visited, recursion_stack, arr[current_node][i]);
                if(res == true){
                    return true;
                }
            }
        }
        recursion_stack[current_node] = false;
        return false;
    }

    bool detectCycle(){
        bool* visited = new bool[vertices];
        bool* recursion_stack = new bool[vertices];
        for(int i=0;i<vertices;i++){
            visited[i] = false;
            recursion_stack[i] = false;
        }
        for(int i=0;i<vertices;i++){
            bool ans = detectCycleHelper(visited, recursion_stack, i);
            if(ans){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g.detectCycle();
    return 0;
}
