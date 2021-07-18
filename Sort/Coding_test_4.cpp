#include <iostream>
#include <algorithm>
using namespace std;

bool up_cmp(int a, int b) {
	return a < b;
}

bool down_cmp(int a, int b) {
	return a > b;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int n, k, sum = 0;
	cin>>n>>k;
	
	int A[n], B[n];
	for(int i = 0; i<n; i++) {
		cin>>A[i];
	}
	
	for(int i = 0; i<n; i++) {
		cin>>B[i];
	}
	
	sort(A, A+n, up_cmp);
	sort(B, B+n, down_cmp);
	
	for(int i = 0; i<k; i++) { 
		if(A[i]<B[i])
			A[i] = B[i];
		else
			break;
	}
	
	for(int i = 0; i<n; i++) {
		sum += A[i];
	}
	cout<<sum;
	return 0;
}


