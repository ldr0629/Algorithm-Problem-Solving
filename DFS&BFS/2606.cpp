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
	// 총 컴퓨터의 수 입력
	cin>>computer;
	
	// 간선에 대한 정보와 바이러스에 걸리지 않은 컴퓨터의 수를 카운트해주기 위한 변수 선언
	int e1, e2, cnt = 0;
	cin>>edge; 
	// 2차원 배열에 저장해줌으로써 간선의 개수만큼 각 간선을 연결해준다.
	for(int i = 0; i<edge; i++) {
		cin>>e1>>e2;
		arr[e1][e2] = 1;
		arr[e2][e1] = 1;
	}
	
	// 1번 컴퓨터가 바이러스에 걸렸을 때 1번 컴퓨터를 통해 바이러스에 걸린 컴퓨터의 수를 구하는 것이므로 1번부터 시작.
	dfs(1);
	
	// DFS 수행 후 연결되지 않은 게 있다면 바이러스에 걸리지 않았으므로 방문 처리가 되지않은 컴퓨터의 수를 계산해준다.
	for(int v = 1; v<=computer; v++) {
		if(!checked[v]) {
			cnt++;
		}
	}
	
	 // 1번 이외에 바이러스에 걸린 컴퓨터의 수 
	cout<<computer-cnt-1;
	return 0;
} 
