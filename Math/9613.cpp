#include <iostream>
#include <string> 
using namespace std;

int gcd(int a, int b) {
	int r;
	while(b!=0) {
		r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int t, n; 
	cin>>t;
	
	while((t--)!=0) {
		cin>>n;
		int data[n];
		for(int i = 0; i<n; i++) {
			cin>>data[i];
		}
	   // n의 범위가 1~100이고, 모든 쌍의 GCD 합을 구해야하므로 n*(n-1)/2 경우의 수가 나오는데
    // sum이 최대값이 나오는 경우는 100*99/2 * 1,000,000으로 약 49억이 나오기에 long long int형으로 선언하였음.
		long long int sum = 0;
		for(int i = 0; i<n-1; i++) {
			for(int j = i+1; j<n; j++) {
				sum += gcd(data[i], data[j]);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
