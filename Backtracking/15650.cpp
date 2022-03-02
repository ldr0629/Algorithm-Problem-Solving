#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX];
bool visited[MAX];

// 이전에 뽑은 순열 중복을 방지하기 위해 data 인자를 넘겨 다음 값이 더 크도록 한다.
void dfs(int data, int target) {
	if (target == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << "\n";
		return;
	}

	for (int i = data; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[target] = i;
			dfs(i + 1, target + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
	return 0;
}
