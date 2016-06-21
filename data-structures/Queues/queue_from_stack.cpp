// Implement a queue using 2 stacks
#include<bits/stdc++.h>

using namespace std;

class node{

int data;
node* next;

public:
    node(int data){
        this->data = data;
        next = NULL;
    }

friend class Stack;
friend class Queue;
};

class Stack{

node* head;

public:

    Stack(){
    head = NULL;
    }
    friend class Queue;

    void push(int data){
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

    int pop(){
        if(head==NULL){
            cout<<"The stack is already empty"<<endl;
            return -1;
        }
        node * temp = head;
        head = head->next;
        int value = temp->data;
        delete temp;
        return value;
}
    bool isEmpty(){
        if(head==NULL){

            return true;
        }
        else{
            return false;
        }
    }

    int sizeOfStack(){
        node* temp = head;
        int counter = 0;
        while(temp!=NULL){
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    void printStackTopToBottom(){
        node* temp = head;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }

    ~Stack(){
        node* temp = head;
        while(head!=NULL){
            head = head->next;
            delete temp;
            temp = head;
        }
    }

};

class Queue{
Stack s1,s2;
public:
    void enqueue(int data){
        if(s1.isEmpty() && s2.isEmpty()){
            s1.push(data);
            return;
        }
        if(!s1.isEmpty()){
            s1.push(data);
            return ;
        }
        else{
            s2.push(data);
            return;
        }

    }

    int dequeue(){
        if(s1.isEmpty() && s2.isEmpty()){

            cout<<"Queue is empty !! "<<endl;
            return -1;
        }
        if(!s1.isEmpty()){
            while(!s1.isEmpty()){
                s2.push(s1.pop());
            }
            int temp = s2.pop();
            while(!s2.isEmpty()){
                s1.push(s2.pop());
            }
            return temp;
        }
    }
};

int main(){
Queue q;
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
cout<<q.dequeue()<<endl;
return 0;
}
