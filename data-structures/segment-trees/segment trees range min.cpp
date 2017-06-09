#include <bits/stdc++.h>
using namespace std;

void buildTree(int arr[], int *tree, int index, int start, int end){
    ///leaf node exceeded
    if(start > end){
        return;
    }

    ///leaf node reached
    if(start == end){
        tree[index] = arr[start];
        return;
    }

    ///go to left child and change range to start to mid
    buildTree(arr, tree, 2*index+1, start, (start+end)/2);

    ///go to right child and change range to mid+1 to end
    buildTree(arr, tree, 2*index+2, ((start+end)/2)+1, end);

    ///current node answer is min of left and right child
    tree[index] = min(tree[2*index+1], tree[2*index+2]);

    return;
}


int query(int* tree, int current_index, int s, int e, int qs, int qe){
    /**
    3 CASES :
        Case 1 :
            No Overlap
        Case 2 :
            Complete Overlap
        Case 3 :
            Partial Overlap
    */

    ///NO OVERLAP
    if(s > qe || e < qs){
        return INT_MAX;
    }
    ///COMPLETE OVERLAP
    if(s>=qs && e<=qe){
        return tree[current_index];
    }
    ///PARTIAL OVERLAP
    else{
        int left = query(tree, 2*current_index+1, s, (s+e)/2, qs, qe);
        int right = query(tree, 2*current_index+2, ((s+e)/2)+1, e, qs, qe);
        return min(left, right);
    }
}


void updateNode(int* tree, int start, int end, int current_index, int i, int value){
    ///NO OVERLAP
    if(i < start || i > end){
        return;
    }
    ///LEAF NODE HAS BEEN REACHED AND THAT LEAF NODE IS THE NODE THAT HAS TO BE CHANGED
    if(start == end && start == i){
        tree[current_index] = value;
        return;
    }
    ///UPDATE LEFT AND RIGHT RECURSIVELY
    updateNode(tree, start, (start+end)/2, 2*current_index+1, i, value);
    updateNode(tree, ((start+end)/2)+1, end, 2*current_index+2, i, value);
    tree[current_index] = min(tree[2*current_index+1], tree[2*current_index+2]);
    return;
}

void rangeUpdate(int* tree, int current_index, int s, int e, int rs, int re, int inc){
    ///limit crossed
    if(s > e){
        return;
    }
    ///no overlap
    if(e < rs || s > re){
        return;
    }
    ///leaf node has been reached and leaf node in range of query
    if(s == e && s >= rs && e <= re){
        tree[s] += inc;
        return;
    }
    ///recursively update the left and right
    rangeUpdate(tree, 2*current_index+1, s, (s+e)/2, rs, re, inc);
    rangeUpdate(tree, 2*current_index+2, ((s+e)/2)+1, e, rs, re, inc);
    tree[current_index] = min(tree[2*current_index+1], tree[2*current_index+2]);
    return;
}

int main(){
    int arr[] = {1,3,2,-2,4,5};
    int n = sizeof arr/sizeof arr[0];

    int * tree = new int[4*n+1];
    buildTree(arr, tree, 0, 0, n-1);

    /**
    for(int i=0;i<4*n+1;i++){
        cout<<tree[i]<<" ";
    }
    */

    cout<<query(tree, 0, 0, n-1, 2, 4)<<endl;
    updateNode(tree, 0, n-1, 0, 3, 0);
    cout<<query(tree, 0, 0, n-1, 2, 4)<<endl;
    rangeUpdate(tree, 0, 0, n-1, 1, 3, 5);
    cout<<query(tree, 0, 0, n-1, 0, 2)<<endl;
    return 0;
}
