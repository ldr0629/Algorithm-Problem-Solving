#include <iostream>

using namespace std;

int dp[30];

int tile_dp(int n) {
    // n이 홀수인 경우 0만 출력. 짝수일 때 고유한 경우 3가지를 고려
	if(n==0) return 1;
	if(n==1) return 0;
	if(n==2) return 3;
	if(dp[n]!=0) return dp[n];
	
    // 3*n-2 형태의 타일을 생각해보고, 마지막에 오는 타일을 기준으로 3가지가 올 수 있다. 
	int num = 3*tile_dp(n-2);
	for(int i = 3; i<=n; i++) {
        // i가 짝수인 경우, 고유한 경우가 2가지씩 늘어난다.
		if(i%2==0) {
			num += 2*tile_dp(n-i);
		}
	}
	
	return dp[n] = num;
}

int main()
{							
	ios::sync_with_stdio(false);
	cin.tie(0);	 
	int n;
	cin>>n;
	cout<<tile_dp(n);
	return 0;
} 
