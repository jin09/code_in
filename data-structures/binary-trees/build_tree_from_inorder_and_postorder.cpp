
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


//refer your nb

//start and end indexes are for the inorder array
binaryTreeNode* buildTreeFromInorderAndPostorder(int * postorder, int * inorder, int &post_end, int in_start,int in_end){
    if(post_end < 0){
        return NULL;
    }
    if(in_start > in_end){
        return NULL;
    }
    int data = postorder[post_end];
    //cout<<data<<endl;
    binaryTreeNode* node = new binaryTreeNode(data);
    int save_pos = 0;
    for(int i=in_start;i<=in_end;i++){
        if(inorder[i] == data){
            save_pos = i;
            break;
        }
    }
    //cout<<"save pos "<<save_pos<<endl;
    post_end--;
    node->right = buildTreeFromInorderAndPostorder(postorder, inorder, post_end, save_pos+1, in_end);
    node->left = buildTreeFromInorderAndPostorder(postorder, inorder, post_end, in_start, save_pos-1);
    return node;
}

int main(){

int postorder[] = {10,40,30,60,90,70,50};
int inorder[] = {10,30,40,50,60,70,90};
int postend = 6;
binaryTreeNode* root = buildTreeFromInorderAndPostorder(postorder,inorder,postend,0,6);
cout<<"Built tree from inorder and postorder is "<<endl<<endl;
printPretty(root, 4, 3, cout);
return 0;
}
