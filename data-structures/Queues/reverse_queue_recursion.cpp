//reverse queue using recursion
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

    Queue(Queue &q){
        arr = new int[q.max_size];
        current_size = q.current_size;
        max_size = q.max_size;
        frontOfQueue = q.frontOfQueue;
        rear = q.rear;
        for(int i=0;i<max_size;i++){
            arr[i] = q.arr[i];
        }
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

    void reverseUsingRecursionHelper(int frontTemp, int rearTemp,Queue& q1){
        if(frontTemp == rearTemp){
            this->arr[frontTemp] = q1.dequeue();
            return ;
        }
        reverseUsingRecursionHelper((frontTemp+1)%this->max_size,rearTemp,q1);
        this->arr[frontTemp] = q1.dequeue();
    }

    void reverseUsingRecursion(Queue &q){
        if(current_size == 0 || current_size==1){
            return ;
        }
        else{
            reverseUsingRecursionHelper(frontOfQueue,rear,q);
        }
    }

    ~Queue(){
        delete [] arr;
    }

};



int main(){
Queue q1;
q1.enqueue(3);
q1.enqueue(6);
q1.enqueue(9);
q1.enqueue(20);
Queue q2(q1);
q1.reverseUsingRecursion(q2);
printf("%d---",q1.dequeue());
printf("%d---",q1.dequeue());
printf("%d---",q1.dequeue());
printf("%d---",q1.dequeue());
return 0;
}
