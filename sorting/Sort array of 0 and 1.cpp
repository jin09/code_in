#include<iostream>
using namespace std;


int main(){
int arr[] = {0, 1, 0, 1, 1, 1};
int i = 0;
int j = 5;
while(i < j){
    if(arr[i] == 0){
        i++;
    }
    else if(arr[j] == 1){
        j--;
    }
    else if(arr[i] == 1 && arr[j] == 0 && i < j){
        arr[i] = 0;
        arr[j] = 1;
    }
}

for(int i=0;i<sizeof arr/sizeof arr[0];i++){
    cout<<arr[i]<<" ";
}

return 0;
}
