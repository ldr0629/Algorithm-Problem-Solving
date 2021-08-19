#include <iostream>
using namespace std;

int fibo[40] = {0};

int fibonacci(int n) {
	if(n==0) {
		return fibo[n] = 0;
	} else if(n==1) {
		return fibo[n] = 1;
	}

	if(fibo[n]!=0) return fibo[n];
	else return fibo[n] = fibonacci(n-1) + fibonacci(n-2);	
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	
	for(int i = 0; i<t; i++) {
		int n;
		cin>>n;
		if(n==0) cout<<1<<" "<<0<<"\n";
		else {
			fibonacci(n);
			cout<<fibo[n-1]<<" "<<fibo[n]<<"\n";
		}
	}
	return 0;
} 
