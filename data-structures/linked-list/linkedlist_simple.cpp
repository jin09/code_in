#include <bits/stdc++.h>
using namespace std;

class linkedList;

class node{

int data;
node* next;

public:
    node(){
        data = NULL;
        next=NULL;
    }
    node(int data){
        this->data = data;
    }

    friend class linkedList;

};


class linkedList{

node * head;
node * tail;

public:

    linkedList(){
        head = NULL;
    }

    linkedList(linkedList const &l){

        node * temp = l.head;
        this->head = NULL;
        recursiveInsertAtHead(temp);

    }

    void recursiveInsertAtHead(node* temp){

        if(temp==NULL){

            return ;
        }

        recursiveInsertAtHead(temp->next);
        //cout<<temp->data<<endl;
        node * n = new node(temp->data);
        n->next = NULL;
        n->next = head;
        head = n;

    }

        void insertAtHead(int data){

            node * n = new node(data);
            n->next =head;
            head = n;
        }

        void insertInMiddle(int pos , int data){

            node * temp = head;
            for(int i=0;i<pos-1;i++){

                temp = temp->next;

            }
            node* n = new node(data);
            n->next = temp->next;
            temp->next = n;

        }

        void addAtEnd(int data){

            node* temp = head;
            while(temp->next!=NULL){

                temp=temp->next;
            }
            node * n = new node(data);
            temp->next = n;
        }

        int searchRecursiveHelper(int key, node* temp, int pos){

            if(temp==NULL){

                return -1;
            }

            if(temp->data!=key){

                int result = searchRecursiveHelper(key,temp->next,pos+1);
                return result;
            }
            else{

                return pos;
            }

        }

        int searchRecursive(int key){

            node * temp = head;

            int result = searchRecursiveHelper(key ,temp,0);

            return result;
        }

        void print(){
            node* temp = head;
            while(temp!=NULL){
                printf("%d-->>",temp->data);
                temp=temp->next;
            }
            cout<<endl;
        }

        int size(){
            node* temp = head;
            int counter = 0;
            while(temp!=NULL){

                counter++;
                temp=temp->next;
            }
            return counter;
        }



        void deleteFirstOccur(int key){

            node* temp = head;
            if(temp->data==key){

                head=temp->next;
                delete temp;
                return ;
            }
            node* prev = temp;
            temp = temp->next;
            while(temp!=NULL){

                if(temp->data==key){

                    prev->next = temp->next;
                    delete temp;
                    return ;
                }
                else{

                    temp=temp->next;
                    prev=prev->next;
                }
            }
        }

        void bubbleSort(){

            int n = size();


            for(int i=0;i<n;i++){

                node* temp1 = head;
                node* temp2 = head->next;

                for(int j=0;j<n-i-1;j++){

                   if(temp1->data > temp2->data){

                    int temp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = temp;
                   }
                   temp1=temp1->next;
                   temp2=temp2->next;

                }
            }

        }

        ~linkedList(){

            node * temp = head;
            while(temp!=NULL){

                temp = head->next;
                delete head;
                head = temp;
            }

        }

};


int main(){

linkedList l;
l.insertAtHead(5);
l.insertAtHead(9);
l.insertAtHead(12);
l.insertAtHead(1);
l.insertAtHead(8);
l.print();
l.bubbleSort();
l.print();
linkedList l2(l);
l2.print();
l.insertInMiddle(2,43);
l.print();
int searchresult=l.searchRecursive(43);
printf("The number was found at position %d",searchresult);
return 0;
}
