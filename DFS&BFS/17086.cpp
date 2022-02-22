#include <bits/stdc++.h>
#define MAX 51
using namespace std;

int n, m, result;
int mat[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int> > v;

int move_xy[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
					{0, 1}, {1, -1}, {1, 0}, {1, 1} };

int bfs(int a, int b) {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(a,b), 0));
	visited[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (mat[x][y] == 1) return cnt;

		for (int i = 0; i < 8; i++) {
			int mx = x + move_xy[i][0];
			int my = y + move_xy[i][1];
			if (mx >= 0 && my >= 0 && mx < n && my < m) {
				if (!visited[mx][my]) {
					visited[mx][my] = true;
					q.push(make_pair(make_pair(mx, my), cnt+1));
				}
			}
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (!mat[i][j]) v.push_back({ i, j });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		memset(visited, false, sizeof(visited));
		int x = v[i].first;
		int y = v[i].second;

		int tmp = bfs(x, y);
		if (tmp > result) result = tmp;
	}
	cout << result;
	return 0;
}
