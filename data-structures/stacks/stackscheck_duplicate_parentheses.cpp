#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    node* next;
    node(char data){
        this->data = data;
        node* next = NULL;
    }
};

void push(node*& head, char data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
    return ;
}

char pop(node*& head){
    if(head==NULL){
        cout<<"Stack is empty !!"<<endl;
        return -1;
    }
    char temp = head->data;
    node* temporary = head;
    head = head->next;
    delete temporary;
    return temp;
}

bool checkForDuplicateParentheses(node*& head, char * arr){
    if(strlen(arr)==0){

        return true ;
    }
    int i=0;
    bool chars;

    while(i<strlen(arr)){
        chars = false;
        if(arr[i]!=')'){
            push(head,arr[i]);
        }
        else if(arr[i]==')'){

            char popped = pop(head);
            while(popped != -1 && popped != '('){
                    chars = true;
                    popped = pop(head);
                  }
            if(popped==-1){
                printf("Parentheses are not balanced !\n");
                return false;
            }
            if(!chars){
                printf("Duplicate parentheses found !\n");
                return false;
            }
        }
        i++;
    }
    printf("NO Duplicate parentheses found ! :)\n");
        return true;
}

int main(){

node* top = NULL;

printf("Enter string to check for balanced parentheses : ");
char arr[100];
scanf("%s",&arr);
bool result = checkForDuplicateParentheses(top,arr);
return 0;
}
