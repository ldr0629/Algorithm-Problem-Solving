#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	
	sort(arr, arr+n, cmp);
	for(int i = 0; i<n; i++) {
		cout<<arr[i]<<' ';
	}
}
