#include <bits/stdc++.h>
using namespace std;

int n, m, y, x, ny, nx;
int dist, maxLen, res;
char mat[51][51];
bool visited[51][51];
int d[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int bfs(int sy, int sx) {
	d[sy][sx] = 1;
	visited[sy][sx] = true;
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || mat[ny][nx] == 'W') continue;
			if (!visited[ny][nx]) {
				visited[ny][nx] = true;
				d[ny][nx] = d[y][x] + 1;
				q.push({ ny, nx });
				if (maxLen < d[ny][nx]) maxLen = d[ny][nx];
			}
		}
	}
	return maxLen - 1;
}

void init() {
	maxLen = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	maxLen = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'L') {
				dist = bfs(i, j);
				if (dist > res) res = dist;
				init();
			}
		}
	}
	cout << res;
}
