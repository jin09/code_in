#include <bits/stdc++.h>
using namespace std;

int magic_grid(int** arr, int x, int y, int m, int n){
  if(x == m && y == n){
    return 1;
  }
  if(x < 0 || x > m || y < 0 || y > n){
    return INT_MAX;
  }
  int down = magic_grid(arr, x+1, y, m, n);
  int right = magic_grid(arr, x, y+1, m, n);
  
  return (min(down, right) - arr[x][y])>0?(min(down, right) - arr[x][y]):1;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    int m,n;
    cin>>m>>n;
    int ** arr = new int*[m];
    for(int i=0;i<m;i++){
      arr[i] = new int[n];
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        cin>>arr[i][j];
      }
    }
    cout<<magic_grid(arr, 0, 0, m-1, n-1)<<endl;
    for(int i=0;i<m;i++){
      delete [] arr[i];
    }
    delete [] arr;
  }
    return 0;
}
