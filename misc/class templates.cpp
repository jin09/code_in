#include<bits/stdc++.h>

using namespace std;

template <class T,class W>
class myclass{
T a;
W b;

public:
    myclass(T a,W b){
        this->a = a;
        this->b = b;
    }

    T sum(){
        return a+b;
    }

};


int main(){
myclass<float,int> c(4.5,5);
float a = c.sum();
cout<<a;
return 0;
}
