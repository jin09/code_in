/*Union and Intersection of LinkedList*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        next = NULL;
    }
};

void insertAtTail(node*& head, int data){
    node* temp = new node(data);
    node* tempHead = head;
    if(head == NULL){
        head = temp;
        return;
    }
    while(tempHead->next!=NULL){
        tempHead= tempHead->next;
    }
    tempHead->next = temp;
    return;
}

void printList(node* head){
    if(head == NULL){
        return ;
    }
    cout<<head->data<<"-->>";
    printList(head->next);
}

void printIntersection(node* head1,node* head2,unordered_map<int,node*>& m){
    //insert all elements of 1st list to map
    while(head1!=NULL){
        m[head1->data] = head1;
        head1 = head1->next;
    }
    while(head2!=NULL){
        //data found
        if(m.find(head2->data) != m.end()){
            cout<<head2->data<<" ";
        }
        head2 = head2->next;
    }
    return;
}

node* unionTwoList(node* head1,node* head2,unordered_map<int,node*>& m){
    //add elements of 1st list
    while(head1 != NULL){
        if(m.find(head1->data) == m.end()){
            m[head1->data] = head1;
        }
        head1 = head1->next;
    }
    //add elements of 2nd list
    while(head2 != NULL){
        if(m.find(head2->data) == m.end()){
            m[head2->data] = head2;
        }
        head2 = head2->next;
    }
    //traverse the hash table and add elements to new linked list
    unordered_map<int,node*>::iterator it;
    node* resultHead = NULL;
    for(it=m.begin();it!=m.end();it++){
        insertAtTail(resultHead,it->first);
    }
    return resultHead;
}

int main(){
node* head1 = NULL;
insertAtTail(head1,2);
insertAtTail(head1,8);
insertAtTail(head1,4);
insertAtTail(head1,7);
printList(head1);
cout<<endl;
node* head2 = NULL;
insertAtTail(head2,2);
insertAtTail(head2,1);
insertAtTail(head2,3);
insertAtTail(head2,7);
insertAtTail(head2,9);
insertAtTail(head2,23);
insertAtTail(head2,42);
insertAtTail(head2,67);
printList(head2);
cout<<endl;
//print Intersection of 2 linked list
unordered_map<int,node*> m;
cout<<"Intersection of 2 linked list is : ";
printIntersection(head1,head2,m);
cout<<endl;
//print the union list
unordered_map<int,node*> m2;
cout<<"Union List : ";
node* unionList = unionTwoList(head1,head2,m2);
printList(unionList);

return 0;
}
