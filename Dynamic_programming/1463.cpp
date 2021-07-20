#include <iostream>
#include <algorithm>
using namespace std;


int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int x, arr[1000001] = {0};
	cin>>x;
	
	for(int i = 2; i<x+1; i++) {
		arr[i] = arr[i-1] + 1;
		if(i%2==0) {
			arr[i] = min(arr[i], arr[i/2] + 1);
		}
		if(i%3==0) {
			arr[i] = min(arr[i], arr[i/3] + 1);
		}
	}
	 
	cout<<arr[x];
	return 0;
} 
