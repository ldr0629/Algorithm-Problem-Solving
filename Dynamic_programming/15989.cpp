#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int t, n;
int dp[MAX][3];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 각 1, 2, 3으로 시작하고 그 수보다 작거나 같은 수를 사용해 
    // 행에 해당하는 수를 만드는 경우의 수를 먼저 구한다.
    dp[1][0] = 1; dp[2][0] = 1; dp[3][0] = 1;
    dp[2][1] = 1; dp[3][1] = 1;
    dp[3][2] = 1;

    for (int i = 4; i <MAX; i++) {
        dp[i][0] = 1;
        dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
        dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
    }

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n][0] + dp[n][1] + dp[n][2]<<"\n";
    }
    return 0;
}
