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
    segTree[pos] = min(segTree[(2*pos)+1],segTree[(2*pos)+2]);
}

int* createSegmentTree(int* input, int n){
    //find the size of seg tree
    int segSize = findSizeOfSegmentTree(n);
    //make tree
    int* segTree = new int[segSize];
    for(int i=0;i<segSize;i++){
        segTree[i] = INT_MAX;
    }

    insertIntoSegTree(input,segTree,0,n-1,0);

    return segTree;
}

int rangeMinQuery(int* segTree, int segTreeLow, int segTreeHigh, int findLow, int findHigh, int pos){

    /**Total Overlap*/
    if(segTreeLow>=findLow && segTreeHigh<=findHigh){
        return segTree[pos];
    }
    /**No OverLap*/
    if(segTreeHigh < findLow || segTreeLow > findHigh){
        return INT_MAX;
    }
    /**Partial Overlap*/
    int mid = (segTreeLow + segTreeHigh)/2;

    int left = rangeMinQuery(segTree,segTreeLow,mid,findLow,findHigh,(2*pos)+1);
    int right = rangeMinQuery(segTree,mid+1,segTreeHigh,findLow,findHigh,(2*pos)+2);

    return min(left,right);

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

cout<<"Min in range 2 to 4 is "<<rangeMinQuery(segTree,0,n-1,2,4,0)<<endl;

cout<<"Min in range 0 to 4 is "<<rangeMinQuery(segTree,0,n-1,0,4,0)<<endl;
return 0;
}
