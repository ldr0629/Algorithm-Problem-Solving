#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int n, hp;
vector<int> v;
int dp[61][61][61];

int dfs(int s1, int s2, int s3) {
	// 죽은 scv에 대한 처리
	if (s1 < 0) return dfs(0, s2, s3);
	if (s2 < 0) return dfs(s1, 0, s3);
	if (s3 < 0) return dfs(s1, s2, 0);
	 
	// 모든 scv가 처음부터 0이라면 공격 X
	if (s1 == 0 && s2 == 0 && s3 == 0) return 0;

	// 계산되어 있는 경우 재귀 호출을 줄이기 위해 DP 사용
	if (dp[s1][s2][s3] != -1) return dp[s1][s2][s3];

	dp[s1][s2][s3] = 123456789;
    // 최소값만 갱신하고 횟수 1씩 카운팅
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 9, s2 - 3, s3 - 1) + 1);
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 9, s2 - 1, s3 - 3) + 1);
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 3, s2 - 1, s3 - 9) + 1);
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 3, s2 - 9, s3 - 1) + 1);
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 1, s2 - 3, s3 - 9) + 1);
	dp[s1][s2][s3] = min(dp[s1][s2][s3], dfs(s1 - 1, s2 - 9, s3 - 3) + 1);

	return dp[s1][s2][s3];
}

int main()
{
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> hp;
		v.push_back(hp);
	}

	cout<<dfs(v[0], v[1], v[2])<<"\n";
}
