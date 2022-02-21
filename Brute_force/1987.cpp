#include <bits/stdc++.h>
#define MAX 21
using namespace std;

int R, C, result;
int alpha[MAX][MAX];
bool visited[26];
int move_xy[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void dfs(int x, int y, int cnt) {
	result = max(result, cnt);
	
	for(int w = 0; w<4; w++) {
		int mx = x + move_xy[w][0];
		int my = y + move_xy[w][1];
    
    // 말이 움직일 때마다 이동할 수 있는 범위에 속해있는지와 같은 알파벳 칸을 지날 수 없기에 알파벳 방문 조건을 체크해주고, 
    // 새로운 알파벳이라면 방문 처리 후 해당 좌표와 카운트를 증가시킨 상태에서 재귀적으로 DFS를 수행해준다. 
    // 동일 알파벳이 다른 좌표에 있는 경우를 생각해 마지막에 false를 해주어 모든 경우에 대해 지날 수 있는 최대 칸 수를 구해준다.
		if(mx>=0 && my>=0 && mx<R && my<C) {
			if(!visited[alpha[mx][my]]) {
				visited[alpha[mx][my]] = true;
				dfs(mx, my, cnt + 1);
				visited[alpha[mx][my]] = false;
			}
		}
		
	}
}


int main() {
  // 세로와 가로칸 수에 대한 입력과 보드판에 입력될 알파벳들을 받아 대입
	cin>>R>>C;
	for(int i = 0; i<R; i++) {
		string row;
		cin>>row;
		for(int j = 0; j<C; j++) {
			alpha[i][j] = row[j] - 'A';
		}
	}
	
  // 가장 처음에 놓인 말은 무조건 카운트되므로 방문처리 해주고, dfs를 수행하여 말이 지날 수 있는 최대칸 수를 출력
	visited[alpha[0][0]] = true;
	dfs(0, 0, 1);
	cout<<result;
    return 0;
}
