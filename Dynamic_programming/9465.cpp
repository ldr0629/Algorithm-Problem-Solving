#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// 테스트 케이스 t, 한 행당 스티커의 개수 n 입력 
	int t, n;
	cin>>t;
	
	for(int i = 0; i<t; i++) {
		// 스티커 2n개에 대한 배열 선언 후, 데이터 입력 
		cin>>n;
		int DP[2][n];  
		
		for(int j = 0; j<2; j++) {
			for(int k = 0; k<n; k++) {
				cin>>DP[j][k];	
			}
		}
		
		
		for(int j = 1; j<n; j++) {
			// 가장 처음의 점수를 구하는 경우엔, 변을 공유하지 않는 조건을 고려해 점수의 합을 구해준다. 
			if(j == 1) {
				DP[0][j] += DP[1][j-1];
				DP[1][j] += DP[0][j-1];
			} // 세번째 열부터 DP에 저장되어 있는 점수들을 비교해 점수를 더해준다. 
			else {
				DP[0][j] += max(DP[1][j-1], DP[1][j-2]);
				DP[1][j] += max(DP[0][j-1], DP[0][j-2]);
			}
		}
		// 2n개의 스티커 중 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다. 
		cout<<max(DP[0][n-1], DP[1][n-1])<<"\n";
	}
	
} 
