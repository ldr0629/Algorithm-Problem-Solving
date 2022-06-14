#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt, min = 50;
	int result;
	string a, b;
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		cnt = 0;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[j + i]) cnt++;
		}
		min = min >= cnt ? cnt : min;
	}
	cout << min;

}
