#include <iostream>
using namespace std;

int search(int arr[], int start, int end, int target) {
	int mid = (start+end)/2;
	if(start>end) {
		return -1;
	} else if(arr[mid] == target) {
		return mid;
	} else if(arr[mid] > target) {
		search(arr, start, mid-1, target);
	} else {
		search(arr, mid+1, end, target);
	}
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int n, m, result;
	cin>>n;
	
	int store[n];
	for(int i = 0; i<n; i++) {
		cin>>store[i];
	}
	
	cin>>m;
	int custom[m];
	for(int i = 0; i<m; i++) {
		cin>>custom[i];
	}
	
	for(int i = 0; i<m; i++) {
		result = search(store, 0, n-1, custom[i]);
		if(result==-1) {
			cout<<"no ";
		} else {
			cout<<"yes ";
		}
	}
	return 0;
}


