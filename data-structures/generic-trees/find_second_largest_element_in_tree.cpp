#include<bits/stdc++.h>
using namespace std;

class treeNode{
public:
    int data;
    int childrenCount;
    treeNode** children;

    treeNode(int data){
        this->data = data;
        childrenCount =0;
        children=NULL;
    }

    ~treeNode(){
        cout<<"Deleting node with data "<<data<<" and its children"<<endl;
        for(int i=0;i<childrenCount;i++){
            delete children[i];
        }
        delete [] children;
    }
};

treeNode* takeInputByOrder(){
    cout<<"Enter node data : ";
    int data;
    cin>>data;
    treeNode* root = new treeNode(data);
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode * temp = q.front();
        q.pop();
        int counter;
        cout<<"Enter the no of children of node with data "<<temp->data<<" : ";
        cin>>counter;
        temp->childrenCount = counter;
        temp->children = new treeNode*[counter];
        for(int i=0;i<temp->childrenCount;i++){
            cout<<"Enter node data : ";
            int d;
            cin>>d;
            temp->children[i] = new treeNode(d);
            q.push(temp->children[i]);
        }
    }
    return root;
}

void printLevelOrder(treeNode* root){
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode* temp = q.front();
        q.pop();
        printf("%d-->",temp->data);
        for(int i=0;i<temp->childrenCount;i++){
            if(temp->children[i]!=NULL){
                q.push(temp->children[i]);
            }
        }
    }
}

int findSecondLargestValue(treeNode* root){
    //no node in the tree
    if(root==NULL){
        return -1;
    }
    //only 1 element in the tree
    if(root->childrenCount==0){
        return -1;
    }
    int largest =-1;
    int secondLargest = -1;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode* temp = q.front();
        q.pop();
        if(temp->data > largest){
            secondLargest = largest;
            largest = temp->data;
        }
        else if(temp->data > secondLargest){
            secondLargest = temp->data;
        }
        for(int i=0;i<temp->childrenCount;i++){
            if(root->children[i]!=NULL){
                q.push(root->children[i]);
            }
        }
    }
    return secondLargest;
}

int main(){

treeNode * root1 = NULL;
root1 = takeInputByOrder();
int secondLargestIntree = findSecondLargestValue(root1);
if(secondLargestIntree != -1){
printf("Second Largest element in the tree is %d\n",secondLargestIntree);
}
else{
    cout<<"There is no second largest element in the tree !!";
}
return 0;
}
