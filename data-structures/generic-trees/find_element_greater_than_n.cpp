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

int findNodeGreaterThanN(treeNode* root, int n){
    if(root==NULL){
        return -1;
    }
    int result = INT_MAX;
    queue<treeNode*> q;
    q.push(root);
    while(!q.empty()){
        treeNode* temp = q.front();
        q.pop();
        if(temp->data > n && temp->data<result){
            result = temp->data;
        }
        for(int i=0;i<temp->childrenCount;i++){
            q.push(temp->children[i]);
        }
    }
    if(result == INT_MAX){
        return -1;
    }
    else{
        return result;
    }
}

int main(){

treeNode * root1 = NULL;
root1 = takeInputByOrder();
int n;
cout<<"Enter data : ";
cin>>n;
int result = findNodeGreaterThanN(root1,n);
if(result==-1){
    cout<<"Not found !"<<endl;
}
else{
    cout<<"Result is whose greater is to be found : "<<result<<endl;
}
return 0;
}
