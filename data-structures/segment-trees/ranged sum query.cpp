/**
* SEGMENT TREES RANGED SUM QUERY
*/

#include<bits/stdc++.h>
using namespace std;


int findSizeOfSegmentTree(int n){

    //Height of segment tree
    int x = (int)(ceil(log2(n)));

    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1;

    return max_size;

}

void insertIntoSegTree(int* input, int* segTree, int low, int high, int pos){
    if(low == high){
        segTree[pos] = input[low];
        return;
    }

    int mid = (low+high)/2;
    insertIntoSegTree(input,segTree,low,mid,2*pos + 1);
    insertIntoSegTree(input,segTree,mid+1,high,2*pos + 2);
    segTree[pos] = segTree[(2*pos)+1] + segTree[(2*pos)+2];
}

int* createSegmentTree(int* input, int n){
    //find the size of seg tree
    int segSize = findSizeOfSegmentTree(n);
    //make tree
    int* segTree = new int[segSize];
    for(int i=0;i<segSize;i++){
        segTree[i] = 0;
    }

    insertIntoSegTree(input,segTree,0,n-1,0);

    return segTree;
}

int rangeSumQuery(int* segTree, int segTreeLow, int segTreeHigh, int findLow, int findHigh, int pos){

    /**Total Overlap*/
    if(segTreeLow>=findLow && segTreeHigh<=findHigh){
        return segTree[pos];
    }
    /**No OverLap*/
    if(segTreeHigh < findLow || segTreeLow > findHigh){
        return 0;
    }
    /**Partial Overlap*/
    int mid = (segTreeLow + segTreeHigh)/2;

    int left = rangeSumQuery(segTree,segTreeLow,mid,findLow,findHigh,(2*pos)+1);
    int right = rangeSumQuery(segTree,mid+1,segTreeHigh,findLow,findHigh,(2*pos)+2);

    return left + right;

}

void updateValueInRange(int* segTree, int segTreeLow, int segTreeHigh, int updateLow, int updateHigh, int updateValue, int pos){
    /**
    * Partial Overlap : Go in both the directions
    * Total Overlap : Go in both direction till you reach the leaf node (segTreeLow == segTreeHigh)
    * No Overlap : Return without doing anything
    */

    //No Overlap
    if(segTreeHigh < updateLow || segTreeLow > updateHigh){
        return;
    }
    //Leaf node is reached
    if(segTreeLow == segTreeHigh){
        segTree[pos] = segTree[pos] + updateValue;
        return ;
    }
    // partial Overlap OR Total ovrelap

    /**DIVIDING STEP*/

    int mid = (segTreeHigh + segTreeLow)/2;
    updateValueInRange(segTree,segTreeLow,mid,updateLow,updateHigh,updateValue,(2*pos)+1);
    updateValueInRange(segTree,mid + 1,segTreeHigh,updateLow,updateHigh,updateValue,(2*pos)+2);

    /**CONQUOR STEP*/

    segTree[pos] = segTree[(2*pos)+1] + segTree[(2*pos)+2];
}

int main(){
int arr[] = {-1,3,4,0,2,1};
int n = sizeof arr/sizeof arr[0];
int* segTree = createSegmentTree(arr,n);
int segSize= findSizeOfSegmentTree(n);

for(int i=0;i<segSize;i++){
    cout<<segTree[i]<<" ";
}
cout<<endl;

cout<<"Sum in range 2 to 4 is "<<rangeSumQuery(segTree,0,n-1,2,4,0)<<endl;

cout<<"Sum in range 0 to 4 is "<<rangeSumQuery(segTree,0,n-1,0,4,0)<<endl;

cout<<"Adding 3 to the nodes in range 2 to 4.... "<<endl;

updateValueInRange(segTree,0,n-1,2,4,3,0);

cout<<"Sum in range 2 to 4 after updation is "<<rangeSumQuery(segTree,0,n-1,2,4,0)<<endl;

cout<<"Sum in range 0 to 4 after updation is "<<rangeSumQuery(segTree,0,n-1,0,4,0)<<endl;

return 0;
}
