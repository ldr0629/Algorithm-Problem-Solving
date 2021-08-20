#include <iostream>
using namespace std;

int computer, edge;
int checked[101];
int arr[101][101];

void dfs(int x) {
	checked[x] = true;
	for(int i = 1; i<=computer; i++) {
		if(arr[x][i] == 1 && checked[i] == 0) {
			dfs(i);	
		}
	}
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>computer;
	
	int e1, e2, cnt = 0;
	cin>>edge; 
	for(int i = 0; i<edge; i++) {
		cin>>e1>>e2;
		arr[e1][e2] = 1;
		arr[e2][e1] = 1;
	}
	
	dfs(1);
	for(int v = 1; v<=computer; v++) {
		if(!checked[v]) {
			cnt++;
		}
	}
	cout<<computer-cnt-1; // 1번 이외 바이러스에 걸린 컴퓨터의 수 
	return 0;
} 
