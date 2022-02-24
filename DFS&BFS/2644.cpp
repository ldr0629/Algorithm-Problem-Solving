#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int n, a, b;
int e, result = -1;
bool visited[MAX];
vector<int> vec[MAX];

void dfs(int start, int target, int cnt) {

	visited[start] = true;
	if (start == target) {
		result = cnt;
		return;
	}
	for (int i = 0; i < vec[start].size(); i++) {
		if (!visited[vec[start][i]]) {
			dfs(vec[start][i], target, cnt + 1);
		}
	}
}

int main() {
	cin >> n >> a >> b >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	dfs(a, b, 0);
	
	cout << result;
	return 0;
}
