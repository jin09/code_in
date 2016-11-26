#include<iostream>
using namespace std;


int main(){
int a;
cout<<"Enter the number for which you want to find the square root: ";
cin>>a;
cout<<"Enter the precision upto which you want to find the square root: ";
int precision;
cin>>precision;
float ans = 0;
int current_precision = 0;
float increment = 1;
while(current_precision <= precision){
    while(ans*ans <= a){
        ans+=increment;
    }
    ans-=increment;
    increment=increment/10;
    current_precision++;
}
cout<<endl<<ans;
return 0;
}
