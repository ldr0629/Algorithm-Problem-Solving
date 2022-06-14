#include <iostream>
using namespace std;

int main() {
	int n, m, a, cnt;
	cin >> n >> a;

	m = n / a;
	cnt = m;
	while (m >= a) {
		m /= a;
		cnt += m;
	}
	cout << cnt;
}
