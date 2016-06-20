//double linked list class
#include<bits/stdc++.h>

using namespace std;

class doublyLinkedList;

class node{
    int data ;
    node* next;
    node* prev;
public:
    node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
    friend class doublyLinkedList;
};

class doublyLinkedList{

node* head;
node* tail;
public:
    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int data){

        if(head==NULL && tail==NULL){
            node* temp = new node(data);
            head = temp;
            tail = temp;
            return;
        }
        else{

            node* temp = new node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
            return;
        }

    }
    void insertAtTail(int data){
        if(head==NULL && tail==NULL){

            node* temp = new node(data);
            head = temp;
            tail = temp;
            return ;
        }
        else{

            node* temp = new node(data);
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
            return ;
        }
    }

    void printStraightUsingHead(){
        node* temp = head;
        while(temp!=NULL){

            printf("%d-->>",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    void printReverseUsingTail(){
        node* temp = tail;
        while(temp!=NULL){

            printf("%d-->>",temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }

    int findFirstPosOfData(int data){
        node* temp = head;
        if(temp == NULL){
            return -1;
        }
        int pos = 1;
        while(temp!=NULL){
            if(temp->data == data){
                return pos;
            }
            else{
                temp = temp->next;
                pos++;
            }
        }
        return -1;
    }

    void deleteNodeAtPos(int pos){
        if(pos==1){
            node* temp  = head;
            head = head->next;
            delete temp;
            return ;
        }
        pos--;
        node* temp = head;
        node* prev = NULL;
        while(pos--){

            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
        temp = prev->next;
        return ;
    }

    int size(){
        node* temp = head;
        int counter =0;
        while(temp!=NULL){

            temp= temp->next;
            counter++;
        }
        return counter;
    }

    void insertAtPos(int data, int pos){
        if(pos == 1){
            insertAtHead(data);
            return ;
        }
        pos-=2;
        node* temp = head;
        while(pos--){
            temp = temp->next;
        }
        node* temp2 = new node(data);
        temp2->next = temp->next;
        temp2->prev = temp;
        return ;
    }

    node* mergeTwoSortedLists(node* head1,node* head2){

    node* result = NULL;

    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    if(head1->data < head2->data){
        result = head1;
        head2->prev = head1;
        result->next = mergeTwoSortedLists(head1->next, head2);
    }
    else{
        result = head2;
        head1->prev = head2;
        result->next = mergeTwoSortedLists(head1,head2->next);
    }
    return result;
}

    int sizing(node* temp){
        int counter = 0;
        while(temp!=NULL){
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    node* mergeSortHelper(node* head){
        //if list is empty or has only 1 element then return
        if(head==NULL || head->next==NULL){
            return head;
        }
        //break the list into 2 halves
        int sizi = sizing(head);
        sizi = sizi/2;
        sizi--;
        node* temp = head;
        while(sizi--){
            temp = temp->next;
        }
        node* next = temp ->next;
        temp->next = NULL;
        next->prev = NULL;

        //recursively break the list into halves
        node* list1 = mergeSortHelper(head);
        node* list2 = mergeSortHelper(next);

        //merge the sorted lists
        node* result = mergeTwoSortedLists(list1,list2);

        return result;
    }

    void mergeSort(){
        node* temp = head;
        this->head = mergeSortHelper(temp);
        temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        this->tail = temp;
        return ;
    }


    ~doublyLinkedList(){
        node* temp = head;
        node* save = NULL;
        while(temp!=NULL){

            save = temp->next;
            delete temp;
            temp = save;
        }
    }

};

int main(){
    doublyLinkedList l;
    int data;
    scanf("%d",&data);
    while(data!=-1){
        l.insertAtTail(data);
        scanf("%d",&data);
    }
    cout<<"Printing using head : ";
    l.printStraightUsingHead();
    cout<<"Printing Using tail : ";
    l.printReverseUsingTail();

    cout<<"Enter the data whose position is to be found : ";
    cin>>data;
    int pos = l.findFirstPosOfData(data);
    if(pos == -1){
        cout<<"Data not found : ";
    }
    else{

        cout<<"First Occurrence of data found at pos : "<< pos<<endl;
    }
    l.insertAtTail(1);
    l.printStraightUsingHead();
    l.mergeSort();
    l.printStraightUsingHead();
    l.printReverseUsingTail();
    return 0;
}
