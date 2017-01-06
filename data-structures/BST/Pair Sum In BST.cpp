#include<bits/stdc++.h>
using namespace std;

// Following is the Binary Tree node structure
/**************
class binaryTreeNode {
    public :
    T data;
    binaryTreeNode<T> *left;
    binaryTreeNode<T> *right;

    binaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
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

class ll{
    public:
    binaryTreeNode *head;
    binaryTreeNode *tail;
};

ll treetoll(binaryTreeNode *root){
    if(root == NULL){
        ll a;
        a.head = NULL;
        a.tail = NULL;
        return a;
    }
    //cout<<root->data<<" ";
    ll left = treetoll(root->left);
    ll right = treetoll(root->right);

    ll current;

    if(left.head == NULL){
        current.head = root;
        current.head->left = NULL;
        current.tail = root;
        current.tail->right = NULL;
    }
    else{
        current.head = left.head;
        current.head->left = NULL;
        current.tail = left.tail;
        root->left = current.tail;
        current.tail->right = root;
        current.tail = current.tail->right;
        current.tail->right = NULL;
    }
    if(right.head == NULL){
        return current;
    }
    else{
        right.head->left = current.tail;
        current.tail->right = right.head;
        current.tail = right.tail;
        current.tail->right = NULL;
        return current;
    }
}

void printll(binaryTreeNode *root){
    while(root!=NULL){
        cout<<root->data<<" ";
        root = root->right;
    }
    cout<<endl;
    return;
}


void printNodesSumToS(binaryTreeNode *root, int s) {
    ll res = treetoll(root);
    printll(res.head);
    binaryTreeNode* first = res.head;
    binaryTreeNode* last = res.tail;

    while(first != last){
        int current = first->data + last->data;
        if(current == s){
            cout<<first->data<<" "<<last->data<<endl;
            first = first->right;
        }
        else if(current > s){
            last = last->left;
        }
        else{
            first = first->right;
        }

    }
}


int main(){

binaryTreeNode* root = NULL;
root = takeInputBylevel();
int s;
cin>>s;
printNodesSumToS(root, s);
return 0;
}
