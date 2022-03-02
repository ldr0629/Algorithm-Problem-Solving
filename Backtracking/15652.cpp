#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

void dfs(int data, int target) {
	if (target == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = data; i <= n; i++) {
		visited[i] = true;
		arr[target] = i;
		dfs(i, target + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
	return 0;
}
