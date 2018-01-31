#include<bits/stdc++.h>
using namespace std;


int eggDrop(int eggs, int floors, int** cache){
	if(floors == 0 || floors == 1){
		return floors;
	}

	if(eggs == 1){
		return floors;
	}

	if(cache[eggs][floors] != -1){
		return cache[eggs][floors];
	}

	int min = INT_MAX;

	for(int i=1;i<=floors;i++){
		int dropping = max(eggDrop(eggs-1, i-1, cache)/*egg broke*/, eggDrop(eggs, floors-i, cache)/*egg didn't break*/);
		if(dropping < min){
			min = dropping;
		}
	}

	// +1 because 1 attempt made on this level of recursion
	cache[eggs][floors] = min + 1;
	
	return cache[eggs][floors];
}


int main()
{
    int n = 2, k = 10;
    int** cache = new int*[n+1];
    for(int i=0;i<=n;i++){
    	cache[i] = new int[k+1];
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=k;j++){
    		cache[i][j] = -1;
    	}
    }

    cout<<"Minimum number of trials in worst case with "<<n<<" eggs and "<<k<<" floors is "<<eggDrop(n, k, cache);

    for(int i=0;i<=n;i++){
    	delete [] cache[i];
    }
    delete [] cache;
    return 0;
}
