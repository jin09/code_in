#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    node* next;
    node(int data){
        this->data = data;
        node* next = NULL;
    }
};

void push(node*& head, int data){
    node* temp1 = new node(data);
    node* temp2 = new node(data);
    temp1->next = head;
    head = temp1;
    return ;
}

int seetop(node* head){
    if(head==NULL){
        return -1;
    }
    else{
        return head->data;
    }
}

int pop(node*& head){
    if(head==NULL){
        cout<<"Stack is empty !!"<<endl;
        return -1;
    }
    int temp = head->data;
    node* temporary = head;
    head = head->next;
    delete temporary;
    return temp;
}

int* stockSpan(node*& top, int * arr, int n){

    if(n==0){
        return NULL;
    }

    int * result = new int[n+1];

    for(int i=0;i<n;i++){

        if(top == NULL){
            push(top,i);
            result[i] = 1;
        }

        else if(arr[i] < arr[seetop(top)]){
            //push
            int temp = seetop(top);
            push(top,i);
            result[i] = seetop(top) - temp;
        }

        else{
            //pop
            while(seetop(top) != -1 && arr[seetop(top)] < arr[i]){
                pop(top);
            }
            int temp = seetop(top);
            push(top,i);
            result[i] = seetop(top) - temp;
        }
    }
    return result;
}


int main(){

node* top = NULL;
int arr[100];
int n;
cout<<"How many stocks ?"<<endl;
cin>>n;
for(int i=0;i<n;i++){
    cout<<"Enter Price of stock on day "<<i<<" : ";
    cin>>arr[i];
}
int * stockSpanResultArray = stockSpan(top,arr,n);
printf("Stock span array is: ");
for(int i=0;i<n;i++){

    printf("%d ",stockSpanResultArray[i]);
}
return 0;
}
