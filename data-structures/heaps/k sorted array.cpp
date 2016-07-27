/*
*Given an array of n elements, where each element is at most k away from
 its target position, devise an algorithm that sorts in O(n log k) time.
 
 INPUT:
 
 int k = 3;
 int arr[] = {2, 6, 3, 12, 56, 8};
 
 OUTPUT:
 
 int resultArr[] = {2,3,6,8,12,56}
*/

#include<bits/stdc++.h>
using namespace std;

class priorityQueueMin{
    vector<int> arr;
    int currentSize;
    int index;

private:
    void minHeapify(int i){
        int leftChild = (2*i)+1;
        int rightChild = (2*i)+2;
        //both the children are in range
        if(leftChild < currentSize && rightChild < currentSize){
            if(arr[leftChild]< arr[i] || arr[rightChild]<arr[i]){
                if(arr[leftChild] < arr[rightChild]){
                    swap(arr[i],arr[leftChild]);
                    minHeapify(leftChild);
                }
                else{
                    swap(arr[i],arr[rightChild]);
                    minHeapify(rightChild);
                }
            }
            else{
                return;
            }
        }
        //only left child is in range
        if(leftChild < currentSize){
            if(arr[leftChild] < arr[i]){
                swap(arr[i],arr[leftChild]);
                minHeapify(leftChild);
            }
        }
        //only right child is in range
        if(rightChild < currentSize){
            if(arr[rightChild] < arr[i]){

                swap(arr[i],arr[rightChild]);
                minHeapify(rightChild);
            }
        }
        //no one is in range
        else{
            return;
        }
    }

public:
    priorityQueueMin(){
        currentSize = 0;
        index =0 ;
    }

    void insertIntoHeap(int data){
        arr.push_back(data);
        int currentIndexOfData = index;
        index++;
        currentSize++;
        int parent = (currentIndexOfData - 1)/2;
        while(parent >= 0){
            if(arr[parent] > arr[currentIndexOfData]){
                swap(arr[parent],arr[currentIndexOfData]);
                currentIndexOfData = parent;
                parent = (currentIndexOfData -1)/2;
            }
            else{
                break;
            }
        }

    }


    void buildHeap(int* arr, int n){
            for(int i=0;i<n;i++){
                this->arr.push_back(arr[i]);
            }
            index = n;
            currentSize = n;
            for(int i=n/2;i>=0;i--){
                minHeapify(i);
            }
        }

    int getMin(){
        return arr[0];
    }


    int deleteMin(){
        int save = arr[0];
        swap(arr[0],arr[currentSize-1]);
        arr.pop_back();
        currentSize--;
        index--;
        minHeapify(0);
        return save;
    }

    int deleteMinAndInsertIntoHeap(int data){
        int save = arr[0];
        arr[0] = data;
        minHeapify(0);
        return save;
    }

    void printHeap(){
        for(int i=0;i<currentSize;i++){
            cout<<arr[0]<<" ";
        }
        cout<<endl;
    }

};


int main(){

int arr[] = {2,6,3,12,56,8};
int k = 3;
int n = sizeof arr/sizeof arr[0];
priorityQueueMin pq;
pq.buildHeap(arr,k+1);
int* resultArr = new int[n];
int index = 0;
for(int i=k+1;i<n;i++){
    resultArr[index] = pq.deleteMinAndInsertIntoHeap(arr[i]);
    index++;
}
while(index<n){
    resultArr[index] = pq.deleteMin();
    index++;
}

//Printing the sorted array
cout<<"Sorted array in O(nlogk): ";
for(int i=0;i<n;i++){
    cout<<resultArr[i]<<" ";
}

return 0;
}
