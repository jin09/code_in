#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int editDistanceHelper(string s1, string s2, int x, int y, int** cache){
  if(x >= s1.length()){
    return s2.length()-y;
  }
  if(y >= s2.length()){
    return s1.length()-x;
  }
  if(cache[x][y] != -1){
    return cache[x][y];
  }
  if(s1[x] == s2[y]){
    return editDistanceHelper(s1, s2, x+1, y+1, cache);
  }
  int insert = 1 + editDistanceHelper(s1, s2, x, y+1, cache);
  int removal = 1 + editDistanceHelper(s1, s2, x+1, y, cache);
  int modify_both = 1 + editDistanceHelper(s1, s2, x+1, y+1, cache);
  
  cache[x][y] = min(insert, min(removal, modify_both));
  return cache[x][y];
}

int editDistance(string s1, string s2){
  int** cache = new int*[s1.length()+1];
  for(int i=0;i<=s1.length();i++){
    cache[i] = new int[s2.length()+1];
  }
  for(int i=0;i<=s1.length();i++){
    for(int j=0;j<=s2.length();j++){
      cache[i][j] = -1;
    }
  }
  return editDistanceHelper(s1, s2, 0, 0, cache);
}
