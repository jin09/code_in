/*
Fibonacci series memoization DP
*/
#include<bits/stdc++.h>
using namespace std;

int fib(int n,int* memo){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    if(memo[n] != 0){
        return memo[n];
    }

    else{
        int result = fib(n-1,memo) + fib(n-2,memo);
        memo[n] = result;
        return result;
    }

}

int main(){
int* memo = new int[100];
memset(memo,0,sizeof memo);
cout<<fib(10,memo)<<endl;
cout<<fib(4,memo);
return 0;
}
