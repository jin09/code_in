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

void printPreorder(treenode* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<"-->";
    for(int i=0;i<root->children_count;i++){
        printPreorder(root->children[i]);
    }
}

void printPostorder(treenode* root){
    if(root==NULL){

        return ;
    }
    for(int i=0;i<root->children_count;i++){

        printPostorder(root->children[i]);
    }
    cout<<root->data<<"-->";
}

int main(){
    treenode * root = NULL;
    root = takeInputByOrder();
    print(root);
    cout<<"Preorder traversal is : ";
    printPreorder(root);
    cout<<endl;
    cout<<"Postorder traversal is : ";
    printPostorder(root);
    cout<<endl;
    return 0;
}
