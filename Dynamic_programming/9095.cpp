#include <iostream>
using namespace std;

int partition(int n) {
	if(n<=3) {
		int dp[3] = {1, 2, 4}; // 3이하인 경우 메모리에 저장해놓은 값을 그대로 반환
		return dp[n-1];
	} else {
		int dp[n] = {1, 2, 4};
		for(int i = 3; i<n; i++) {
			dp[i] = dp[i-3] + dp[i-2] + dp[i-1]; // 3초과인 경우 반복되는 1, 2, 3의 합으로만 계산되므로 이전 3개의 경우의 수를 더해 n에 대한 경우의 수를 구함
		}
		return dp[n-1];
	}
	
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int t, n, cnt;
	cin>>t;
	for(int i = 0; i<t; i++) {
		cin>>n;
		cnt = partition(n);
		cout<<cnt<<endl;
	}

	return 0;
} 
