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

void insertIntoBST(binaryTreeNode*& root, int data){
    if(root == NULL){
        root = new binaryTreeNode(data);
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if(data < root->data){
        insertIntoBST(root->left,data);
    }
    if(data > root->data){
        insertIntoBST(root->right,data);
    }
}


bool isBST(binaryTreeNode* root,int low, int high){
    if(root== NULL){
        return true;
    }
    if(root->data <=high && root->data>=low){

        bool ansfromleft = isBST(root->left,low,root->data);
        bool ansfromright = isBST(root->right,root->data,high);

        return ansfromleft & ansfromright;
    }
    else{
        return false;
    }
}

binaryTreeNode* buildBSTFromSortedArray(int * arr, int start, int end){
    if(start > end){
        return NULL;
    }

    int mid = (start + end) / 2;
    int data = arr[mid];
    binaryTreeNode* node = new binaryTreeNode(data);
    node->left = buildBSTFromSortedArray(arr,start,mid-1);
    node->right = buildBSTFromSortedArray(arr,mid+1,end);
    return node;
}

void printInRange(binaryTreeNode* root,int low, int high){
    if(root==NULL){
        return ;
    }
    if(root->data >low && root->data < high){
        cout<<root->data<<" ";
    }
    printInRange(root->left,low, high);
    printInRange(root->right,low, high);

}


int main(){

int arr[] = {1,2,3,4,5,6,7};
binaryTreeNode* root = buildBSTFromSortedArray(arr,0,6);
cout<<"Printing the Binary Search tree "<<endl<<endl;
printPretty(root,3,2,cout);
cout<<endl;
printInRange(root , 1,4);
cout<<endl<<endl;
cout<<"Create and print BST : "<<endl;
cout<<endl;
binaryTreeNode* bst = NULL;
insertIntoBST(bst,3);
insertIntoBST(bst ,7);
insertIntoBST(bst ,1);
insertIntoBST(bst,2);

//printPretty(bst,3,2,cout);
//cout<<endl;
if(isBST(bst,INT_MIN,INT_MAX)){
    printf("BST hai !!\n");
}
else{
    printf("BST nahin hai !! \n");
}
return 0;
}
