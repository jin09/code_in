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

bool checkIfTreesAreSame(treeNode* root1,treeNode* root2){
    if(root1==NULL){
        if(root2==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    if(root2==NULL){
        if(root1==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    if(root1->data != root2->data){
        return false;
    }
    if(root1->childrenCount != root2->childrenCount){
        return false;
    }
    for(int i=0;i<root1->childrenCount;i++){
        bool ansFromFuture = checkIfTreesAreSame(root1->children[i],root2->children[i]);
        if(ansFromFuture==false){
            return false;
        }
    }
    return true;
}

int main(){

treeNode * root1 = NULL;
root1 = takeInputByOrder();
printLevelOrder(root1);
treeNode* root2 = takeInputByOrder();
printLevelOrder(root2);
if(checkIfTreesAreSame(root1,root2)){
    cout<<"Trees are identical !"<<endl;
}
else{
    cout<<"Trees are not identical !!"<<endl;
}
return 0;
}
