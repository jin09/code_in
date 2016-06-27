#include<bits/stdc++.h>
using namespace std;

class treenode{
public:
int data;
treenode ** children;
int children_count;
treenode(int data){
    this->data = data;
    children_count = 0;
    children = NULL;
}
};

treenode* takeInput(){
    int data;
    std::cout<<"Enter the node data : ";
    std::cin>>data;
    treenode* node = new treenode(data);
    int count;
    std::cout<<"Enter the children count for node "<<data<<" : ";
    std::cin>>count;
    node->children_count = count;
    node->children = new treenode*[count];
    for(int i=0;i<node->children_count;i++){
        node->children[i] = takeInput();
    }
    return node;
}

treenode* takeInputByOrder(){
    int data;
    std::cout<<"Enter root data : ";
    std::cin>>data;
    treenode* root = new treenode(data);
    std::queue< treenode*> q;
    q.push(root);
    while(!q.empty()){
        treenode* temp = q.front();
        q.pop();
        std::cout<<"Enter the children count for the node with data "<<temp->data<<" : ";
        int count;
        std::cin>>count;
        temp->children_count = count;
        temp->children = new treenode*[count];

        for(int i=0;i<count;i++){

            int d ;
            std::cout<<"Enter the data for "<<i<<"children of node "<<temp->data<<" : ";
            std::cin>>d;
            temp->children[i] = new treenode(d);
            q.push(temp->children[i]);
        }
    }
    return root;
}

void print(treenode* root){
    std::cout<<root->data<<" --> ";
    for(int i=0;i<root->children_count;i++){

        std::cout<<root->children[i]->data<<" --> ";
    }
    std::cout<<std::endl;
    for(int i=0;i<root->children_count;i++){
        print(root->children[i]);
    }
}

int height(treenode* root){

    if(root==NULL){
        return 0;
    }
    int maxHeight = 0;
    for(int i=0;i<root->children_count;i++){

        int h = height(root->children[i]);
        maxHeight = max(maxHeight,h+1);
    }
    return maxHeight;
}

int maxNodeData(treenode* root){
    if(root==NULL){
        return 0;
    }
    int maxNode = root->data;
    for(int i=0;i<root->children_count;i++){

        int maxi = maxNodeData(root->children[i]);
        maxNode = max(maxi,maxNode);
    }
    return maxNode;
}

int sumOfNodes(treenode* root){
    if(root==NULL){
        return 0;
    }
    int sum = root->data;
    for(int i=0;i<root->children_count;i++){
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}

void printAllElementsAtKDepth(treenode* root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){

        cout<<root->data<<" ";
        return ;
    }
    for(int i=0;i<root->children_count;i++){
        printAllElementsAtKDepth(root->children[i],k-1);
    }
}

int numberOfNodesGreaterThanX(treenode* root, int x){
    if(root==NULL){
        return 0;
    }
    int result = 0;
    if(root->data > x){
        result = 1;
    }
    int num=0;
    for(int i=0;i<root->children_count;i++){
        num = num + numberOfNodesGreaterThanX(root->children[i],x);
    }
    return num + result;
}

int main(){
    treenode * root = NULL;
    root = takeInputByOrder();
    print(root);
    int h = height(root);
    cout<<"Height of the tree is : "<<h<<endl;
    int maxNode = maxNodeData(root);
    cout<<"Max Node in tree is : "<<maxNode<<endl;
    int sum = sumOfNodes(root);
    cout<<"Sum of nodes is : "<<sum<<endl;
    printAllElementsAtKDepth(root,1);
    int num_of_nodes_greater_than_x = numberOfNodesGreaterThanX(root,3);
    cout<<"Number of nodes greater than X are : "<<num_of_nodes_greater_than_x<<endl;

    return 0;
}



