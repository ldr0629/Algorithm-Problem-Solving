#include <iostream>
#define MAX 501
using namespace std;

int n, m, friend_cnt = 0;
int e1, e2;
bool visited[MAX], friend_num[MAX];
int mat[MAX][MAX];

void dfs() {
	// 자신의 친구를 방문 처리하고, 친구를 나타내는 배열에 처리. 
	for(int i = 2; i<=n; i++) {
		if(mat[1][i]) {
			visited[i] = true;
			friend_num[i] = true;
		}
	}
	
	// 친구의 친구를 구하기 위해 자신의 친구인 경우 방문 처리 
	for(int i = 2; i<=n; i++) {
		if(friend_num[i]) {
			for(int j = 1; j<=n; j++) { 
				if(mat[i][j]) visited[j] = true;
			}
		}
	}
	
	// 방문 처리된 경우 자신의 친구 또는 친구의 친구이므로 카운트 증가 
	for(int i = 2; i<=n; i++) {
		if(visited[i]) friend_cnt++;
	}
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	
	// 동기의 수와 리스트 길이 입력 
	cin>>n>>m;
	// 간선 연결 
	for(int i = 0; i<m; i++) {
		cin>>e1>>e2;
		mat[e1][e2] = 1;
		mat[e2][e1] = 1;
	}
	
	// 초대하는 동기의 수를 알아내기 위한 DFS 수행 
	dfs();
	
	// 동기의 수 출력 
	cout<<friend_cnt;
	return 0;
} 
