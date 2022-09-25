#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		int num = 1, min_pos = 1;
		while (1) {
			if (num % n == 0) {
				cout << min_pos<<"\n";
				break;
			}
			else {
				num = (num * 10) + 1;
				num %= n;
				min_pos++;
			}
		}
	}

}

