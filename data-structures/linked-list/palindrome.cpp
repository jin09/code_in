//Check if linked list is a palindrome or not
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


bool checkIfListIsPalindrome(node* head, node* last, int moveit, int size){

if(last==NULL){

    return true;
}
int x = moveit -1;
bool result = checkIfListIsPalindrome(head,last->next,x,size);

if(moveit<0){
int toMove = size + moveit;

for(int i=0;i<toMove;i++){

    head = head->next;
}

return (result) & (head->data == last->data);
}

else{
    return result;
}
}


int main(){
    bool result;
node* head = takeInputInsertAtTail();
int counter = size(head);
if(counter%2==0){
        counter = counter/2;
        int save = counter-1;
         result = checkIfListIsPalindrome(head,head,save,counter);
}
else{
    counter = counter/2;
     result = checkIfListIsPalindrome(head,head,counter,counter);
}

if(result){
    cout<<"Palindrome hai"<<endl;
}
else{
    cout<<"Palindrome nhi hai"<<endl;
}
return 0;
}
