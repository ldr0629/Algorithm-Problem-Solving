#include <iostream>
#include <string.h>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mat[51][51], n, m;
int t, k, cnt;
int visited[51][51] = { false };

void dfs(int i, int j) {
	visited[i][j] = true;
	for (int w = 0; w < 4; w++) {
		int ny = i + dy[w];
		int nx = j + dx[w];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (mat[ny][nx] == 1 && !visited[ny][nx]) {
			dfs(ny, nx);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> m >> n >> k; 

		memset(mat, 0, sizeof(mat));
		memset(visited, 0, sizeof(visited));

		int x, y;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			mat[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}

