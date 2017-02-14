#include<bits/stdc++.h>
using namespace std;


int towerOfHanoi(int n, char a/*Move From 'a'*/, char b/*Move To 'b'*/, char c/*Using 'c' as axillary*/){

    if(n == 1){
        cout<<"Move disk from "<<a<<" to "<<b<<endl;
        return 1;
    }
    int move1 = towerOfHanoi(n-1, a, c, b);
    int move2 = 1;
    cout<<"Move disk from "<<a<<" to "<<b<<endl;
    int move3 = towerOfHanoi(n-1, c, b, a);

    return move1+move2+move3;
}


int main(){
char movefrom = 'X';
char moveto = 'Y';
char aux = 'Z';
int totalMoves = towerOfHanoi(19, movefrom, moveto, aux);
cout<<endl<<"Total number of moves are : "<<totalMoves<<endl;
return 0;
}
