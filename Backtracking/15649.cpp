#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

void dfs(int target) {
	if (target == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[target] = i;
			dfs(target + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
	return 0;
}
