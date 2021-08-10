#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visited[1001];
int arr[1001][1001];
queue<int> q;

void bfs(int start) {
	if(visited[start]) return;
	q.push(start);
	visited[start] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i = 1; i<=n; i++) {
			if(arr[x][i] == 1 && visited[i] == 0) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

void init() {
	for(int i = 1; i<=n; i++) {
		visited[i] = 0;
		for(int j = 1; j<=n; j++) {
			arr[i][j] = 0;
		}
	}
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	
	while((t--)!=0) {
		cin>>n;
		for(int i = 1; i<=n; i++) {
			cin>>m;
			arr[i][m] = 1;
		}
		
		int cnt = 0;
		for(int i = 1; i<=n; i++) {
			if(!visited[i]) {
				cnt++;	
			}
			bfs(i);
		}
		cout<<cnt<<endl;
		init();
	}
	return 0;
} 
