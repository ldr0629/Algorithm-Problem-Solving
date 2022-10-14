#include <bits/stdc++.h>
using namespace std;

int n, r, tmp, root;
vector<int> adj[51];

int dfs(int here) {
	int ret = 0;
	int child = 0;
	for (int there : adj[here]) {
		if (there == r) continue; // 지울 노드의 경우 자식 노드도 삭제되기에 더 이상 탐색 X
		ret += dfs(there);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (tmp == -1) root = i;
		else adj[tmp].push_back(i);
	}

	cin >> r;
	if (r == root) {
		cout << 0 << "\n"; return 0; // 루트 노드를 삭제할 경우의 처리
	}
	cout << dfs(root) << "\n";
}

