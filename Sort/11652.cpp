#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(long long int a, long long int b) {
	return a < b;
}

int main() {
	int n, cnt = 1, max = 1; 
	long long int data;
	cin>>n;
	long long int arr[n];
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}
  
	sort(arr, arr+n, cmp);
	
	data = arr[0];
	for(int i = 1; i<n; i++) {
		if(arr[i]==arr[i-1]) {
			cnt++;
			if(max < cnt) {
				max = cnt;
				data = arr[i];
			}
		}
		else 
			cnt = 1;
	}
  
	cout<<data;
}
