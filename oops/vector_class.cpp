#include <bits/stdc++.h>

using namespace std;

class Vector{

int * arr;
int curr_size;
int max_size;

public:
    Vector(){
    arr = new int[4];
    curr_size = 0;
    max_size = 4;
    }

    Vector(int pre_defined_size){

        arr = new int[pre_defined_size];
        curr_size = 0;
        max_size = pre_defined_size;
    }

    Vector(Vector const &v){
        arr = new int[v.max_size];
        max_size = v.max_size;
        curr_size = v.curr_size;
        for(int i=0;i<=curr_size;i++){

            arr[i] = v.arr[i];
        }
    }

    void pushback(int a){
            if(curr_size<max_size){
            arr[curr_size] = a;
            curr_size++;
        }
        else{

            cout<<"Doubling the size of array";
            int * newarr = new int[max_size*2];
            max_size = 2 * max_size;
            for(int i=0;i<curr_size;i++){

                newarr[i] = arr[i];
            }
            newarr[curr_size] = a;
            curr_size++;
            delete [] arr;
            arr = newarr;
        }
    }

    void popback(){
        if(curr_size*4 <= max_size){

            int * newarr = new int[(curr_size*4) + 1];
            for(int i=0;i<curr_size-1;i++){

                newarr[i] = arr[i];
            }
            delete [] arr;
            arr = newarr;

        }
        else{
        curr_size--;
        }
    }

    void print(){
        for(int i=0;i<curr_size;i++){

            printf("%d-->>",arr[i]);
        }
        printf("\n");
    }

    ~Vector(){
        cout<<"DELETING ARRAY VECTOR";
        delete [] arr;
    }

};

int main(){

Vector v;
v.pushback(2);
v.print();
v.pushback(7);
v.print();
v.pushback(9);
v.print();
v.pushback(6);
v.print();
v.pushback(12);
v.print();
Vector newvector(v);
cout<<"NEW COPED VECTOR"<<endl;
newvector.print();
newvector.popback();
newvector.print();
return 0;
}
