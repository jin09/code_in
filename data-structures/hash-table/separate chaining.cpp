/*   Hash Table Separate chaining
*/

#include<bits/stdc++.h>
using namespace std;

class hashNode{
public:
    int data;
    char* key;
    hashNode* next;
    //Constructor
    hashNode(int data, char* key){
        this->data = data;
        this->key = new char[strlen(key)+1]; //+1 for security purpose (not needed)
        strcpy(this->key,key);
        next = NULL;
    }
    //Destructor
    ~hashNode(){
        delete [] key;
    }
};

class hashTable{
    int currentSize;
    int tableSize;
    hashNode** bucketArray;

    void rehash(){
        int oldTableSize = tableSize;
        currentSize = 0;
        tableSize = tableSize*2;

        hashNode** oldBucket = bucketArray;
        bucketArray = new hashNode*[tableSize];

        for(int i=0;i<tableSize;i++){
            bucketArray[i] = NULL;
        }

        for(int i=0;i<oldTableSize;i++){
            hashNode* temp = oldBucket[i];
            while(temp!=NULL){
                insertIntoHashTable(temp->key,temp->data);
                temp = temp->next;
            }
        }

        //the old hash table must be deleted
        delete oldBucket;
        cout<<"rehash succesful ! ";
        cout<<endl;
    }
public:
    hashTable(){
        currentSize = 0;
        //initialize the table size to 3 (It is the number of buckets in the array)
        tableSize = 3;
        bucketArray = new hashNode*[tableSize];
        for(int i=0;i<tableSize;i++){
            bucketArray[i] = NULL;
        }
    }

    long long int getIndex(char* key){
        //h(key) -->> integer
        // L = length of the key (strlen)
        // hash function : [sumation{ key[L-i-1] * pow(37,i) }] mod tableSize
        long long int currentPower = 1;
        long long int sumation = 0;
        int L = strlen(key);

        for(int i=0;i<L;i++){
            sumation = sumation + key[L-i-1]*currentPower;
            currentPower = currentPower*37;
        }
        sumation = sumation % tableSize;
        return sumation;
    }

    void insertIntoHashTable(char* key, int value){
        int index = getIndex(key);
        hashNode* newNode = new hashNode(value,key);
        hashNode* head = bucketArray[index];
        newNode->next = head;
        bucketArray[index] = newNode;
        currentSize++;

        if(currentSize*1.0/tableSize > 0.75){
            rehash();
        }
    }

    int findValue(char* key){
        int index = getIndex(key);
        //now simply traverse the Linked List
        hashNode* temp = bucketArray[index];
        while(temp!=NULL){
            if(strcmp(key,temp->key) == 0){
                break;
            }
            temp = temp->next;
        }
        if(temp!=NULL){
            return temp->data;
        }
        else{
            cout<<"No such item exists !!";
            return -1;
        }
    }

    int deleteKey(char* key){
        int index = getIndex(key);
        hashNode* prev = bucketArray[index];
        hashNode* current = prev;
        while(current != NULL){
            if(strcmp(current->key,key) == 0){
                break;
            }
            prev = current;
            current = current->next;
        }
        //reached the end of the linked list
        if(current == NULL){
            cout<<"Unable to delete key because the key was not found in the table !! ";
            return -1;
        }
        //deletion at head
        if(prev==current){
            bucketArray[index] = current->next;
            int returnValue = current->data;
            delete current;
            currentSize--;
            return returnValue;
        }
        //element found somewhere in the middle of the linked List
        else{
            prev->next = current->next;
            int returnValue = current->data;
            delete current;
            currentSize--;
            return returnValue;
        }
    }

    void print(){
        for(int i=0;i<tableSize;i++){
            cout<<"Bucket "<<i<<" : ";
            hashNode* temp = bucketArray[i];
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    ~hashTable(){
        for(int i=0;i<tableSize;i++){
            hashNode* temp = bucketArray[i];
            hashNode* next = NULL;
            if(temp!=NULL){
                next = temp->next;
            }
            while(temp!=NULL){
                delete temp;
                temp = next;
                if(next!=NULL){
                    next = next->next;
                }
            }
        }
        delete [] bucketArray;
    }
};


int main(){
hashTable h;
char a[] = "jonathan";
h.insertIntoHashTable(a,10);
char b[] = "roma";
char c[] = "hashed";
h.insertIntoHashTable(b,13);
cout<<"Printing the hash table before rehashing :"<<endl;
h.print();
cout<<endl;
h.insertIntoHashTable(c,20);
cout<<"Printing the hash table after rehashing :"<<endl;
h.print();
cout<<endl;
//if output is -1 then the key does not exists
cout<< h.findValue(a)<<endl;
cout<< h.findValue(b) <<endl;
cout<< h.findValue("brrrr")<<endl;

return 0;
}
