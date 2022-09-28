#include <bits/stdc++.h>
using namespace std;

// 모음 하나 반드시 포함
bool isVowel(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') return true;
	}
	return false;
}

// 모음 3개 or 자음 3개 연속 X
bool threeCnt(string s) {
	int consonant = 0;
	int vowel = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			if (consonant != 0) consonant = 0;
			vowel++;
		}
		else {
			if (vowel != 0) vowel = 0;
			consonant++;
		}

		if (consonant >= 3 || vowel >= 3) return false;
	}
	return true;
}

// 같은 글자 연속 두번 X (단 ee, oo는 허용)
bool twoConti(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == s[i + 1]) {
			if (s[i] == 'e' || s[i] == 'o') continue;
			else return false;
		}
	}
	return true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<string, bool>> v;
	string pwd;
	while (cin >> pwd) {
		if (pwd == "end") break;

		if (isVowel(pwd) == false || threeCnt(pwd) == false || twoConti(pwd) == false) {
			v.push_back(make_pair(pwd, false));
		}
		else {
			v.push_back(make_pair(pwd, true));
		}
	}

    for (int i = 0; i < v.size(); i++) {
        cout << "<" << v[i].first << "> is ";
        if (v[i].second == false) cout << "not acceptable.\n";
        else cout << "acceptable.\n";
    }	
}

