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

bool checkIfTreesAreIdentical(binaryTreeNode* root1, binaryTreeNode* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }

    bool checkCurrentNode ;
    if(root1->data == root2->data){
        checkCurrentNode =true;
    }
    else{
        checkCurrentNode = false;
    }
    bool checkLeftNode = checkIfTreesAreIdentical(root1->left,root2->left);
    bool checkRightNode = checkIfTreesAreIdentical(root1->right,root2->right);
    return checkCurrentNode & checkLeftNode & checkRightNode;
}

int main(){
binaryTreeNode * root1 = NULL;
root1 = takeInputByLevel();
printPreOrder(root1);
cout<<endl;

binaryTreeNode * root2 = NULL;
root2 = takeInputByLevel();
printPreOrder(root2);
cout<<endl;

if(checkIfTreesAreIdentical(root1,root2)){
    cout<<"The given two trees are identical ! "<<endl;
}
else{
    cout<<"The given two trees are not identical !!"<<endl;
}
return 0;
}
