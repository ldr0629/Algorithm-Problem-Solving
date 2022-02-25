#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int n, m, cnt, max;
bool visited[MAX];
vector<int> result;
vector<int> v[MAX];

void dfs(int start) {
	visited[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		if (!visited[v[start][i]]) {
			cnt++;
			dfs(v[start][i]);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));

		cnt = 0;
		dfs(i);
		if (max == cnt) {
			result.push_back(i);
		}

		if (max < cnt) {
			max = cnt;
			result.clear();
			result.push_back(i);
		}
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}
