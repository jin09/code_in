//Reverse linked List Iterative
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


node* takeInputInsertAtTail(){
    node* head=NULL;
    node* tail = NULL;

    int data ;
    cout<<"Enter the first data"<<endl;
    cin>>data ;
    while(data!=-1){

        if(head==NULL){

            node* temp = new node(data);
            head = temp;
            tail = temp;
        }
        else{
            node* temp = new node(data);
            tail->next = temp;
            tail = temp;
        }
        cout<<"Enter the next data "<<endl;
        cin>>data;
    }
    return head;
}

void print(node* temp){

    while(temp!= NULL){

        printf("%d->",temp->data);
        temp = temp->next;
    }
    cout<<endl;
}

int size(node* head){

    int counter =0;
    while(head!=NULL){

        counter++;
        head = head->next;
    }
    return counter;
}


void reverseListIterative(node* &head){

    if(head==NULL || head->next==NULL){

        return ;
    }

    node * current = head;
    node* prev = NULL;
    node* nextNode = head->next;
    while(current!=NULL){

        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;
return ;
}


int main(){
    node* head = takeInputInsertAtTail();
    print(head);
    reverseListIterative(head);
    print(head);
    return 0;
}
