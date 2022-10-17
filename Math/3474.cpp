#include <iostream>
using namespace std;

int n, t;
long long sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		sum = 0; 
		for (int i = 5; i <= n; i*=5) sum += n / i;
		
		cout << sum << "\n";
	}

}
