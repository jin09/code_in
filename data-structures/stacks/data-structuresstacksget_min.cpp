#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    node* next;
    node(int data){
        this->data = data;
        node* next = NULL;
    }
};

void push(node*& head,node*& mini, int data){
    node* temp1 = new node(data);
    node* temp2 = new node(data);
    temp1->next = head;
    head = temp1;
    if(mini == NULL){
        mini = temp2;
        return ;
    }
    else if(temp2->data < mini->data){
        delete mini;
        mini = temp2;
        return;
    }
    return ;
}

int pop(node*& head,node*& mini){
    if(head==NULL){
        cout<<"Stack is empty !!"<<endl;
        return -1;
    }
    int temp = head->data;
    node* temporary = head;
    head = head->next;
    delete temporary;
    if(mini->data == temp){
        delete mini;
        mini = NULL;
    }
    return temp;
}

int getMin(node*& mini){
    if(mini == NULL){
        return -1;
    }
    else{
        return mini->data;
    }
}

int main(){

node* top = NULL;
node* mini = NULL;
push(top,mini,2);
push(top,mini,4);
push(top,mini,6);
push(top,mini,8);
cout<<"MINIMUM IS "<<getMin(mini)<<endl;
return 0;
}
