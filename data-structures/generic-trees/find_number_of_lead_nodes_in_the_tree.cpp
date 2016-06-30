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
        if(counter>0){
        temp->children = new treeNode*[counter];
        }
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

int findNumberOfLeafNodes(treeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->children == NULL){
        return 1;
    }
    int sum =0;
    for(int i=0;i<root->childrenCount;i++){
        sum = sum + findNumberOfLeafNodes(root->children[i]);
    }
    return sum;
}

int main(){

treeNode * root1 = NULL;
root1 = takeInputByOrder();
int numberOfLeafNodes = findNumberOfLeafNodes(root1);
cout<<"Number of leaf nodes in the tree are : "<<numberOfLeafNodes<<endl;
return 0;
}
