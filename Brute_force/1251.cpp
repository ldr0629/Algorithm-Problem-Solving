#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string result;

void solve(string, int, int);

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.length()-1; i++) {
		for (int j = i; j < str.length() - 1; j++) {
			if (i >= j) continue;
			string tmp = str;
			solve(tmp, i, j);
		}
	}
	cout << result;
}

void solve(string tmp, int idx1, int idx2) {
	string word1 = "", word2 = "", word3 = "";
	for (int i = 0; i <= idx1; i++) word1 += tmp[i];
	for (int i = idx1 + 1; i <= idx2; i++) word2 += tmp[i];
	for (int i = idx2 + 1; i < tmp.length(); i++) word3 += tmp[i];

	reverse(word1.begin(), word1.end());
	reverse(word2.begin(), word2.end());
	reverse(word3.begin(), word3.end());

	string tmp_result = word1 + word2 + word3;
	if (result == "") result = tmp_result;
	else {
		if (result > tmp_result) result = tmp_result;
	}
}
