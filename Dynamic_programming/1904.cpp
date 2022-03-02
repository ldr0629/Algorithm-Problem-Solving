#include <bits/stdc++.h>
#define MOD 15746
using namespace std;

int main() {
  	int n;
	cin >> n;
  
  	// 00, 1로만 이루어진 경우의 수를 이용해 
  	int DP[n+1];
	DP[1] = 1 % MOD;
	DP[2] = 2 % MOD;
	for (int i = 3; i <= n; i++) {
		DP[i] = (DP[i-1] + DP[i-2]) % MOD;
	}

	cout << DP[n];
}
