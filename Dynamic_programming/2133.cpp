#include <iostream>

using namespace std;

int dp[30];

int tile_dp(int n) {
	if(n==0) return 1;
	if(n==1) return 0;
	if(n==2) return 3;
	if(dp[n]!=0) return dp[n];
	
	int num = 3*tile_dp(n-2);
	for(int i = 3; i<=n; i++) {
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
