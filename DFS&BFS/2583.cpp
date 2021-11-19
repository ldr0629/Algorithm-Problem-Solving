#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 100
using namespace std;

int n, m, k, cnt;
int adj_mat[SIZE][SIZE];
bool visited[SIZE][SIZE];
int distance1[4] = {0,0,1,-1};
int distance2[4] = {1,-1,0,0};

void dfs(int x, int y) {
	visited[x][y] = true;
	cnt++;
	
	int mx, my;
	for(int w = 0; w<4; w++) {
		mx = x + distance1[w];
		my = y + distance2[w];
		if(mx<0 || mx>=n || my<0 || my>=m) {
			continue;
		}
		if(adj_mat[mx][my] == 0 && !visited[mx][my]) {
			dfs(mx, my);
		}
	}
}

bool cmp(int a, int b) {
	return a<b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	
	int x1, y1, x2, y2;
	for(int i = 0; i<k; i++) {
		cin>>y1>>x1>>y2>>x2;
		for(int i = x1; i<x2; i++) {
			for(int j = y1; j<y2; j++) {
				adj_mat[i][j] = 1;
				visited[i][j] = true;
			}
		}
	}
	
	vector<int> vec;
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<m; j++) {
			if(adj_mat[i][j] == 0 && !visited[i][j]) {
				cnt = 0;
				dfs(i, j);
				vec.push_back(cnt);
			}
		}
	}
	
	sort(vec.begin(), vec.end(), cmp);
	cout<<vec.size()<<"\n";
	for(int i = 0; i<vec.size(); i++) {
		cout<<vec[i]<<" ";
	}
}
