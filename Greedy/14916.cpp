#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, cnt = 0; 
	cin >> n;
	while (n != 0) {
		if (n == 1) {
			cout << -1;
			return 0;
		}

		if (n % 5 != 0) { 
			n -= 2; 
			cnt++;
		}
		else if (n % 5 == 0) {
			cnt += n / 5;
			n %= 5;
		}

	}

	cout << cnt;
		
}
