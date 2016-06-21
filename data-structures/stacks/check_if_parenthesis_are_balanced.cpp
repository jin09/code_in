// balanced parenthesis stack 
#include<bits/stdc++.h>

using namespace std;

class node{

char data;
node* next;

public:
    node(char data){
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

    void push(char data){
        node* temp = new node(data);
        temp->next = head;
        head = temp;
    }

    char pop(){
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
            printf("%c\n",temp->data);
            temp = temp->next;
        }
    }

    char top(){
        if(head!=NULL){
        return head->data;
        }
        else{
            return NULL;
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

bool isParenthesisBalanced(char * input){
    int length = strlen(input);
    Stack s;
    for(int i=0;i<length;i++){
        if(input[i]=='(' ||input[i]=='{' || input[i]=='['){
            s.push(input[i]);
           }
           if(input[i]==')'){
                if(s.top()=='(' && s.isEmpty()==0){
                    s.pop();
                }
                else{
                    return false;
                }
           }
           if(input[i]=='}'){
                if(s.top()=='{' && s.isEmpty()==0){
                    s.pop();
                }
                else{
                    return false;
                }
           }
           if(input[i]==']'){
                if(s.top()=='[' && s.isEmpty()==0){
                    s.pop();
                }
                else{
                    return false;
                }
           }
    }
    if(s.isEmpty()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
char arr[100];
cout<<"Enter string to check if parenthesis are balanced or not: "<<endl;
scanf("%s",&arr);
if(isParenthesisBalanced(arr)){
    cout<<"Balanced hai"<<endl;
}
else{
    cout<<"Balaneced Nahi hai"<<endl;
}
return 0;
}
