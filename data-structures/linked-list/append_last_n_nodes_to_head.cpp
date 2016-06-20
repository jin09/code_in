// Append the last n elements of a linked list to the front.
// e.g. for 1→ 2→ 3 → 4 → 5 → 6→ null and n = 2 return 5→ 6→ 1→ 2→ 3 → 4 → null
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

void appendNodesFromLastToHead(node* &head, int n){
    //if list is empty then return
    if(head==NULL){

        printf("The list is empty !\n");
        return ;
    }
    //else count the number of nodes and reach the end of the list
    int counter = 0;
    node* temp = head;
    while(temp->next != NULL){
        counter++;
        temp = temp->next;
    }
    counter++;
    //make the list circular list by connection the last node and the head node
    temp->next = head;
    //find the number of hops required to reach the point of cut-off
    int size = counter;
    int toTraverse = size - n;
    toTraverse--;
    //go to that node
    temp = head;
    while(toTraverse--){
        temp = temp->next;
    }
    //make head equal to the next of this node as that is the start of the list now
    head = temp->next;
    //disconnect the circular list
    temp->next = NULL;
    return;
}

int main(){
    node* head = takeInputInsertAtTail();
    printf("Normal printing : ");
    print(head);
    cout<< "Enter the value of n to append the from the last to the end : ";
    int n;
    cin>>n;
    appendNodesFromLastToHead(head,n);
    cout<<"modified list : ";
    print(head);
    return 0;
}
