#include<bits/stdc++.h>
using namespace std;

class minHeap{
vector<int> arr;
private:
    void minHeapify(int pos){
        int leftChild = 2*pos+1;
        int rightChild = 2*pos+2;

        //both are in range
        if(leftChild < arr.size() && rightChild < arr.size()){
            if(arr[pos] <= arr[leftChild] && arr[pos] <= arr[rightChild]){
                return;
            }
            if(arr[leftChild] < arr[rightChild]){
                swap(arr[leftChild], arr[pos]);
                minHeapify(leftChild);
            }
            else{
                swap(arr[rightChild], arr[pos]);
                minHeapify(rightChild);
            }
        }
        //only left child is in range
        if(leftChild < arr.size()){
            if(arr[pos] <= arr[leftChild]){
                return;
            }
            else{
                swap(arr[leftChild], arr[pos]);
                minHeapify(leftChild);
            }
        }
        if(rightChild < arr.size()){
            if(arr[pos] <= arr[rightChild]){
                return;
            }
            else{
                swap(arr[rightChild], arr[pos]);
                minHeapify(rightChild);
            }
        }
        else{
            return;
        }
    }

public:

    void buidHeap(int* arr, int n){
        for(int i=0;i<n;i++){
            this->arr.push_back(arr[i]);
        }
        for(int i=n/2;i>=0;i--){
            minHeapify(i);
        }
    }

    int getMin(){
        return arr[0];
    }

    int deleteMin(){
        int save = arr[0];
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        minHeapify(0);
        return save;
    }

    void insertInHeap(int data){
        arr.push_back(data);
        int pos_of_new_element = arr.size()-1;
        int parent = (pos_of_new_element-1)/2;
        while(parent >= 0){
            if(arr[pos_of_new_element] < arr[parent]){
                swap(arr[pos_of_new_element], arr[parent]);
                pos_of_new_element = parent;
                parent = (parent-1)/2;
            }
            else{
                break;
            }
        }
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            printf("%d ",arr[i]);
        }
        cout<<endl;
    }

    bool isEmpty(){
        if(arr.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
int arr[] = {1,9,7,4,2,6};
minHeap m;
m.buidHeap(arr, 6);
m.print();
m.insertInHeap(0);
m.print();
cout<<"Heap Sort : ";
while(!m.isEmpty()){
    cout<<m.deleteMin()<<" ";
}
return 0;
}
