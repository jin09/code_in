/* Winning the Snakes and Ladders
   Refer this image : http://i1.wp.com/www.citywomenflaward.co.uk/wp-content/uploads/2014/05/snakes-and-ladders.jpg

   
   The snakes and ladders are represented by :
board[2]= 13;  //There is a ladder from 2 to 2+13 i.e 15
board[5] = 2;
board[9] = 18;
board[18] = 11;
board[17] = -13; // There is a snake from 17 that leads you to 17-13 i.e 4
board[20] = -14;
board[24] = -8;
board[25] = 10;
board[32] = -2;
board[34] = -22;
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

    int shortestPath(int source,int destination){
        if(source == destination){
            return 0;
        }
        //the dist array can be used as a visited array as well
        int* dist = new int[v];
        for(int i=0;i<v;i++){
            dist[i] = -1; // set to infinity
        }
        int* parent = new int[v];
        for(int i=0;i<v;i++){
            parent[i] = -1; // parent of each node not set
        }

        queue<int> q;
        parent[source] = 0;
        dist[source] = 0;
        q.push(source);

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            list<int>::iterator it;
            for(it = arr[temp].begin();it!=arr[temp].end();it++){
                if(dist[*it] == -1){
                    dist[*it] = dist[temp] + 1;
                    parent[*it] = temp;
                    q.push(*it);
                }
            }
        }
        //printing the path
        cout<<"shortest path from source to destination is : ";
        int current = destination;
        cout<<current<<"<<--";
        while(parent[current] != 0){
            cout<<parent[current]<<"<<--";
            current = parent[current];
        }
        cout<<endl;
        return dist[destination];
    }

    ~Graph(){
        delete [] arr;
    }
};

int main(){

Graph g(50);

int board[50] = {0};
board[2]= 13;
board[5] = 2;
board[9] = 18;
board[18] = 11;
board[17] = -13;
board[20] = -14;
board[24] = -8;
board[25] = 10;
board[32] = -2;
board[34] = -22;


for(int i=1;i<=36;i++){
    if(board[i] == 0){
        for(int j=1;j<=6;j++){
            int pos = i+j;
            if(pos<=36){
                if(board[pos]!=0){
                    g.addEdge(i,pos+board[pos]);
                }
                else{
                    g.addEdge(i,pos);
                }
            }
        }
    }
}

int result = g.shortestPath(1,36);
cout<<"The shortest distance from source to destination is "<<result<<endl;
return 0;
}
