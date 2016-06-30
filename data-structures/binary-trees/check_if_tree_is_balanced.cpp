#include<bits/stdc++.h>
using namespace std;

class binaryTreeNode{
public:
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode(){
        if(left!=NULL)
            delete left;
        if(right!=NULL)
            delete right;
    }
};


binaryTreeNode* takeInputByLevel(){

    int data;
    cout<<"Enter data of the node : ";
    cin>>data;
    binaryTreeNode* root = new binaryTreeNode(data);

    queue<binaryTreeNode*> q;
    q.push(root);

    while(!q.empty()){
        binaryTreeNode* temp = q.front();
        q.pop();
        int leftData;
        int rightData;
        cout<<"Enter the left data of the node with value "<<temp->data<<" : ";
        cin>>leftData;
        if(leftData!=-1){
            temp->left = new binaryTreeNode(leftData);
            q.push(temp->left);
        }
        cout<<"Enter the right data of the node with value "<<temp->data<<" : ";
        cin>>rightData;
        if(rightData!=-1){
            temp->right = new binaryTreeNode(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

void printPreOrder(binaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<"-->";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

class hbpair{
public:
    int height;
    bool balanced;
    hbpair(){
        height = 0;
        balanced = false;
    }
};

hbpair checkIfTreeIsBalanced(binaryTreeNode* root){
    hbpair p;
    if(root==NULL){
        p.height = 0;
        return p;
    }
    hbpair left = checkIfTreeIsBalanced(root->left);
    hbpair right = checkIfTreeIsBalanced(root->right);

    p.height = max(left.height,right.height)+1;
    int balance = abs(left.height - right.height);
    if(balance<=1){
        p.balanced = true;
    }
    else{
        p.balanced = false;
    }
    return p;
}

int main(){
binaryTreeNode * root1 = NULL;
root1 = takeInputByLevel();
printPreOrder(root1);
cout<<endl;
hbpair p;
p = checkIfTreeIsBalanced(root1);
if(p.balanced){
    cout<<"The tree is balanced !! "<<endl;
}
else{
    cout<<"The tree is not balanced !!"<<endl;
}
return 0;
}
