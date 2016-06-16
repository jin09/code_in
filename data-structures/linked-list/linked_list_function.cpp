#include <bits/stdc++.h>
using namespace std;

class node{
public:
int data;
node* next;

    node(){
        data = NULL;
        next=NULL;
    }
    node(int data){
        this->data = data;
        next = NULL;
    }

};

node* takeInputInsertAtHead(){

node* head = NULL;
int data ;
cout<<"Enter the first element"<<endl;
cin>>data;
while(data != -1){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
    cout<<"Enter the next element"<<endl;
    cin>>data;
}
return head;
}

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

node* mergeTwoSortedLists(node* head1,node* head2){

    node* head = NULL;
    node* tail = NULL;
    while(head1!=NULL && head2!=NULL){

        if(head==NULL){

            if(head1->data < head2->data){

                node * temp = new node(head1->data);
                head = temp;
                tail = temp;
                head1=head1->next;
            }
            else{
                node * temp = new node(head2->data);
                head = temp;
                tail= temp;
                head2=head2->next;
            }
        }

        else{

            if(head1->data < head2->data){

                node * temp = new node(head1->data);
                tail->next = temp;
                tail = temp;
                head1=head1->next;
            }
            else{
                node * temp = new node(head2->data);
                tail->next = temp;
                tail = temp;
                head2 = head2->next;
            }
        }
    }
    while(head1!=NULL){

        tail->next=head1;
        tail=head1;
        head1=head1->next;
    }

    while(head2!=NULL){

        tail->next = head2;
        tail = head2;
        head2 = head2->next;
    }

    return head;
}

node* reverseRecursive(node* head){

    if(head==NULL || head->next==NULL){

        return head;
    }

    node* lastNode = reverseRecursive(head->next);

    node* temp = lastNode;
    while(temp->next!=NULL){

        temp=temp->next;
    }
    temp->next = head;
    temp=temp->next;
    temp->next = NULL;
    return lastNode;

}

node* mergeSort(node* head){

    if(head==NULL || head->next==NULL){

        return head;

    }

    node* temp = head;
    int counter = 0;
    while(temp!=NULL){

        temp=temp->next;
        counter++;
    }
    counter=counter/2;
    counter--;
    temp = head;
    while(counter--){

        temp = temp->next;

    }
    node* saveNext = temp->next;
    temp->next =NULL;
    //recursively break the linked List
    node* result1 = mergeSort(head);
    node* result2 = mergeSort(saveNext);

    //Merge the linked List

    node* mergedSortedList = mergeTwoSortedLists(result1,result2);

    return mergedSortedList;

}

int main(){

node* head1 = takeInputInsertAtTail();
print(head1);
node * sortedList = mergeSort(head1);
print(sortedList);
return 0;
}
