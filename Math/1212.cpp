#include <iostream>
#include <string>

using namespace std;

string s, res = "";
int i;

void oct_first();
void oct();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;

	for (i = 0; i < s.length(); i++) {
		if (i == 0)
			oct_first();
		else 
			oct();
	}
	cout << res;
}

void oct_first() {
	if (s[i] - '0' == 0) res += "0";
	else if (s[i] - '0' == 1) res += "1";
	else if (s[i] - '0' == 2) res += "10";
	else if (s[i] - '0' == 3) res += "11";
	else if (s[i] - '0' == 4) res += "100";
	else if (s[i] - '0' == 5) res += "101";
	else if (s[i] - '0' == 6) res += "110";
	else if (s[i] - '0' == 7) res += "111";
}

void oct() {
	if (s[i] - '0' == 0) res += "000";
	else if (s[i] - '0' == 1) res += "001";
	else if (s[i] - '0' == 2) res += "010";
	else if (s[i] - '0' == 3) res += "011";
	else if (s[i] - '0' == 4) res += "100";
	else if (s[i] - '0' == 5) res += "101";
	else if (s[i] - '0' == 6) res += "110";
	else if (s[i] - '0' == 7) res += "111";
}
