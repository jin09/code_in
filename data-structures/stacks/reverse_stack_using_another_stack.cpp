// reverse the stack using another stack
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

};

void stackReverse(Stack& s){
    Stack s1;

    if(s.isEmpty() || s.sizeOfStack()==1){
        return ;
    }
    int saveData = s.pop();
    int counter = 1;
    while(!s.isEmpty()){
        s1.push(s.pop());
        counter++;
    }
    s.push(saveData);
    while(!s1.isEmpty()){
        s.push(s1.pop());
    }
    counter = counter - 2;
    int pops = counter;
    for(int i=0;i<counter;i++){

    saveData = s.pop();
    for(int j=0;j<pops;j++){
        s1.push(s.pop());
    }
    pops--;
    s.push(saveData);
    while(!s1.isEmpty()){
        s.push(s1.pop());
    }
    }
    return ;
}

int main(){

Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
cout<<"Normal stack printing : "<<endl;
s.printStackTopToBottom();
stackReverse(s);
cout<<"Reversed stack is : "<<endl;
s.printStackTopToBottom();
return 0;
}
