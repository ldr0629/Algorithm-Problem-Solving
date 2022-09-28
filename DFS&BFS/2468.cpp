#include <bits/stdc++.h>
#define MAX 101
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mat[MAX][MAX];
bool visited[MAX][MAX] = {false};
int n, max_num, cnt, result;

void dfs(int i, int j, int h) {
	visited[i][j] = true;
	for (int w = 0; w < 4; w++) {
		int ny = i + dy[w];
		int nx = j + dx[w];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (mat[ny][nx] > h && !visited[ny][nx]) {
			dfs(ny, nx, h);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	max_num = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j]; 
			if (mat[i][j] > max_num) max_num = mat[i][j];
		}
	}

	result = 1;
	for (int h = 1; h <= max_num; h++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] > h && !visited[i][j]) {
					cnt++;
					dfs(i, j, h);
				}
			}
		}
		if (cnt > result) result = cnt;
	}
	cout << result;
}

