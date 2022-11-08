#include <bits/stdc++.h>

using namespace std;

int r, c, k, y, x;
char mat[6][6];
int visited[6][6], result;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int dfs(int y, int x) {
  // 종점에 도착시 거리를 비교해 k와 같다면 가지수 증가
	if (y == 0 && x == c - 1) {
		if (k == visited[y][x]) return 1;
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < r && nx < c && !visited[ny][nx]
			&& mat[ny][nx] != 'T') {
			visited[ny][nx] = visited[y][x] + 1;
			ret += dfs(ny, nx);
      // 모든 경로에 대해 탐색하므로 다시 0으로 초기화
			visited[ny][nx] = 0;
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++){
			cin >> mat[i][j];
		}	
	}
	
	// 시작점 초기화 후 dfs
	visited[r - 1][0] = 1;
	cout << dfs(r - 1, 0);
}
