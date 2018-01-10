#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

int editDistanceHelper(string s1, string s2, int x, int y){
  if(x >= s1.length()){
    return s2.length()-y;
  }
  if(y >= s2.length()){
    return s1.length()-x;
  }
  if(s1[x] == s2[y]){
    return editDistanceHelper(s1, s2, x+1, y+1);
  }
  int insert = 1 + editDistanceHelper(s1, s2, x, y+1);
  int removal = 1 + editDistanceHelper(s1, s2, x+1, y);
  int modify_both = 1 + editDistanceHelper(s1, s2, x+1, y+1);
  
  return min(insert, min(removal, modify_both));
}

int editDistance(string s1, string s2){
  return editDistanceHelper(s1, s2, 0, 0);
}
