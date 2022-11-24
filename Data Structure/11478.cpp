#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int cnt = 0;
	string str;
	cin >> str;

	set<string> set;
	string tmp = "";
	for (int i = 0; i < str.size(); i++) {
		for (int j = i; j < str.size(); j++) {
			tmp += str[j];
			set.insert(tmp);
		}
		tmp = "";
	}
	cout << set.size();
}
