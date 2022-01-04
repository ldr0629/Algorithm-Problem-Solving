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
	
	dp[0] = stair[0];
	dp[1] = max(stair[1], stair[0] + stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	
	for(int i = 3; i<stair_num; i++) {
		dp[i] = max(stair[i] + dp[i-2], 
					stair[i] + stair[i-1] + dp[i-3]);
	}
	
	cout<<dp[stair_num-1];
	
    return 0;
}
