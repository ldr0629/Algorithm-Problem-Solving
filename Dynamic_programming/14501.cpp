#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

// 남은 일에 대한 변수 n 
int n;
// 상담을 완료하는데 걸리는 기간과 금액에 대한 배열 T, P
// 최대 수익을 담아놓기 위한 배열 DP 
int T[MAX], P[MAX], DP[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	// 1일부터 N일까지 각각의 기간과 금액 입력 
	cin>>n;
	for(int i = 0; i<n; i++) {
		cin>>T[i]>>P[i];	
	}
	
	
	for(int i = 0; i<n; i++) {
		// i번째 일에서 상담 걸리는 기간을 더했을 때 범위를 초과하지 않는 경우 
		// i번째 일에 소요 시간, 비용을 더해 저장하고 i + t[i]번째 일과 비교해 더 큰 값을 넣는다. 
		if(i+T[i] < n+1)  DP[i+T[i]] = max(DP[i+T[i]], DP[i] + P[i]);
		
		// DP[i+1]이 0인 경우엔 i번째 값을 넣어줘야 한다. 
		// i+1번째 일에 상담을 할 수 없다면 i번째일 때의 최대 이익을 넣어준다. 
		DP[i+1] = max(DP[i+1], DP[i]);
	}
	
	cout<<DP[n];
	return 0;
} 

