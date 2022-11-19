#include <bits/stdc++.h>
using namespace std;

string str;
unordered_map<string, int> unMap;
vector<string> result;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		unMap.insert({ str, i });
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (unMap.find(str) != unMap.end()) result.push_back(str);
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (auto res : result) {
		cout << res << "\n";
	}
}
