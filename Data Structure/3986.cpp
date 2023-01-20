#include <iostream>
#include <stack>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt = 0;
	cin >> n;

	string word;
	for (int i = 0; i < n; i++) {
		stack<char> stk;
		cin >> word;
		for (auto l : word) {
			if (stk.size() && stk.top() == l) stk.pop();
			else stk.push(l);
		}
		if (stk.size() == 0) cnt++;
	}
	cout << cnt;

}

