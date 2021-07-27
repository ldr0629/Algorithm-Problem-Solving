#include <iostream>

using namespace std;

int dp[1001] = {0};

int tile_dp(int n) {
	if(n == 1) return 1;
	if(n == 2) return 2;
	if(dp[n]!=0) return dp[n];
	return dp[n] = (tile_dp(n-1) + tile_dp(n-2)) % 10007;
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
