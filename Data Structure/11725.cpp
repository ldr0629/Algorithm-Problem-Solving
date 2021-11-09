#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

int n;
int parent[MAX];
vector<int> list[MAX];
bool visited[MAX];

void dfs(int start) {
	visited[start] = true;
	for(int i = 0; i<list[start].size(); i++) {
		int next = list[start][i];
		if(!visited[next]) {
			parent[next] = start;
			dfs(next);
		}
	}
}

int main() {
	cin>>n;
	
	for(int i = 0; i<n-1; i++) {
		int x, y;
		cin>>x>>y;
		list[x].push_back(y);
		list[y].push_back(x);
	}
	dfs(1);
	
	for(int i = 2; i<=n; i++) {
		cout << parent[i] << "\n";
	}
}
