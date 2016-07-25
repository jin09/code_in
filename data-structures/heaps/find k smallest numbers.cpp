/*  Find minimum K numbers
Given an array find minimum K Numbers
*/

#include<bits/stdc++.h>
using namespace std;

class priorityQueueMin{

    vector <int> arr;
    int index;
    int currentSize;
private:

    void heapify(int i){
        int leftChild = (2*i)+1;
        int rightChild = (2*i)+2;
        //both the children are in range
        if(leftChild<currentSize && rightChild<currentSize){
            if(arr[leftChild]<arr[i]){
                swap(arr[i],arr[leftChild]);
                heapify(leftChild);
            }
            else if(arr[rightChild]<arr[i]){
                swap(arr[i],arr[rightChild]);
                heapify(rightChild);
            }
            else{
                return ;
            }
        }
        //only left child is in range
        if(leftChild<currentSize){
            if(arr[leftChild]<arr[i]){
                swap(arr[i],arr[leftChild]);
                heapify(leftChild);
            }
        }
        //only right child is in range
        if(rightChild<currentSize){
            if(arr[rightChild]<arr[i]){
                swap(arr[i],arr[rightChild]);
                heapify(rightChild);
            }
            else{
                return;
            }
        }
        //none of the children are in range
        else{
            return;
        }
    }

public:
    priorityQueueMin(){
        index =0 ;
        currentSize = 0;
    }
    //creates a heap in order O(NlogN)
    void insertIntoHeap(int data){
        arr.push_back(data);
        int currentIndexOfData = index;
        index++;
        currentSize++;
        int parent = (currentIndexOfData-1)/2;
        while(parent>=0){
            if(arr[parent] <= arr[currentIndexOfData]){
                break;
            }
            else{
                swap(arr[currentIndexOfData],arr[parent]);
                currentIndexOfData = parent;
                parent = (currentIndexOfData-1)/2;
            }
        }
    }
    //creates a heap in order O(N)
    //copy elements to the vector
    //then set the index and currentSize
    //now call heapify on vector from n/2 to 0
    void buildHeap(int* arr, int n){
        for(int i=0;i<n;i++){
            this->arr.push_back(arr[i]);
        }
        index = n;
        currentSize = n;

        for(int i=n/2;i>=0;i--){
            heapify(i);
        }
    }

    int getMin(){
        return arr[0];
    }

    int deleteMin(){
        int save = arr[0];
        swap(arr[0],arr[index-1]);
        index--;
        currentSize--;
        arr.pop_back();
        heapify(0);
        return save;
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[0]<<" ";
        }
        cout<<endl;
    }
};


int main(){

priorityQueueMin pq;
int arr[] = {1,9,7,4,2,6};

pq.buildHeap(arr,sizeof arr/sizeof arr[0]);

//pq.print();
//cout<<endl;

int k;
cout<<"To find the min K numbers enter the value of K: ";
cin>>k;

for(int i=0;i<k;i++){
    cout<<pq.deleteMin()<<" ";
}
return 0;
}
