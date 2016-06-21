// Implement a stack using 2 queues
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

    int Size(){
        return current_size;
    }

    ~Queue(){
        delete [] arr;
    }

};

class Stack{

Queue *q1,*q2;

public:
    Stack(){
        q1 = new Queue();
        q2 = new Queue();
    }
    Stack(int size1, int size2){
        q1 = new Queue(size1);
        q2 = new Queue(size2);
    }

    void push(int data){
        if(q1->isEmpty() && q2->isEmpty()){
            q1->enqueue(data);
            return ;
        }
        if(!(q1->isEmpty())){
            q1->enqueue(data);
            return ;
        }
        else{
            q2->enqueue(data);
            return ;
        }

    }

    int pop(){
        if(q1->isEmpty() && q2->isEmpty()){
            cout<<"Stack is Empty !! "<<endl;
            return -1;
        }
        if(!q1->isEmpty()){
            while(q1->Size() > 1){
                q2->enqueue(q1->dequeue());
            }
            return q1->dequeue();
        }
        else{
            while(q2->Size() > 1){
                q1->enqueue(q2->dequeue());
            }
            return q2->dequeue();
        }
    }

};

int main(){

Stack s;
s.push(1);
s.push(2);
s.push(3);

cout<< s.pop()<<endl;

s.push(4);

cout<<s.pop()<<endl;

cout<<s.pop()<<endl;

cout<< s.pop()<<endl;

cout<<endl;

cout<< s.pop()<<endl;

return 0;
}
