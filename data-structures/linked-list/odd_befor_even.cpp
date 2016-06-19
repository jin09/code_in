//Odd numbers before even numbers
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

void insertOddInEvenIfCurrentNodeIsHead(node*& evenHead, node*& evenTail, node*& currentNode){

    if(evenHead == NULL){

        evenHead = currentNode;
        evenTail = currentNode;
        currentNode = currentNode->next;
        evenHead->next = NULL;
        return;
    }

    else{

        evenTail->next = currentNode;
        currentNode = currentNode->next;
        evenTail = evenTail->next;
        evenTail->next = NULL;
        return ;
    }

}

void insertOddInEvenIfCurrentIsNotHead(node*& evenHead,node*& evenTail,node*& currentNode,node*& prevNode){

    if(evenHead == NULL){

        evenHead = currentNode;
        evenTail = evenHead;
        prevNode->next = currentNode->next;
        currentNode = currentNode->next;
        evenHead->next == NULL;
        return;
    }
    else{

        evenTail->next = currentNode;
        evenTail = evenTail->next;
        prevNode->next = currentNode->next;
        currentNode = currentNode->next;
        evenTail->next = NULL;
        return ;
    }

}

void insertCurrentInEvenList(node* &evenHead, node* &evenTail, node* &currentNode, node* &prevNode){

    if(prevNode == NULL){

        insertOddInEvenIfCurrentNodeIsHead(evenHead,evenTail,currentNode);
        return ;
    }
    else{

        insertOddInEvenIfCurrentIsNotHead(evenHead,evenTail,currentNode,prevNode);
        return;
    }

}

node* oddBeforeEven(node* head){
    //empty or 1 element
    if(head==NULL || head->next==NULL){

        return head;
    }
    //list is not empty
    node* headForEven = NULL;
    node* tailForEven = NULL;

    node* currentNode = head;
    node* prevNode = NULL;

    while(currentNode != NULL){

        if(currentNode->data % 2 == 0){
            //delete the current node and put that node in the even list
            insertCurrentInEvenList(headForEven,tailForEven,currentNode,prevNode);
        }
        else{

            prevNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    if(prevNode == NULL){

        return headForEven;
    }
    else{
        prevNode->next = headForEven;
        return head;
    }

}

int main(){
    node* head = takeInputInsertAtTail();
    print(head);
    head = oddBeforeEven(head);
    print(head);
    return 0;
}
