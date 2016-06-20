// simple stack class using node
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

};

class Stack{

node* head;

public:

    Stack(){
    head = NULL;
    }

    void push(int data){
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

    int pop(){
        if(head==NULL){
            cout<<"The list is already empty"<<endl;
            return -1;
        }
        node * temp = head;
        head = head->next;
        int value = temp->data;
        delete temp;
        return value;
}
};

int main(){

Stack s;
s.push(3);
s.push(7);
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;

return 0;
}
