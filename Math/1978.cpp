#include <iostream>

using namespace std;
int main() {
	int n, cnt = 0, j;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++) {
		cin>>arr[i];
	}
	
	for(int i = 0; i<n; i++) {
		for(j = 2; j<arr[i]; j++) {
				if(arr[i]%j == 0) {
					break;	
				}
		}
		if(arr[i] == j)
			cnt++;
	}
	cout<<cnt;
}

