#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int mat[101][101], n, m, sy, sx;
int y, x;
int visited[101][101] = { false };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < row.size(); j++) {
			mat[i][j] = row[j] - '0';
		}
	}

	queue<pair<int, int>> q;
	visited[sy][sx] = 1;
	q.push({ sy, sx });
	while (q.size()) {
		tie(y, x) = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || mat[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
	cout << visited[n - 1][m - 1];
	
}

