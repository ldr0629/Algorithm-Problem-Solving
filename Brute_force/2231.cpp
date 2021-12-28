#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);
	
	int n, sum, creator;
	bool check = false;
	cin>>n;
	
	for(int i = 1; i<n; i++) {
		sum = i, creator = i;
		for(int j = i; j!=0; j/=10) {
			sum += j%10;
		}
		if(n == sum) {
			cout<<creator;
			check = true;
			break;
		}
	} 
	
	if(!check) {
		cout<<0;
	}
	return 0;
} 



