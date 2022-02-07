#include <iostream>
#include <queue>
#include <string>
#define MAX 101
#define INF 999999999
using namespace std;

// 가로, 세로를 나타내는 변수와 입력받을 미로, 최소 벽의 수를 구하려는 가중치 2차원 배열 선언 
int n, m;
int maze[MAX][MAX];
int dist[MAX][MAX];
// 총 4개의 좌표이므로 2차원 배열로 선언 
int move_xy[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

// 다익스트라를 활용한 BFS로 최소의 가중치를 생각해서 목적지까지 벽의 개수를 구한다. 
void move_bfs() {
	queue<pair<int, int> > q;
	q.push({0,0});
	dist[0][0] = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		// 4개의 좌표로 이동할 수 있기에 움직일 좌표에 대한 변수 선언 후 예외처리를 해준다. 
		// 미로의 범위가 넘어가지 않는다면, 벽이 있는지 없는지 확인하고 이동 좌표에 값을 넣어준다. 
		for(int w = 0; w<4; w++) {
			int mx = x + move_xy[w][0];
			int my = y + move_xy[w][1];
			if(mx<0 || my<0 || mx>=m || my>=n) {
				continue;
			} 
			
			if(maze[mx][my]) {
				if(dist[mx][my] > dist[x][y] + 1) {
					dist[mx][my] = dist[x][y] + 1;
					q.push({mx, my});
				}
			} else if(!maze[mx][my]) {
				if(dist[mx][my] > dist[x][y]) {
					dist[mx][my] = dist[x][y];
					q.push({mx, my});
				}
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	// 각 행의 미로를 나타내는 문자열 변수 선언 후 입력 
	string str;
	for(int i = 0; i<m; i++) {
		cin>>str;
		// 각각의 행, 열마다 처음에는 가중치가 없기에 무한대로 초기화 후, 미로 배열에는 미로의 상태를 대입해준다. 
		for(int j = 0; j<n; j++) {
			dist[i][j] = INF;
			maze[i][j] = str[j] - '0';
		}
	}
	
	// BFS 수행 후, 마지막 좌표로 이동하기 위한 최소 벽의 개수 출력 
	move_bfs();
	cout<<dist[m-1][n-1];
} 
