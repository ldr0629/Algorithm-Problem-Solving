#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#define MAX 301

using namespace std;

int n, m, cnt;
int x, y, x2, y2;
string mat[MAX];
int visited[MAX][MAX];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// 2차원을 1차원의 큐로 생각하여 최대 크기가 300이지만 올바른 좌표를 구하기 위해 범위를 크게 잡음
int bfs(int sy, int sx) {
	queue<int> q;
	visited[sy][sx] = 1;
	q.push(1000*sy+sx);
	cnt = 0;
	while (mat[y2][x2] != '0') {
		cnt++;
		queue<int> tmp;
		while (q.size()) {
			int y = q.front()/1000; 
			int x = q.front()%1000;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx]) {
					visited[ny][nx] = cnt;
					// 0이면 계속 탐색, 1이면 멈춰서 cnt++
					if (mat[ny][nx] != '0') {
						mat[ny][nx] = '0';
						tmp.push(1000*ny+nx); // next point
					}
					else {
						q.push(1000*ny+nx);
					}
				}
			}
		}
		q = tmp;
	}
	return visited[y2][x2];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	cin >> y >> x >> y2 >> x2;
	y--; x--; y2--; x2--; // 인덱스 기준이므로 하나씩 감소
	for (int i = 0; i < n; i++) {
		cin >> mat[i];
	}

	cout<<bfs(y, x);
}
