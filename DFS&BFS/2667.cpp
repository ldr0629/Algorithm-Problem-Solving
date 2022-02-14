#include <bits/stdc++.h>
#define MAX 26
using namespace std;

int n, dan_cnt;
int board[MAX][MAX];
int move_xy[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
bool visited[MAX][MAX];
vector<int> v;

void dfs(int x, int y) {
	dan_cnt++;
	visited[x][y] = true;

	// 움직일 수 있는 경우의 수가 4가지이므로 각 이동 좌표에 대해 지도 범위를 초과하지 않았다면
	// 단지 내 집이 존재하고, 방문 처리되지 않았을 때 재귀적으로 DFS 수행
	for (int w = 0; w < 4; w++) {
		int mx = x + move_xy[w][0];
		int my = y + move_xy[w][1];
		if (mx < 0 || my < 0 || mx >= n || my >= n) {
			continue;
		}

		if (board[mx][my] == 1 && !visited[mx][my]) {
			dfs(mx, my);
		}
	}
}

int main() {

	// 지도의 크기와 집의 유무를 나타내는 지도 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < n; j++) {
			board[i][j] = row[j] - '0';
		}
	}

	// 집이있는 곳과 방문 처리되지 않은 곳에 한하여 DFS를 수행하고, 
	// 단지 내 집의 수를 카운트하여 벡터에 넣어준다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				dan_cnt = 0;
				dfs(i, j);
				v.push_back(dan_cnt);
			}
		}
	}

	// 오름차순 정렬 수행 후, 총 단지 수와 각 단지별 집의 수 출력
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}
