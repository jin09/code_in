/*   Priority queue MAX HEAP
     Build Heap - O(n)
*/
#include<bits/stdc++.h>
using namespace std;

class priorityQueueMax{
vector<int> arr;
int currentSize;
int index;
private:
    void heapify(int i){
        //children of the node
        int leftChild = (2*i) + 1;
        int rightChild = (2*i) + 2;
        //both child are in range of the array(heap)
        if(leftChild<index && rightChild<index){
            //if left or right child has value greater than root node
            if(arr[leftChild]>arr[i] || arr[rightChild]>arr[i]){
                if(arr[leftChild] > arr[rightChild]){
                    swap(arr[i],arr[leftChild]);
                    heapify(leftChild);
                }
                else{
                    swap(arr[i],arr[rightChild]);
                    heapify(rightChild);
                }
            }
            else{
                return ;
            }
        }

        //only left child is in range
        if(leftChild<index){
            if(arr[leftChild]>arr[i]){
                swap(arr[leftChild],arr[i]);
                heapify(leftChild);
            }
        }
        //only right child is in range
        if(rightChild < index){
            if(arr[rightChild] > arr[i]){
                swap(arr[rightChild],arr[i]);
                heapify(rightChild);
            }
        }
        else{
            return;
        }

    }
public:
    priorityQueueMax(){
        currentSize = 0;
        index = 0;
    }

    void buildHeapFromArray(int * brr, int n){
        for(int i=0;i<n;i++){
            arr.push_back(brr[i]);
        }
        currentSize = n;
        index = n;
        for(int i=n/2;i>=0;i--){
            heapify(i);
        }
    }

    int getSize(){
        return currentSize;
    }

    int deleteMax(){
        swap(arr[0],arr[index-1]);
        int returnValue = arr[index-1];
        arr.pop_back();
        index--;
        currentSize--;
        heapify(0);
       // print();
        //cout<<endl;
        return returnValue;
    }

    int getMax(){
        return arr[0];
    }

    void print(){
        for(int i=0;i<index;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){

priorityQueueMax pq;
int arr[] = {1,9,7,4,2,6};

pq.buildHeapFromArray(arr,6);
cout<<"printing the priority queue after building the MAX heap : ";
pq.print();

//pq.print();
//cout<<endl;

cout<<"Heap sort (should be in descending order because it is MAX heap) : ";

for(int i=0;i<6;i++){
    arr[i] = pq.deleteMax();
    cout<<arr[i]<<" ";
}
return 0;
}

