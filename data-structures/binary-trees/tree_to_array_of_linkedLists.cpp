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

class linkedList{
public:
    binaryTreeNode* head;
    binaryTreeNode* tail;

    linkedList(){
        head = NULL;
        tail = NULL;
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

void binaryTreeToArrayOfLinkedListsHelper(binaryTreeNode* root, linkedList**& ll, int depth){
    if(root==NULL){
        return ;
    }

    //save the left and right pointers of the root node as the node
    //itself will be used up and appended to some or the other linkedList
    binaryTreeNode* saveLeft = root->left;
    binaryTreeNode* saveRight = root->right;

    //check if insert at head
    if(ll[depth]->head == NULL){
        //insert at head
        ll[depth]->head = root;
        ll[depth]->head->left = NULL;
        ll[depth]->head->right = NULL;
        ll[depth]->tail = root;
    }
    else{
            //insert at tail
        ll[depth]->tail->right = root;
        binaryTreeNode* temp = ll[depth]->tail;
        ll[depth]->tail = ll[depth]->tail->right;
        ll[depth]->tail->left = temp;
        ll[depth]->tail->right = NULL;
    }

    //recursive calls to left and right node of the root
    binaryTreeToArrayOfLinkedListsHelper(saveLeft,ll,depth+1);
    binaryTreeToArrayOfLinkedListsHelper(saveRight,ll,depth+1);
}

linkedList** binaryTreeToArrayOfLinkedLists(binaryTreeNode* root){
    if(root == NULL){
        return NULL;
    }
    int height = checkIfTreeIsBalanced(root).height;
    linkedList** ll = new linkedList*[height];
    for(int i=0;i<height;i++){
        ll[i] = new linkedList();
    }
    binaryTreeToArrayOfLinkedListsHelper(root, ll, 0);
    return ll;
}

void printLinkedList(binaryTreeNode* head){
    if(head == NULL){
        return ;
    }
    printf("%d-->",head->data);
    printLinkedList(head->right);
}

int main(){

binaryTreeNode * root1 = NULL;
root1 = takeInputByLevel();
printPreOrder(root1);
cout<<endl;
int height = checkIfTreeIsBalanced(root1).height;
cout<<"Converting the binary tree to an array of linked lists .. .. "<<endl;
linkedList** result = binaryTreeToArrayOfLinkedLists(root1);
cout<<"Printing sll the linkedLists that are formed ... ... ..."<<endl<<endl<<endl;
for(int i=0;i<height;i++){
    printLinkedList(result[i]->head);
    cout<<endl;
}
cout<<endl<<endl<<endl;
return 0;
}
