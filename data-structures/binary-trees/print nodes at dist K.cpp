/*   Given a tree and a node of tree, print all nodes which are at distance k from the given
     node.
     reference : http://algorithms.tutorialhorizon.com/print-all-the-nodes-which-are-x-distance-from-the-given-node/

     first print all the nodes down to the target node
     next keep finding the parent and reduce the value of k each time
     after parent is found then check that target node was to the left or to the right of the parent
     if target was to the left then print all down nodes in the right subtree of the parent
     else print all the down nodes in the left subtree of the parent

*/

#include<bits/stdc++.h>
using namespace std;

class BST;

class binaryTreeNode{
public:
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;
    binaryTreeNode* parent;

    binaryTreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   PRETTY PRINT   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

// Find the maximum height of the binary tree
int maxHeight(binaryTreeNode *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<binaryTreeNode*>& nodesQueue, ostream& out) {
  deque<binaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<binaryTreeNode*>& nodesQueue, ostream& out) {
  deque<binaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<binaryTreeNode*>& nodesQueue, ostream& out) {
  deque<binaryTreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(binaryTreeNode *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

  deque<binaryTreeNode*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      binaryTreeNode *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  END OF PRETTY PRINT   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

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



binaryTreeNode* findParent(binaryTreeNode* root, int targetNode){
    if(root == NULL){
        return NULL;
    }
    if(root->data == targetNode){
        return NULL;
    }
    if(root->left != NULL){
        if(root->left->data == targetNode){
            return root;
        }
    }
    if(root->right != NULL){
        if(root->right->data == targetNode){
            return root;
        }
    }

    binaryTreeNode* left = findParent(root->left,targetNode);
    binaryTreeNode* right = findParent(root->right,targetNode);
    if(left!=NULL){
        return left;
    }
    if(right!=NULL){
        return right;
    }
    else{
        return NULL;
    }
}

void printNodesDown(binaryTreeNode* root, int k){
    if(root == NULL){
        return;
    }
    if(k==0){
        printf("%d ",root->data);
    }
    printNodesDown(root->left,k-1);
    printNodesDown(root->right,k-1);
}

binaryTreeNode* searchNodeInTree(binaryTreeNode* root , int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data == data){
        return root;
    }
    binaryTreeNode* left = searchNodeInTree(root->left,data);
    binaryTreeNode* right = searchNodeInTree(root->right,data);
    if(left!= NULL){
        return left;
    }
    if(right!=NULL){
        return right;
    }
    else{
        return NULL;
    }
}

void printNodesAtDistanceK(binaryTreeNode* root ,int targetNodeData, int k){
    //first search the tree
    if(root == NULL){
        return;
    }
    //searching..
    binaryTreeNode* target = searchNodeInTree(root,targetNodeData);
    if(target == NULL){
        cout<<"Data not Found !! ";
        return ;
    }
    //printing type 1 nodes ..
    printNodesDown(target,k);
    //printing type 2 nodes ..
    binaryTreeNode* parent = findParent(root,target->data);
    while(parent != NULL && k != -1){
        k--;
        if(parent->right == target){
            //dont print nodes from this branch
            printNodesDown(parent->left,k-1);
        }
        else{
            //dont print nodes in left branch
            printNodesDown(parent->right,k-1);
        }
        target = parent;
        parent = findParent(root,parent->data);
    }
}

int main(){
binaryTreeNode* root = takeInputBylevel();
printPretty(root,1,2,cout);
int targetdata,k;
cout<<"Enter target node data : ";
cin>>targetdata;
cout<<"Enter the value of k : ";
cin>>k;
cout<<"Printing the nodes with at distance k : ";
printNodesAtDistanceK(root,targetdata,k);
return 0;
}

