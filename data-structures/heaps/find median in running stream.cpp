/**  Find running median from a stream of integers. i.e. You are getting inputs
*    from the user and after every input you need to tell the median to the
*    user.

*   After reading 1st element of stream - 5 -> median - 5
*   After reading 2nd element of stream - 5, 15 -> median - 10
*   After reading 3rd element of stream - 5, 15, 1 -> median - 5
*   After reading 4th element of stream - 5, 15, 1, 3 -> median - 4, so on...
*/

#include<bits/stdc++.h>
using namespace std;
/******************************************   MIN HEAP IMPLEMENTATION    ********************************************/
class priorityQueueMin{

public:

    vector <int> arr;
    int index;
    int currentSize;


    void minHeapify(int i){
        int leftChild = (2*i)+1;
        int rightChild = (2*i)+2;
        //both the children are in range
        if(leftChild<currentSize && rightChild<currentSize){
            if(arr[i]>arr[leftChild] || arr[i]>arr[rightChild]){
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
        //only left Child is in range
        if(leftChild<currentSize){
            if(arr[leftChild]<arr[i]){
                swap(arr[i],arr[leftChild]);
                minHeapify(leftChild);
            }
        }
        if(rightChild<currentSize){
            if(arr[rightChild]<arr[i]){
                swap(arr[i],arr[rightChild]);
                minHeapify(rightChild);
            }
        }
        //all the children are out of range
        else{
            return;
        }
    }


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
            minHeapify(i);
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
        minHeapify(0);
        return save;
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[0]<<" ";
        }
        cout<<endl;
    }
};
/**************************************  END OF MIN HEAP IMPLEMENTATION    *************************************/


/******************************************   MAX HEAP IMPLEMENTATION    ********************************************/

class priorityQueueMax{
public:
    vector <int> arr;
    int index;
    int currentSize;

    void maxHeapify(int i){
        int leftChild = (2*i)+1;
        int rightChild = (2*i)+2;
        //both the children are in range
        if(leftChild<currentSize && rightChild<currentSize){
            if(arr[i]<arr[leftChild] || arr[i]<arr[rightChild]){
                if(arr[leftChild] > arr[rightChild]){
                    swap(arr[i],arr[leftChild]);
                    maxHeapify(leftChild);
                }
                else{
                    swap(arr[i],arr[rightChild]);
                    maxHeapify(rightChild);
                }
            }
            else{
                return;
            }
        }
        //only left Child is in range
        if(leftChild<currentSize){
            if(arr[leftChild]>arr[i]){
                swap(arr[i],arr[leftChild]);
                maxHeapify(leftChild);
            }
        }
        if(rightChild<currentSize){
            if(arr[rightChild]>arr[i]){
                swap(arr[i],arr[rightChild]);
                maxHeapify(rightChild);
            }
        }
        //all the children are out of range
        else{
            return;
        }
    }

    priorityQueueMax(){
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
            if(arr[parent] >= arr[currentIndexOfData]){
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
            maxHeapify(i);
        }
    }

    int getMax(){
        return arr[0];
    }

    int deleteMax(){
        int save = arr[0];
        swap(arr[0],arr[index-1]);
        index--;
        currentSize--;
        arr.pop_back();
        maxHeapify(0);
        return save;
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[0]<<" ";
        }
        cout<<endl;
    }
};

/***************************************    END OF MAX HEAP IMPLEMENTATION    ****************************************/
//if both the sizes are the same then normal insertion
//if both the sizes are not same then first insert then balance the heaps
void insertIntoHeaps(priorityQueueMax& pmax, priorityQueueMin& pmin, int data){

    //if max is empty insert into it
    if(pmax.currentSize ==0){
        pmax.insertIntoHeap(data);
        return;
    }
    //if min heap is empty insert into it
    if(pmin.currentSize == 0){
        pmin.insertIntoHeap(data);
        return;
    }
    if(data <= pmax.arr[0]){
        pmax.insertIntoHeap(data);
        return;
    }
    else{
        pmin.insertIntoHeap(data);
        return;
    }
}

void balanceHeaps(priorityQueueMax& pmax, priorityQueueMin& pmin){
    if(abs(pmax.currentSize - pmin.currentSize) > 1){
        if(pmax.currentSize > pmin.currentSize){
            int maximum = pmax.deleteMax();
            pmin.insertIntoHeap(maximum);
        }
        else{
            int minimum = pmin.deleteMin();
            pmax.insertIntoHeap(minimum);
        }
    }
    else{
        return;
    }
}

double getMedian(priorityQueueMax& pmax, priorityQueueMin& pmin){
    //one of the heaps is empty
    if(pmax.currentSize==0 || pmin.currentSize==0){
        if(pmax.currentSize == 0){
            return pmin.arr[0];
        }
        else{
            return pmax.arr[0];
        }
    }
    //even integers
    if(pmax.currentSize == pmin.currentSize){
        double a = pmax.arr[0];
        double b= pmin.arr[0];
        return (a+b)/2;
    }

    //odd
    else{
        if(pmax.currentSize > pmin.currentSize){
            return pmax.arr[0];
        }
        else{
            return pmin.arr[0];
        }
    }
}

int main(){
priorityQueueMax pmax;
priorityQueueMin pmin;
int a;
cout<<" Keep entering the values for median(-1 to exit) :";
cin>>a;
while(1){
    if(a == -1){
        break;
    }
    insertIntoHeaps(pmax,pmin,a);
    balanceHeaps(pmax,pmin);
    cout<<"Median so far is : ";
    cout<<getMedian(pmax,pmin)<<endl;
    cout<<" Keep entering the values for median (-1 to exit) :";
    cin>>a;
}
return 0;
}
