/*    Lowest common ancestor in the binary tree
      Optimised approach to solve the problem to traverse the tree and check if the value at 
      that point is equal to the value of the low or the high , if it is equal to the value of the low or the high then return
      the value of the node to the parent and if a parent gets the value of both left and right as low or high then that will be our 
      Lowest Common Ancestor
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

bool vectorOfPathFromRootToGivenNode(binaryTreeNode* root , int data, vector<int>& path){
    if(root == NULL){
        return false;
    }
    bool left = vectorOfPathFromRootToGivenNode(root->left,data,path);
    bool right = vectorOfPathFromRootToGivenNode(root->right,data,path);

    if(root->data == data){
        path.push_back(root->data);
        return true;
    }
    if(left | right){
        path.push_back(root->data);
        return true;
    }
    else{
        return false;
    }
}

int lowestCommonAncestorInBinaryTreeOptimised(binaryTreeNode* root, int low, int high){
    if(root == NULL){
        return -1;
    }
    if(root->data == low || root->data == high){
        return root->data;
    }
    int left = lowestCommonAncestorInBinaryTreeOptimised(root->left,low,high);
    int right = lowestCommonAncestorInBinaryTreeOptimised(root->right,low,high);
    //cases to optimize the recursive call
    if(left != low && left != high && left != -1){
        return left;
    }
    if(right != low && right != high && right != -1){
        return right;
    }
    //end of optimization cases
    if((left == low || left == high) && (right == low || right == high)){
        cout<<"The lowest common ancestor is : "<<root->data;
        return root->data;
    }
    if(left == -1 && right == -1){
        return -1;
    }
    if(left != -1){
        return left;
    }
    if(right != -1){
        return right;
    }
}

int main(){
binaryTreeNode* root = takeInputBylevel();
printPretty(root,3,4,cout);

int low,high;
cout<<"Enter the value of low : ";
cin>>low;
cout<<"Enter the value of high : ";
cin>>high;
cout<<"Lowest common ancestor in the binary tree is : "<<lowestCommonAncestorInBinaryTreeOptimised(root,low,high);

return 0;
}

