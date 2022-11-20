#include <bits/stdc++.h>
using namespace std;

int ele, cnt;
unordered_set<int> A, B;
unordered_set<int>::iterator it;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ele;
		A.insert(ele);
	}

	for (int i = 0; i < m; i++) {
		cin >> ele;
		B.insert(ele);
	}


	for (auto it = A.begin(); it != A.end(); it++) {
		int cur = *it;
		if (B.find(cur) == B.end()) {
			cnt++;
		}
	}

	for (auto it = B.begin(); it != B.end(); it++) {
		int cur = *it;
		if (A.find(cur) == A.end()) {
			cnt++;
		}
	}

	cout << cnt;
}
