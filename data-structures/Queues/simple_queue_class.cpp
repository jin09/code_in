// simple Queue class
#include<bits/stdc++.h>

using namespace std;

class Queue{
int * arr;
int current_size;
int max_size;
int frontOfQueue;
int rear;

public:
    Queue(){
        arr= new int[5];
        current_size = 0;
        max_size = 5;
        frontOfQueue = 0;
        rear = 4;
    }

    Queue(int Size){
        arr = new int[Size];
        current_size = 0;
        max_size = Size;
        frontOfQueue = 0;
        rear = Size-1;
    }

    bool isFull(){
        return current_size==max_size?true:false;
    }

    bool isEmpty(){
        return current_size == 0? true:false;
    }

    void enqueue(int data){
        if(!isFull()){
            rear = (rear +1)%max_size;
            arr[rear] = data;
            current_size++;
        }
        else{
            cout<<"Cant insert data !! The queue is full ."<<endl;
        }
    }

    int dequeue(){
        if(!isEmpty()){
            int temp = arr[frontOfQueue];
            frontOfQueue = (frontOfQueue + 1)%max_size;
            current_size--;
            return temp;
        }
        else{
            cout<<"Queue is empty .."<<endl;
            return -1;
        }
    }

    int getFront(){
        if(!isEmpty()){
            return arr[frontOfQueue];
        }
        else{
            cout<<"Queue is Empty !"<<endl;
            return -1;
        }
    }

    ~Queue(){
        delete [] arr;
    }

};


int main(){

Queue q(100);
q.enqueue(5);
q.enqueue(6);
q.enqueue(7);
cout<<q.getFront()<<endl;
q.dequeue();
cout<<q.getFront()<<endl;
q.dequeue();

q.enqueue(8);
q.enqueue(9);
q.enqueue(10);
cout<<q.getFront()<<endl;
q.dequeue();
q.dequeue();
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.dequeue();

cout<< q.getFront()<<endl;

return 0;
}
