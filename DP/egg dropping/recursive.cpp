#include<bits/stdc++.h>
using namespace std;


int eggDrop(int eggs, int floors){
	if(floors == 0 || floors == 1){
		return floors;
	}

	if(eggs == 1){
		return floors;
	}

	int min = INT_MAX;

	for(int i=1;i<=floors;i++){
		int dropping = max(eggDrop(eggs-1, i-1)/*egg broke*/, eggDrop(eggs, floors-i)/*egg didn't break*/);
		if(dropping < min){
			min = dropping;
		}
	}
	// +1 because 1 attempt made on this level of recursion
	return min + 1;
}


int main()
{
    int n = 2, k = 10;
    cout<<"Minimum number of trials in worst case with "<<n<<" eggs and "<<k<<" floors is "<<eggDrop(n, k);
    return 0;
}
