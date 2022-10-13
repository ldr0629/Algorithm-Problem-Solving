#include <bits/stdc++.h>
using namespace std;

int n;
string str, res;
vector<string> s;

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (isdigit(str[j])) {
				if (res.length() == 1 && res == "0") { // 문자를 더하기 전에 0이 있는 경우 생략하므로 초기화
					res = "";
				}
				res += str[j];
				if (j == str.length() - 1) { // 문자열의 마지막 문자인 경우 벡터에 삽입 후 초기화
					s.push_back(res);
					res = "";
				}
			}
			else {
				if (res != "") { // 연속된 숫자 또는 하나의 숫자가 있었던 경우 벡터 삽입
					s.push_back(res);
				}
				res = "";
			}
		}

	}
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << "\n";
	}
}

