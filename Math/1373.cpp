#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, res = "";
	cin >> s;

	while (s.length() % 3 != 0) {
		s = '0' + s;
	}

	for (int i = 0; i < s.length(); i += 3) {
		int sum = 0;
		for (int j = i; j < i + 3; j++) {
			sum += (s[j] - '0') * pow(2, 2 - (j % 3));
		}
		res += to_string(sum);
	}
	cout << res;
}
