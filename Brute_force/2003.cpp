#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// 수열의 길이 n, i~j번째 수까지의 합을 나타내는 m 입력
	int n, m;
	cin>>n>>m; 
	
  // 크기에 맞게 배열 선언 후 데이터 입력
	int A[n], cnt = 0;
	for(int i = 0; i<n; i++) {
		cin>>A[i];
	}
	
  // 부분적으로 i부터 j번째 수까지 합을 체크해야하므로 매 번 i번째 데이터로 합을 초기화해준 후, m이 되는 경우의 수를 구해준다.
	int sum = 0;
	for(int i = 0; i<n; i++) {
		sum = A[i];
		if(sum == m) {
			cnt++;
			continue;
		}
		for(int j = i+1; j<n; j++) {
			sum += A[j];
			
			if(sum == m) {
				cnt++;
				break;
			} else if(sum > m) {
				break;
			}
		}
	}
	cout<<cnt;
} 
