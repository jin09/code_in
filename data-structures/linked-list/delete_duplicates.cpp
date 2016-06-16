//Eliminate duplicates from a sorted linked list

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

void removeDuplicatesFromList(node* head){

    if(head==NULL || head->next==NULL){

        return ;
    }

    node* temp = head;

    while(temp->next!=NULL){

        node* temp2 = temp->next;
        node* prev_to_temp2 = temp;
        while(temp2!=NULL){

            if(temp2->data==temp->data){
                prev_to_temp2->next = temp2->next;
                delete temp2;
                temp2 = prev_to_temp2->next;
            }
            else{
                prev_to_temp2 = prev_to_temp2->next;
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }

return ;

}


int main(){
node* head = takeInputInsertAtTail();
print(head);
removeDuplicatesFromList(head);
print(head);
return 0;
}
