#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, y, x, cnt, cnt2;
int mat[104][104];
int visited[104][104];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;

void go(int y, int x) {
	visited[y][x] = 1;
	if (mat[y][x] == 1) { 
		v.push_back({ y, x });
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
		go(ny, nx);
	}
	return;
}


int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	while (true) {
		cnt2 = 0;
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		go(0, 0);
		// 모두 녹기 한 시간 전에 남아있는 치즈조각 칸의 개수 체크
		for (auto ele : v) {
			cnt2++;
			mat[ele.first][ele.second] = 0;
		}

		// 치즈가 다 녹았는지 체크
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] != 0) flag = true;
			}
		}
		cnt++;
		if (!flag) break;
	}
	cout << cnt << "\n" << cnt2;
}
