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
    ~BinaryTreeNode(){
		if(left!=NULL)
			delete left;
		if(right!=NULL)
			delete right;
	}
};

binaryTreeNode* takeInputBylevel(){

binaryTreeNode* root = NULL;
int data;
cout<<"Enter the root data: ";
cin>>data;
root = new binaryTreeNode(data);
queue<binaryTreeNode*> q;
q.push(root);
while(!q.empty()){

    binaryTreeNode* temp = q.front();
    q.pop();
    cout<<"Enter the left node data of the node with data "<<temp->data<<" : ";
    int d;
    cin>>d;
    if(d != -1){
        temp->left = new binaryTreeNode(d);
        q.push(temp->left);
    }
    cout<<"Enter the right node data of the node with data "<<temp->data<<" : ";
    cin>>d;
    if(d != -1){
        temp->right = new binaryTreeNode(d);
        q.push(temp->right);
    }
}
return root;
}

void printLevelOrder(binaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    queue<binaryTreeNode*> q;
    q.push(root);
    while(!q.empty()){
        binaryTreeNode* temp = q.front();
        q.pop();
        cout<<temp->data<<"-->";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

void printPreOrder(binaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<"->";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(binaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<"->";
}

void printInOrder(binaryTreeNode* root){
    if(root==NULL){
        return ;
    }
    printInOrder(root->left);
    cout<<root->data<<"->";
    printInOrder(root->right);
}

int numberOfNodes(binaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left;
    int right;
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    left =  numberOfNodes(root->left);
    right = numberOfNodes(root->right);

    return left + right +1;
}

int height(binaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight,rightHeight)+1;
}

int lengthOfDiameterOfBinaryTree(binaryTreeNode* root){                            //not optimized ... complexity is high
    if(root==NULL){
        return 0;
    }

    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    int left_dia = lengthOfDiameterOfBinaryTree(root->left);
    int right_dia = lengthOfDiameterOfBinaryTree(root->right);

    return max(leftHeight+rightHeight+1,max(left_dia,right_dia));
}

class hdpair{
public:
    int height;
    int diameter;
    hdpair(){
        height = 0;

    }
};

hdpair lengthOfDiameterOfBinaryTreeOptimized(binaryTreeNode* root){

    hdpair p;
    if(root==NULL){
        p.diameter=0;
        p.height=0;
        return p;
    }

    hdpair left = lengthOfDiameterOfBinaryTreeOptimized(root->left);
    hdpair right = lengthOfDiameterOfBinaryTreeOptimized(root->right);

    p.diameter = max(left.height + right.height + 1, max(left.diameter,right.diameter));
    p.height = max(left.height,right.height)+1;

    return p;

}

binaryTreeNode* findNode(binaryTreeNode* root, int key){
    if(root == NULL){
        return root;
    }
    if(root->data==key){
        return root;
    }
    binaryTreeNode* temp = findNode(root->left,key);
    if(temp!=NULL){
        return temp;
    }
    temp = findNode(root->right,key);
    return temp;
}

void mirror(binaryTreeNode*& root){
    if(root==NULL){
        return ;
    }
    mirror(root->left);
    mirror(root->right);

    binaryTreeNode* tempLeft = root->left;
    binaryTreeNode* tempright = root->right;

    root->left =NULL;
    root->right =NULL;

    root->left = tempright;
    root->right = tempLeft;
}

int main(){

binaryTreeNode* root = NULL;
root = takeInputBylevel();
cout<<"Level order traversal : ";
printLevelOrder(root);
cout<<endl;
cout<<"Pre order traversal : ";
printPreOrder(root);
cout<<endl;
cout<<"In order traversal : ";
printInOrder(root);
cout<<endl;
cout<<"Post order traversal : ";
printPostOrder(root);
cout<<endl;
cout<<"Number of nodes in the tree are : "<<numberOfNodes(root)<<endl;
cout<<"Height of the tree is : "<<height(root)<<endl;
cout<<"Length of diameter of binary tree is : "<<lengthOfDiameterOfBinaryTree(root)<<endl;
cout<<"Length of diameter (optimized) of binary tree is : "<<lengthOfDiameterOfBinaryTreeOptimized(root).diameter<<endl;
cout<<"Height of the tree (hdpair) is : "<<lengthOfDiameterOfBinaryTreeOptimized(root).height<<endl;
binaryTreeNode* found = findNode(root,3);
cout<<found->data;
mirror(root);
cout<<"Mirroring..... Printing tree after mirroring Level Order traversal : "<<endl;
printLevelOrder(root);
return 0;
}
