#include<bits/stdc++.h>
using namespace std;

class BST;

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

    friend class BST;
};

class BST{

    binaryTreeNode* root;

private:
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       INTERNAL WORKING OF THE BEAUTIFUL PRINT        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


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

public:


  /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     CONSTRUCTOR      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    BST(){
        root = NULL;
    }


  /*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     INSERT TO BST      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
    void insertToBSTHelper(binaryTreeNode*& root, int data){
        if(root == NULL){
            root = new binaryTreeNode(data);
            return ;
        }
        if(data < root->data){
            insertToBSTHelper(root->left,data);
        }
        else{
            insertToBSTHelper(root->right, data);
        }
    }

    void insertToBST(int data){

        if(root == NULL){
            root = new binaryTreeNode(data);
            return ;
        }
        if(data < root->data){
            insertToBSTHelper(root->left, data);
        }
        if(data > root->data){
            insertToBSTHelper(root->right, data);
        }
    }

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        BEAUTIFUL PRINT       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


    void beautifulPrint(){

    printPretty(root,4,3,cout);

    }
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        SEARCH IN THE BST       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    bool searchInBSTHelper(binaryTreeNode* temp , int data){
        if(temp == NULL){
            return false;
        }
        if(data == temp->data){
            return true;
        }
        if(data > temp->data){
            return searchInBSTHelper(temp->right,data);
        }
        else{
            return searchInBSTHelper(temp->left,data);
        }
    }

    bool searchInBST(int data){

        binaryTreeNode* temp = root;

        if(root == NULL){
            return false;
        }

        return searchInBSTHelper(temp , data);
    }

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       IS EMPTY      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    bool isEmpty(){
        if(root == NULL){
            return true;
        }
        else{
            return false;
        }
    }


/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       RETURN MIN DATA     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    int minInBSTData(binaryTreeNode* root){
        if(root == NULL){
            return -1;
        }
        if(root->left == NULL){
            return root->data;
        }
        else{
            return minInBSTData(root->left);
        }
    }

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       PRINT PREORDER     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

void printPreorderHelper(binaryTreeNode* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<"-->";
    printPreorderHelper(root->left);
    printPreorderHelper(root->right);
}

void printPreorder(){
    binaryTreeNode* temp = this->root;
    printPreorderHelper(temp);
    return ;
}

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       RETURN NODE WITH MIN DATA     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/
    binaryTreeNode* minInBSTNode(binaryTreeNode* root){
        if(root == NULL){
            return root;
        }
        if(root->left == NULL){
            return root;
        }
        else{
            return minInBSTNode(root->left);
        }
    }
/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       RETURN NODE WITH MAX DATA     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    binaryTreeNode* maxInBSTNode(binaryTreeNode* root){
        if(root==NULL){
            return root;
        }
        if(root->right == NULL){
            return root;
        }
        else{
            return maxInBSTNode(root->right);
        }
    }

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       RETURN MAX DATA     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    int maxInBSTData(binaryTreeNode* root){
        if(root == NULL){
            return -1;
        }
        if(root->right == NULL){
            return root->data;
        }
        else{
            return maxInBSTData(root->right);
        }

    }

/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      DELETE IN BST       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

    // search the element
    // delete case 1 : no child
    //case 2 : 1 child
    // case 3 : 2 children


    //i have not handled the case where the data to be found does not exists
    binaryTreeNode* findParentOfNodeHelper(binaryTreeNode* root , int data){

        if(data <= root->data)
        {
            if(root->left->data == data){
                    if(searchInBSTHelper(root->left->left,data)){
                        return findParentOfNodeHelper(root->left,data);
                    }
                    if(searchInBSTHelper(root->left->right,data)){
                        return findParentOfNodeHelper(root->left,data);
                    }
                    else{
                        return root;
                    }
            }
        }
        if(data >= root->data){

            if(root->right->data == data){
                if(searchInBSTHelper(root->right->left,data)){
                       return findParentOfNodeHelper(root->right,data);
                }
                if(searchInBSTHelper(root->right->right,data)){
                       return findParentOfNodeHelper(root->right,data);
                }
                else{
                return root;
                }
            }
        }
        else{
            if(data < root->data){
                return findParentOfNodeHelper(root->left, data);
            }
            else{
                return findParentOfNodeHelper(root->right ,data);
            }
        }
    }

    binaryTreeNode* findParentOfNode(int data){
        if(data == this->root->data){
            binaryTreeNode* temp = root;

            if(searchInBSTHelper(temp->left,data)){
                    return findParentOfNodeHelper(temp->left,data);
                }
            if(searchInBSTHelper(temp->right,data)){
                    return findParentOfNodeHelper(temp->right,data);
                }
            else{
                    return NULL;
                }
        }
        binaryTreeNode* temp = this->root;
        return findParentOfNodeHelper(temp,data);
    }


    void deleteDataFromBSTCases(binaryTreeNode* root){
        //case 1 : no child (leaf node)
        if(root->left==NULL && root->right==NULL){
            if(root == this->root){
                delete root;
                this->root = NULL;
                return;
            }
            else{
                binaryTreeNode* parent = findParentOfNode(root->data);
                if(parent->left->data == root->data){
                    parent->left = NULL;
                }
                else{
                    parent->right = NULL;
                }
                delete root;
                return;
            }
        }

        //case 2 : 1 child

        if(root->left == NULL || root->right == NULL){
            //find its parent node
            binaryTreeNode* parent = findParentOfNode(root->data);

            //we again have 2 possibilities :
             //parent is NULL (the current node to be deleted is the root node)
             //parent is not NULL

             //case : 2.1 = parent is null
             if(parent == NULL){
                //save the child of root node
                binaryTreeNode* childOfNodeToBeDeleted;
                if(root->left == NULL){
                    childOfNodeToBeDeleted = root->right;
                }
                else{
                    childOfNodeToBeDeleted = root->left;
                }
                delete root;
                this->root = childOfNodeToBeDeleted;
                return ;
             }

             //case 2.2 = parent is not null

             else{
                binaryTreeNode* childOfNodeToBeDeleted ;
                if(root->left == NULL){
                    childOfNodeToBeDeleted = root->right;
                }
                else{
                    childOfNodeToBeDeleted = root->left;
                }
                if(parent->left->data == root->data){
                    delete root;
                    parent->left = childOfNodeToBeDeleted;
                    return ;
                }
                else{
                    delete root;
                    parent->right = childOfNodeToBeDeleted;
                    return ;
                }
             }
        }

        //case 3 : node to be deleted has 2 children
        if(root->left!=NULL && root->right!=NULL){

                binaryTreeNode* minInRightSubtree = minInBSTNode(root->right);
                root->data = minInRightSubtree->data;
                deleteDataFromBSTCases(minInRightSubtree);
                return ;
        }
    }

    //this is the search function of the delete
    bool deleteDataFromBSTHelper(binaryTreeNode* root,int data){
        if(root == NULL){
            return false;
        }
        if(root->data == data){
            //Element found
            //this node must be deleted
            deleteDataFromBSTCases(root);
            return true;
        }
        if(data < root->data){
            return deleteDataFromBSTHelper(root->left, data);
        }
        else{
            return deleteDataFromBSTHelper(root->right, data);
        }
    }

    bool deleteDataFromBST(int data){
        binaryTreeNode* temp = root;
        return deleteDataFromBSTHelper(temp, data);
    }

};


int main(){
BST b;
b.insertToBST(3);
b.insertToBST(7);
b.insertToBST(1);
b.insertToBST(9);
b.insertToBST(6);
b.insertToBST(2);
b.beautifulPrint();
b.deleteDataFromBST(1);
b.beautifulPrint();
b.deleteDataFromBST(3);
b.beautifulPrint();
if(b.searchInBST(3)){
    printf("element was found !");
}
else{
    printf("Element was not found !");
}
return 0;
}
