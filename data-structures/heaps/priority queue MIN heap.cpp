/*   Priority queue MIN HEAP
*/

#include<bits/stdc++.h>
using namespace std;

class priorityQueueMin{

vector<int> arr;
int index;
int currentSize;

private:
    void heapify(int i){

        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
        //both the children are in range of the array
        if(leftChild<index && rightChild<index){
            //the parent node is sitting wrong
            if(arr[i]>arr[leftChild] || arr[i]>arr[rightChild]){
                //the minimum of the the two children should go up
                if(arr[leftChild] < arr[rightChild]){
                    swap(arr[i],arr[leftChild]);
                    heapify(leftChild);
                }
                else{
                    swap(arr[i],arr[rightChild]);
                    heapify(rightChild);
                }
            }
            //parent node is sitting right , and there is no need to heapify so return.
            else{
                return;
            }
        }
        //only left child is in range of the array
        if(leftChild<index){
            //the parent node is sitting wrong
            if(arr[i]>arr[leftChild]){
                swap(arr[i],arr[leftChild]);
                heapify(leftChild);
            }
            //the parent node is sitting right , there is no need to heapify further
            else{
                return;
            }
        }
        //only right child is in range of the array
        if(rightChild<index){
            //the parent node is sitting wrong
            if(arr[i]>rightChild){
                swap(arr[i],arr[rightChild]);
                heapify(rightChild);
            }
            //the parent node is sitting right and there isno need for heapify.
            else{
                return;
            }
        }
        //both the children are out of the range of the array, which means that we have reached the leaf node
        else{
            return ;
        }
    }
public:
    priorityQueueMin(){
        index = 0;
        currentSize = 0;
    }

    void insertIntoHeap(int data){
        arr.push_back(data);
        int currentIndexOfData = index;
        index++;
        currentSize++;
        int parent = (currentIndexOfData - 1)/2;
        while(parent>=0){
            //currently inserted data is sitting right
            if(arr[parent] <= arr[currentIndexOfData]){
                break;
            }
            //else the data must be swapped
            else{
                swap(arr[parent],arr[currentIndexOfData]);
                currentIndexOfData = parent;
                parent = (currentIndexOfData - 1)/2;
            }
        }
    }

    int getMin(){
        return arr[0];
    }

    int deleteMin(){
        swap(arr[0],arr[index-1]);
        int returnValue = arr[index - 1];
        arr.pop_back();
        index--;
        currentSize--;
        heapify(0);
       // print();
        //cout<<endl;
        return returnValue;
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            printf("%d ",arr[i]);
        }
    }
};


int main(){

priorityQueueMin pq;
int arr[] = {1,9,7,4,2,6};

for(int i=0;i<6;i++){
	pq.insertIntoHeap(arr[i]);
}

//pq.print();
//cout<<endl;


cout<<"Heap sort : ";

for(int i=0;i<6;i++){
    arr[i] = pq.deleteMin();
    cout<<arr[i]<<" ";
}
return 0;
}

