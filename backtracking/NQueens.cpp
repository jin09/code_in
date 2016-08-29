bool canPlace(vector<string> &s,int row, int col){

    //check the row
    for(int i=0;i<s.size();i++){
        if(s[row][i] == 'Q'){
            if(i != col){
                return false;
            }
        }
    }
    //check the col
    for(int i=0;i<s.size();i++){
        if(s[i][col] == 'Q'){
            if(i != row){
                return false;
            }
        }
    }
    //check the / diagonal
    int bound = s.size()-1;
    int x = row+1;
    int y = col-1;

    while(x <= bound && y >= 0){
        if(s[x][y] == 'Q'){
            return false;
        }
        x++;
        y--;
    }

    x = row-1;
    y = col +1;

    while(x>=0 && y<=bound){
        if(s[x][y] == 'Q'){
            return false;
        }
        x--;
        y++;
    }

    //check the \ diagonal
    x = row +1;
    y = col +1;

    while(x <= bound && y<= bound){
        if(s[x][y] == 'Q'){
            return false;
        }
        x++;
        y++;
    }

    x = row -1;
    y = col -1;

    while(x >= 0 && y>= 0){
        if(s[x][y] == 'Q'){
            return false;
        }
        x--;
        y--;
    }
    return true;

}

bool placeMyQueens(vector<vector<string> >&res,vector<string> &s, int row){
    if(row == s.size()){
        //I have found the answer
        res.push_back(s);
        return false;
    }

    for(int i=0;i<s.size();i++){
        if(canPlace(s,row,i)){
            s[row][i] = 'Q';
            bool ans = placeMyQueens(res,s,row+1);
            if(ans == false){
                s[row][i] = '.';
            }
        }
    }
    //reset the row by '.'
    for(int i=0;i<s.size();i++){
        s[row][i] = '.';
    }
    return false;
}

vector<vector<string> > solveNQueens(int A) {
    
    vector<vector<string> > res ;
    vector<string> s(A) ;
    for(int i=0;i<A;i++){
        for(int j=0;j<A;j++){
            s[i].push_back('.');
        }
    }
    placeMyQueens(res,s,0);
    return res;
}

int main(){

vector<vector<string> > res = solveNQueens(4);

for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
        cout<<res[i][j]<<endl;
    }
    cout<<endl<<endl;
}

return 0;
}
