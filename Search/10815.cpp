#include <iostream>
#include <algorithm>
using namespace std;

int search(int arr[], int length, int target) { 
	int start = 0;
	int end = length-1;
	int mid;
	
	while(start<=end) {
		mid = (start+end)/2;
		if(arr[mid] == target) {
			return mid;
		} else {
			if(arr[mid] > target) {
				end = mid-1;
			} else {
				start = mid+1;
			}
		}
	}
	return -1;
}

bool cmp(int a, int b) {
	return a<b;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int n, m, result;
	cin>>n;
	
	int mycard[n];
	for(int i = 0; i<n; i++) {
		cin>>mycard[i];
	}
	sort(mycard, mycard+n, cmp);
	
	cin>>m;
	int check_card[m];
	for(int i = 0; i<m; i++) {
		cin>>check_card[i];
	}
	
	for(int i = 0; i<m; i++) { 
		result = search(mycard, n, check_card[i]);
		if(result==-1) {
			cout<<0<<' ';
		} else {
			cout<<1<<' ';
		}
	}
	return 0;
}
