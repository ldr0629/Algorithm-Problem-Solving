#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
queue<pair<int, int>> q;
bool visited[MAX] = { false };
int n, k, cnt = 0;
int ans;

void bfs(int n, int t) {
	q.push({ n, t });
	while (!q.empty()) {
		int n = q.front().first;
		int t = q.front().second;
		q.pop();
		visited[n] = true;
		if (n == k) {
			if (cnt == 0) {
				ans = t;
				cnt++;
			}
			else if (cnt > 0 && ans == t)
				cnt++;
		}
        
        if (n + 1 <= MAX-1 && !visited[n + 1]) q.push({n+1, t+1});
        if (n - 1 >= 0 && !visited[n - 1]) q.push({ n - 1, t + 1 });
        if (n * 2 <= MAX-1 && !visited[n * 2]) q.push({ n * 2, t + 1 });
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	if (n == k) cout << 0 << '\n' << 1;
	else {
		bfs(n, 0);
		cout << ans << '\n' << cnt;
	}
}
