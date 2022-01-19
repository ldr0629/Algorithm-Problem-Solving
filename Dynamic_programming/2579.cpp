#include <iostream>
#include <cmath>
#define MAX 300
using namespace std;

int stair[MAX];
int dp[MAX];

int main(void) {
	int stair_num;
	cin>>stair_num;
	
	for(int i = 0; i<stair_num; i++) {
		cin>>stair[i];
	}
	
	// 첫번째 계단을 올라간 경우의 점수
	dp[0] = stair[0];
	// 두번째 계단을 갈 때 첫번째 계단을 거쳐가는 경우와 두번째 계단으로 바로 가는 경우의 점수를 비교
	dp[1] = max(stair[1], stair[0] + stair[1]);
	// 세번째 계단으로 갈 때 첫번째 계단을 밟고 세번째 계단으로 건너뛰었을 때와, 두번째를 밟고 세번째로 갔을 때의 점수를 비교
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	
	// 저장된 값을 이용해 네번째 계단부터 계단에서의 점수와 더해 더 높은 점수를 dp[i]에 넣는다.
	for(int i = 3; i<stair_num; i++) {
		dp[i] = max(stair[i] + dp[i-2], 
					stair[i] + stair[i-1] + dp[i-3]);
	}
	
	cout<<dp[stair_num-1];
	
    return 0;
}
