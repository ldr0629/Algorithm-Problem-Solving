#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m, a, b;
int arr[MAX], sum[MAX];


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
}
