// k reverse the linked list
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

node* kReverse(node* head, int k){

    if(head==NULL || head->next==NULL){

        return head;
    }

    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int counter = 0;

    while(current!=NULL && counter<k){

        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        counter++;
    }

    if(next != NULL){
        head->next = kReverse(next,k);
    }

    return prev;

}

int main(){
    node* head = takeInputInsertAtTail();
    printf("Normal printing : ");
    print(head);
    cout<< "Enter the value of k to reverse the list : ";
    int k;
    cin>>k;
    head = kReverse(head, k);
    cout<<"modified list : ";
    print(head);
    return 0;
}
