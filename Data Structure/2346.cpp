#include <bits/stdc++.h>
using namespace std;

deque<pair<int, int>> ballon;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, boom;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> boom;
		ballon.push_back({ i, boom });
	}

	for (int i = 1; i <= n; i++) {
		cout << ballon.front().first << " ";
		int paper = ballon.front().second;
		ballon.pop_front(); // 풍선 터뜨리기

    // 오른쪽으로 이동할 경우 앞에 있던 요소를 뒤로 옮긴다.
		if (paper > 0) {
			paper--;
			while (paper != 0) {
				ballon.push_back(ballon.front());
				ballon.pop_front();
				paper--;
			}
		} // 왼쪽으로 이동할 경우 뒤에 있던 요소를 앞으로 옮긴다.
		else {
			while (paper != 0) {
				ballon.push_front(ballon.back());
				ballon.pop_back();
				paper++;
			}
		}
	}
}
