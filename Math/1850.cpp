#include <iostream>
using namespace std;

long long int gcd(long long int n, long long int m) {
	if(m == 0)
		return n;
	return gcd(m, n%m);
}

int main() {
	long long int a, b, r;
	cin>>a>>b;
	
	r = gcd(a, b);
	for(int i = 0; i<r; i++) {
		cout<<1;
	}
	return 0;
}
