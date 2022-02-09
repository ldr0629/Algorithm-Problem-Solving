#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
int arr[15];
int lotto[6]; 

// 백트래킹, DFS를 수행하는 경우
// 0,0부터 시작해서 lotto라는 배열에 6개가 찰때까지 차례대로 집합을 구성한 뒤
// 재귀적으로 호출했을 때 길이가 6이되면 그때의 집합 원소들을 출력해준다.
void dfs(int start, int len) {
	if(len == 6) {
		for(int i = 0; i<6; i++) {
			cout<<lotto[i]<<' ';
		}
		cout<<"\n";
		return;
	}
	
	for(int i = start; i<k; i++) {
		lotto[len] = arr[i];
		dfs(i+1, len+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

  // 집합을 구성하는 원소의 개수를 입력받고, 데이터 입력
	while(1) {
		cin>>k;
		
		if(k == 0) break;
		
		for(int i = 0; i<k; i++) {
			cin>>arr[i];
		}
		
		dfs(0, 0);
        cout<<"\n";
	}
} 
