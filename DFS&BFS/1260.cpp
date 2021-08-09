#include <iostream>
#include <queue>
using namespace std;

int n, m, v;
int checked[1001];
int arr[1001][1001];
queue<int> q;

void dfs(int x) {
	checked[x] = true;
	cout<<x<<' ';
	for(int i = 1; i<=n; i++) {
		if(arr[x][i] == 1 && checked[i] == 0) {
			dfs(i);	
		}
	}
}

void bfs(int start) {
	q.push(start);
	checked[start] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		cout<<x<<' ';
		for(int i = 1; i<=n; i++) {
			if(arr[x][i] == 1 && checked[i] == 0) {
				checked[i] = true;
				q.push(i);
			}
		}
	}
}

void init(int n) {
	for(int i = 1; i<=n; i++) {
		checked[i] = 0;
	}
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	int e1, e2;
	cin>>n>>m>>v;
	
	for(int i = 0; i<m; i++) {
		cin>>e1>>e2;
		arr[e1][e2] = 1;
		arr[e2][e1] = 1;
	}
	
	dfs(v);
	cout<<endl;
	init(n);
	bfs(v);
	return 0;
} 
