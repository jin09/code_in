/**
Implement a queue using 2 stacks
*/
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        next = NULL;
    }
};

class Stack{
node* topOfStack;
public:
    Stack(){
        topOfStack = NULL;
    }
    void push(int data){
        node* temp = new node(data);
        if(topOfStack == NULL){
            topOfStack = temp;
        }
        else{
            temp->next = topOfStack;
            topOfStack = temp;
        }
    }

    int pop(){
        if(topOfStack == NULL){
            cout<<"The stack is empty!!";
            return -1;
        }
        else{
            int save = topOfStack->data;
            node* next = topOfStack->next;
            delete topOfStack;
            topOfStack = next;
            return save;
        }
    }

    int top(){
        if(topOfStack == NULL){
           cout<<"The stack is empty!!";
            return -1;
        }
        else{
            return topOfStack->data;
        }
    }
    bool isEmpty(){
        if(topOfStack == NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

class Queue{
Stack push, pop;
public:
    void enqueue(int data){
        push.push(data);
    }
    int dequeue(){
        if(pop.isEmpty()){
            if(push.isEmpty()){
                cout<<"The Queue is Empty!!";
                return -1;
            }
            else{
                while(!push.isEmpty()){
                    pop.push(push.pop());
                }
                return pop.pop();
            }
        }
        else{
            return pop.pop();
        }
    }
};

int main(){

Queue q;
q.enqueue(2);
q.enqueue(4);
q.enqueue(5);
q.enqueue(9);
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;

return 0;
}
